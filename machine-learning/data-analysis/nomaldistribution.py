#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt

mu, sigma = 100, 15

x = mu + sigma * np.random.randn(10000)

fig, ax = plt.subplots()

n, bins, patches = ax.hist(x, 100, density=1, facecolor="g", alpha=0.75)

ax.set_xlabel("Smarts")
ax.set_ylabel("Probability")
ax.set_title("Histogram of IQ")
ax.text(60, 0.025, r"$\mu=100, \ \sigma=15$")
ax.axis([40, 160, 0, 0.03])
ax.grid()

plt.show()
