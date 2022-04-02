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
# # Built-in Data Structures, Functions,

# + [markdown] deletable=true editable=true
# ## Data Structures and Sequences

# + [markdown] deletable=true editable=true
# ### Tuple

# + deletable=true editable=true
tup = 4, 5, 6
tup

# + deletable=true editable=true
nested_tup = (4, 5, 6), (7, 8)
nested_tup

# + deletable=true editable=true
tuple([4, 0, 2])
tup = tuple("string")
tup

# + deletable=true editable=true
tup[0]

# + deletable=true editable=true
tup = tuple(["foo", [1, 2], True])
tup[2] = False

# + deletable=true editable=true
tup[1].append(3)
tup

# + deletable=true editable=true
(4, None, "foo") + (6, 0) + ("bar",)

# + deletable=true editable=true
("foo", "bar") * 4

# + [markdown] deletable=true editable=true
# #### Unpacking tuples

# + deletable=true editable=true
tup = (4, 5, 6)
a, b, c = tup
b

# + deletable=true editable=true
tup = 4, 5, (6, 7)
a, b, (c, d) = tup
d

# + [markdown] deletable=true editable=true
# tmp = a
# a = b
# b = tmp

# + deletable=true editable=true
a, b = 1, 2
a
b
b, a = a, b
a
b

# + deletable=true editable=true
seq = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
for a, b, c in seq:
    print("a={0}, b={1}, c={2}".format(a, b, c))

# + deletable=true editable=true
values = 1, 2, 3, 4, 5
a, b, *rest = values
a, b
rest

# + deletable=true editable=true
a, b, *_ = values

# + [markdown] deletable=true editable=true
# #### Tuple methods

# + deletable=true editable=true
a = (1, 2, 2, 2, 3, 4, 2)
a.count(2)

# + [markdown] deletable=true editable=true
# ### List

# + deletable=true editable=true
a_list = [2, 3, 7, None]
tup = ("foo", "bar", "baz")
b_list = list(tup)
b_list
b_list[1] = "peekaboo"
b_list

# + deletable=true editable=true
gen = range(10)
gen
list(gen)

# + [markdown] deletable=true editable=true
# #### Adding and removing elements

# + deletable=true editable=true
b_list.append("dwarf")
b_list

# + deletable=true editable=true
b_list.insert(1, "red")
b_list

# + deletable=true editable=true
b_list.pop(2)
b_list

# + deletable=true editable=true
b_list.append("foo")
b_list
b_list.remove("foo")
b_list

# + deletable=true editable=true
"dwarf" in b_list

# + deletable=true editable=true
"dwarf" not in b_list

# + [markdown] deletable=true editable=true
# #### Concatenating and combining lists

# + deletable=true editable=true
[4, None, "foo"] + [7, 8, (2, 3)]

# + deletable=true editable=true
x = [4, None, "foo"]
x.extend([7, 8, (2, 3)])
x

# + [markdown] deletable=true editable=true
# everything = []
# for chunk in list_of_lists:
#     everything.extend(chunk)

# + [markdown] deletable=true editable=true
# everything = []
# for chunk in list_of_lists:
#     everything = everything + chunk

# + [markdown] deletable=true editable=true
# #### Sorting

# + deletable=true editable=true
a = [7, 2, 5, 1, 3]
a.sort()
a

# + deletable=true editable=true
b = ["saw", "small", "He", "foxes", "six"]
b.sort(key=len)
b

# + [markdown] deletable=true editable=true
# #### Binary search and maintaining a sorted list

# + deletable=true editable=true
import bisect

c = [1, 2, 2, 2, 3, 4, 7]
bisect.bisect(c, 2)
bisect.bisect(c, 5)
bisect.insort(c, 6)
c

# + [markdown] deletable=true editable=true
# #### Slicing

# + deletable=true editable=true
seq = [7, 2, 3, 7, 5, 6, 0, 1]
seq[1:5]

# + deletable=true editable=true
seq[3:4] = [6, 3]
seq

# + deletable=true editable=true
seq[:5]
seq[3:]

# + deletable=true editable=true
seq[-4:]
seq[-6:-2]

# + deletable=true editable=true
seq[::2]

# + deletable=true editable=true
seq[::-1]

# + [markdown] deletable=true editable=true
# ### Built-in Sequence Functions

# + [markdown] deletable=true editable=true
# #### enumerate

# + [markdown] deletable=true editable=true
# i = 0
# for value in collection:
#    # do something with value
#    i += 1

# + [markdown] deletable=true editable=true
# for i, value in enumerate(collection):
#    # do something with value

# + deletable=true editable=true
some_list = ["foo", "bar", "baz"]
mapping = {}
for i, v in enumerate(some_list):
    mapping[v] = i
mapping

# + [markdown] deletable=true editable=true
# #### sorted

