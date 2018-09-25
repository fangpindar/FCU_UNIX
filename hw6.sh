echo '<html>'
echo '<head>'
echo '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">'
echo '<title> UNIX 2018/02  </title>'
echo '</head>'
echo '<body>'
echo '<h3> UNIX ==>  2018/02 ,  IECS Compter !</h3> <hr>'
std=$(cat unix2018.data)
p="http://myweb.fcu.edu.tw/~"
n=1
for a in $std
do
echo "*** <a href=$p$a target="_blank"> $n </a>  "
n=$(($n + 1))
r=$(($n % 10))
if [ $r -eq 1 ]
then
echo "<br> <br>"
fi
done
echo '<hr>'
echo '</body>'
echo '</html>'
exit 0