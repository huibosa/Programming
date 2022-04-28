import json

with open("username.json") as f:
    username = json.load(f)

print(username)
