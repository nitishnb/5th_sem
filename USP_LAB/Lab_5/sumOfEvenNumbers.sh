echo -n " Enter  upper  limit  :  "
read n
k=2
while [ $k -lt $n ]
do
	sum=$((sum+k))
	k=$((k+2))
done
echo " Sum  is  $sum"
