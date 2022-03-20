#!/usr/bin/env python3


import numpy as np
import matplotlib.pyplot as plt

theta = np.linspace(0, 2 * np.pi, 200)
x = np.sin(theta)
y = np.cos(theta)

# x = np.linspace(-1, 1, 1000)
# y = np.sqrt(1-x**2)

fig, ax = plt.subplots(figsize=(4, 4))
ax.plot(x, y, color="darkred", linewidth=2)
ax.xaxis.set_major_locator(plt.NullLocator())
ax.yaxis.set_major_locator(plt.NullLocator())
ax.axis("equal")
plt.show()
