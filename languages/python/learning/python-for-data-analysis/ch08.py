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
# # Data Wrangling: Join, Combine,

# + deletable=true editable=true
import numpy as np
import pandas as pd

pd.options.display.max_rows = 20
np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## Hierarchical Indexing

# + deletable=true editable=true
data = pd.Series(
    np.random.randn(9),
    index=[["a", "a", "a", "b", "b", "c", "c", "d", "d"], [1, 2, 3, 1, 3, 1, 2, 2, 3]],
)
data

# + deletable=true editable=true
data.index

# + deletable=true editable=true
data["b"]
data["b":"c"]
data.loc[["b", "d"]]

# + deletable=true editable=true
data.loc[:, 2]

# + deletable=true editable=true
data.unstack()

# + deletable=true editable=true
data.unstack().stack()

# + deletable=true editable=true
frame = pd.DataFrame(
    np.arange(12).reshape((4, 3)),
    index=[["a", "a", "b", "b"], [1, 2, 1, 2]],
    columns=[["Ohio", "Ohio", "Colorado"], ["Green", "Red", "Green"]],
)
frame

# + deletable=true editable=true
frame.index.names = ["key1", "key2"]
frame.columns.names = ["state", "color"]
frame

# + deletable=true editable=true
frame["Ohio"]

# + [markdown] deletable=true editable=true
# MultiIndex.from_arrays([['Ohio', 'Ohio', 'Colorado'], ['Green', 'Red', 'Green']],
#                        names=['state', 'color'])

# + [markdown] deletable=true editable=true
# ### Reordering and Sorting Levels

# + deletable=true editable=true
frame.swaplevel("key1", "key2")

# + deletable=true editable=true
frame.sort_index(level=1)
frame.swaplevel(0, 1).sort_index(level=0)

# + [markdown] deletable=true editable=true
# ### Summary Statistics by Level

# + deletable=true editable=true
frame.sum(level="key2")
frame.sum(level="color", axis=1)

# + [markdown] deletable=true editable=true
# ### Indexing with a DataFrame's columns

# + deletable=true editable=true
frame = pd.DataFrame(
    {
        "a": range(7),
        "b": range(7, 0, -1),
        "c": ["one", "one", "one", "two", "two", "two", "two"],
        "d": [0, 1, 2, 0, 1, 2, 3],
    }
)
frame

# + deletable=true editable=true
frame2 = frame.set_index(["c", "d"])
frame2

# + deletable=true editable=true
frame.set_index(["c", "d"], drop=False)

# + deletable=true editable=true
frame2.reset_index()

# + [markdown] deletable=true editable=true
# ## Combining and Merging Datasets

# + [markdown] deletable=true editable=true
# ### Database-Style DataFrame Joins

# + deletable=true editable=true
df1 = pd.DataFrame({"key": ["b", "b", "a", "c", "a", "a", "b"], "data1": range(7)})
df2 = pd.DataFrame({"key": ["a", "b", "d"], "data2": range(3)})
df1
df2

# + deletable=true editable=true
pd.merge(df1, df2)

# + deletable=true editable=true
pd.merge(df1, df2, on="key")

# + deletable=true editable=true
df3 = pd.DataFrame({"lkey": ["b", "b", "a", "c", "a", "a", "b"], "data1": range(7)})
df4 = pd.DataFrame({"rkey": ["a", "b", "d"], "data2": range(3)})
pd.merge(df3, df4, left_on="lkey", right_on="rkey")

# + deletable=true editable=true
pd.merge(df1, df2, how="outer")

# + deletable=true editable=true
df1 = pd.DataFrame({"key": ["b", "b", "a", "c", "a", "b"], "data1": range(6)})
df2 = pd.DataFrame({"key": ["a", "b", "a", "b", "d"], "data2": range(5)})
df1
df2
pd.merge(df1, df2, on="key", how="left")

# + deletable=true editable=true
pd.merge(df1, df2, how="inner")

# + deletable=true editable=true
left = pd.DataFrame(
    {"key1": ["foo", "foo", "bar"], "key2": ["one", "two", "one"], "lval": [1, 2, 3]}
)
right = pd.DataFrame(
    {
        "key1": ["foo", "foo", "bar", "bar"],
        "key2": ["one", "one", "one", "two"],
        "rval": [4, 5, 6, 7],
    }
)
pd.merge(left, right, on=["key1", "key2"], how="outer")

