while True:
    a = input("> ")
    if a == "q":
        break
    b = input("> ")
    if b == "q":
        break
    try:
        answer = int(a) / int(b)
    except ZeroDivisionError:
        print("no zero")
    else:
        print(answer)
