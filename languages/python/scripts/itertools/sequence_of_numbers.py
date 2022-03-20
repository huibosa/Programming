#!/usr/bin/env python3

import itertools as it


def generateEvens():
    n = 0
    while True:
        yield n
        n += 2


def generateOdds():
    n = 1
    while True:
        yield n
        n += 2


evens = generateEvens()
print(list(next(evens) for _ in range(5)))

odds = generateOdds()
print(list(next(odds) for _ in range(5)))

evens = it.count(step=2)
print(list(next(evens) for _ in range(5)))

odds = it.count(start=1, step=2)
print(list(next(evens) for _ in range(5)))

count_with_floats = it.count(start=0.5, step=0.75)
print(list(next(count_with_floats) for _ in range(5)))

negative_count = it.count(start=-1, step=-0.5)
print(list(next(negative_count) for _ in range(5)))
