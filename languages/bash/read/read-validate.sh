#!/usr/bin/env bash

invalid_input() {
  echo "Invalid input '$REPLY'" >& 2
  exit 1
}

read -p "Enter a single item > "

[[ -z "$REPLY" ]] && invalid_input
[[ $(echo "$REPLY" | wc -w) -gt 1 ]] && invalid_input

if [[ "$REPLY" =~ ^([0-9]|[a-z]|_|\.|-)+$ ]]; then
  echo "'$REPLY' is a valid filename."
  
  if [[ -e "$REPLY" ]]; then
    echo "And file '$REPLY' exists."
  else
    echo "However, file '$REPLY' does not exist."
  fi

  # is input a floating number
  if [[ "$REPLY" =~ ^-?[0-9]*\.[0-9]+$ ]]; then
    echo "'$REPLY' is a floating point number."
  else
    echo "'$REPLY' is not a floating point number."
  fi

  # is input a integer
  if [[ "$REPLY" =~ ^-?[0-9]+$ ]]; then
    echo "'$REPLY' is an integer."
  else
    echo "'$REPLY' is not an integer."
  fi
else
  echo "The string '$REPLY' is not a valid filename."
fi
