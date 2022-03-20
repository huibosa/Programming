filename = "programming_poll.txt"

responses = []

while True:
    a = input("> ")
    if a == "quit":
        break
    else:
        responses.append(a)

with open(filename, "w") as f:
    for response in responses:
        f.write(f"{response}\n")
