#!/bin/bash
# use to count the total lines of these codes

count_file_type=".+\.(c|h|s|S)$"
count_sum=0
if [$# = 0]
then
    work_pwd=$(pwd)
else
    work_pwd=$1
fi

function scan_dir() {
    local work_dir file_lines_num
    file_lines_num=0
    work_dir=$1
    for file_to_count in $(ls | grep -E $count_file_type)
    do
        file_lines_num=`cat $file_to_count | wc -l`
        count_sum=`expr $file_lines_num + $count_sum`
    done
    for dir in $(ls -F|grep /)
    do
        cd $dir
        scan_dir $(pwd .)
        cd ..
    done
}

scan_dir work_dir
echo $count_sum
