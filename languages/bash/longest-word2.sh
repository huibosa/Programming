#!/usr/bin/env bash

for i; do
  if [[ -r "$1" ]]; then
    maxWord=
    maxLen=0
    for w in $(strings "$i"); do
      len=$(echo -n "$w"| wc -c)
      if [[ "$len" > "$maxLen" ]]; then
        maxLen="$len"
        maxWord="$w"
      fi
    done
    echo "$i: '$maxWord' ($maxLen characters)"
  fi
done
