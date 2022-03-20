#!/usr/bin/env python3


def add(a, b):
    ret = []
    for x1, x2 in zip(a, b):
        ret.append(x1 + x2)
    return ret


def sub(a, b):
    ret = []
    for x1, x2 in zip(a, b):
        ret.append(x1 - x2)
    return ret


def div(a, b):
    ret = []
    for x1, x2 in zip(a, b):
        ret.append(x1 / x2)
    return ret


def times(a, b):
    ret = []
    for x1, x2 in zip(a, b):
        ret.append(x1 * x2)
    return ret


def dot(a, b):
    ret = 0
    for x1, x2 in zip(a, b):
        ret += x1 * x2
    return ret


def scalar_multi(n, a):
    ret = []
    for i in a:
        ret.append(i * n)
    return ret


a = [1, 2, 3]
b = [4, 5, 6]

print(f"a = {a}, b = {b}")
print(f"Addition: {add(a, b)}")
print(f"Substraction: {sub(a, b)}")
print(
    f"Multiplycation: {times(a, b)}",
)
print(f"Division: {div(a, b)}")
print(f"Dot: {dot(a, b)}")
print(f"Scalar multiplycation: {scalar_multi(3, a)}")
