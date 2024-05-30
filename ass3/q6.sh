#Largest and Smallest
#--------------------
clear
echo "Enter three no."
read a
read b
read c
if [ $a -ge $b -a $a -ge $c ]
then
	echo "Largest is $a"
elif [ $b -ge $a -a $b -ge $c ]
then
	echo "Largest is $b"
else 
	echo "Largest is $c"
fi
if [ $a -le $b -a $a -le $c ]
then
        echo "Smallest is $a"
elif [ $b -le $a -a $b -le $c ]
then
        echo "Smallest is $b"
else
        echo "Smallest is $c"
fi
