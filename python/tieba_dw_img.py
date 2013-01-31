#!/usr/bin/env python3.2
import os
import platform
import shutil

from bs4 import BeautifulSoup
from urllib.parse import urlparse
from urllib.parse import urljoin
import urllib.request

tieba_name = "c语言"
tieba_url = "http://tieba.baidu.com/"
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
        album = tag["href"]
        if album not in album_entries:
            album_entries.append(album)
        else:
            page_num = -1
            break
    page_num += 1

# fetch images
cur_page = None
next_page = None
img_set = set()
for album in album_entries:
    cur_dir = os.path.join(work_dir,urllib.parse.unquote_plus(album.split("=")[-1],encoding='gbk'))
    try: os.makedirs(cur_dir)
    except: continue
    next_page = urllib.parse.urljoin(tieba_url,album)
    while (cur_page != next_page):
        cur_page = next_page
        page = urllib.request.urlopen(cur_page)
        soup = BeautifulSoup(page.read())
        for image in soup.find_all("img",onload="ZyqTupian.resize(this)"):
            img_src = image["src"]
            img_src = img_src.replace("/abpic","/pic")
            img_set.add(img_src)
        for tmp in soup.find_all('a'):
            if (tmp.string == "下一页"):
                next_page = urllib.parse.urljoin(tieba_url,tmp["href"])
    print ("album's name:%s, images num:%d" % (urllib.parse.unquote_plus(album.split("=")[-1],encoding='gbk'),len(img_set)))
    img_count += len(img_set)
    for img_addr in img_set:
        path = os.path.join(cur_dir,img_addr.split('/')[-1])
        img_dld = urllib.request.urlopen(img_addr).read()
        file_tmp = open(path, 'wb')
        file_tmp.write(img_dld)
        file_tmp.close()
    album_count += 1
    img_count += len(img_set)
    img_set.clear()

print ("download complete, totally %d albums, %d images")
