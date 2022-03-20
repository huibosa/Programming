#!/usr/bin/env bash

# script to recursive travel a dir of n levels

#######################################
# JUST FOR PRACTICE USE "FIND" INSTEAD
#######################################

find ./ -print0 | while IFS= read -r -d '' file do
  echo "$file"
done

function usage() {
  echo "usage: $0 <directory>"
  exit 1
}

function traverse() {
  for file in "$1"/*; do
    if [[ ! -d "$file" ]]; then
      echo "$file is a file"
    else
      echo "entering recursion with: $file"
      traverse "$file"
    fi
  done
}

function main() {
  [[ "$#" -ne 1 ]] && usage
  traverse "$1"
}

main "$1"

read
