#!/usr/bin/env bash

if [[ "$1" ]]; then
  echo "${1,,}"
  echo "${1,}"
  echo "${1^^}"
  echo "${1^}"
fi
