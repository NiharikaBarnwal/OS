#reverse the digits of a no
#--------------------------
clear
echo "Enter a number:"
read n
rev=0
while [ $n -ne 0 ]
do
	x=`expr $n % 10`
	rev=`expr $rev \* 10 + $x`
	n=`expr $n / 10`
done
echo "Reversed no.: $rev"
