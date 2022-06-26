#!/usr/bin/env bash

foo=([2]=a [4]=b [6]=c)

for i in "${foo[@]}"; do
  echo $i
done

for i in "${!foo[@]}"; do
  echo $i
done
