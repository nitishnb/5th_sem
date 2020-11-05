echo "Enter temprature in Fahrenheit (to convert into Celsius): "
read temp
c=$(expr "scale=2; ($temp - 32) * 5/9 "|bc)
echo "$temp F = $c °C"
