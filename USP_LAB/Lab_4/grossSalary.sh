echo "Enter Basic salary"
read basic
hra=`expr 20 \* $basic / 100`
da=`expr 10 \* $basic / 100`
gs=`expr $basic + $hra + $da`
echo "Gross salary : Rs. $gs"
