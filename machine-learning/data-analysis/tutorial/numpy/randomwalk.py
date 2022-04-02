#!/usr/bin/env python3

import numpy as np
import timeit


def random_walk_fastest(n=1000):
    steps = np.random.choice([-1, 1], n)
    return np.cumsum(steps)
