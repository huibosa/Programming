#!/usr/bin/env python3

import itertools as it

a = [0, 1, 2, 3, 4, 5, 6, 7]

for i in it.combinations_with_replacement(a, 3):
    for j in i:
        print(j, end="")
    print()
