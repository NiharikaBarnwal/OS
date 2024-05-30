#Palindrome
#----------
clear
echo "Enter the string:"
read s
echo $s>temp
rvs="$(rev temp)"
if [ $s = $rvs ]
then
echo "It is palindrome"
else
echo "It is not a Palindrome"
fi
