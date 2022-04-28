import json

a = input("> ")

with open("favorite_number.json", "w") as f:
    json.dump(a, f)
