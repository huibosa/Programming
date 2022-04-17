#!/usr/bin/env python3

import itertools as its

bills = [50, 20, 10, 5, 1]
makes_100 = []
for n in range(1, 101):
    for combination in its.combinations_with_replacement(bills, n):
        if sum(combination) == 100:
            makes_100.append(combination)

print(len(makes_100))
