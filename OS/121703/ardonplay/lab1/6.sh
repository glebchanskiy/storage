#!/bin/bash
if [ $1 ] 
then
dir=$2

if [ !$dir ]
then 
	dir="${1%%.*}".exe
fi

if gcc $1 -o $dir
then 
./$dir
else
echo "Compilation finish with error(s)"
exit 1
fi
else
echo "where is the file???"
exit 1
fi