# + deletable=true editable=true
pd.merge(left, right, on="key1")
pd.merge(left, right, on="key1", suffixes=("_left", "_right"))

# + [markdown] deletable=true editable=true
# ### Merging on Index

# + deletable=true editable=true
left1 = pd.DataFrame({"key": ["a", "b", "a", "a", "b", "c"], "value": range(6)})
right1 = pd.DataFrame({"group_val": [3.5, 7]}, index=["a", "b"])
left1
right1
pd.merge(left1, right1, left_on="key", right_index=True)

# + deletable=true editable=true
pd.merge(left1, right1, left_on="key", right_index=True, how="outer")

# + deletable=true editable=true
lefth = pd.DataFrame(
    {
        "key1": ["Ohio", "Ohio", "Ohio", "Nevada", "Nevada"],
        "key2": [2000, 2001, 2002, 2001, 2002],
        "data": np.arange(5.0),
    }
)
righth = pd.DataFrame(
    np.arange(12).reshape((6, 2)),
    index=[
        ["Nevada", "Nevada", "Ohio", "Ohio", "Ohio", "Ohio"],
        [2001, 2000, 2000, 2000, 2001, 2002],
    ],
    columns=["event1", "event2"],
)
lefth
righth

# + deletable=true editable=true
pd.merge(lefth, righth, left_on=["key1", "key2"], right_index=True)
pd.merge(lefth, righth, left_on=["key1", "key2"], right_index=True, how="outer")

# + deletable=true editable=true
left2 = pd.DataFrame(
    [[1.0, 2.0], [3.0, 4.0], [5.0, 6.0]],
    index=["a", "c", "e"],
    columns=["Ohio", "Nevada"],
)
right2 = pd.DataFrame(
    [[7.0, 8.0], [9.0, 10.0], [11.0, 12.0], [13, 14]],
    index=["b", "c", "d", "e"],
    columns=["Missouri", "Alabama"],
)
left2
right2
pd.merge(left2, right2, how="outer", left_index=True, right_index=True)

# + deletable=true editable=true
left2.join(right2, how="outer")

# + deletable=true editable=true
left1.join(right1, on="key")

# + deletable=true editable=true
another = pd.DataFrame(
    [[7.0, 8.0], [9.0, 10.0], [11.0, 12.0], [16.0, 17.0]],
    index=["a", "c", "e", "f"],
    columns=["New York", "Oregon"],
)
another
left2.join([right2, another])
left2.join([right2, another], how="outer")

# + [markdown] deletable=true editable=true
# ### Concatenating Along an Axis

# + deletable=true editable=true
arr = np.arange(12).reshape((3, 4))
arr
np.concatenate([arr, arr], axis=1)

# + deletable=true editable=true
s1 = pd.Series([0, 1], index=["a", "b"])
s2 = pd.Series([2, 3, 4], index=["c", "d", "e"])
s3 = pd.Series([5, 6], index=["f", "g"])

# + deletable=true editable=true
pd.concat([s1, s2, s3])

# + deletable=true editable=true
pd.concat([s1, s2, s3], axis=1)

# + deletable=true editable=true
s4 = pd.concat([s1, s3])
s4
pd.concat([s1, s4], axis=1)
pd.concat([s1, s4], axis=1, join="inner")

# + deletable=true editable=true
pd.concat([s1, s4], axis=1, join_axes=[["a", "c", "b", "e"]])

# + deletable=true editable=true
result = pd.concat([s1, s1, s3], keys=["one", "two", "three"])
result
result.unstack()

# + deletable=true editable=true
pd.concat([s1, s2, s3], axis=1, keys=["one", "two", "three"])

# + deletable=true editable=true
df1 = pd.DataFrame(
    np.arange(6).reshape(3, 2), index=["a", "b", "c"], columns=["one", "two"]
)
df2 = pd.DataFrame(
    5 + np.arange(4).reshape(2, 2), index=["a", "c"], columns=["three", "four"]
)
df1
df2
pd.concat([df1, df2], axis=1, keys=["level1", "level2"])

# + deletable=true editable=true
pd.concat({"level1": df1, "level2": df2}, axis=1)

# + deletable=true editable=true
pd.concat([df1, df2], axis=1, keys=["level1", "level2"], names=["upper", "lower"])

# + deletable=true editable=true
df1 = pd.DataFrame(np.random.randn(3, 4), columns=["a", "b", "c", "d"])
df2 = pd.DataFrame(np.random.randn(2, 3), columns=["b", "d", "a"])
df1
df2

