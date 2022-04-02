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
# # Advanced NumPy

# + deletable=true editable=true
import numpy as np
import pandas as pd

np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
PREVIOUS_MAX_ROWS = pd.options.display.max_rows
pd.options.display.max_rows = 20
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## ndarray Object Internals

# + deletable=true editable=true
np.ones((10, 5)).shape

# + deletable=true editable=true
np.ones((3, 4, 5), dtype=np.float64).strides

# + [markdown] deletable=true editable=true
# ### NumPy dtype Hierarchy

# + deletable=true editable=true
ints = np.ones(10, dtype=np.uint16)
floats = np.ones(10, dtype=np.float32)
np.issubdtype(ints.dtype, np.integer)
np.issubdtype(floats.dtype, np.floating)

# + deletable=true editable=true
np.float64.mro()

# + deletable=true editable=true
np.issubdtype(ints.dtype, np.number)

# + [markdown] deletable=true editable=true
# ## Advanced Array Manipulation

# + [markdown] deletable=true editable=true
# ### Reshaping Arrays

# + deletable=true editable=true
arr = np.arange(8)
arr
arr.reshape((4, 2))

# + deletable=true editable=true
arr.reshape((4, 2)).reshape((2, 4))

# + deletable=true editable=true
arr = np.arange(15)
arr.reshape((5, -1))

# + deletable=true editable=true
other_arr = np.ones((3, 5))
other_arr.shape
arr.reshape(other_arr.shape)

# + deletable=true editable=true
arr = np.arange(15).reshape((5, 3))
arr
arr.ravel()

# + deletable=true editable=true
arr.flatten()

# + [markdown] deletable=true editable=true
# ### C Versus Fortran Order

# + deletable=true editable=true
arr = np.arange(12).reshape((3, 4))
arr
arr.ravel()
arr.ravel("F")

# + [markdown] deletable=true editable=true
# ### Concatenating and Splitting Arrays

# + deletable=true editable=true
arr1 = np.array([[1, 2, 3], [4, 5, 6]])
arr2 = np.array([[7, 8, 9], [10, 11, 12]])
np.concatenate([arr1, arr2], axis=0)
np.concatenate([arr1, arr2], axis=1)

# + deletable=true editable=true
np.vstack((arr1, arr2))
np.hstack((arr1, arr2))

# + deletable=true editable=true
arr = np.random.randn(5, 2)
arr
first, second, third = np.split(arr, [1, 3])
first
second
third

# + [markdown] deletable=true editable=true
# #### Stacking helpers: r_ and c_

# + deletable=true editable=true
arr = np.arange(6)
arr1 = arr.reshape((3, 2))
arr2 = np.random.randn(3, 2)
np.r_[arr1, arr2]
np.c_[np.r_[arr1, arr2], arr]

# + deletable=true editable=true
np.c_[1:6, -10:-5]

# + [markdown] deletable=true editable=true
# ### Repeating Elements: tile and repeat

# + deletable=true editable=true
arr = np.arange(3)
arr
arr.repeat(3)

# + deletable=true editable=true
arr.repeat([2, 3, 4])

# + deletable=true editable=true
arr = np.random.randn(2, 2)
arr
arr.repeat(2, axis=0)

# + deletable=true editable=true
arr.repeat([2, 3], axis=0)
arr.repeat([2, 3], axis=1)

# + deletable=true editable=true
arr
np.tile(arr, 2)

# + deletable=true editable=true
arr
np.tile(arr, (2, 1))
np.tile(arr, (3, 2))

# + [markdown] deletable=true editable=true
# ### Fancy Indexing Equivalents: take and put

# + deletable=true editable=true
arr = np.arange(10) * 100
inds = [7, 1, 2, 6]
arr[inds]

# + deletable=true editable=true
arr.take(inds)
arr.put(inds, 42)
arr
arr.put(inds, [40, 41, 42, 43])
arr

# + deletable=true editable=true
inds = [2, 0, 2, 1]
arr = np.random.randn(2, 4)
arr
arr.take(inds, axis=1)

# + [markdown] deletable=true editable=true
# ## Broadcasting

# + deletable=true editable=true
arr = np.arange(5)
arr
arr * 4

# + deletable=true editable=true
arr = np.random.randn(4, 3)
arr.mean(0)
demeaned = arr - arr.mean(0)
demeaned
demeaned.mean(0)

# + deletable=true editable=true
arr
row_means = arr.mean(1)
row_means.shape
row_means.reshape((4, 1))
demeaned = arr - row_means.reshape((4, 1))
demeaned.mean(1)

# + [markdown] deletable=true editable=true
# ### Broadcasting Over Other Axes

# + deletable=true editable=true
arr - arr.mean(1)

# + deletable=true editable=true
arr - arr.mean(1).reshape((4, 1))

# + deletable=true editable=true
arr = np.zeros((4, 4))
arr_3d = arr[:, np.newaxis, :]
arr_3d.shape
arr_1d = np.random.normal(size=3)
arr_1d[:, np.newaxis]
arr_1d[np.newaxis, :]

