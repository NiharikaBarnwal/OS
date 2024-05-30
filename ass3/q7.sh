#Grading using switch case
#-------------------------
clear
echo "Enter name:"
read name
echo "Enter roll no:"
read roll
echo "Enter your marks:"
read a b c d
avg=`expr $a + $b + $c + $d`
avg=`expr $avg / 40`
case $avg in
	1) echo "Fail";;
	2) echo "Fail";;
	3) echo "Fail";;
	4) echo "Fail";;
	5) echo "C";;
	6) echo "B";;
	7) echo "A";;
	8) echo "E";;
	*) echo "O";;
esac
