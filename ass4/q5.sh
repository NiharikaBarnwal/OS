#GCD of two no.
#--------------
clear
echo "Enter two no.:"
read n1 n2
gcd=1
i=1
while [ $i -le $n1 ]
do
	if [ `expr $n1 % $i` -eq 0 -a `expr $n2 % $i` -eq 0 ]
	then
		gcd=$i
	fi
	i=`expr $i + 1`
done
echo "The gdc is: $gcd"
