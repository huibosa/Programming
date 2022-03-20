#!/usr/bin/env bash

declare -a files
declare -A file_group
declare -A file_owner
declare -A groups
declare -A owners

if [[ ! -d "$1" ]]; then
  echo "Usage $0 dir" >&2
  exit 1
fi

for i in "$1"/**/*; do
  owner="$(stat -c %U "$i")"
  group="$(stat -c %G "$i")"
  files+=("$i")
  file_owner["$i"]="$owner"
  file_group["$i"]="$group"
  ((++owners[$owner]))
  ((++groups[$group]))
done

# list collected file
{ for i in "${files[@]}"; do
    printf "%-40s %-10s %-10s\n" \
      "$i" "${file_owner["$i"]}" "${file_group["$i"]}"
done } | sort
echo

# list owners
echo "File owners:"
{ for i in "${!owners[@]}"; do
    printf "%-10s: %5d file(s)\n" "$i" "${owners["$i"]}"
done } | sort
echo

# list groups
echo "File group owners:"
{ for i in "${!groups[@]}"; do
    printf "%-10s: %5d file(s)\n" "$i" "${groups["$i"]}"
done } | sort
