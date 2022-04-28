toppings = []

while True:
    topping = input("> ")
    if topping != "quit":
        print(f"Adding {topping} to list.")
        toppings.append(topping)
        print(toppings)
    else:
        break
