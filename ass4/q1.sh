#Display odd position
#--------------------
clear
echo "Enter a 5 digit no.:"
read n
i=1
while [ $n -ne 0 ]
do
	x=`expr $n % 10`
	if [ `expr $i % 2` -ne 0 ]
	then
		echo $x
	fi
	n=`expr $n / 10`
	i=`expr $i + 1`
done
