#!/usr/bin/env bash

animals=("a dog" "a cat" "a fish")

for i in ${animals[*]}; do
  echo $i
done

for i in ${animals[@]}; do
  echo $i
done

for i in "${animals[*]}"; do
  echo $i
done

for i in "${animals[@]}"; do
  echo $i
done
