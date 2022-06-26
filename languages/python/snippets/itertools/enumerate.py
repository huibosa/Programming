#!/usr/bin/env python3

import itertools as it


def enumerate(arr):
    return zip(it.count(), arr)


for i, v in enumerate(list("abc")):
    print(f"{i}: v")
