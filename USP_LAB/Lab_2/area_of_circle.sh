echo "Enter the radius of the circle : "
read r
area=$(echo "scale=2;22 / 7* ($r * $r)"| bc)
echo "The radius of the circle with radius $r units is $area sq units"
