try:
    a = int(input("> "))
    b = int(input("> "))
except ValueError:
    print("please input a number")
else:
    print(a + b)
