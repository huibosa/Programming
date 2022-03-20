#!/usr/bin/env python3

# 1 + 2 + 3 + 4 + ... + n ~ (n^2)/2

import sys
import numpy as np
import matplotlib.pyplot as plt

X = int(sys.argv[1])

arr = np.arange(1, X + 1)
a = np.power(1 - 1 / arr, arr)
plt.plot(a, "k", label=r"$(1-\frac{1}{x})^x$")

exp = np.full_like(a, 1 / np.exp(1))
plt.plot(exp, "r--", label=r"$\frac{1}{e}$")

plt.legend()
plt.show()
