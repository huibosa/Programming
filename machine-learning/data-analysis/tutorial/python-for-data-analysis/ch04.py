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

# + [markdown] deletable=true editable=true
# # NumPy Basics: Arrays and Vectorized Computation

# + deletable=true editable=true
import numpy as np

np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
np.set_printoptions(precision=4, suppress=True)

# + deletable=true editable=true
import numpy as np

my_arr = np.arange(1000000)
my_list = list(range(1000000))

# + deletable=true editable=true
# %time for _ in range(10): my_arr2 = my_arr * 2
# %time for _ in range(10): my_list2 = [x * 2 for x in my_list]

# + [markdown] deletable=true editable=true
# ## The NumPy ndarray: A Multidimensional Array Object

# + deletable=true editable=true
import numpy as np

# Generate some random data
data = np.random.randn(2, 3)
data

# + deletable=true editable=true
data * 10
data + data

# + deletable=true editable=true
data.shape
data.dtype

# + [markdown] deletable=true editable=true
# ### Creating ndarrays

# + deletable=true editable=true
data1 = [6, 7.5, 8, 0, 1]
arr1 = np.array(data1)
arr1

# + deletable=true editable=true
data2 = [[1, 2, 3, 4], [5, 6, 7, 8]]
arr2 = np.array(data2)
arr2

# + deletable=true editable=true
arr2.ndim
arr2.shape

# + deletable=true editable=true
arr1.dtype
arr2.dtype

# + deletable=true editable=true
np.zeros(10)
np.zeros((3, 6))
np.empty((2, 3, 2))

# + deletable=true editable=true
np.arange(15)

# + [markdown] deletable=true editable=true
# ### Data Types for ndarrays

# + deletable=true editable=true
arr1 = np.array([1, 2, 3], dtype=np.float64)
arr2 = np.array([1, 2, 3], dtype=np.int32)
arr1.dtype
arr2.dtype

# + deletable=true editable=true
arr = np.array([1, 2, 3, 4, 5])
arr.dtype
float_arr = arr.astype(np.float64)
float_arr.dtype

# + deletable=true editable=true
arr = np.array([3.7, -1.2, -2.6, 0.5, 12.9, 10.1])
arr
arr.astype(np.int32)

# + deletable=true editable=true
numeric_strings = np.array(["1.25", "-9.6", "42"], dtype=np.string_)
numeric_strings.astype(float)

# + deletable=true editable=true
int_array = np.arange(10)
calibers = np.array([0.22, 0.270, 0.357, 0.380, 0.44, 0.50], dtype=np.float64)
int_array.astype(calibers.dtype)

# + deletable=true editable=true
empty_uint32 = np.empty(8, dtype="u4")
empty_uint32

# + [markdown] deletable=true editable=true
# ### Arithmetic with NumPy Arrays

# + deletable=true editable=true
arr = np.array([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
arr
arr * arr
arr - arr

# + deletable=true editable=true
1 / arr
arr**0.5

# + deletable=true editable=true
arr2 = np.array([[0.0, 4.0, 1.0], [7.0, 2.0, 12.0]])
arr2
arr2 > arr

# + [markdown] deletable=true editable=true
# ### Basic Indexing and Slicing

# + deletable=true editable=true
arr = np.arange(10)
arr
arr[5]
arr[5:8]
arr[5:8] = 12
arr

# + deletable=true editable=true
arr_slice = arr[5:8]
arr_slice

# + deletable=true editable=true
arr_slice[1] = 12345
arr

# + deletable=true editable=true
arr_slice[:] = 64
arr

# + deletable=true editable=true
arr2d = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
arr2d[2]

# + deletable=true editable=true
arr2d[0][2]
arr2d[0, 2]

# + deletable=true editable=true
arr3d = np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]])
arr3d

# + deletable=true editable=true
arr3d[0]

# + deletable=true editable=true
old_values = arr3d[0].copy()
arr3d[0] = 42
arr3d
arr3d[0] = old_values
arr3d

# + deletable=true editable=true
arr3d[1, 0]

# + deletable=true editable=true
x = arr3d[1]
x
x[0]

# + [markdown] deletable=true editable=true
# #### Indexing with slices

# + deletable=true editable=true
arr
arr[1:6]

# + deletable=true editable=true
arr2d
arr2d[:2]

# + deletable=true editable=true
arr2d[:2, 1:]

# + deletable=true editable=true
arr2d[1, :2]

# + deletable=true editable=true
arr2d[:2, 2]

# + deletable=true editable=true
arr2d[:, :1]

# + deletable=true editable=true
arr2d[:2, 1:] = 0
arr2d

