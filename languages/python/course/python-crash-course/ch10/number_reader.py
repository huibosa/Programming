import json

with open("numbers.json") as f:
    numbers = json.load(f)

print(numbers)
