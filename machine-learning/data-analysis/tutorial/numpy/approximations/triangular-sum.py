#!/usr/bin/env python3

# 1 + 2 + 3 + 4 + ... + n ~ (n^2)/2

import sys
import numpy as np
import matplotlib.pyplot as plt

N = int(sys.argv[1])

tSum = np.cumsum(np.arange(1, N + 1))
plt.plot(tSum, "k--", label="1 + 2 + 3 + ... + N")

halfSquareN = np.square(np.arange(1, N + 1)) / 2
plt.plot(halfSquareN, "r", label=r"$\frac{N^2}{2}$")

plt.legend()
plt.show()
