#!/usr/bin/env python
# ---
# jupyter:
#   jupytext:
#     cell_metadata_filter: -all
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

s1 = 2
s2 = 0.5
s3 = -1
vec = np.array([1, 2])

# +
fig = plt.figure()
ax = fig.add_subplot()

ax.plot([0, vec[0]], [0, vec[1]], "bs--", label="v")
ax.plot([0, s1 * vec[0]], [0, s1 * vec[1]], "ro-", label="v*s1")
ax.plot([0, s2 * vec[0]], [0, s2 * vec[1]], "kp-", label="v*s2")
ax.plot([0, s3 * vec[0]], [0, s3 * vec[1]], "g*-", label="v*s3")

ax.axis("square")
ax.set_xlim([-4, 4])
ax.set_ylim([-4, 4])
ax.grid()
ax.legend()

plt.show()

# +
fig = plt.figure()
ax = fig.add_subplot()

v = np.array([4, 2])
w = np.array([-1, 2])
vec3 = v + w
vec4 = v - w

ax.plot([0, v[0]], [0, v[1]], "kp-", label="v")
ax.plot([0, w[0]], [0, w[1]], "bo-", label="w")
ax.plot([0, vec3[0]], [0, vec3[1]], "r.-", label="v + w")
ax.plot([0, vec4[0]], [0, vec4[1]], "r.-", label="v - w")

ax.axis("scaled")
ax.set_xlim([-2, 6])
ax.set_ylim([-2, 5])
ax.legend()
