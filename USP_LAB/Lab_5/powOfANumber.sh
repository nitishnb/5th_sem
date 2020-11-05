echo -n "Enter the value of X & N to find X^N value :  "
read x n
product=1
while [ $n -gt 0 ]
do
	product=$((product*x))
	n=$((n-1))
done
echo "The result is $product"
