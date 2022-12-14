#!/bin/bash

count=0
size=0
dir=.
start_dir=`pwd`
output=output.txt

if [ $1 ]; then
	dir=$1
fi

if [ $2 ]; then
	output=$2
fi

for file in `find $dir -type f -name '*'` 
do
	let size=$size+`wc -c $file | awk '{print $1}'`
	let count=$count+1
done 2>/dev/null

cd $dir
temp_dir=`pwd`
cd $start_dir
echo "$temp_dir $size $count" >> $output
