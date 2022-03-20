#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import scipy as sp

# +
x, y = np.arange(-3, 4, 1), np.arange(-3, 4, 1)
X, Y = np.meshgrid(x, y)

Z = X + Y
fig = plt.figure(figsize=(9, 9))
ax = fig.add_subplot(1, 1, 1, projection="3d")
ax.scatter(X, Y, Z, s=100, label="$z=x+y$")
ax.legend()
plt.show()