# + [markdown] deletable=true editable=true
# ### Boolean Indexing

# + deletable=true editable=true
names = np.array(["Bob", "Joe", "Will", "Bob", "Will", "Joe", "Joe"])
data = np.random.randn(7, 4)
names
data

# + deletable=true editable=true
names == "Bob"

# + deletable=true editable=true
data[names == "Bob"]

# + deletable=true editable=true
data[names == "Bob", 2:]
data[names == "Bob", 3]

# + deletable=true editable=true
names != "Bob"
data[~(names == "Bob")]

# + deletable=true editable=true
cond = names == "Bob"
data[~cond]

# + deletable=true editable=true
mask = (names == "Bob") | (names == "Will")
mask
data[mask]

# + deletable=true editable=true
data[data < 0] = 0
data

# + deletable=true editable=true
data[names != "Joe"] = 7
data

# + [markdown] deletable=true editable=true
# ### Fancy Indexing

# + deletable=true editable=true
arr = np.empty((8, 4))
for i in range(8):
    arr[i] = i
arr

# + deletable=true editable=true
arr[[4, 3, 0, 6]]

# + deletable=true editable=true
arr[[-3, -5, -7]]

# + deletable=true editable=true
arr = np.arange(32).reshape((8, 4))
arr
arr[[1, 5, 7, 2], [0, 3, 1, 2]]

# + deletable=true editable=true
arr[[1, 5, 7, 2]][:, [0, 3, 1, 2]]

# + [markdown] deletable=true editable=true
# ### Transposing Arrays and Swapping Axes

# + deletable=true editable=true
arr = np.arange(15).reshape((3, 5))
arr
arr.T

# + deletable=true editable=true
arr = np.random.randn(6, 3)
arr
np.dot(arr.T, arr)

# + deletable=true editable=true
arr = np.arange(16).reshape((2, 2, 4))
arr
arr.transpose((1, 0, 2))

# + deletable=true editable=true
arr
arr.swapaxes(1, 2)

# + [markdown] deletable=true editable=true
# ## Universal Functions: Fast Element-Wise Array Functions

# + deletable=true editable=true
arr = np.arange(10)
arr
np.sqrt(arr)
np.exp(arr)

# + deletable=true editable=true
x = np.random.randn(8)
y = np.random.randn(8)
x
y
np.maximum(x, y)

# + deletable=true editable=true
arr = np.random.randn(7) * 5
arr
remainder, whole_part = np.modf(arr)
remainder
whole_part

# + deletable=true editable=true
arr
np.sqrt(arr)
np.sqrt(arr, arr)
arr

# + [markdown] deletable=true editable=true
# ## Array-Oriented Programming with Arrays

# + deletable=true editable=true
points = np.arange(-5, 5, 0.01)  # 1000 equally spaced points
xs, ys = np.meshgrid(points, points)
ys

# + deletable=true editable=true
z = np.sqrt(xs**2 + ys**2)
z

# + deletable=true editable=true
import matplotlib.pyplot as plt

plt.imshow(z, cmap=plt.cm.gray)
plt.colorbar()
plt.title("Image plot of $\sqrt{x^2 + y^2}$ for a grid of values")

# + deletable=true editable=true
plt.draw()

# + deletable=true editable=true
plt.close("all")

# + [markdown] deletable=true editable=true
# ### Expressing Conditional Logic as Array Operations

# + deletable=true editable=true
xarr = np.array([1.1, 1.2, 1.3, 1.4, 1.5])
yarr = np.array([2.1, 2.2, 2.3, 2.4, 2.5])
cond = np.array([True, False, True, True, False])

# + deletable=true editable=true
result = [(x if c else y) for x, y, c in zip(xarr, yarr, cond)]
result

# + deletable=true editable=true
result = np.where(cond, xarr, yarr)
result

# + deletable=true editable=true
arr = np.random.randn(4, 4)
arr
arr > 0
np.where(arr > 0, 2, -2)

# + deletable=true editable=true
np.where(arr > 0, 2, arr)  # set only positive values to 2

# + [markdown] deletable=true editable=true
# ### Mathematical and Statistical Methods

# + deletable=true editable=true
arr = np.random.randn(5, 4)
arr
arr.mean()
np.mean(arr)
arr.sum()

# + deletable=true editable=true
arr.mean(axis=1)
arr.sum(axis=0)

# + deletable=true editable=true
arr = np.array([0, 1, 2, 3, 4, 5, 6, 7])
arr.cumsum()

# + deletable=true editable=true
arr = np.array([[0, 1, 2], [3, 4, 5], [6, 7, 8]])
arr
arr.cumsum(axis=0)
arr.cumprod(axis=1)

