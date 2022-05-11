#!/usr/bin/env bash

IFS=$'\n' read -r -d '' -a arr1 < <(seq 5 && printf '\0')
declare -p arr1

IFS=$'\n' read -r -d '' -a arr2 < <(seq -f 'Num %g' 5 && printf '\0')
declare -p arr2

IFS=$'\n' read -r -d '' -a arr3 < <(seq -f 'Num*%g' 5 && printf '\0')
declare -p arr3
