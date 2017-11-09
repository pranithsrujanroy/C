n=$1
m=$n

while [ $m -gt 0 ]
do
	temp=`expr $m \% 10`
	m=`expr $m \/ 10`
	echo $temp
done

#echo $m
