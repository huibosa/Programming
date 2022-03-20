#!/usr/bin/env python3

import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

# +
n = 10

x = np.linspace(1, 2, 100)

logn = np.log(x)
nlogn = x * np.log(x)
nSquare = np.power(x, 2)
nCubic = np.power(x, 3)

plt.plot(x, logn, label="log(n)")
plt.plot(x, nlogn, label="n*log(n)")
plt.plot(x, x, label="n")
plt.plot(x, nSquare, label="n^2")
plt.plot(x, nCubic, label="n^3")
plt.legend()

plt.show()
