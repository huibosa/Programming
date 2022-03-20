#!/usr/bin/env bash
set -x

cat << _EOF_
Please Select:

1. Display System Information
2. Display Disk Space
3. Display Home Space Utilization
0. Quit

_EOF_

read -p "Enter selection [0-3] > "

if [[ "$REPLY" =~ ^[0-3]$ ]]; then
  [[ "$REPLY" == 0 ]] && echo "Program terminated." && exit
  
  if [[ "$REPLY" == 1 ]]; then
    echo "Host name: $HOSTNAME"
    uptime
    exit
  fi
  
  [[ "$REPLY" == 2 ]] && df -h && exit
  
  if [[ "$REPLY" == 3 ]]; then
    if [[ "$UID" -eq 0 ]]; then
      echo "Home Space Utilization (All Users)"
      du -sh /home/*
    else
      echo "Home Space Utilization ($USER)"
      du -sh "$HOME"
    fi
    exit
  fi
fi
