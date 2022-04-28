import json

with open("favorite_number.json") as f:
    print(json.load(f))
