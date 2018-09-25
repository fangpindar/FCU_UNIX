student=$(cat "/export/home/kklin/std.txt")
online=$(who | cut -c 1-8 | sort)
exist=0
x=0
echo "上線名單："
for o in $online
do
    seat_num=0
    for s in $student
    do
         seat_num=$(($seat_num+1))
         if [ "$o" == "$s" ]; then
            echo "座號:$seat_num 學號:$o"
         fi
    done
    x=$(($x+1))
done
echo '<br>'
echo ">>上線人數:$x"
seat_num=0
y=0
echo "<br> <br>"
echo ">>未登入系統名單："
for s in $student
do
    seat_num=$(($seat_num+1))
   for o in $online
   do
      if [ "$s" == "$o" ]; then
         exist=1
         break
      fi   
   done
   if [ "$exist" == 0 ]; then
      echo "座號:$seat_num 學號:$s"
      y=$(($y+1))
   fi
   exist=0
done
echo '<br>'
echo "未登入系統人數:$y"
z=0
z=$(($x+$y))
echo "<br> <br>"
echo "(全體人數共$z人)"
exit 0

