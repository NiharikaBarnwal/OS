#Even or odd
#-----------
clear
echo "Enter a no.:"
read a
if [ `expr $a % 2` -eq 0 ]
then
	echo "Even"
else
	echo "Odd"
fi
