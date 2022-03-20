#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

x = np.linspace(-10, 10, 100)

ax.spines["left"].set_position("center")
ax.spines["bottom"].set_position("center")
ax.spines["right"].set_color("none")
ax.spines["top"].set_color("none")

ax.xaxis.set_ticks_position("bottom")
ax.yaxis.set_ticks_position("left")

ax.plot(x, (x - 1) / 2, "r-", label="x-2y=1")
ax.plot(x, (-3 * x + 11) / 2, "r--", label="3x+2y=11")

ax.legend(loc="upper right")

plt.show()
