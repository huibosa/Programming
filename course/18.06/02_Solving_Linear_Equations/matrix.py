#!/usr/bin/env python

import numpy as np

A = np.array([[1, 2, 3], [2, 5, 2], [6, -3, 1]])

x = np.array([[0, 0, 2]]).T

# matrix multiplication
b1 = np.dot(A, x)

# row at a time
# b2 = np.asarray([A[0:1,:]*x],
#                  [A[1:2,:]*x],
#                  [A[2:3,:]*x])

b3 = A[:, :1] * x[0] + A[:, 1:2] * x[1] + A[:, 2:3] * x[2]

print(b3)
