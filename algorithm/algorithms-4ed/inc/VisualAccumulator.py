#!/usr/bin/env python3

import sys
import fileinput
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
    arr = []
    for line in fileinput.input():
        arr.append(int(line))

    va = VisualAccumulator(np.array(arr)[:14350])
    va.plot()


if __name__ == "__main__":
    main()
