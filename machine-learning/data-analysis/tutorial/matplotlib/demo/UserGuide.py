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
import numpy as np
import pandas as pd

fig, ax = plt.subplots()
ax.plot([1, 2, 3, 4], [1, 4, 2, 3])

plt.plot([1, 2, 3, 4], [1, 4, 2, 3])

fig = plt.figure()
fig, ax = plt.subplots()
fig, ax = plt.subplots(2, 2)

a = pd.DataFrame(np.random.rand(4, 5), columns=list("abcde"))
a_asarray = a.values
a_asarray

# +
x = np.linspace(0, 2, 100)

fig, ax = plt.subplots()
ax.plot(x, x, label="linear")
ax.plot(x, x**2, label="quadratic")
ax.plot(x, x**3, label="cubic")

ax.set_xlabel("x label")
ax.set_ylabel("y label")
ax.set_title("Simple Plot")
ax.legend()

# +
x = np.linspace(0, 2, 100)

plt.plot(x, x, label="linear")
plt.plot(x, x**2, label="quadratic")
plt.plot(x, x**3, label="cubic")

plt.xlabel("x label")
plt.ylabel("y label")
plt.title("")
plt.legend()


# -


def my_plotter(ax, data1, data2, param_dict):
    """
    A helper function to make a graph

    Parameters
    ----------
    ax : Axes
        The axes to draw to

    data1 : array
       The x data

    data2 : array
       The y data

    param_dict : dict
       Dictionary of kwargs to pass to ax.plot

    Returns
    -------
    out : list
        list of artists added
    """
    out = ax.plot(data1, data2, **param_dict)
    return out


data1, data2, data3, data4 = np.random.randn(4, 100)
fig, ax = plt.subplots(1, 1)
my_plotter(ax, data1, data2, {"marker": "x"})

data1, data2, data3, data4 = np.random.randn(4, 100)
plt.plot(data1, data2, marker="x")
