#!/usr/bin/env python3

import itertools as it
import sys
import numpy as np
import matplotlib.pyplot as plt


def main():
    N = int(sys.argv[1])
    _, ax = plt.subplots()

    xs = np.random.rand(N) * 1000
    ys = np.random.rand(N) * 1000
    ax.scatter(xs, ys, s=5)

    pts = np.array(list(zip(xs, ys)))
    maxDist = 0
    maxPair = ()

    for a, b in it.product(pts, pts):
        dist = np.sqrt(sum([(a[i] - b[i]) ** 2 for i in (0, 1)]))

        if dist > maxDist:
            maxDist = dist
            maxPair = (a, b)

    print(pts)

    arr = np.array(maxPair)
    print()
    print(arr)
    print(arr[0])
    print(arr[1])

    ax.plot(arr[:, 0], arr[:, 1], "v--")
    plt.show()


if __name__ == "__main__":
    main()
