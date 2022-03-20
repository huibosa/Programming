#!/usr/bin/env bash

cat << _EOF_
Please Select:

A. Display System Information
B. Display Disk Space
C. Display Home Space Utilization
Q. Quit

_EOF_

read -p "Enter selection [A, B, C or D] > "

case "$REPLY" in
  q|Q)  echo "Program terminated." exit ;;
  a|A)  echo "Hostname: $HOSTNAME" uptime ;;
  b|B)  df -h ;;
  c|C)  if [[ "$(id -u)" -eq 0 ]]; then
          echo "Home Space Utilization (All Users)"
          du -sh /home/*
        else
          echo "Home Space Utilization ($USER)"
          du -sh "$HOME"
        fi
        ;;
  *)    echo "Invalid entry" >&2
        exit 1
        ;;
esac
