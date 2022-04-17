#!/usr/bin/env python3

import operator
import itertools as it


def accumulate(inputs, func):
    itr = iter(inputs)
    prev = next(itr)
    for cur in itr:
        yield prev
        prev = func(prev, cur)


print(list(it.accumulate([1, 2, 3, 4, 5], operator.add)))
