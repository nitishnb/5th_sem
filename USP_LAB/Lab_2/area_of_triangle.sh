echo "Enter base and height of triangle : "
read base
read height
area=$(echo "scale=2;1/2*$base*$height"|bc)
echo "The area of the triangle is $area sq units"
