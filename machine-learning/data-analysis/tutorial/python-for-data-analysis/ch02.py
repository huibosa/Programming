# -*- coding: utf-8 -*-
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
# # Python Language Basics, IPython, and Jupyter Notebooks

# + deletable=true editable=true
import numpy as np

np.random.seed(12345)
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## The Python Interpreter

# + [markdown] deletable=true editable=true
# ```python
# $ python
# Python 3.6.0 | packaged by conda-forge | (default, Jan 13 2017, 23:17:12)
# [GCC 4.8.2 20140120 (Red Hat 4.8.2-15)] on linux
# Type "help", "copyright", "credits" or "license" for more information.
# >>> a = 5
# >>> print(a)
# 5
# ```

# + [markdown] deletable=true editable=true
# ```python
# print('Hello world')
# ```

# + [markdown] deletable=true editable=true
# ```python
# $ python hello_world.py
# Hello world
# ```

# + [markdown] deletable=true editable=true
# ```shell
# $ ipython
# Python 3.6.0 | packaged by conda-forge | (default, Jan 13 2017, 23:17:12)
# Type "copyright", "credits" or "license" for more information.
#
# IPython 5.1.0 -- An enhanced Interactive Python.
# ?         -> Introduction and overview of IPython's features.
# # # %quickref -> Quick reference.
# help      -> Python's own help system.
# object?   -> Details about 'object', use 'object??' for extra details.
#
# In [1]: %run hello_world.py
# Hello world
#
# In [2]:
# ```

# + [markdown] deletable=true editable=true
# ## IPython Basics

# + [markdown] deletable=true editable=true
# ### Running the IPython Shell

# + [markdown] deletable=true editable=true
# $

# + deletable=true editable=true
import numpy as np

data = {i: np.random.randn() for i in range(7)}
data

# + [markdown] deletable=true editable=true
# >>> from numpy.random import randn
# >>> data = {i : randn() for i in range(7)}
# >>> print(data)
# {0: -1.5948255432744511, 1: 0.10569006472787983, 2: 1.972367135977295,
# 3: 0.15455217573074576, 4: -0.24058577449429575, 5: -1.2904897053651216,
# 6: 0.3308507317325902}

# + [markdown] deletable=true editable=true
# ### Running the Jupyter Notebook

# + [markdown] deletable=true editable=true
# ```shell
# $ jupyter notebook
# [I 15:20:52.739 NotebookApp] Serving notebooks from local directory:
# /home/wesm/code/pydata-book
# [I 15:20:52.739 NotebookApp] 0 active kernels
# [I 15:20:52.739 NotebookApp] The Jupyter Notebook is running at:
# http://localhost:8888/
# [I 15:20:52.740 NotebookApp] Use Control-C to stop this server and shut down
# all kernels (twice to skip confirmation).
# Created new window in existing browser session.
# ```

# + [markdown] deletable=true editable=true
# ### Tab Completion

# + [markdown] deletable=true editable=true
# ```
# In [1]: an_apple = 27
#
# In [2]: an_example = 42
#
# In [3]: an
# ```

# + [markdown] deletable=true editable=true
# ```
# In [3]: b = [1, 2, 3]
#
# In [4]: b.
# ```

# + [markdown] deletable=true editable=true
# ```
# In [1]: import datetime
#
# In [2]: datetime.
# ```

# + [markdown] deletable=true editable=true
# ```
# In [7]: datasets/movielens/
# ```

# + [markdown] deletable=true editable=true
# ### Introspection

# + [markdown] deletable=true editable=true
# ```
# In [8]: b = [1, 2, 3]
#
# In [9]: b?
# Type:       list
# String Form:[1, 2, 3]
# Length:     3
# Docstring:
# list() -> new empty list
# list(iterable) -> new list initialized from iterable's items
#
# In [10]: print?
# Docstring:
# print(value, ..., sep=' ', end='\n', file=sys.stdout, flush=False)
#
# Prints the values to a stream, or to sys.stdout by default.
# Optional keyword arguments:
# file:  a file-like object (stream); defaults to the current sys.stdout.
# sep:   string inserted between values, default a space.
# end:   string appended after the last value, default a newline.
# flush: whether to forcibly flush the stream.
# Type:      builtin_function_or_method
# ```

