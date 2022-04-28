import json


def get_stored_username():

    with open("username.json") as f:
        username = json.load(f)

    check = input(f"Are you {username}? (y/n) ")

    if check == "y":
        print(f"Welcome back, {username}!")
    else:
        get_new_username()


def get_new_username():

    username = input("What is your name? ")

    with open("username.json", "w") as f:
        json.dump(username, f)

    print(f"We'll remember you when you come back, {username}")


def greet_user():

    try:
        username = get_stored_username()
    except FileNotFoundError:
        username = get_new_username()


greet_user()
