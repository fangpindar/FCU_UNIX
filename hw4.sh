student=$(cat "/etc/passwd" | grep '^d0' | cut -c 1-8)
for s in $student
do
    id="/student/iecs/1062/"$s"/id.txt"
    test -e $s && cat $id || echo "$s"
done
exit 0