#!/usr/bin/env bash



if [[ $# -ne 1 ]]; then
  echo "Usage is $0 basepath"
fi

path=$1

declare -A statArray

while read line; do
  ftype=$(file -b "$line" | cut -d, -f1)
  ((++statArray["$ftype"]))
done <<< "$(find "$path" -type f -print)"


for file in "${!statArray[@]}"; do
  printf "%s\t\t\t%s\n" "$file" "${statArray["$file"]}"
done