# + [markdown] deletable=true editable=true
# ```python
# def add_numbers(a, b):
#     """
#     Add two numbers together
#
#     Returns
#     -------
#     the_sum : type of arguments
#     """
#     return a + b
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [11]: add_numbers?
# Signature: add_numbers(a, b)
# Docstring:
# Add two numbers together
#
# Returns
# -------
# the_sum : type of arguments
# File:      <ipython-input-9-6a548a216e27>
# Type:      function
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [12]: add_numbers??
# Signature: add_numbers(a, b)
# Source:
# def add_numbers(a, b):
#     """
#     Add two numbers together
#
#     Returns
#     -------
#     the_sum : type of arguments
#     """
#     return a + b
# File:      <ipython-input-9-6a548a216e27>
# Type:      function
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [13]: np.*load*?
# np.__loader__
# np.load
# np.loads
# np.loadtxt
# np.pkgload
# ```

# + [markdown] deletable=true editable=true
# ### The %run Command

# + [markdown] deletable=true editable=true
# ```python
# def f(x, y, z):
#     return (x + y) / z
#
# a = 5
# b = 6
# c = 7.5
#
# result = f(a, b, c)
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [14]: %run ipython_script_test.py
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [15]: c
# Out [15]: 7.5
#
# In [16]: result
# Out[16]: 1.4666666666666666
# ```

# + [markdown] deletable=true editable=true
# ```python
# >>> %load ipython_script_test.py
#
#     def f(x, y, z):
#         return (x + y) / z
#
#     a = 5
#     b = 6
#     c = 7.5
#
#     result = f(a, b, c)
# ```

# + [markdown] deletable=true editable=true
# #### Interrupting running code

# + [markdown] deletable=true editable=true
# ### Executing Code from the Clipboard

# + [markdown] deletable=true editable=true
# ```python
# x = 5
# y = 7
# if x > 5:
#     x += 1
#
#     y = 8
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [17]: %paste
# x = 5
# y = 7
# if x > 5:
#     x += 1
#
#     y = 8
# ## -- End pasted text --
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [18]: %cpaste
# Pasting code; enter '--' alone on the line to stop or use Ctrl-D.
# :x = 5
# :y = 7
# :if x > 5:
# :    x += 1
# :
# :    y = 8
# :--
# ```

# + [markdown] deletable=true editable=true
# ### Terminal Keyboard Shortcuts

# + [markdown] deletable=true editable=true
# ### About Magic Commands

# + [markdown] deletable=true editable=true
# ```python
# In [20]: a = np.random.randn(100, 100)
#
# In [20]: %timeit np.dot(a, a)
# 10000 loops, best of 3: 20.9 µs per loop
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [21]: %debug?
# Docstring:
# ::
#
#   # %debug [--breakpoint FILE:LINE] [statement [statement ...]]
#
# Activate the interactive debugger.
#
# This magic command support two ways of activating debugger.
# One is to activate debugger before executing code.  This way, you
# can set a break point, to step through the code from the point.
# You can use this mode by giving statements to execute and optionally
# a breakpoint.
#
# The other one is to activate debugger in post-mortem mode.  You can
# activate this mode simply running %debug without any argument.
# If an exception has just occurred, this lets you inspect its stack
# frames interactively.  Note that this will always work only on the last
# traceback that occurred, so you must call this quickly after an
# exception that you wish to inspect has fired, because if another one
# occurs, it clobbers the previous one.
#
# If you want IPython to automatically do this on every exception, see
# the %pdb magic for more details.
#
# positional arguments:
#   statement             Code to run in debugger. You can omit this in cell
#                         magic mode.
#
# optional arguments:
#   --breakpoint <FILE:LINE>, -b <FILE:LINE>
#                         Set break point at LINE in FILE.
#
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [22]: %pwd
# Out[22]: '/home/wesm/code/pydata-book
#
# In [23]: foo = %pwd
#
# In [24]: foo
# Out[24]: '/home/wesm/code/pydata-book'
# ```

