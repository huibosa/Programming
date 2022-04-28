import matplotlib.pyplot as plt

numbers = list(range(1, 5001))
cubes = [x**3 for x in range(1, 5001)]

fig, ax = plt.subplots()
ax.scatter(numbers, cubes, s=10)

ax.set_title("Cube Numbers", fontsize=24)
ax.set_xlabel("Numbers", fontsize=14)
ax.set_ylabel("Cubes of Numbers", fontsize=14)

plt.show()
