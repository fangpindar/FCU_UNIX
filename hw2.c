read -p "please enter an integer m:" m
read -p "please enter an integer n:" n
while [ "$n" != "0" ]
do
    r=$(($m % $n))
    m=$n
    n=$r
done
echo "GCD:$m"