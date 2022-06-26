#!/usr/bin/env bash

if read -t 10 -sp "Enter secret passphrase > " secret_pass; then
  echo -e "\nSecret passphrase = '$secret_pass'"
else
  echo -e "\nInput timed out" >&2
  exit 1
fi
