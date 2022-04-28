while True:
    username = input("> ")

    if username != "quit":

        print(f"Hello, {username}")

        with open("guest_book.txt", "a") as f:
            f.write(username + "\n")
    else:
        break
