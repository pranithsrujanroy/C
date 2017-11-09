n=$1
m=$n
temp=1
while [ $m -gt 0 ]
do
	temp=`expr $m \* $temp`
	m=`expr $m - 1`
	echo $temp
done

echo "\nfactorial of $n is $temp \n"
#echo $m