# + [markdown] deletable=true editable=true
# ### Matplotlib Integration

# + [markdown] deletable=true editable=true
# ```python
# In [26]: %matplotlib
# Using matplotlib backend: Qt4Agg
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [26]: %matplotlib inline
# ```

# + [markdown] deletable=true editable=true
# ## Python Language Basics

# + [markdown] deletable=true editable=true
# ### Language Semantics

# + [markdown] deletable=true editable=true
# #### Indentation, not braces

# + [markdown] deletable=true editable=true
# ```python
# for x in array:
#     if x < pivot:
#         less.append(x)
#     else:
#         greater.append(x)
# ```

# + [markdown] deletable=true editable=true
# ```python
# a = 5; b = 6; c = 7
# ```

# + [markdown] deletable=true editable=true
# #### Everything is an object

# + [markdown] deletable=true editable=true
# #### Comments

# + [markdown] deletable=true editable=true
# ```python
# results = []
# for line in file_handle:
#     # keep the empty lines for now
#     # if len(line) == 0:
#     #   continue
#     results.append(line.replace('foo', 'bar'))
# ```

# + [markdown] deletable=true editable=true
# ```python
# print("Reached this line")  # Simple status report
# ```

# + [markdown] deletable=true editable=true
# #### Function and object method calls

# + [markdown] deletable=true editable=true
# ```
# result = f(x, y, z)
# g()
# ```

# + [markdown] deletable=true editable=true
# ```
# obj.some_method(x, y, z)
# ```

# + [markdown] deletable=true editable=true
# ```python
# result = f(a, b, c, d=5, e='foo')
# ```

# + [markdown] deletable=true editable=true
# #### Variables and argument passing

# + deletable=true editable=true
a = [1, 2, 3]

# + deletable=true editable=true
b = a

# + deletable=true editable=true
a.append(4)
b

# + [markdown] deletable=true editable=true
# ```python
# def append_element(some_list, element):
#     some_list.append(element)
# ```

# + [markdown] deletable=true editable=true
# ```python
# In [27]: data = [1, 2, 3]
#
# In [28]: append_element(data, 4)
#
# In [29]: data
# Out[29]: [1, 2, 3, 4]
# ```

# + [markdown] deletable=true editable=true
# #### Dynamic references, strong types

# + deletable=true editable=true
a = 5
type(a)
a = "foo"
type(a)

# + deletable=true editable=true
"5" + 5

# + deletable=true editable=true
a = 4.5
b = 2
# String formatting, to be visited later
print("a is {0}, b is {1}".format(type(a), type(b)))
a / b

# + deletable=true editable=true
a = 5
isinstance(a, int)

# + deletable=true editable=true
a = 5
b = 4.5
isinstance(a, (int, float))
isinstance(b, (int, float))

# + [markdown] deletable=true editable=true
# #### Attributes and methods

# + [markdown] deletable=true editable=true
# ```python
# In [1]: a = 'foo'
#
# In [2]: a.<Press Tab>
# a.capitalize  a.format      a.isupper     a.rindex      a.strip
# a.center      a.index       a.join        a.rjust       a.swapcase
# a.count       a.isalnum     a.ljust       a.rpartition  a.title
# a.decode      a.isalpha     a.lower       a.rsplit      a.translate
# a.encode      a.isdigit     a.lstrip      a.rstrip      a.upper
# a.endswith    a.islower     a.partition   a.split       a.zfill
# a.expandtabs  a.isspace     a.replace     a.splitlines
# a.find        a.istitle     a.rfind       a.startswith
# ```

# + deletable=true editable=true
a = "foo"

# + deletable=true editable=true
getattr(a, "split")


