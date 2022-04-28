name = input("> ")

filename = "guest.txt"

with open(filename, "w") as f:
    f.write(name)
