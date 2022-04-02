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
# # Getting Started with pandas

# + deletable=true editable=true
import pandas as pd

# + deletable=true editable=true
from pandas import Series, DataFrame

# + deletable=true editable=true
import numpy as np

np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
PREVIOUS_MAX_ROWS = pd.options.display.max_rows
pd.options.display.max_rows = 20
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## Introduction to pandas Data Structures

# + [markdown] deletable=true editable=true
# ### Series

# + deletable=true editable=true
obj = pd.Series([4, 7, -5, 3])
obj

# + deletable=true editable=true
obj.values
obj.index  # like range(4)

# + deletable=true editable=true
obj2 = pd.Series([4, 7, -5, 3], index=["d", "b", "a", "c"])
obj2
obj2.index

# + deletable=true editable=true
obj2["a"]
obj2["d"] = 6
obj2[["c", "a", "d"]]

# + deletable=true editable=true
obj2[obj2 > 0]
obj2 * 2
np.exp(obj2)

# + deletable=true editable=true
"b" in obj2
"e" in obj2

# + deletable=true editable=true
sdata = {"Ohio": 35000, "Texas": 71000, "Oregon": 16000, "Utah": 5000}
obj3 = pd.Series(sdata)
obj3

# + deletable=true editable=true
states = ["California", "Ohio", "Oregon", "Texas"]
obj4 = pd.Series(sdata, index=states)
obj4

# + deletable=true editable=true
pd.isnull(obj4)
pd.notnull(obj4)

# + deletable=true editable=true
obj4.isnull()

# + deletable=true editable=true
obj3
obj4
obj3 + obj4

# + deletable=true editable=true
obj4.name = "population"
obj4.index.name = "state"
obj4

# + deletable=true editable=true
obj
obj.index = ["Bob", "Steve", "Jeff", "Ryan"]
obj

# + [markdown] deletable=true editable=true
# ### DataFrame

# + deletable=true editable=true
data = {
    "state": ["Ohio", "Ohio", "Ohio", "Nevada", "Nevada", "Nevada"],
    "year": [2000, 2001, 2002, 2001, 2002, 2003],
    "pop": [1.5, 1.7, 3.6, 2.4, 2.9, 3.2],
}
frame = pd.DataFrame(data)

# + deletable=true editable=true
frame

# + deletable=true editable=true
frame.head()

# + deletable=true editable=true
pd.DataFrame(data, columns=["year", "state", "pop"])

# + deletable=true editable=true
frame2 = pd.DataFrame(
    data,
    columns=["year", "state", "pop", "debt"],
    index=["one", "two", "three", "four", "five", "six"],
)
frame2
frame2.columns

# + deletable=true editable=true
frame2["state"]
frame2.year

# + deletable=true editable=true
frame2.loc["three"]

# + deletable=true editable=true
frame2["debt"] = 16.5
frame2
frame2["debt"] = np.arange(6.0)
frame2

# + deletable=true editable=true
val = pd.Series([-1.2, -1.5, -1.7], index=["two", "four", "five"])
frame2["debt"] = val
frame2

# + deletable=true editable=true
frame2["eastern"] = frame2.state == "Ohio"
frame2

# + deletable=true editable=true
del frame2["eastern"]
frame2.columns

# + deletable=true editable=true
pop = {"Nevada": {2001: 2.4, 2002: 2.9}, "Ohio": {2000: 1.5, 2001: 1.7, 2002: 3.6}}

# + deletable=true editable=true
frame3 = pd.DataFrame(pop)
frame3

# + deletable=true editable=true
frame3.T

# + deletable=true editable=true
pd.DataFrame(pop, index=[2001, 2002, 2003])

# + deletable=true editable=true
pdata = {"Ohio": frame3["Ohio"][:-1], "Nevada": frame3["Nevada"][:2]}
pd.DataFrame(pdata)

# + deletable=true editable=true
frame3.index.name = "year"
frame3.columns.name = "state"
frame3

# + deletable=true editable=true
frame3.values

# + deletable=true editable=true
frame2.values

# + [markdown] deletable=true editable=true
# ### Index Objects

# + deletable=true editable=true
obj = pd.Series(range(3), index=["a", "b", "c"])
index = obj.index
index
index[1:]

