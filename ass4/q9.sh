#Factorial of a no.
#------------------
clear
echo "Enter a no.:"
read n
f=1
i=1
while [ $i -ne `expr $n + 1` ]
do
	f=`expr $f \* $i`
	i=`expr $i + 1`
done
echo "The factorial is: $f"
