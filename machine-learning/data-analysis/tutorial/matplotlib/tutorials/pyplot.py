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
#     display_name: Python 3
#     language: python
#     name: python3
# ---

# %matplotlib inline

import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()
ax.plot([1, 2, 3, 4])
ax.set_ylabel("some numbers")

fig, ax = plt.subplots()
ax.plot([1, 2, 3, 4], [1, 4, 9, 16])

# +
fig, ax = plt.subplots()

ax.plot([1, 2, 3, 4], [1, 4, 9, 16], "ro")
ax.axis([0, 6, 0, 20])

# +
# evenly sampled time at 200ms intervals
t = np.arange(0.0, 5.0, 0.2)

# red dashes, blue squares and green triangles
fig, ax = plt.subplots()
ax.plot(t, t, "r--", t, t**2, "bs", t, t**3, "g^")
# ax.plot(t, t, 'r--')
# ax.plot(t, t**2, 'bs')
# ax.plot(t, t**3, 'g^')

# +
data = {"a": np.arange(50), "c": np.random.randint(0, 50, 50), "d": np.random.randn(50)}
data["b"] = data["a"] + 10 * np.random.randn(50)
data["d"] = np.abs(data["d"]) * 100

fig, ax = plt.subplots()
ax.scatter("a", "b", c="c", s="d", data=data)
ax.set_xlabel("entry a")
ax.set_ylabel("entry b")

# +
names = ["group_a", "group_b", "group_c"]
values = [1, 10, 100]

fig = plt.figure(figsize=(9, 3))
ax1 = fig.add_subplot(1, 3, 1)
ax2 = fig.add_subplot(1, 3, 2)
ax3 = fig.add_subplot(1, 3, 3)

ax1.bar(names, values)
ax2.scatter(names, values)
ax3.plot(names, values)
fig.suptitle("Categorical Plotting")


# +
def f(t):
    return np.exp(-t) * np.cos(2 * np.pi * t)


t1 = np.arange(0.0, 5.0, 0.1)
t2 = np.arange(0.0, 5.0, 0.02)

fig = plt.figure(figsize=(9, 9))

ax1 = fig.add_subplot(211)
ax1.plot(t1, f(t1), "bo", t2, f(t2), "k")

ax2 = fig.add_subplot(212)
plt.plot(t2, np.cos(2 * np.pi * t2), "r--")

# +
mu, sigma = 100, 15
x = mu + sigma * np.random.randn(10000)

# the histogram of the data
n, bins, patches = plt.hist(x, 50, density=1, facecolor="g", alpha=0.75)


plt.xlabel("Smarts")
plt.ylabel("Probability")
plt.title("Histogram of IQ")
plt.text(60, 0.025, r"$\mu=100,\ \sigma=15$")
plt.axis([40, 160, 0, 0.03])
plt.grid(True)
plt.show()

# +
ax = plt.subplot()

t = np.arange(0.0, 5.0, 0.01)
s = np.cos(2 * np.pi * t)
ax.plot(t, s, lw=2)

ax.annotate(
    "local max",
    xy=(2, 1),
    xytext=(3, 1.5),
    arrowprops=dict(facecolor="black", shrink=0.05),
)

ax.set_ylim(-2, 2)
plt.show()

# +
# Fixing random state for reproducibility
np.random.seed(19680801)

# make up some data in the open interval (0, 1)
y = np.random.normal(loc=0.5, scale=0.4, size=1000)
y = y[(y > 0) & (y < 1)]
y.sort()
x = np.arange(len(y))

# plot with various axes scales
fig = plt.figure()
ax1 = fig.add_subplot(2, 2, 1)
ax2 = fig.add_subplot(2, 2, 2)
ax3 = fig.add_subplot(2, 2, 3)
ax4 = fig.add_subplot(2, 2, 4)

# linear
ax1.plot(x, y)
ax1.set_yscale("linear")
ax1.set_title("linear")
ax1.grid(True)

# log
ax2.plot(x, y)
ax2.set_yscale("log")
ax2.set_title("log")
ax2.grid(True)

# symmetric log
ax3.plot(x, y - y.mean())
ax3.set_yscale("symlog", linthresh=0.01)
ax3.set_title("symlog")
ax3.grid(True)

# logit
ax4.plot(x, y)
ax4.set_yscale("logit")
ax4.set_title("logit")
ax4.grid(True)
# Adjust the subplot layout, because the logit one may take more space
# than usual, due to y-tick labels like "1 - 10^{-3}"
plt.subplots_adjust(
    top=0.92, bottom=0.08, left=0.10, right=0.95, hspace=0.25, wspace=0.35
)

plt.show()
