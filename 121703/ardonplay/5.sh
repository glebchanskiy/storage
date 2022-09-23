#!/bin/bash
for file in `find $2 -type f -iname "*$3"`
do
	echo $file;
done > $1
