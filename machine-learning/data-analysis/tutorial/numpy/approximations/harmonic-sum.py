#!/usr/bin/env python3

# 1 + 1/2 + 1/3 + 1/4 + ... + 1/n ~ ln(n)

import sys
import numpy as np
import matplotlib.pyplot as plt

N = int(sys.argv[1])

nOnes = np.ones(N)
oneToN = np.arange(1, N + 1)
hSum = np.cumsum(nOnes / oneToN)
plt.plot(hSum, "k", label=r"$1+1/2+1/3+1/4+...+1/n$")

lnN = np.arange(1, N)
plt.plot(np.log(lnN), "r--", label=r"$ln(N)$")

plt.legend()
plt.show()
