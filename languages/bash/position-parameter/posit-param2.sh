#!/usr/bin/env bash

count=1

while [[ $# -gt 0 ]]; do
  echo "Arguments ${count}: $1"
  count=$((count + 1))
  shift
done
