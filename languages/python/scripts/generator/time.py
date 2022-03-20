#!/usr/bin/env python3

import cProfile

print(cProfile.run("sum([i*2 for i in range(100000)])"))
print("*" * 80)
print(cProfile.run("sum((i*2 for i in range(100000)))"))
