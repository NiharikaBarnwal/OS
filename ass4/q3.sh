#sum of the digits of a no
#--------------------------
clear
echo "Enter a number:"
read n
sum=0
while [ $n -ne 0 ]
do
        x=`expr $n % 10`
        sum=`expr $sum + $x`
        n=`expr $n / 10`
done
echo "Sum of the digit of the no.: $sum"
