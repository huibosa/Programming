import numpy as np


A = np.ones((3, 3))
B = np.arange(1, 4).reshape(3, 1)
b = np.arange(1, 4)

print(f"A:\n{A}")
print(f"B:\n{B}")
print(f"b:\n{b}")
print("*" * 50)


print(f"A @ B:\n{A @ B}")
print(f"A * B:\n{A * B}")
print(f"A * B.T:\n{A * B.T}")

print("*" * 50)

print(f"A @ b:\n{A @ b}")
print(f"A * b:\n{A * b}")

print("*" * 50)