# + [markdown] deletable=true editable=true
# #### Duck typing

# + deletable=true editable=true
def isiterable(obj):
    try:
        iter(obj)
        return True
    except TypeError:  # not iterable
        return False


# + deletable=true editable=true
isiterable("a string")
isiterable([1, 2, 3])
isiterable(5)

# + [markdown] deletable=true editable=true
# if not isinstance(x, list) and isiterable(x):
#     x = list(x)

# + [markdown] deletable=true editable=true
# #### Imports

# + [markdown] deletable=true editable=true
# ```python
# # some_module.py
# PI = 3.14159
#
# def f(x):
#     return x + 2
#
# def g(a, b):
#     return a + b
# ```

# + [markdown] deletable=true editable=true
# import some_module
# result = some_module.f(5)
# pi = some_module.PI

# + [markdown] deletable=true editable=true
# from some_module import f, g, PI
# result = g(5, PI)

# + [markdown] deletable=true editable=true
# import some_module as sm
# from some_module import PI as pi, g as gf
#
# r1 = sm.f(pi)
# r2 = gf(6, pi)

# + [markdown] deletable=true editable=true
# #### Binary operators and comparisons

# + deletable=true editable=true
5 - 7
12 + 21.5
5 <= 2

# + deletable=true editable=true
a = [1, 2, 3]
b = a
c = list(a)
a is b
a is not c

# + deletable=true editable=true
a == c

# + deletable=true editable=true
a = None
a is None

# + [markdown] deletable=true editable=true
# #### Mutable and immutable objects

# + deletable=true editable=true
a_list = ["foo", 2, [4, 5]]
a_list[2] = (3, 4)
a_list

# + deletable=true editable=true
a_tuple = (3, 5, (4, 5))
a_tuple[1] = "four"

# + [markdown] deletable=true editable=true
# ### Scalar Types

# + [markdown] deletable=true editable=true
# #### Numeric types

# + deletable=true editable=true
ival = 17239871
ival**6

# + deletable=true editable=true
fval = 7.243
fval2 = 6.78e-5

# + deletable=true editable=true
3 / 2

# + deletable=true editable=true
3 // 2

# + [markdown] deletable=true editable=true
# #### Strings

# + [markdown] deletable=true editable=true
# a = 'one way of writing a string'
# b = "another way"

# + deletable=true editable=true
c = """
This is a longer string that
spans multiple lines
"""

# + deletable=true editable=true
c.count("\n")

# + deletable=true editable=true
a = "this is a string"
a[10] = "f"
b = a.replace("string", "longer string")
b

# + deletable=true editable=true
a

# + deletable=true editable=true
a = 5.6
s = str(a)
print(s)

# + deletable=true editable=true
s = "python"
list(s)
s[:3]

# + deletable=true editable=true
s = "12\\34"
print(s)

# + deletable=true editable=true
s = r"this\has\no\special\characters"
s

# + deletable=true editable=true
a = "this is the first half "
b = "and this is the second half"
a + b

# + deletable=true editable=true
template = "{0:.2f} {1:s} are worth US${2:d}"

# + deletable=true editable=true
template.format(4.5560, "Argentine Pesos", 1)

# + [markdown] deletable=true editable=true
# #### Bytes and Unicode

# + deletable=true editable=true
val = "español"
val

# + deletable=true editable=true
val_utf8 = val.encode("utf-8")
val_utf8
type(val_utf8)

# + deletable=true editable=true
val_utf8.decode("utf-8")

# + deletable=true editable=true
val.encode("latin1")
val.encode("utf-16")
val.encode("utf-16le")

# + deletable=true editable=true
bytes_val = b"this is bytes"
bytes_val
decoded = bytes_val.decode("utf8")
decoded  # this is str (Unicode) now

# + [markdown] deletable=true editable=true
# #### Booleans

# + deletable=true editable=true
True and True
False or True

# + [markdown] deletable=true editable=true
# #### Type casting

