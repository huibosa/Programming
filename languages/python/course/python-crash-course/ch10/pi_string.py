filename = "pi_digits.txt"

with open(filename) as f:
    contents = f.read()


print(contents.index("031202"))
