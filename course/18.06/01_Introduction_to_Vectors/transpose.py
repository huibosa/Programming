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

# +
v1 = np.array([2, 3, -1], ndmin=2)

print(v1)
print(" ")
print(v1.T)

# +
M = np.round(10 * np.random.randn(3, 3))

print(M)
print(" ")
print(M.T)
