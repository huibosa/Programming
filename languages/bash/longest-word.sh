#!/usr/bin/env bash

# while [[ $# -ne 0 ]]; do
while [[ -n "$1" ]]; do
  if [[ -r "$1" ]]; then
    maxWord=
    maxLen=0
    for w in $(strings "$1"); do
      len=$(echo -n "$w"| wc -c)
      if [[ "$len" > "$maxLen" ]]; then
        maxLen="$len"
        maxWord="$w"
      fi
    done
    echo "$1: '$maxWord' ($maxLen characters)"
  fi
  shift
done
