#!/usr/bin/env bash

mkdir temp

./permutations.py | while read -r fname; do
  touch "$fname" && chmod "$fname" "$fname"
  mv "$fname" temp
done