# + deletable=true editable=true
arr = np.random.randn(3, 4, 5)
depth_means = arr.mean(2)
depth_means
depth_means.shape
demeaned = arr - depth_means[:, :, np.newaxis]
demeaned.mean(2)

# + [markdown] deletable=true editable=true
# ```python
# def demean_axis(arr, axis=0):
#     means = arr.mean(axis)
#
#     # This generalizes things like [:, :, np.newaxis] to N dimensions
#     indexer = [slice(None)] * arr.ndim
#     indexer[axis] = np.newaxis
#     return arr - means[indexer]
# ```

# + [markdown] deletable=true editable=true
# ### Setting Array Values by Broadcasting

# + deletable=true editable=true
arr = np.zeros((4, 3))
arr[:] = 5
arr

# + deletable=true editable=true
col = np.array([1.28, -0.42, 0.44, 1.6])
arr[:] = col[:, np.newaxis]
arr
arr[:2] = [[-1.37], [0.509]]
arr

# + [markdown] deletable=true editable=true
# ## Advanced ufunc Usage

# + [markdown] deletable=true editable=true
# ### ufunc Instance Methods

# + deletable=true editable=true
arr = np.arange(10)
np.add.reduce(arr)
arr.sum()

# + deletable=true editable=true
np.random.seed(12346)  # for reproducibility
arr = np.random.randn(5, 5)
arr[::2].sort(1)  # sort a few rows
arr[:, :-1] < arr[:, 1:]
np.logical_and.reduce(arr[:, :-1] < arr[:, 1:], axis=1)

# + deletable=true editable=true
arr = np.arange(15).reshape((3, 5))
np.add.accumulate(arr, axis=1)

# + deletable=true editable=true
arr = np.arange(3).repeat([1, 2, 2])
arr
np.multiply.outer(arr, np.arange(5))

# + deletable=true editable=true
x, y = np.random.randn(3, 4), np.random.randn(5)
result = np.subtract.outer(x, y)
result.shape

# + deletable=true editable=true
arr = np.arange(10)
np.add.reduceat(arr, [0, 5, 8])

# + deletable=true editable=true
arr = np.multiply.outer(np.arange(4), np.arange(5))
arr
np.add.reduceat(arr, [0, 2, 4], axis=1)


# + [markdown] deletable=true editable=true
# ### Writing New ufuncs in Python

# + deletable=true editable=true
def add_elements(x, y):
    return x + y


add_them = np.frompyfunc(add_elements, 2, 1)
add_them(np.arange(8), np.arange(8))

# + deletable=true editable=true
add_them = np.vectorize(add_elements, otypes=[np.float64])
add_them(np.arange(8), np.arange(8))

# + deletable=true editable=true
arr = np.random.randn(10000)
# %timeit add_them(arr, arr)
# %timeit np.add(arr, arr)

# + [markdown] deletable=true editable=true
# ## Structured and Record Arrays

# + deletable=true editable=true
dtype = [("x", np.float64), ("y", np.int32)]
sarr = np.array([(1.5, 6), (np.pi, -2)], dtype=dtype)
sarr

# + deletable=true editable=true
sarr[0]
sarr[0]["y"]

# + deletable=true editable=true
sarr["x"]

# + [markdown] deletable=true editable=true
# ### Nested dtypes and Multidimensional Fields

# + deletable=true editable=true
dtype = [("x", np.int64, 3), ("y", np.int32)]
arr = np.zeros(4, dtype=dtype)
arr

# + deletable=true editable=true
arr[0]["x"]

# + deletable=true editable=true
arr["x"]

# + deletable=true editable=true
dtype = [("x", [("a", "f8"), ("b", "f4")]), ("y", np.int32)]
data = np.array([((1, 2), 5), ((3, 4), 6)], dtype=dtype)
data["x"]
data["y"]
data["x"]["a"]

# + [markdown] deletable=true editable=true
# ### Why Use Structured Arrays?

# + [markdown] deletable=true editable=true
# ## More About Sorting

# + deletable=true editable=true
arr = np.random.randn(6)
arr.sort()
arr

# + deletable=true editable=true
arr = np.random.randn(3, 5)
arr
arr[:, 0].sort()  # Sort first column values in-place
arr

# + deletable=true editable=true
arr = np.random.randn(5)
arr
np.sort(arr)
arr

# + deletable=true editable=true
arr = np.random.randn(3, 5)
arr
arr.sort(axis=1)
arr

# + deletable=true editable=true
arr[:, ::-1]

# + [markdown] deletable=true editable=true
# ### Indirect Sorts: argsort and lexsort

# + deletable=true editable=true
values = np.array([5, 0, 1, 3, 2])
indexer = values.argsort()
indexer
values[indexer]

# + deletable=true editable=true
arr = np.random.randn(3, 5)
arr[0] = values
arr
arr[:, arr[0].argsort()]

# + deletable=true editable=true
first_name = np.array(["Bob", "Jane", "Steve", "Bill", "Barbara"])
last_name = np.array(["Jones", "Arnold", "Arnold", "Jones", "Walters"])
sorter = np.lexsort((first_name, last_name))
sorter
zip(last_name[sorter], first_name[sorter])

