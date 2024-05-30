#Sum of given series
#-------------------
clear
echo "Enter the length of series:"
read n
i=1
sum=0
while [ $i -ne `expr $n + 1` ]
do
	sum=$(echo "1/$i + $sum" | bc -l)
	i=`expr $i + 1`
done
echo "The sum is: $sum"
