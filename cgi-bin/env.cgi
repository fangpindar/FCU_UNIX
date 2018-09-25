#!/bin/bash

echo "Content-type: text/html"
echo ""

/bin/cat << EOM
<HTML>
<HEAD><TITLE> ENV ! </TITLE>
</HEAD>
<BODY bgcolor="#cccccc" text="#000000">
<P>
<SMALL>
<PRE>
EOM

/bin/env

/bin/cat << EOM
</PRE>
</SMALL>
<P>
EOM
echo "</BODY>"
echo "</HTML>"
