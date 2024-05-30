#Fibonacci series
#----------------
clear
echo "Enter a number:"
read n
x=0
y=1
i=2
f=0
echo $x
echo $y
while [ $i -ne $n ]
do
	f=`expr $x + $y`
	x=$y
	y=$f
	echo $f
	i=`expr $i + 1`
done