# + [markdown] deletable=true editable=true
# index[1] = 'd'  # TypeError

# + deletable=true editable=true
labels = pd.Index(np.arange(3))
labels
obj2 = pd.Series([1.5, -2.5, 0], index=labels)
obj2
obj2.index is labels

# + deletable=true editable=true
frame3
frame3.columns
"Ohio" in frame3.columns
2003 in frame3.index

# + deletable=true editable=true
dup_labels = pd.Index(["foo", "foo", "bar", "bar"])
dup_labels

# + [markdown] deletable=true editable=true
# ## Essential Functionality

# + [markdown] deletable=true editable=true
# ### Reindexing

# + deletable=true editable=true
obj = pd.Series([4.5, 7.2, -5.3, 3.6], index=["d", "b", "a", "c"])
obj

# + deletable=true editable=true
obj2 = obj.reindex(["a", "b", "c", "d", "e"])
obj2

# + deletable=true editable=true
obj3 = pd.Series(["blue", "purple", "yellow"], index=[0, 2, 4])
obj3
obj3.reindex(range(6), method="ffill")

# + deletable=true editable=true
frame = pd.DataFrame(
    np.arange(9).reshape((3, 3)),
    index=["a", "c", "d"],
    columns=["Ohio", "Texas", "California"],
)
frame
frame2 = frame.reindex(["a", "b", "c", "d"])
frame2

# + deletable=true editable=true
states = ["Texas", "Utah", "California"]
frame.reindex(columns=states)

# + deletable=true editable=true
frame.loc[["a", "b", "c", "d"], states]

# + [markdown] deletable=true editable=true
# ### Dropping Entries from an Axis

# + deletable=true editable=true
obj = pd.Series(np.arange(5.0), index=["a", "b", "c", "d", "e"])
obj
new_obj = obj.drop("c")
new_obj
obj.drop(["d", "c"])

# + deletable=true editable=true
data = pd.DataFrame(
    np.arange(16).reshape((4, 4)),
    index=["Ohio", "Colorado", "Utah", "New York"],
    columns=["one", "two", "three", "four"],
)
data

# + deletable=true editable=true
data.drop(["Colorado", "Ohio"])

# + deletable=true editable=true
data.drop("two", axis=1)
data.drop(["two", "four"], axis="columns")

# + deletable=true editable=true
obj.drop("c", inplace=True)
obj

# + [markdown] deletable=true editable=true
# ### Indexing, Selection, and Filtering

# + deletable=true editable=true
obj = pd.Series(np.arange(4.0), index=["a", "b", "c", "d"])
obj
obj["b"]
obj[1]
obj[2:4]
obj[["b", "a", "d"]]
obj[[1, 3]]
obj[obj < 2]

# + deletable=true editable=true
obj["b":"c"]

# + deletable=true editable=true
obj["b":"c"] = 5
obj

# + deletable=true editable=true
data = pd.DataFrame(
    np.arange(16).reshape((4, 4)),
    index=["Ohio", "Colorado", "Utah", "New York"],
    columns=["one", "two", "three", "four"],
)
data
data["two"]
data[["three", "one"]]

# + deletable=true editable=true
data[:2]
data[data["three"] > 5]

# + deletable=true editable=true
data < 5
data[data < 5] = 0
data

# + [markdown] deletable=true editable=true
# #### Selection with loc and iloc

# + deletable=true editable=true
data.loc["Colorado", ["two", "three"]]

# + deletable=true editable=true
data.iloc[2, [3, 0, 1]]
data.iloc[2]
data.iloc[[1, 2], [3, 0, 1]]

# + deletable=true editable=true
data.loc[:"Utah", "two"]
data.iloc[:, :3][data.three > 5]

# + [markdown] deletable=true editable=true
# ### Integer Indexes

# + [markdown] deletable=true editable=true
# ser = pd.Series(np.arange(3.))
# ser
# ser[-1]

# + deletable=true editable=true
ser = pd.Series(np.arange(3.0))

# + deletable=true editable=true
ser

# + deletable=true editable=true
ser2 = pd.Series(np.arange(3.0), index=["a", "b", "c"])
ser2[-1]

# + deletable=true editable=true
ser[:1]
ser.loc[:1]
ser.iloc[:1]

