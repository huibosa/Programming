#!/usr/bin/env bash

foo=file.txt.zip

echo ${foo#*.}
echo ${foo##*.}
echo ${foo%.*}
echo ${foo%%.*}
