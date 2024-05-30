#No. of occurence of a particular digit
#--------------------------------------
clear
echo "Enter the no.:"
read n
echo "Enter the digit:"
read x
count=0
while [ $n -ne 0 ]
do
	a=`expr $n % 10`
	if [ $a -eq $x ]
	then
		count=`expr $count + 1`
	fi
	n=`expr $n / 10`
done
echo $count
