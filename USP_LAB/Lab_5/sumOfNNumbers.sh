echo -n "Enter the upper limit : "
read n
i=1
while [ $i -le $n ]
do 
	sum=$((sum+i))
	i=$((i+1))
done
echo "The sum of numbers is $sum"
