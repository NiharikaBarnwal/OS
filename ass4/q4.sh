#position of a substring in a string
#-----------------------------------
clear
echo "Enter a string:"
read str
echo "Enter the substring:"
read substr
position="${str%%$substr*}"
if [ "$position" != "$str" ]; then
    position=$(( ${#position} + 1 ))
else
    position=0
fi

if [ "$position" -gt 0 ]; then
    echo "Position of substring '$substr' in '$str' is: $position"
else
    echo "Substring '$substr' not found in '$str'"
fi
