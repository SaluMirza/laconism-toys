#!/usr/bin/env python3.2
import os
import platform
import shutil

from bs4 import BeautifulSoup
from urllib.parse import urlparse
from urllib.parse import urljoin
import urllib.request

tieba_name = "c语言"
work_dir = os.getcwd()
album_count = 0
img_count = 0

# fetch album entries
tieba_name = urllib.parse.quote_plus(tieba_name,encoding='gbk')
page_num = 1
album_entries = [] 
while page_num > 0:
    page = urllib.request.urlopen("http://tieba.baidu.com/f/tupian?kw=%s&pn=%d" % (tieba_name,page_num))
    soup = BeautifulSoup(page.read())
    for tag in soup.find_all('a', class_="alb_box_inner"):
        album = {
            "name": tag["href"].split("=")[-1],
            "href": urllib.parse.urljoin("http://tieba.baidu.com/",tag["href"]),
            }
        if album not in album_entries:
            album_entries.append(album)
        else:
            page_num = -1
            break
    page_num += 1

# fetch images
cur_page = None
next_page = None
page_num = 2
img_set = set()
for album in album_entries:
    cur_dir = os.path.join(work_dir,urllib.parse.unquote_plus(album["name"],encoding='gbk'))
    os.makedirs(cur_dir)
    next_page = album["href"]
    while (cur_page != next_page):
        print ("%s" % next_page)
        page = urllib.request.urlopen(next_page)
        cur_page = next_page
        soup = BeautifulSoup(page.read())
        for image in soup.find_all("img",onload="ZyqTupian.resize(this)"):
            img_src = image["src"]
            img_src = img_src.replace("/abpic","/pic")
            img_set.add(img_src)
        for tmp in soup.find_all('a'):
            if (tmp.string == "下一页"):
                next_page = album["href"] + ("&pn=%d" % page_num)
        page_num += 1
    for img_addr in img_set:
        path = os.path.join(cur_dir,img_addr.split('/')[-1])
        img_dld = urllib.request.urlopen(img_addr).read()
        file_tmp = open(path, 'wb')
        file_tmp.write(img_dld)
        file_tmp.close()
    page_num = 2
    album_count += 1
    img_count += len(img_set)
    print ("%s download complete, totally %d albums, %d images" % (urllib.parse.unquote_plus(album["name"],encoding='gbk'),album_count,len(img_set)))
    img_set.clear()

print ("download complete, totally %d albums, %d images")