# + [markdown] deletable=true editable=true
# ### Arithmetic and Data Alignment

# + deletable=true editable=true
s1 = pd.Series([7.3, -2.5, 3.4, 1.5], index=["a", "c", "d", "e"])
s2 = pd.Series([-2.1, 3.6, -1.5, 4, 3.1], index=["a", "c", "e", "f", "g"])
s1
s2

# + deletable=true editable=true
s1 + s2

# + deletable=true editable=true
df1 = pd.DataFrame(
    np.arange(9.0).reshape((3, 3)),
    columns=list("bcd"),
    index=["Ohio", "Texas", "Colorado"],
)
df2 = pd.DataFrame(
    np.arange(12.0).reshape((4, 3)),
    columns=list("bde"),
    index=["Utah", "Ohio", "Texas", "Oregon"],
)
df1
df2

# + deletable=true editable=true
df1 + df2

# + deletable=true editable=true
df1 = pd.DataFrame({"A": [1, 2]})
df2 = pd.DataFrame({"B": [3, 4]})
df1
df2
df1 - df2

# + [markdown] deletable=true editable=true
# #### Arithmetic methods with fill values

# + deletable=true editable=true
df1 = pd.DataFrame(np.arange(12.0).reshape((3, 4)), columns=list("abcd"))
df2 = pd.DataFrame(np.arange(20.0).reshape((4, 5)), columns=list("abcde"))
df2.loc[1, "b"] = np.nan
df1
df2

# + deletable=true editable=true
df1 + df2

# + deletable=true editable=true
df1.add(df2, fill_value=0)

# + deletable=true editable=true
1 / df1
df1.rdiv(1)

# + deletable=true editable=true
df1.reindex(columns=df2.columns, fill_value=0)

# + [markdown] deletable=true editable=true
# #### Operations between DataFrame and Series

# + deletable=true editable=true
arr = np.arange(12.0).reshape((3, 4))
arr
arr[0]
arr - arr[0]

# + deletable=true editable=true
frame = pd.DataFrame(
    np.arange(12.0).reshape((4, 3)),
    columns=list("bde"),
    index=["Utah", "Ohio", "Texas", "Oregon"],
)
series = frame.iloc[0]
frame
series

# + deletable=true editable=true
frame - series

# + deletable=true editable=true
series2 = pd.Series(range(3), index=["b", "e", "f"])
frame + series2

# + deletable=true editable=true
series3 = frame["d"]
frame
series3
frame.sub(series3, axis="index")

# + [markdown] deletable=true editable=true
# ### Function Application and Mapping

# + deletable=true editable=true
frame = pd.DataFrame(
    np.random.randn(4, 3),
    columns=list("bde"),
    index=["Utah", "Ohio", "Texas", "Oregon"],
)
frame
np.abs(frame)

# + deletable=true editable=true
f = lambda x: x.max() - x.min()
frame.apply(f)

# + deletable=true editable=true
frame.apply(f, axis="columns")


# + deletable=true editable=true
def f(x):
    return pd.Series([x.min(), x.max()], index=["min", "max"])


frame.apply(f)

# + deletable=true editable=true
format = lambda x: "%.2f" % x
frame.applymap(format)

# + deletable=true editable=true
frame["e"].map(format)

# + [markdown] deletable=true editable=true
# ### Sorting and Ranking

# + deletable=true editable=true
obj = pd.Series(range(4), index=["d", "a", "b", "c"])
obj.sort_index()

# + deletable=true editable=true
frame = pd.DataFrame(
    np.arange(8).reshape((2, 4)), index=["three", "one"], columns=["d", "a", "b", "c"]
)
frame.sort_index()
frame.sort_index(axis=1)

# + deletable=true editable=true
frame.sort_index(axis=1, ascending=False)

# + deletable=true editable=true
obj = pd.Series([4, 7, -3, 2])
obj.sort_values()

# + deletable=true editable=true
obj = pd.Series([4, np.nan, 7, np.nan, -3, 2])
obj.sort_values()

# + deletable=true editable=true
frame = pd.DataFrame({"b": [4, 7, -3, 2], "a": [0, 1, 0, 1]})
frame
frame.sort_values(by="b")

# + deletable=true editable=true
frame.sort_values(by=["a", "b"])