# + [markdown] deletable=true editable=true
# ### Methods for Boolean Arrays

# + deletable=true editable=true
arr = np.random.randn(100)
(arr > 0).sum()  # Number of positive values

# + deletable=true editable=true
bools = np.array([False, False, True, False])
bools.any()
bools.all()

# + [markdown] deletable=true editable=true
# ### Sorting

# + deletable=true editable=true
arr = np.random.randn(6)
arr
arr.sort()
arr

# + deletable=true editable=true
arr = np.random.randn(5, 3)
arr
arr.sort(1)
arr

# + deletable=true editable=true
large_arr = np.random.randn(1000)
large_arr.sort()
large_arr[int(0.05 * len(large_arr))]  # 5% quantile

# + [markdown] deletable=true editable=true
# ### Unique and Other Set Logic

# + deletable=true editable=true
names = np.array(["Bob", "Joe", "Will", "Bob", "Will", "Joe", "Joe"])
np.unique(names)
ints = np.array([3, 3, 3, 2, 2, 1, 1, 4, 4])
np.unique(ints)

# + deletable=true editable=true
sorted(set(names))

# + deletable=true editable=true
values = np.array([6, 0, 0, 3, 2, 5, 6])
np.in1d(values, [2, 3, 6])

# + [markdown] deletable=true editable=true
# ## File Input and Output with Arrays

# + deletable=true editable=true
arr = np.arange(10)
np.save("some_array", arr)

# + deletable=true editable=true
np.load("some_array.npy")

# + deletable=true editable=true
np.savez("array_archive.npz", a=arr, b=arr)

# + deletable=true editable=true
arch = np.load("array_archive.npz")
arch["b"]

# + deletable=true editable=true
np.savez_compressed("arrays_compressed.npz", a=arr, b=arr)

# + deletable=true editable=true
# !rm some_array.npy
# !rm array_archive.npz
# !rm arrays_compressed.npz

# + [markdown] deletable=true editable=true
# ## Linear Algebra

# + deletable=true editable=true
x = np.array([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
y = np.array([[6.0, 23.0], [-1, 7], [8, 9]])
x
y
x.dot(y)

# + deletable=true editable=true
np.dot(x, y)

# + deletable=true editable=true
np.dot(x, np.ones(3))

# + deletable=true editable=true
x @ np.ones(3)

# + deletable=true editable=true
from numpy.linalg import inv, qr

X = np.random.randn(5, 5)
mat = X.T.dot(X)
inv(mat)
mat.dot(inv(mat))
q, r = qr(mat)
r

# + [markdown] deletable=true editable=true
# ## Pseudorandom Number Generation

# + deletable=true editable=true
samples = np.random.normal(size=(4, 4))
samples

# + deletable=true editable=true
from random import normalvariate

N = 1000000
# %timeit samples = [normalvariate(0, 1) for _ in range(N)]
# %timeit np.random.normal(size=N)

# + deletable=true editable=true
np.random.seed(1234)

# + deletable=true editable=true
rng = np.random.RandomState(1234)
rng.randn(10)

# + [markdown] deletable=true editable=true
# ## Example: Random Walks

# + deletable=true editable=true
import random

position = 0
walk = [position]
steps = 1000
for i in range(steps):
    step = 1 if random.randint(0, 1) else -1
    position += step
    walk.append(position)

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
plt.plot(walk[:100])

# + deletable=true editable=true
np.random.seed(12345)

# + deletable=true editable=true
nsteps = 1000
draws = np.random.randint(0, 2, size=nsteps)
steps = np.where(draws > 0, 1, -1)
walk = steps.cumsum()

# + deletable=true editable=true
walk.min()
walk.max()

# + deletable=true editable=true
(np.abs(walk) >= 10).argmax()

# + [markdown] deletable=true editable=true
# ### Simulating Many Random Walks at Once

# + deletable=true editable=true
nwalks = 5000
nsteps = 1000
draws = np.random.randint(0, 2, size=(nwalks, nsteps))  # 0 or 1
steps = np.where(draws > 0, 1, -1)
walks = steps.cumsum(1)
walks

# + deletable=true editable=true
walks.max()
walks.min()

# + deletable=true editable=true
hits30 = (np.abs(walks) >= 30).any(1)
hits30
hits30.sum()  # Number that hit 30 or -30

# + deletable=true editable=true
crossing_times = (np.abs(walks[hits30]) >= 30).argmax(1)
crossing_times.mean()

# + deletable=true editable=true
steps = np.random.normal(loc=0, scale=0.25, size=(nwalks, nsteps))

# + [markdown] deletable=true editable=true
# ## Conclusion
