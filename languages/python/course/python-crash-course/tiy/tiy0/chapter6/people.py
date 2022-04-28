person1 = {
    "first_name": "john",
    "last_name": "simith",
    "age": 18,
    "city": "Beijing",
}

person2 = {
    "first_name": "tom",
    "last_name": "kati",
    "age": 36,
    "city": "Guangdon",
}

person3 = {
    "first_name": "hu",
    "last_name": "haoran",
    "age": 24,
    "city": "Sichuan",
}

people = []

people.append(person1)
people.append(person2)
people.append(person3)

for person in people:
    for key, value in person.items():
        if key != "age":
            print(f"{key.title()}: {value.title()}")
        else:
            print(f"{key.title()}: {value}")
