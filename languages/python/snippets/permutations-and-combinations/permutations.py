#!/usr/bin/env python3

import itertools as it

nums = list(range(0, 8))

for i in it.combinations_with_replacement(nums, 3):
    for j in i:
        print(j, end="")
    print()
