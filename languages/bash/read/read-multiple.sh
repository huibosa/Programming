#!/usr/bin/env bash

echo -n "Enter one or more values > "
read var1 var2 var3 var4 var5

cat << _EOF_
var1 = '${var1}'
var2 = '${var2}'
var3 = '${var3}'
var4 = '${var4}'
var5 = '${var5}'
_EOF_
