import json


def get_stored_username():
    """Get stored user name if available."""
    try:
        with open("username.json") as f:
            username = json.load(f)
    except FileNotFoundError:
        return None
    else:
        return username


def get_new_username():
    """Prompt for a new username."""
    username = input("> ")
    with open("username.json", "w") as f:
        json.dump(username, f)
    return username


def greet_user():
    """Greet the user by name"""
    username = get_stored_username()
    if username:
        print(username)
    else:
        get_new_username()


greet_user()
