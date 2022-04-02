#!/usr/bin/env python3

import numpy as np


def get_sparcity(A):
    return 1.0 - np.count_nonzero(A) / A.size