# + deletable=true editable=true
obj = pd.Series([7, -5, 7, 4, 2, 0, 4])
obj.rank()

# + deletable=true editable=true
obj.rank(method="first")

# + deletable=true editable=true
# Assign tie values the maximum rank in the group
obj.rank(ascending=False, method="max")

# + deletable=true editable=true
frame = pd.DataFrame({"b": [4.3, 7, -3, 2], "a": [0, 1, 0, 1], "c": [-2, 5, 8, -2.5]})
frame
frame.rank(axis="columns")

# + [markdown] deletable=true editable=true
# ### Axis Indexes with Duplicate Labels

# + deletable=true editable=true
obj = pd.Series(range(5), index=["a", "a", "b", "b", "c"])
obj

# + deletable=true editable=true
obj.index.is_unique

# + deletable=true editable=true
obj["a"]
obj["c"]

# + deletable=true editable=true
df = pd.DataFrame(np.random.randn(4, 3), index=["a", "a", "b", "b"])
df
df.loc["b"]

# + [markdown] deletable=true editable=true
# ## Summarizing and Computing Descriptive Statistics

# + deletable=true editable=true
df = pd.DataFrame(
    [[1.4, np.nan], [7.1, -4.5], [np.nan, np.nan], [0.75, -1.3]],
    index=["a", "b", "c", "d"],
    columns=["one", "two"],
)
df

# + deletable=true editable=true
df.sum()

# + deletable=true editable=true
df.sum(axis="columns")

# + deletable=true editable=true
df.mean(axis="columns", skipna=False)

# + deletable=true editable=true
df.idxmax()

# + deletable=true editable=true
df.cumsum()

# + deletable=true editable=true
df.describe()

# + deletable=true editable=true
obj = pd.Series(["a", "a", "b", "c"] * 4)
obj.describe()

# + [markdown] deletable=true editable=true
# ### Correlation and Covariance

# + [markdown] deletable=true editable=true
# conda install pandas-datareader

# + deletable=true editable=true
price = pd.read_pickle("examples/yahoo_price.pkl")
volume = pd.read_pickle("examples/yahoo_volume.pkl")

# + [markdown] deletable=true editable=true
# import pandas_datareader.data as web
# all_data = {ticker: web.get_data_yahoo(ticker)
#             for ticker in ['AAPL', 'IBM', 'MSFT', 'GOOG']}
#
# price = pd.DataFrame({ticker: data['Adj Close']
#                      for ticker, data in all_data.items()})
# volume = pd.DataFrame({ticker: data['Volume']
#                       for ticker, data in all_data.items()})

# + deletable=true editable=true
returns = price.pct_change()
returns.tail()

# + deletable=true editable=true
returns["MSFT"].corr(returns["IBM"])
returns["MSFT"].cov(returns["IBM"])

# + deletable=true editable=true
returns.MSFT.corr(returns.IBM)

# + deletable=true editable=true
returns.corr()
returns.cov()

# + deletable=true editable=true
returns.corrwith(returns.IBM)

# + deletable=true editable=true
returns.corrwith(volume)

# + [markdown] deletable=true editable=true
# ### Unique Values, Value Counts, and Membership

# + deletable=true editable=true
obj = pd.Series(["c", "a", "d", "a", "a", "b", "b", "c", "c"])

# + deletable=true editable=true
uniques = obj.unique()
uniques

# + deletable=true editable=true
obj.value_counts()

# + deletable=true editable=true
pd.value_counts(obj.values, sort=False)

# + deletable=true editable=true
obj
mask = obj.isin(["b", "c"])
mask
obj[mask]

# + deletable=true editable=true
to_match = pd.Series(["c", "a", "b", "b", "c", "a"])
unique_vals = pd.Series(["c", "b", "a"])
pd.Index(unique_vals).get_indexer(to_match)

# + deletable=true editable=true
data = pd.DataFrame(
    {"Qu1": [1, 3, 4, 3, 4], "Qu2": [2, 3, 1, 2, 3], "Qu3": [1, 5, 2, 4, 4]}
)
data

# + deletable=true editable=true
result = data.apply(pd.value_counts).fillna(0)
result

# + [markdown] deletable=true editable=true
# ## Conclusion

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS
