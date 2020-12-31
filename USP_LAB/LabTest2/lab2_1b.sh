#!/bin/sh
if [ $# -eq 2 ]
then
	sort $1 > temp
	sort $2 > temp1
	sort -m temp temp1
	rm temp temp1
	exit 1
fi
echo "Error in number of arguments"
