#!/usr/bin/env python3


def add(A, B):
    ret = []
    for x, y in zip(A, B):
        temp = []
        for i, j in zip(x, y):
            temp.append(i + j)
        ret.append(temp)
    return ret


def sub(A, B):
    ret = []
    for x, y in zip(A, B):
        temp = []
        for i, j in zip(x, y):
            temp.append(i - j)
        ret.append(temp)
    return ret


def mat(A, B):
    ret = []
    for x, y in zip(A, B):
        temp = []
        for i, j in zip(x, y):
            temp.append(i * j)
        ret.append(temp)
    return ret


def div(A, B):
    ret = []
    for x, y in zip(A, B):
        temp = []
        for i, j in zip(x, y):
            temp.append(i / j)
        ret.append(temp)
    return ret


# def scalarMat(n, A):
#     depth = lambda L: isinstance(L, list) and max(map(depth, L)) + 1
#
#     ret = []
#     for i in range(depth(A)):
#         tot = []
#         for j in A[i]:
#             tot.append(n * j)
#         ret.append(tot)
#     return ret


def scalarMat(n, A):
    ret = []
    for i in A:
        temp = []
        for j in i:
            temp.append(n * j)
        ret.append(temp)
    return ret


def dot(A, B):
    pass


A = [[1, 2, 3], [2, 3, 4]]

B = [[3, 4, 5], [4, 5, 6]]

print(f"A = {A}")
print(f"B = {B}")

print(f"Matrix Addition: {add(A, B)}")
print(f"Matrix Substraction: {sub(A, B)}")
print(f"Matrix Multiplycation: {mat(A, B)}")
print(f"Matrix Division: {div(A, B)}")
print(f"Matrix Scalar multiplication: {scalarMat(3, A)}")
