#!/bin/sh

NAME[0]=12
NAME[1]=1
NAME[2]=32
NAME[3]=4
NAME[4]="Daisy"
for i in 0 1 2 3 
do
	echo ${NAME[$i]}
done

echo "First Index: ${NAME[1]}"
echo "Second Index: ${NAME[1]}"
