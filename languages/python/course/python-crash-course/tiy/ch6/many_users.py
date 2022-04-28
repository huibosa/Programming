users = {
    "aeinstein": {
        "first": "albert",
        "last": "einstein",
        "location": "princeton",
    },
    "mcurie": {
        "first": "marie",
        "last": "curie",
        "location": "paris",
    },
}

for user, user_info in users.items():
    print(f"\nUsername: {user}")
    print(f"\tFull name: {user_info['first'].title()} {user_info['last'].title()}")
    print(f"\tLocation: {user_info['location'].title()}")
