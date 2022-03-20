#!/usr/bin/env python3

import sys
import numpy as np
import matplotlib.pyplot as plt


class VisualAccumulator:
    def __init__(self, arr):
        self.arr = arr
        _, self.ax = plt.subplots()
        self.plt = plt

    def getCumSumMean(self):
        cSum = np.cumsum(self.arr)
        count = np.arange(1, self.arr.size + 1)
        cSumMean = cSum / count

        return cSumMean

    def plot(self):
        cSumMean = self.getCumSumMean()

        self.ax.scatter(np.arange(self.arr.size), self.arr, s=0.5, c="k", alpha=0.5)
        self.ax.plot(cSumMean, c="r")

        self.plt.show()


def main():
    T = int(sys.argv[1])

    arr = np.random.rand(T) * 2 + -1
    va = VisualAccumulator(arr)
    va.plot()


if __name__ == "__main__":
    main()
