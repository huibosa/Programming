#!/usr/bin/env python3

import sys
import itertools as it
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches


def main():
    xlo = np.double(sys.argv[1])
    xhi = np.double(sys.argv[2])
    ylo = np.double(sys.argv[3])
    yhi = np.double(sys.argv[4])
    N = int(sys.argv[5])
    _, ax = plt.subplots()

    rectStart = (xhi, ylo)
    rectWidth = xhi - xlo
    rectHeight = yhi - ylo

    xs = np.random.rand(N)
    ys = np.random.rand(N)
    pts = np.array(list(zip(xs, ys)))

    ax.scatter(pts[:, 0], pts[:, 1], s=0.4, c="k", alpha=0.7)

    rect = patches.Rectangle(
        rectStart, rectWidth, rectHeight, linewidth=1, edgecolor="r", fill=False
    )
    ax.add_patch(rect)

    ax.plot()
    plt.show()


if __name__ == "__main__":
    main()
