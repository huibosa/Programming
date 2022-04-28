def collatz(number):
    if number & 0x01:
        return 3 * number + 1
    else:
        return number // 2


number = int(input("Please input a number: "))
while number != 1:
    number = collatz(number)
    print(f"number = {number}")

print("Finish!!")
