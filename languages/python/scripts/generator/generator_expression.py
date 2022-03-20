#!/usr/bin/env python3

import sys

nums_squared_lc = [num**2 for num in range(100000000)]
nums_squared_gc = (num**2 for num in range(100000000))

print(sys.getsizeof(nums_squared_lc))
print(sys.getsizeof(nums_squared_gc))