# + deletable=true editable=true
sorted([7, 1, 2, 6, 0, 3, 2])
sorted("horse race")

# + [markdown] deletable=true editable=true
# #### zip

# + deletable=true editable=true
seq1 = ["foo", "bar", "baz"]
seq2 = ["one", "two", "three"]
zipped = zip(seq1, seq2)
list(zipped)

# + deletable=true editable=true
seq3 = [False, True]
list(zip(seq1, seq2, seq3))

# + deletable=true editable=true
for i, (a, b) in enumerate(zip(seq1, seq2)):
    print("{0}: {1}, {2}".format(i, a, b))

# + deletable=true editable=true
pitchers = [("Nolan", "Ryan"), ("Roger", "Clemens"), ("Curt", "Schilling")]
first_names, last_names = zip(*pitchers)
first_names
last_names

# + [markdown] deletable=true editable=true
# #### reversed

# + deletable=true editable=true
list(reversed(range(10)))

# + [markdown] deletable=true editable=true
# ### dict

# + deletable=true editable=true
empty_dict = {}
d1 = {"a": "some value", "b": [1, 2, 3, 4]}
d1

# + deletable=true editable=true
d1[7] = "an integer"
d1
d1["b"]

# + deletable=true editable=true
"b" in d1

# + deletable=true editable=true
d1[5] = "some value"
d1
d1["dummy"] = "another value"
d1
del d1[5]
d1
ret = d1.pop("dummy")
ret
d1

# + deletable=true editable=true
list(d1.keys())
list(d1.values())

# + deletable=true editable=true
d1.update({"b": "foo", "c": 12})
d1

# + [markdown] deletable=true editable=true
# #### Creating dicts from sequences

# + [markdown] deletable=true editable=true
# mapping = {}
# for key, value in zip(key_list, value_list):
#     mapping[key] = value

# + deletable=true editable=true
mapping = dict(zip(range(5), reversed(range(5))))
mapping

# + [markdown] deletable=true editable=true
# #### Default values

# + [markdown] deletable=true editable=true
# if key in some_dict:
#     value = some_dict[key]
# else:
#     value = default_value

# + [markdown] deletable=true editable=true
# value = some_dict.get(key, default_value)

# + deletable=true editable=true
words = ["apple", "bat", "bar", "atom", "book"]
by_letter = {}
for word in words:
    letter = word[0]
    if letter not in by_letter:
        by_letter[letter] = [word]
    else:
        by_letter[letter].append(word)
by_letter

# + [markdown] deletable=true editable=true
# for word in words:
#     letter = word[0]
#     by_letter.setdefault(letter, []).append(word)

# + [markdown] deletable=true editable=true
# from collections import defaultdict
# by_letter = defaultdict(list)
# for word in words:
#     by_letter[word[0]].append(word)

# + [markdown] deletable=true editable=true
# #### Valid dict key types

# + deletable=true editable=true
hash("string")
hash((1, 2, (2, 3)))
hash((1, 2, [2, 3]))  # fails because lists are mutable

# + deletable=true editable=true
d = {}
d[tuple([1, 2, 3])] = 5
d

# + [markdown] deletable=true editable=true
# ### set

# + deletable=true editable=true
set([2, 2, 2, 1, 3, 3])
{2, 2, 2, 1, 3, 3}

# + deletable=true editable=true
a = {1, 2, 3, 4, 5}
b = {3, 4, 5, 6, 7, 8}

# + deletable=true editable=true
a.union(b)
a | b

# + deletable=true editable=true
a.intersection(b)
a & b

# + deletable=true editable=true
c = a.copy()
c |= b
c
d = a.copy()
d &= b
d

# + deletable=true editable=true
my_data = [1, 2, 3, 4]
my_set = {tuple(my_data)}
my_set

# + deletable=true editable=true
a_set = {1, 2, 3, 4, 5}
{1, 2, 3}.issubset(a_set)
a_set.issuperset({1, 2, 3})

# + deletable=true editable=true
{1, 2, 3} == {3, 2, 1}

# + [markdown] deletable=true editable=true
# ### List, Set, and Dict Comprehensions

# + [markdown] deletable=true editable=true
# [

# + [markdown] deletable=true editable=true
# result = []
# for val in collection:
#     if

# + deletable=true editable=true
strings = ["a", "as", "bat", "car", "dove", "python"]
[x.upper() for x in strings if len(x) > 2]

# + [markdown] deletable=true editable=true
# dict_comp = {

# + [markdown] deletable=true editable=true
# set_comp = {

# + deletable=true editable=true
unique_lengths = {len(x) for x in strings}
unique_lengths

# + deletable=true editable=true
set(map(len, strings))

# + deletable=true editable=true
loc_mapping = {val: index for index, val in enumerate(strings)}
loc_mapping

