import json

numbers = [2, 3, 5, 7, 11, 13]

with open("numbers.json", "w") as f:
    json.dump(numbers, f)
