#!/bin/bash

echo "Content-type: text/html"
echo ""
echo '<html>'
echo '<head>'
echo '<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">'
echo '<title> Who Uptime ! </title>'
echo '</head>'
echo '<body>'
echo '<h3>'
hostname
echo '</h3>'
uptime
/jws/home/staffs/kklin/sswho
echo '</body>'
echo '</html>'
exit 0
