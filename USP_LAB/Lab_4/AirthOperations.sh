echo "Menu\n 1) Addition\n 2) Subtraction \n 3) Divison\n 4) Multiplication\n 5) Remainder\n "
read choice
echo "Enter a and b : "
read a b
case "$choice" in
	1) c=`echo $a + $b | bc`;;
	2) c=`echo $a - $b | bc`;;
	3) c=`echo $a / $b | bc`;;
	4) c=`echo $a \* $b | bc`;;
	5) c=`echo $a % $b | bc`;;
	*) echo "Invalid option"
	    exit 1
esac
echo "The result is : $c"
