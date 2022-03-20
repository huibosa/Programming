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
m1 = np.random.randn(4, 5)  # 4x5 5x4
m2 = np.random.randn(4, 5)

print(np.matmul(m1, m2.T))
print(" ")
print(m1 @ m2.T)
print("")
print(np.matmul(m1, m2.T) - m1 @ m2.T)
# -

m1 @ np.zeros_like(m1.T)

m1 @ np.identity(m1.shape[1])

m1 @ m1.T
