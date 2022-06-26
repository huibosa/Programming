#!/usr/bin/env python3

# https://onestepcode.com/memory-mountain-cpu-cache/

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

import sys

data = []
index = []
columns = []

with open(sys.argv[1]) as f:
    for i, line in enumerate(f):
        # Discard first two lines (meta data)
        if i < 2:
            continue

        items = line.strip().split("\t")

        if i == 2:
            # Build columns
            columns = items
        else:
            # Build indexes
            index.append(items[0])
            # Build data
            row = [float(numstr) for numstr in items[1:]]
            data.append(row)


x = np.arange(1, 16)  # stride
y = np.arange(1, 15)  # size ticks
x, y = np.meshgrid(x, y)
xticks = columns
yticks = index

z = np.array(data)

fig = plt.figure()
ax = plt.axes(projection="3d")

ax.set_title("Memory Mountain\n", fontsize=22)
ax.set_xticks(range(1, 16, 2))
ax.set_yticks(range(1, 15, 2))
ax.set_xticklabels(xticks[::2])
ax.set_yticklabels(yticks[::2])
ax.set_xlabel("Stride", fontsize=18, labelpad=20)
ax.set_ylabel("Size", fontsize=18, labelpad=20)
ax.tick_params(axis="z", pad=10)

ax.plot_surface(x, y, z, cmap="jet")

plt.rcParams.update({"font.size": 16})
plt.tight_layout()
plt.show()
