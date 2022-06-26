#!/usr/bin/env bash

FILE=/etc/passwd

read -p "Enter a username > " username

fileInfo="$(grep "^${username}:" ${FILE})"

if [[ -n "${fileInfo}" ]]; then
  IFS=":" read user pw uid gid name home shell <<< "${fileInfo}"
  echo "User = '$user'"
  echo "UID = '$uid'"
  echo "GID = '$gid'"
  echo "Full Name = '$name'"
  echo "Home Dir. = '$home'"
  echo "Shell = '$shell'"
else
  echo "No such user '${username}'" >&2
  exit 1
fi
