#!/usr/bin/env python

import numpy as np

a = np.array([[1, 0, 0], [-3, 1, 0], [0, 0, 1]])

b = np.array([[1, 2, 1], [3, 8, 1], [0, 4, 1]])

result = np.dot(a, b)

print(result)
