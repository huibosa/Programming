#!/usr/bin/env bash

# children=(./child1.sh ./child2.sh ./child3.sh ./child4.sh ./child5.sh)

# for child in "${children[@]}"; do
#   "${child}" &
#   pids+=("$!")
# done

for ((i = 0; i < 5; i++)); do
  ./press.sh &
  pids+=("$!")
done

for pid in "${pids[@]}"; do
  wait "$pid"
done
