#!/usr/bin/env bash

# unset whole array
foo=(a b c d e f)
echo "${foo[@]}"

unset foo
echo "${foo[@]}"

# unset single entry
foo=(a b c d e f)
echo "${foo[@]}"

unset foo[2]
echo "${foo[@]}"
