#!/usr/bin/env bash

readarray -t arr1 < <(seq 5)
declare -p arr1

readarray -t arr2 < <(seq -f 'Num %g' 5)
declare -p arr2

readarray -t arr2 < <(seq -f 'Num*%g' 5)
declare -p arr2