# + [markdown] deletable=true editable=true
# ### Alternative Sort Algorithms

# + deletable=true editable=true
values = np.array(["2:first", "2:second", "1:first", "1:second", "1:third"])
key = np.array([2, 2, 1, 1, 1])
indexer = key.argsort(kind="mergesort")
indexer
values.take(indexer)

# + [markdown] deletable=true editable=true
# ### Partially Sorting Arrays

# + deletable=true editable=true
np.random.seed(12345)
arr = np.random.randn(20)
arr
np.partition(arr, 3)

# + deletable=true editable=true
indices = np.argpartition(arr, 3)
indices
arr.take(indices)

# + [markdown] deletable=true editable=true
# ### numpy.searchsorted: Finding Elements in a Sorted Array

# + deletable=true editable=true
arr = np.array([0, 1, 7, 12, 15])
arr.searchsorted(9)

# + deletable=true editable=true
arr.searchsorted([0, 8, 11, 16])

# + deletable=true editable=true
arr = np.array([0, 0, 0, 1, 1, 1, 1])
arr.searchsorted([0, 1])
arr.searchsorted([0, 1], side="right")

# + deletable=true editable=true
data = np.floor(np.random.uniform(0, 10000, size=50))
bins = np.array([0, 100, 1000, 5000, 10000])
data

# + deletable=true editable=true
labels = bins.searchsorted(data)
labels

# + deletable=true editable=true
pd.Series(data).groupby(labels).mean()

# + [markdown] deletable=true editable=true
# ## Writing Fast NumPy Functions with Numba

# + deletable=true editable=true
import numpy as np


def mean_distance(x, y):
    nx = len(x)
    result = 0.0
    count = 0
    for i in range(nx):
        result += x[i] - y[i]
        count += 1
    return result / count


# + [markdown] deletable=true editable=true
# ```python
# In [209]: x = np.random.randn(10000000)
#
# In [210]: y = np.random.randn(10000000)
#
# In [211]: %timeit mean_distance(x, y)
# 1 loop, best of 3: 2 s per loop
#
# In [212]: %timeit (x - y).mean()
# 100 loops, best of 3: 14.7 ms per loop
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [213]: import numba as nb
#
# In [214]: numba_mean_distance = nb.jit(mean_distance)
# ```

# + [markdown] deletable=true editable=true
# ```python
# @nb.jit
# def mean_distance(x, y):
#     nx = len(x)
#     result = 0.0
#     count = 0
#     for i in range(nx):
#         result += x[i] - y[i]
#         count += 1
#     return result / count
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [215]: %timeit numba_mean_distance(x, y)
# 100 loops, best of 3: 10.3 ms per loop
# ```

# + [markdown] deletable=true editable=true
# ```python
# from numba import float64, njit
#
# @njit(float64(float64[:], float64[:]))
# def mean_distance(x, y):
#     return (x - y).mean()
# ```

# + [markdown] deletable=true editable=true
# ### Creating Custom numpy.ufunc Objects with Numba

# + [markdown] deletable=true editable=true
# ```python
# from numba import vectorize
#
# @vectorize
# def nb_add(x, y):
#     return x + y
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [13]: x = np.arange(10)
#
# In [14]: nb_add(x, x)
# Out[14]: array([  0.,   2.,   4.,   6.,   8.,  10.,  12.,  14.,  16.,  18.])
#
# In [15]: nb_add.accumulate(x, 0)
# Out[15]: array([  0.,   1.,   3.,   6.,  10.,  15.,  21.,  28.,  36.,  45.])
# ```

# + [markdown] deletable=true editable=true
# ## Advanced Array Input and Output

# + [markdown] deletable=true editable=true
# ### Memory-Mapped Files

# + deletable=true editable=true
mmap = np.memmap("mymmap", dtype="float64", mode="w+", shape=(10000, 10000))
mmap

# + deletable=true editable=true
section = mmap[:5]

# + deletable=true editable=true
section[:] = np.random.randn(5, 10000)
mmap.flush()
mmap
del mmap

# + deletable=true editable=true
mmap = np.memmap("mymmap", dtype="float64", shape=(10000, 10000))
mmap

# + deletable=true editable=true
# %xdel mmap
# !rm mymmap

# + [markdown] deletable=true editable=true
# ### HDF5 and Other Array Storage Options

# + [markdown] deletable=true editable=true
# ## Performance Tips

# + [markdown] deletable=true editable=true
# ### The Importance of Contiguous Memory

# + deletable=true editable=true
arr_c = np.ones((1000, 1000), order="C")
arr_f = np.ones((1000, 1000), order="F")
arr_c.flags
arr_f.flags
arr_f.flags.f_contiguous

# + deletable=true editable=true
# %timeit arr_c.sum(1)
# %timeit arr_f.sum(1)

# + deletable=true editable=true
arr_f.copy("C").flags

# + deletable=true editable=true
arr_c[:50].flags.contiguous
arr_c[:, :50].flags

# + deletable=true editable=true
# %xdel arr_c
# %xdel arr_f

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS
