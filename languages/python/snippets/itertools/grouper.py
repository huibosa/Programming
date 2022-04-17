#!/usr/bin/env python3

import itertools as its


# n = 2: [0:2] [2:4] [4:6]
# n = 3: [0:3] [3:6] [6:9]
def naive_grouper(inputs, n):
    num_groups = len(inputs) // n
    return [tuple(inputs[i * n : (i + 1) * n]) for i in range(num_groups)]


def better_gouper(inputs, n):
    itrs = [iter(inputs)] * n
    return zip(*itrs)


def grouper(inputs, n, fillvalue=None):
    itrs = [iter(inputs)] * n
    return its.zip_longest(*itrs, fillvalue=fillvalue)


def main():
    for _ in better_gouper(range(100000000), 10):
        pass


if __name__ == "__main__":
    main()
