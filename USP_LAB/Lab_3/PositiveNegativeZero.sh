#!/bin/sh

echo -n "Enter value of a : " 
read a

if [ $a -eq 0 ] 
then
     echo "ZERO"
elif [ $a -gt 0 ]
then 
     echo "POSITIVE number"
else
	echo "NEGATIVE number"	
fi

