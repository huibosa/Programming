#!/usr/bin/env python3

import itertools as it


def fibs():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


fib = fibs()
print([next(fib) for _ in range(10)])

count_by_three = it.count(step=3)
count_by_four = it.count(step=4)

all_ones = it.repeat(1)
all_twos = it.repeat(2)

five_ones = it.repeat(1, 5)
three_fours = it.repeat(4, 3)

alternating_ones = it.cycle([-1, 1])
