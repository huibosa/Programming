#!/usr/bin/env python3

import numpy as np


def norm(arr, l):
    total = 0
    for i in arr:
        total += np.power(i, l)
    return np.power(total, 1 / l)


arr = [1, 2, 3]
print(f"{norm(arr, 1)}")
print(f"{norm(arr, 2)}")
print(f"{norm(arr, 3)}")
