#!/usr/bin/env python3

import itertools as its

makes_100 = []

bills = [20, 20, 20, 10, 10, 10, 10, 10, 5, 5, 1, 1, 1, 1, 1]

for n in range(1, len(bills) + 1):
    for combination in its.combinations(bills, n):
        if sum(combination) == 100:
            makes_100.append(combination)

print(set(makes_100))
