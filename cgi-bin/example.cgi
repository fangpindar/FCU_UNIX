#!/bin/bash

echo "Content-type: text/html"
echo ""

echo "<html><head><title> QUERY_STRING ! </title></head>"
echo "<body> Testing ==> "
echo "QUERY_STRING = $QUERY_STRING <br>"
q=$(echo $QUERY_STRING | sed 's/[=&]/ /g')
echo "q = $q !"
echo "</body></html>"
