student=$(cat "/export/home/kklin/std.txt")
online=$(who | cut -c 1-8 | sort)
exist=0
x=0
echo "�W�u�W��G"
for o in $online
do
    seat_num=0
    for s in $student
    do
         seat_num=$(($seat_num+1))
         if [ "$o" == "$s" ]; then
            echo "�y��:$seat_num �Ǹ�:$o"
         fi
    done
    x=$(($x+1))
done
echo '<br>'
echo ">>�W�u�H��:$x"
seat_num=0
y=0
echo "<br> <br>"
echo ">>���n�J�t�ΦW��G"
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
      echo "�y��:$seat_num �Ǹ�:$s"
      y=$(($y+1))
   fi
   exist=0
done
echo '<br>'
echo "���n�J�t�ΤH��:$y"
z=0
z=$(($x+$y))
echo "<br> <br>"
echo "(����H�Ʀ@$z�H)"
exit 0

