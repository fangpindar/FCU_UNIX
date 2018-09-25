#!/bin/bash
echo "Content-type: text/html"
echo ""
echo '<html>'
echo '<head>'
echo '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">'
echo '<title> 點名系統 ! </title>'
echo '</head>'
echo '<body>'
echo '<h3>' 
echo '<br>'
echo '</h3>'
student=$(cat "ux2017.txt")
online=$(who | cut -c 1-8 | sort -u )
exist=0
n=0
echo "實到名單：<br>"
for o in $online
do
    seat_num=0
    for s in $student
    do
         seat_num=$(($seat_num+1))
         if [ "$o" == "$s" ]; then
            n=$(($n+1)) 
            echo "座號:$seat_num 學號:$o<br>"
         fi
    done
done
echo "上課人數:$n<br>"
seat_num=0
n=0
echo "缺席名單:<br>"
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
      echo "座號:$seat_num 學號:$s<br>"
      n=$(($n+1))
   fi
   exist=0
done
echo "缺席人數:$n<br>"
exit 0