# + [markdown] deletable=true editable=true
# #### Nested list comprehensions

# + deletable=true editable=true
all_data = [
    ["John", "Emily", "Michael", "Mary", "Steven"],
    ["Maria", "Juan", "Javier", "Natalia", "Pilar"],
]

# + [markdown] deletable=true editable=true
# names_of_interest = []
# for names in all_data:
#     enough_es = [name for name in names if name.count('e') >= 2]
#     names_of_interest.extend(enough_es)

# + deletable=true editable=true
result = [name for names in all_data for name in names if name.count("e") >= 2]
result

# + deletable=true editable=true
some_tuples = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
flattened = [x for tup in some_tuples for x in tup]
flattened

# + [markdown] deletable=true editable=true
# flattened = []
#
# for tup in some_tuples:
#     for x in tup:
#         flattened.append(x)

# + deletable=true editable=true
[[x for x in tup] for tup in some_tuples]

# + [markdown] deletable=true editable=true
# ## Functions

# + [markdown] deletable=true editable=true
# def my_function(x, y, z=1.5):
#     if z > 1:
#         return z * (x + y)
#     else:
#         return z / (x + y)

# + [markdown] deletable=true editable=true
# my_function(5, 6, z=0.7)
# my_function(3.14, 7, 3.5)
# my_function(10, 20)

# + [markdown] deletable=true editable=true
# ### Namespaces, Scope, and Local Functions

# + [markdown] deletable=true editable=true
# def func():
#     a = []
#     for i in range(5):
#         a.append(i)

# + [markdown] deletable=true editable=true
# a = []
# def func():
#     for i in range(5):
#         a.append(i)

# + deletable=true editable=true
a = None


def bind_a_variable():
    global a
    a = []


bind_a_variable()
print(a)

# + [markdown] deletable=true editable=true
# ### Returning Multiple Values

# + [markdown] deletable=true editable=true
# def f():
#     a = 5
#     b = 6
#     c = 7
#     return a, b, c
#
# a, b, c = f()

# + [markdown] deletable=true editable=true
# return_value = f()

# + [markdown] deletable=true editable=true
# def f():
#     a = 5
#     b = 6
#     c = 7
#     return {'a' : a, 'b' : b, 'c' : c}

# + [markdown] deletable=true editable=true
# ### Functions Are Objects

# + deletable=true editable=true
states = [
    "   Alabama ",
    "Georgia!",
    "Georgia",
    "georgia",
    "FlOrIda",
    "south   carolina##",
    "West virginia?",
]

# + deletable=true editable=true
import re


def clean_strings(strings):
    result = []
    for value in strings:
        value = value.strip()
        value = re.sub("[!#?]", "", value)
        value = value.title()
        result.append(value)
    return result


# + deletable=true editable=true
clean_strings(states)


# + deletable=true editable=true
def remove_punctuation(value):
    return re.sub("[!#?]", "", value)


clean_ops = [str.strip, remove_punctuation, str.title]


def clean_strings(strings, ops):
    result = []
    for value in strings:
        for function in ops:
            value = function(value)
        result.append(value)
    return result


# + deletable=true editable=true
clean_strings(states, clean_ops)

# + deletable=true editable=true
for x in map(remove_punctuation, states):
    print(x)

# + [markdown] deletable=true editable=true
# ### Anonymous (Lambda) Functions

# + [markdown] deletable=true editable=true
# def short_function(x):
#     return x * 2
#
# equiv_anon = lambda x: x * 2

# + [markdown] deletable=true editable=true
# def apply_to_list(some_list, f):
#     return [f(x) for x in some_list]
#
# ints = [4, 0, 1, 5, 6]
# apply_to_list(ints, lambda x: x * 2)

# + deletable=true editable=true
strings = ["foo", "card", "bar", "aaaa", "abab"]

# + deletable=true editable=true
strings.sort(key=lambda x: len(set(x)))
strings

# + [markdown] deletable=true editable=true
# ### Currying: Partial Argument Application

# + [markdown] deletable=true editable=true
# def add_numbers(x, y):
#     return x + y

# + [markdown] deletable=true editable=true
# add_five = lambda y: add_numbers(5, y)

# + [markdown] deletable=true editable=true
# from functools import partial
# add_five = partial(add_numbers, 5)

# + [markdown] deletable=true editable=true
# ### Generators

# + deletable=true editable=true
some_dict = {"a": 1, "b": 2, "c": 3}
for key in some_dict:
    print(key)

# + deletable=true editable=true
dict_iterator = iter(some_dict)
dict_iterator

# + deletable=true editable=true
list(dict_iterator)


# + deletable=true editable=true
def squares(n=10):
    print("Generating squares from 1 to {0}".format(n**2))
    for i in range(1, n + 1):
        yield i**2


# + deletable=true editable=true
gen = squares()
gen

