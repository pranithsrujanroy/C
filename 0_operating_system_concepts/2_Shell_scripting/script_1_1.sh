#!/bin/bash
# Author	:	kirito_ys


if [ `expr $1 % 2` -eq 0 ]	
	then 
	echo $1 - even
	else
	echo $1 - odd
fi
