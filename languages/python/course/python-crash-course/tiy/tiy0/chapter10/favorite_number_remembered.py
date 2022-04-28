import json

filename = "favorite_number.json"

while True:
    a = input("> ")

    try:
        with open(filename) as f:
            print(json.load(f))

    except:
        if a == "quit":
            break

        with open(filename, "w") as f:
            json.dump(a, f)
