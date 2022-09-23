#!/bin/bash

count=0
size=0
dir=.
dir2=$(pwd)
output=7.txt

if [ $1 ]; then
	dir=$1
fi

if [ $2 ]; then
	output=$2
fi

for file in find $dir -type f -name '*' 
do
	# $size = $(($size + `wc -c $file | awk '{print $1}'`))
	let size=$size+`wc -c $file | awk '{print $1}'`
	let count=$count+1
done 2>/dev/null

echo size: $size, files: $count
cd $dir
dir=$(pwd)
cd $dir2
echo "$dir $size $count" >> $output
