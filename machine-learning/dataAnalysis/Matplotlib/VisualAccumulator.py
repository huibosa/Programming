#!/usr/bin/env python

import sys
import numpy as np
import matplotlib.pyplot as plt


class VisualAccumulator:
    def __init__(self):
        self.total = 0
        self.count = 0
        self.fig, self.ax = plt.subplots()
        self.plt = plt

    def addDataValue(self, val):
        self.count += 1
        self.total += val
        self.ax.plot(self.count, val, "k.")
        self.ax.plot(self.count, self.mean(), "r.")

    def mean(self):
        return self.total / self.count

    def plot(self):
        self.plt.show()


def main():
    T = int(sys.argv[1])
    a = VisualAccumulator()

    for _ in range(T):
        a.addDataValue(np.random.rand() * 2 + -1)

    a.plot()


if __name__ == "__main__":
    main()
