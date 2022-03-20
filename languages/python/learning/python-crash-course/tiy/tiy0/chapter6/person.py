person = {
    "first_name": "john",
    "last_name": "simith",
    "age": 18,
    "city": "Beijing",
}

for key, value in person.items():
    if key != "age":
        print(f"{key.title()}: {value.title()}")
    else:
        print(f"{key.title()}: {value}")
