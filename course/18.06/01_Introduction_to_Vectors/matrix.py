# ---
# jupyter:
#   jupytext:
#     formats: ipynb,py:light
#     text_representation:
#       extension: .py
#       format_name: light
#       format_version: '1.5'
#       jupytext_version: 1.12.0
#   kernelspec:
#     display_name: 'Python 3.9.9 64-bit (''DataAnalysis'': venv)'
#     language: python
#     name: python3
# ---

import numpy as np
import matplotlib.pyplot as plt

np.identity(5)

np.zeros((3, 4))

np.full([1, 1], 7)

M = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
M

# +
a = np.array([[1, 0, 0], [-1, 1, 0], [0, -1, 1]])

b = np.array([1, 4, 9]).reshape((3, 1))
b = np.array([1, 4, 9])[np.newaxis].T


np.dot(a, b)
