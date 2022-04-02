#!/usr/bin/env python3

# 1 + 2 + 4 + 8 + ... + n = 2N - 1 ~ 2N when N = 2^n

import sys
import numpy as np
import matplotlib.pyplot as plt

N = int(sys.argv[1])

sum = np.cumsum(np.arange(1, N + 2, 2))
plt.plot(sum, "k", label="1 + 2 + 4 + 8 + ... + N")

plt.plot(2 * np.arange(1, N + 1), label="2N")

plt.legend()
plt.show()