# + deletable=true editable=true
for x in gen:
    print(x, end=" ")

# + [markdown] deletable=true editable=true
# #### Generator expresssions

# + deletable=true editable=true
gen = (x**2 for x in range(100))
gen

# + [markdown] deletable=true editable=true
# def _make_gen():
#     for x in range(100):
#         yield x ** 2
# gen = _make_gen()

# + deletable=true editable=true
sum(x**2 for x in range(100))
dict((i, i**2) for i in range(5))

# + [markdown] deletable=true editable=true
# #### itertools module

# + deletable=true editable=true
import itertools

first_letter = lambda x: x[0]
names = ["Alan", "Adam", "Wes", "Will", "Albert", "Steven"]
for letter, names in itertools.groupby(names, first_letter):
    print(letter, list(names))  # names is a generator

# + [markdown] deletable=true editable=true
# ### Errors and Exception Handling

# + deletable=true editable=true
float("1.2345")
float("something")


# + deletable=true editable=true
def attempt_float(x):
    try:
        return float(x)
    except:
        return x


# + deletable=true editable=true
attempt_float("1.2345")
attempt_float("something")

# + deletable=true editable=true
float((1, 2))


# + deletable=true editable=true
def attempt_float(x):
    try:
        return float(x)
    except ValueError:
        return x


# + deletable=true editable=true
attempt_float((1, 2))


# + deletable=true editable=true
def attempt_float(x):
    try:
        return float(x)
    except (TypeError, ValueError):
        return x


# + [markdown] deletable=true editable=true
# f = open(path, 'w')
#
# try:
#     write_to_file(f)
# finally:
#     f.close()

# + [markdown] deletable=true editable=true
# f = open(path, 'w')
#
# try:
#     write_to_file(f)
# except:
#     print('Failed')
# else:
#     print('Succeeded')
# finally:
#     f.close()

# + [markdown] deletable=true editable=true
# #### Exceptions in IPython

# + [markdown] deletable=true editable=true
# In [10]: %run examples/ipython_bug.py
# ---------------------------------------------------------------------------
# AssertionError                            Traceback (most recent call last)
# /home/wesm/code/pydata-book/examples/ipython_bug.py in <module>()
#      13     throws_an_exception()
#      14
# ---> 15 calling_things()
#
# /home/wesm/code/pydata-book/examples/ipython_bug.py in calling_things()
#      11 def calling_things():
#      12     works_fine()
# ---> 13     throws_an_exception()
#      14
#      15 calling_things()
#
# /home/wesm/code/pydata-book/examples/ipython_bug.py in throws_an_exception()
#       7     a = 5
#       8     b = 6
# ----> 9     assert(a + b == 10)
#      10
#      11 def calling_things():
#
# AssertionError:

# + [markdown] deletable=true editable=true
# ## Files and the Operating System

# + deletable=true editable=true
# %pushd book-materials

# + deletable=true editable=true
path = "examples/segismundo.txt"
f = open(path)

# + [markdown] deletable=true editable=true
# for line in f:
#     pass

# + deletable=true editable=true
lines = [x.rstrip() for x in open(path)]
lines

# + deletable=true editable=true
f.close()

# + deletable=true editable=true
with open(path) as f:
    lines = [x.rstrip() for x in f]

# + deletable=true editable=true
f = open(path)
f.read(10)
f2 = open(path, "rb")  # Binary mode
f2.read(10)

# + deletable=true editable=true
f.tell()
f2.tell()

# + deletable=true editable=true
import sys

sys.getdefaultencoding()

# + deletable=true editable=true
f.seek(3)
f.read(1)

# + deletable=true editable=true
f.close()
f2.close()

# + deletable=true editable=true
with open("tmp.txt", "w") as handle:
    handle.writelines(x for x in open(path) if len(x) > 1)
with open("tmp.txt") as f:
    lines = f.readlines()
lines

# + deletable=true editable=true
import os

os.remove("tmp.txt")

# + [markdown] deletable=true editable=true
# ### Bytes and Unicode with Files

# + deletable=true editable=true
with open(path) as f:
    chars = f.read(10)
chars

# + deletable=true editable=true
with open(path, "rb") as f:
    data = f.read(10)
data

# + deletable=true editable=true
data.decode("utf8")
data[:4].decode("utf8")

# + deletable=true editable=true
sink_path = "sink.txt"
with open(path) as source:
    with open(sink_path, "xt", encoding="iso-8859-1") as sink:
        sink.write(source.read())
with open(sink_path, encoding="iso-8859-1") as f:
    print(f.read(10))

# + deletable=true editable=true
os.remove(sink_path)

# + deletable=true editable=true
f = open(path)
f.read(5)
f.seek(4)
f.read(1)
f.close()

# + deletable=true editable=true
# %popd

# + [markdown] deletable=true editable=true
# ## Conclusion
