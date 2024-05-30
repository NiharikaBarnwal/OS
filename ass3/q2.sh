#Sum and avg of 4 no.
#-------------------
clear
c=`expr $1 + $2 + $3 + $4`
echo "ADDITION OF FOUR NO.: $c"
d=`expr $c / 4`
echo "AVERAGE OF FOUR NO.: $d"
