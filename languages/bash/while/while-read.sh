#!/usr/bin/env bash

while read -r distro version release; do
  printf "Distro: %s\tVersion: %s\tReleased: %s\n" \
    "$distro" \
    "$version" \
    "$release"
done < distros.txt
