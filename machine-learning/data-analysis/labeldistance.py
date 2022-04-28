#!/usr/bin/env python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import itertools
import numpy as np

fig = plt.figure()
ax = fig.gca(projection="3d")

# plot points
a, b, c1, c2, z1, z2, z3 = 1, 2, 3, 4, 3, 6, 3
pts = [(a, 0, 0), (b, 0, 0), (c1, c2, 0), (z1, z2, z3)]
for p in pts:
    ax.scatter(p[0], p[1], p[2], zdir="z", c="r")

# plot tetrahedron
for a, b in itertools.product(pts, pts):
    x = np.linspace(a[0], b[0], 100)
    y = np.linspace(a[1], b[1], 100)
    z = np.linspace(a[2], b[2], 100)
    d = np.sqrt(sum([(a[i] - b[i]) ** 2 for i in (0, 1, 2)]))
    s = "%.2f" % d
    m = [(a[i] + b[i]) / 2.0 for i in (0, 1, 2)]
    ax.plot(x, y, z)
    if d > 0:
        ax.text(m[0], m[1], m[2], s)
    print(a, b, s)

plt.show()
