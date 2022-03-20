import matplotlib.pyplot as plt

x_values = range(1, 5001)
y_values = [x**3 for x in range(1, 5001)]

fig, ax = plt.subplots()
ax.scatter(x_values, y_values, c=y_values, cmap=plt.cm.Blues, s=10)

ax.set_title("Cubes Number", fontsize=24)
ax.set_xlabel("Numbers", fontsize=14)
ax.set_ylabel("Cubes of Numbers", fontsize=14)

plt.show()
plt.savefig("cubes_plot.png", bbox_inches="tight")
