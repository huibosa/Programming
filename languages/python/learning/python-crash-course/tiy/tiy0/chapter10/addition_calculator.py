while True:
    try:
        a = int(input("> "))
        if a == "q":
            break

        b = int(input("> "))
        if b == "q":
            break
    except:
        print("input a number!")
    else:
        print(a + b)
