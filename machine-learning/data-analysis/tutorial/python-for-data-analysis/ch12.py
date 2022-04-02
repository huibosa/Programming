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
# # Advanced pandas

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
# ## Categorical Data

# + [markdown] deletable=true editable=true
# ### Background and Motivation

# + deletable=true editable=true
import numpy as np
import pandas as pd

values = pd.Series(["apple", "orange", "apple", "apple"] * 2)
values
pd.unique(values)
pd.value_counts(values)

# + deletable=true editable=true
values = pd.Series([0, 1, 0, 0] * 2)
dim = pd.Series(["apple", "orange"])
values
dim

# + deletable=true editable=true
dim.take(values)

# + [markdown] deletable=true editable=true
# ### Categorical Type in pandas

# + deletable=true editable=true
fruits = ["apple", "orange", "apple", "apple"] * 2
N = len(fruits)
df = pd.DataFrame(
    {
        "fruit": fruits,
        "basket_id": np.arange(N),
        "count": np.random.randint(3, 15, size=N),
        "weight": np.random.uniform(0, 4, size=N),
    },
    columns=["basket_id", "fruit", "count", "weight"],
)
df

# + deletable=true editable=true
fruit_cat = df["fruit"].astype("category")
fruit_cat

# + deletable=true editable=true
c = fruit_cat.values
type(c)

# + deletable=true editable=true
c.categories
c.codes

# + deletable=true editable=true
df["fruit"] = df["fruit"].astype("category")
df.fruit

# + deletable=true editable=true
my_categories = pd.Categorical(["foo", "bar", "baz", "foo", "bar"])
my_categories

# + deletable=true editable=true
categories = ["foo", "bar", "baz"]
codes = [0, 1, 2, 0, 0, 1]
my_cats_2 = pd.Categorical.from_codes(codes, categories)
my_cats_2

# + deletable=true editable=true
ordered_cat = pd.Categorical.from_codes(codes, categories, ordered=True)
ordered_cat

# + deletable=true editable=true
my_cats_2.as_ordered()

# + [markdown] deletable=true editable=true
# ### Computations with Categoricals

# + deletable=true editable=true
np.random.seed(12345)
draws = np.random.randn(1000)
draws[:5]

# + deletable=true editable=true
bins = pd.qcut(draws, 4)
bins

# + deletable=true editable=true
bins = pd.qcut(draws, 4, labels=["Q1", "Q2", "Q3", "Q4"])
bins
bins.codes[:10]

# + deletable=true editable=true
bins = pd.Series(bins, name="quartile")
results = pd.Series(draws).groupby(bins).agg(["count", "min", "max"]).reset_index()
results

# + deletable=true editable=true
results["quartile"]

# + [markdown] deletable=true editable=true
# #### Better performance with categoricals