# + deletable=true editable=true
s = "3.14159"
fval = float(s)
type(fval)
int(fval)
bool(fval)
bool(0)

# + [markdown] deletable=true editable=true
# #### None

# + deletable=true editable=true
a = None
a is None
b = 5
b is not None

# + [markdown] deletable=true editable=true
# def add_and_maybe_multiply(a, b, c=None):
#     result = a + b
#
#     if c is not None:
#         result = result * c
#
#     return result

# + deletable=true editable=true
type(None)

# + [markdown] deletable=true editable=true
# #### Dates and times

# + deletable=true editable=true
from datetime import datetime, date, time

dt = datetime(2011, 10, 29, 20, 30, 21)
dt.day
dt.minute

# + deletable=true editable=true
dt.date()
dt.time()

# + deletable=true editable=true
dt.strftime("%m/%d/%Y %H:%M")

# + deletable=true editable=true
datetime.strptime("20091031", "%Y%m%d")

# + deletable=true editable=true
dt.replace(minute=0, second=0)

# + deletable=true editable=true
dt2 = datetime(2011, 11, 15, 22, 30)
delta = dt2 - dt
delta
type(delta)

# + deletable=true editable=true
dt
dt + delta

# + [markdown] deletable=true editable=true
# ### Control Flow

# + [markdown] deletable=true editable=true
# #### if, elif, and else

# + [markdown] deletable=true editable=true
# if x < 0:
#     print('It's negative')

# + [markdown] deletable=true editable=true
# if x < 0:
#     print('It's negative')
# elif x == 0:
#     print('Equal to zero')
# elif 0 < x < 5:
#     print('Positive but smaller than 5')
# else:
#     print('Positive and larger than or equal to 5')

# + deletable=true editable=true
a = 5
b = 7
c = 8
d = 4
if a < b or c > d:
    print("Made it")

# + deletable=true editable=true
4 > 3 > 2 > 1

# + [markdown] deletable=true editable=true
# #### for loops

# + [markdown] deletable=true editable=true
# for value in collection:
#     # do something with value

# + [markdown] deletable=true editable=true
# sequence = [1, 2, None, 4, None, 5]
# total = 0
# for value in sequence:
#     if value is None:
#         continue
#     total += value

# + [markdown] deletable=true editable=true
# sequence = [1, 2, 0, 4, 6, 5, 2, 1]
# total_until_5 = 0
# for value in sequence:
#     if value == 5:
#         break
#     total_until_5 += value

# + deletable=true editable=true
for i in range(4):
    for j in range(4):
        if j > i:
            break
        print((i, j))

# + [markdown] deletable=true editable=true
# for a, b, c in iterator:
#     # do something

# + [markdown] deletable=true editable=true
# #### while loops

# + [markdown] deletable=true editable=true
# x = 256
# total = 0
# while x > 0:
#     if total > 500:
#         break
#     total += x
#     x = x // 2

# + [markdown] deletable=true editable=true
# #### pass

# + [markdown] deletable=true editable=true
# if x < 0:
#     print('negative!')
# elif x == 0:
#     # TODO: put something smart here
#     pass
# else:
#     print('positive!')

# + [markdown] deletable=true editable=true
# #### range

# + deletable=true editable=true
range(10)
list(range(10))

# + deletable=true editable=true
list(range(0, 20, 2))
list(range(5, 0, -1))

# + [markdown] deletable=true editable=true
# seq = [1, 2, 3, 4]
# for i in range(len(seq)):
#     val = seq[i]

# + [markdown] deletable=true editable=true
# sum = 0
# for i in range(100000):
#     # % is the modulo operator
#     if i % 3 == 0 or i % 5 == 0:
#         sum += i

# + [markdown] deletable=true editable=true
# #### Ternary expressions

# + [markdown] deletable=true editable=true
# value =

# + [markdown] deletable=true editable=true
# if

# + deletable=true editable=true
x = 5
"Non-negative" if x >= 0 else "Negative"
