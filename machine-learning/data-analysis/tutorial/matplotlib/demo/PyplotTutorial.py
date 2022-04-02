# ---
# jupyter:
#   jupytext:
#     formats: ipynb,py
#     text_representation:
#       extension: .py
#       format_name: light
#       format_version: '1.5'
#       jupytext_version: 1.12.0
#   kernelspec:
#     display_name: Python 3.9.2 64-bit
#     name: python3
# ---

import matplotlib.pyplot as plt

plt.plot([1, 2, 3, 4])
plt.ylabel("some numbers")
plt.show()

plt.plot([1, 2, 3, 4], [1, 4, 9, 16])

plt.plot([1, 2, 3, 4], [1, 4, 9, 16], "ro")
plt.axis([0, 6, 0, 20])

import numpy as np

t = np.arange(0.0, 5.0, 0.2)
plt.plot(t, t, "r--", t, t**2, "bs", t, t**3, "g^")