# + deletable=true editable=true
pd.concat([df1, df2], ignore_index=True)

# + [markdown] deletable=true editable=true
# ### Combining Data with Overlap

# + deletable=true editable=true
a = pd.Series(
    [np.nan, 2.5, np.nan, 3.5, 4.5, np.nan], index=["f", "e", "d", "c", "b", "a"]
)
b = pd.Series(np.arange(len(a), dtype=np.float64), index=["f", "e", "d", "c", "b", "a"])
b[-1] = np.nan
a
b
np.where(pd.isnull(a), b, a)

# + deletable=true editable=true
b[:-2].combine_first(a[2:])

# + deletable=true editable=true
df1 = pd.DataFrame(
    {
        "a": [1.0, np.nan, 5.0, np.nan],
        "b": [np.nan, 2.0, np.nan, 6.0],
        "c": range(2, 18, 4),
    }
)
df2 = pd.DataFrame(
    {"a": [5.0, 4.0, np.nan, 3.0, 7.0], "b": [np.nan, 3.0, 4.0, 6.0, 8.0]}
)
df1
df2
df1.combine_first(df2)

# + [markdown] deletable=true editable=true
# ## Reshaping and Pivoting

# + [markdown] deletable=true editable=true
# ### Reshaping with Hierarchical Indexing

# + deletable=true editable=true
data = pd.DataFrame(
    np.arange(6).reshape((2, 3)),
    index=pd.Index(["Ohio", "Colorado"], name="state"),
    columns=pd.Index(["one", "two", "three"], name="number"),
)
data

# + deletable=true editable=true
result = data.stack()
result

# + deletable=true editable=true
result.unstack()

# + deletable=true editable=true
result.unstack(0)
result.unstack("state")

# + deletable=true editable=true
s1 = pd.Series([0, 1, 2, 3], index=["a", "b", "c", "d"])
s2 = pd.Series([4, 5, 6], index=["c", "d", "e"])
data2 = pd.concat([s1, s2], keys=["one", "two"])
data2
data2.unstack()

# + deletable=true editable=true
data2.unstack()
data2.unstack().stack()
data2.unstack().stack(dropna=False)

# + deletable=true editable=true
df = pd.DataFrame(
    {"left": result, "right": result + 5},
    columns=pd.Index(["left", "right"], name="side"),
)
df
df.unstack("state")

# + deletable=true editable=true
df.unstack("state").stack("side")

# + [markdown] deletable=true editable=true
# ### Pivoting “Long” to “Wide” Format

# + deletable=true editable=true
data = pd.read_csv("examples/macrodata.csv")
data.head()
periods = pd.PeriodIndex(year=data.year, quarter=data.quarter, name="date")
columns = pd.Index(["realgdp", "infl", "unemp"], name="item")
data = data.reindex(columns=columns)
data.index = periods.to_timestamp("D", "end")
ldata = data.stack().reset_index().rename(columns={0: "value"})

# + deletable=true editable=true
ldata[:10]

# + deletable=true editable=true
pivoted = ldata.pivot("date", "item", "value")
pivoted

# + deletable=true editable=true
ldata["value2"] = np.random.randn(len(ldata))
ldata[:10]

# + deletable=true editable=true
pivoted = ldata.pivot("date", "item")
pivoted[:5]
pivoted["value"][:5]

# + deletable=true editable=true
unstacked = ldata.set_index(["date", "item"]).unstack("item")
unstacked[:7]

# + [markdown] deletable=true editable=true
# ### Pivoting “Wide” to “Long” Format

# + deletable=true editable=true
df = pd.DataFrame(
    {"key": ["foo", "bar", "baz"], "A": [1, 2, 3], "B": [4, 5, 6], "C": [7, 8, 9]}
)
df

# + deletable=true editable=true
melted = pd.melt(df, ["key"])
melted

# + deletable=true editable=true
reshaped = melted.pivot("key", "variable", "value")
reshaped

# + deletable=true editable=true
reshaped.reset_index()

# + deletable=true editable=true
pd.melt(df, id_vars=["key"], value_vars=["A", "B"])

# + deletable=true editable=true
pd.melt(df, value_vars=["A", "B", "C"])
pd.melt(df, value_vars=["key", "A", "B"])

# + [markdown] deletable=true editable=true
# ## Conclusion
