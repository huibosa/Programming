strs=(foo bar foobar baz)

for str in "${strs[@]}"; do
  printf "%s" "$str" > "$str".txt
done
