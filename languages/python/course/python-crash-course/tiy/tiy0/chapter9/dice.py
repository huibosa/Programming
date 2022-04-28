from random import randint


class Die:
    def __init__(self, sides=6):
        self.sides = sides

    def roll_die(self):
        return randint(1, self.sides)


d6 = Die()

results = []

for i in range(10):
    results.append(d6.roll_die())

print(results)

d10 = Die(10)

results = []

for i in range(10):
    results.append(d10.roll_die())

print(results)

d20 = Die(20)

results = []

for i in range(10):
    results.append(d20.roll_die())

print(results)