# + deletable=true editable=true
N = 10000000
draws = pd.Series(np.random.randn(N))
labels = pd.Series(["foo", "bar", "baz", "qux"] * (N // 4))

# + deletable=true editable=true
categories = labels.astype("category")

# + deletable=true editable=true
labels.memory_usage()
categories.memory_usage()

# + deletable=true editable=true
# %time _ = labels.astype('category')

# + [markdown] deletable=true editable=true
# ### Categorical Methods

# + deletable=true editable=true
s = pd.Series(["a", "b", "c", "d"] * 2)
cat_s = s.astype("category")
cat_s

# + deletable=true editable=true
cat_s.cat.codes
cat_s.cat.categories

# + deletable=true editable=true
actual_categories = ["a", "b", "c", "d", "e"]
cat_s2 = cat_s.cat.set_categories(actual_categories)
cat_s2

# + deletable=true editable=true
cat_s.value_counts()
cat_s2.value_counts()

# + deletable=true editable=true
cat_s3 = cat_s[cat_s.isin(["a", "b"])]
cat_s3
cat_s3.cat.remove_unused_categories()

# + [markdown] deletable=true editable=true
# #### Creating dummy variables for modeling

# + deletable=true editable=true
cat_s = pd.Series(["a", "b", "c", "d"] * 2, dtype="category")

# + deletable=true editable=true
pd.get_dummies(cat_s)

# + [markdown] deletable=true editable=true
# ## Advanced GroupBy Use

# + [markdown] deletable=true editable=true
# ### Group Transforms and "Unwrapped" GroupBys

# + deletable=true editable=true
df = pd.DataFrame({"key": ["a", "b", "c"] * 4, "value": np.arange(12.0)})
df

# + deletable=true editable=true
g = df.groupby("key").value
g.mean()

# + deletable=true editable=true
g.transform(lambda x: x.mean())

# + deletable=true editable=true
g.transform("mean")

# + deletable=true editable=true
g.transform(lambda x: x * 2)

# + deletable=true editable=true
g.transform(lambda x: x.rank(ascending=False))


# + deletable=true editable=true
def normalize(x):
    return (x - x.mean()) / x.std()


# + deletable=true editable=true
g.transform(normalize)
g.apply(normalize)

# + deletable=true editable=true
g.transform("mean")
normalized = (df["value"] - g.transform("mean")) / g.transform("std")
normalized

# + [markdown] deletable=true editable=true
# ### Grouped Time Resampling

# + deletable=true editable=true
N = 15
times = pd.date_range("2017-05-20 00:00", freq="1min", periods=N)
df = pd.DataFrame({"time": times, "value": np.arange(N)})
df

# + deletable=true editable=true
df.set_index("time").resample("5min").count()

# + deletable=true editable=true
df2 = pd.DataFrame(
    {
        "time": times.repeat(3),
        "key": np.tile(["a", "b", "c"], N),
        "value": np.arange(N * 3.0),
    }
)
df2[:7]

# + deletable=true editable=true
time_key = pd.TimeGrouper("5min")

# + deletable=true editable=true
resampled = df2.set_index("time").groupby(["key", time_key]).sum()
resampled
resampled.reset_index()

# + [markdown] deletable=true editable=true
# ## Techniques for Method Chaining

# + [markdown] deletable=true editable=true
# ```python
# df = load_data()
# df2 = df[df['col2'] < 0]
# df2['col1_demeaned'] = df2['col1'] - df2['col1'].mean()
# result = df2.groupby('key').col1_demeaned.std()
# ```

# + [markdown] deletable=true editable=true
# ```python
# # Usual non-functional way
# df2 = df.copy()
# df2['k'] = v
#
# # Functional assign way
# df2 = df.assign(k=v)
# ```

# + [markdown] deletable=true editable=true
# ```python
# result = (df2.assign(col1_demeaned=df2.col1 - df2.col2.mean())
#           .groupby('key')
#           .col1_demeaned.std())
# ```

# + [markdown] deletable=true editable=true
# ```python
# df = load_data()
# df2 = df[df['col2'] < 0]
# ```

# + [markdown] deletable=true editable=true
# ```python
# df = (load_data()
#       [lambda x: x['col2'] < 0])
# ```

# + [markdown] deletable=true editable=true
# ```python
# result = (load_data()
#           [lambda x: x.col2 < 0]
#           .assign(col1_demeaned=lambda x: x.col1 - x.col1.mean())
#           .groupby('key')
#           .col1_demeaned.std())
# ```

# + [markdown] deletable=true editable=true
# ### The pipe Method

# + [markdown] deletable=true editable=true
# ```python
# a = f(df, arg1=v1)
# b = g(a, v2, arg3=v3)
# c = h(b, arg4=v4)
# ```

# + [markdown] deletable=true editable=true
# ```python
# result = (df.pipe(f, arg1=v1)
#           .pipe(g, v2, arg3=v3)
#           .pipe(h, arg4=v4))
# ```

# + [markdown] deletable=true editable=true
# ```python
# g = df.groupby(['key1', 'key2'])
# df['col1'] = df['col1'] - g.transform('mean')
# ```

# + [markdown] deletable=true editable=true
# ```python
# def group_demean(df, by, cols):
#     result = df.copy()
#     g = df.groupby(by)
#     for c in cols:
#         result[c] = df[c] - g[c].transform('mean')
#     return result
# ```

# + [markdown] deletable=true editable=true
# ```python
# result = (df[df.col1 < 0]
#           .pipe(group_demean, ['key1', 'key2'], ['col1']))
# ```

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS

# + [markdown] deletable=true editable=true
# ## Conclusion
