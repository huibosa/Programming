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
# # Data Aggregation and Group Operations

# + deletable=true editable=true
import numpy as np
import pandas as pd

PREVIOUS_MAX_ROWS = pd.options.display.max_rows
pd.options.display.max_rows = 20
np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## GroupBy Mechanics

# + deletable=true editable=true
df = pd.DataFrame(
    {
        "key1": ["a", "a", "b", "b", "a"],
        "key2": ["one", "two", "one", "two", "one"],
        "data1": np.random.randn(5),
        "data2": np.random.randn(5),
    }
)
df

# + deletable=true editable=true
grouped = df["data1"].groupby(df["key1"])
grouped

# + deletable=true editable=true
grouped.mean()

# + deletable=true editable=true
means = df["data1"].groupby([df["key1"], df["key2"]]).mean()
means

# + deletable=true editable=true
means.unstack()

# + deletable=true editable=true
states = np.array(["Ohio", "California", "California", "Ohio", "Ohio"])
years = np.array([2005, 2005, 2006, 2005, 2006])
df["data1"].groupby([states, years]).mean()

# + deletable=true editable=true
df.groupby("key1").mean()
df.groupby(["key1", "key2"]).mean()

# + deletable=true editable=true
df.groupby(["key1", "key2"]).size()

# + [markdown] deletable=true editable=true
# ### Iterating Over Groups

# + deletable=true editable=true
for name, group in df.groupby("key1"):
    print(name)
    print(group)

# + deletable=true editable=true
for (k1, k2), group in df.groupby(["key1", "key2"]):
    print((k1, k2))
    print(group)

# + deletable=true editable=true
pieces = dict(list(df.groupby("key1")))
pieces["b"]

# + deletable=true editable=true
df.dtypes
grouped = df.groupby(df.dtypes, axis=1)

# + deletable=true editable=true
for dtype, group in grouped:
    print(dtype)
    print(group)

# + [markdown] deletable=true editable=true
# ### Selecting a Column or Subset of Columns

# + [markdown] deletable=true editable=true
# df.groupby('key1')['data1']
# df.groupby('key1')[['data2']]

# + [markdown] deletable=true editable=true
# df['data1'].groupby(df['key1'])
# df[['data2']].groupby(df['key1'])

# + deletable=true editable=true
df.groupby(["key1", "key2"])[["data2"]].mean()

# + deletable=true editable=true
s_grouped = df.groupby(["key1", "key2"])["data2"]
s_grouped
s_grouped.mean()

# + [markdown] deletable=true editable=true
# ### Grouping with Dicts and Series

# + deletable=true editable=true
people = pd.DataFrame(
    np.random.randn(5, 5),
    columns=["a", "b", "c", "d", "e"],
    index=["Joe", "Steve", "Wes", "Jim", "Travis"],
)
people.iloc[2:3, [1, 2]] = np.nan  # Add a few NA values
people

# + deletable=true editable=true
mapping = {"a": "red", "b": "red", "c": "blue", "d": "blue", "e": "red", "f": "orange"}

# + deletable=true editable=true
by_column = people.groupby(mapping, axis=1)
by_column.sum()

# + deletable=true editable=true
map_series = pd.Series(mapping)
map_series
people.groupby(map_series, axis=1).count()

# + [markdown] deletable=true editable=true
# ### Grouping with Functions

# + deletable=true editable=true
people.groupby(len).sum()

# + deletable=true editable=true
key_list = ["one", "one", "one", "two", "two"]
people.groupby([len, key_list]).min()

# + [markdown] deletable=true editable=true
# ### Grouping by Index Levels

# + deletable=true editable=true
columns = pd.MultiIndex.from_arrays(
    [["US", "US", "US", "JP", "JP"], [1, 3, 5, 1, 3]], names=["cty", "tenor"]
)
hier_df = pd.DataFrame(np.random.randn(4, 5), columns=columns)
hier_df

# + deletable=true editable=true
hier_df.groupby(level="cty", axis=1).count()

# + [markdown] deletable=true editable=true
# ## Data Aggregation

# + deletable=true editable=true
df
grouped = df.groupby("key1")
grouped["data1"].quantile(0.9)


# + deletable=true editable=true
def peak_to_peak(arr):
    return arr.max() - arr.min()


grouped.agg(peak_to_peak)

# + deletable=true editable=true
grouped.describe()

# + [markdown] deletable=true editable=true
# ### Column-Wise and Multiple Function Application

# + deletable=true editable=true
tips = pd.read_csv("examples/tips.csv")
# Add tip percentage of total bill
tips["tip_pct"] = tips["tip"] / tips["total_bill"]
tips[:6]

# + deletable=true editable=true
grouped = tips.groupby(["day", "smoker"])

# + deletable=true editable=true
grouped_pct = grouped["tip_pct"]
grouped_pct.agg("mean")

# + deletable=true editable=true
grouped_pct.agg(["mean", "std", peak_to_peak])

# + deletable=true editable=true
grouped_pct.agg([("foo", "mean"), ("bar", np.std)])

# + deletable=true editable=true
functions = ["count", "mean", "max"]
result = grouped["tip_pct", "total_bill"].agg(functions)
result

# + deletable=true editable=true
result["tip_pct"]

# + deletable=true editable=true
ftuples = [("Durchschnitt", "mean"), ("Abweichung", np.var)]
grouped["tip_pct", "total_bill"].agg(ftuples)

# + deletable=true editable=true
grouped.agg({"tip": np.max, "size": "sum"})
grouped.agg({"tip_pct": ["min", "max", "mean", "std"], "size": "sum"})

# + [markdown] deletable=true editable=true
# ### Returning Aggregated Data Without Row Indexes

# + deletable=true editable=true
tips.groupby(["day", "smoker"], as_index=False).mean()


# + [markdown] deletable=true editable=true
# ## Apply: General split-apply-combine

# + deletable=true editable=true
def top(df, n=5, column="tip_pct"):
    return df.sort_values(by=column)[-n:]


top(tips, n=6)

# + deletable=true editable=true
tips.groupby("smoker").apply(top)

# + deletable=true editable=true
tips.groupby(["smoker", "day"]).apply(top, n=1, column="total_bill")

# + deletable=true editable=true
result = tips.groupby("smoker")["tip_pct"].describe()
result
result.unstack("smoker")

# + [markdown] deletable=true editable=true
# f = lambda x: x.describe()
# grouped.apply(f)

# + [markdown] deletable=true editable=true
# ### Suppressing the Group Keys

# + deletable=true editable=true
tips.groupby("smoker", group_keys=False).apply(top)

# + [markdown] deletable=true editable=true
# ### Quantile and Bucket Analysis

# + deletable=true editable=true
frame = pd.DataFrame({"data1": np.random.randn(1000), "data2": np.random.randn(1000)})
quartiles = pd.cut(frame.data1, 4)
quartiles[:10]


# + deletable=true editable=true
def get_stats(group):
    return {
        "min": group.min(),
        "max": group.max(),
        "count": group.count(),
        "mean": group.mean(),
    }


grouped = frame.data2.groupby(quartiles)
grouped.apply(get_stats).unstack()

# + deletable=true editable=true
# Return quantile numbers
grouping = pd.qcut(frame.data1, 10, labels=False)
grouped = frame.data2.groupby(grouping)
grouped.apply(get_stats).unstack()

# + [markdown] deletable=true editable=true
# ### Example: Filling Missing Values with Group-Specific       Values

# + deletable=true editable=true
s = pd.Series(np.random.randn(6))
s[::2] = np.nan
s
s.fillna(s.mean())

# + deletable=true editable=true
states = [
    "Ohio",
    "New York",
    "Vermont",
    "Florida",
    "Oregon",
    "Nevada",
    "California",
    "Idaho",
]
group_key = ["East"] * 4 + ["West"] * 4
data = pd.Series(np.random.randn(8), index=states)
data

# + deletable=true editable=true
data[["Vermont", "Nevada", "Idaho"]] = np.nan
data
data.groupby(group_key).mean()

# + deletable=true editable=true
fill_mean = lambda g: g.fillna(g.mean())
data.groupby(group_key).apply(fill_mean)

# + deletable=true editable=true
fill_values = {"East": 0.5, "West": -1}
fill_func = lambda g: g.fillna(fill_values[g.name])
data.groupby(group_key).apply(fill_func)

# + [markdown] deletable=true editable=true
# ### Example: Random Sampling and Permutation

# + deletable=true editable=true
# Hearts, Spades, Clubs, Diamonds
suits = ["H", "S", "C", "D"]
card_val = (list(range(1, 11)) + [10] * 3) * 4
base_names = ["A"] + list(range(2, 11)) + ["J", "K", "Q"]
cards = []
for suit in ["H", "S", "C", "D"]:
    cards.extend(str(num) + suit for num in base_names)

deck = pd.Series(card_val, index=cards)

# + deletable=true editable=true
deck[:13]


# + deletable=true editable=true
def draw(deck, n=5):
    return deck.sample(n)


draw(deck)

# + deletable=true editable=true
get_suit = lambda card: card[-1]  # last letter is suit
deck.groupby(get_suit).apply(draw, n=2)

# + deletable=true editable=true
deck.groupby(get_suit, group_keys=False).apply(draw, n=2)

# + [markdown] deletable=true editable=true
# ### Example: Group Weighted Average and Correlation

# + deletable=true editable=true
df = pd.DataFrame(
    {
        "category": ["a", "a", "a", "a", "b", "b", "b", "b"],
        "data": np.random.randn(8),
        "weights": np.random.rand(8),
    }
)
df

# + deletable=true editable=true
grouped = df.groupby("category")
get_wavg = lambda g: np.average(g["data"], weights=g["weights"])
grouped.apply(get_wavg)

# + deletable=true editable=true
close_px = pd.read_csv("examples/stock_px_2.csv", parse_dates=True, index_col=0)
close_px.info()
close_px[-4:]

# + deletable=true editable=true
spx_corr = lambda x: x.corrwith(x["SPX"])

# + deletable=true editable=true
rets = close_px.pct_change().dropna()

# + deletable=true editable=true
get_year = lambda x: x.year
by_year = rets.groupby(get_year)
by_year.apply(spx_corr)

# + deletable=true editable=true
by_year.apply(lambda g: g["AAPL"].corr(g["MSFT"]))

# + [markdown] deletable=true editable=true
# ### Example: Group-Wise Linear Regression

# + deletable=true editable=true
import statsmodels.api as sm


def regress(data, yvar, xvars):
    Y = data[yvar]
    X = data[xvars]
    X["intercept"] = 1.0
    result = sm.OLS(Y, X).fit()
    return result.params


# + deletable=true editable=true
by_year.apply(regress, "AAPL", ["SPX"])

# + [markdown] deletable=true editable=true
# ## Pivot Tables and Cross-Tabulation

# + deletable=true editable=true
tips.pivot_table(index=["day", "smoker"])

# + deletable=true editable=true
tips.pivot_table(["tip_pct", "size"], index=["time", "day"], columns="smoker")

# + deletable=true editable=true
tips.pivot_table(
    ["tip_pct", "size"], index=["time", "day"], columns="smoker", margins=True
)

# + deletable=true editable=true
tips.pivot_table(
    "tip_pct", index=["time", "smoker"], columns="day", aggfunc=len, margins=True
)

# + deletable=true editable=true
tips.pivot_table(
    "tip_pct",
    index=["time", "size", "smoker"],
    columns="day",
    aggfunc="mean",
    fill_value=0,
)

# + [markdown] deletable=true editable=true
# ### Cross-Tabulations: Crosstab

# + deletable=true editable=true
from io import StringIO

data = """\
Sample  Nationality  Handedness
1   USA  Right-handed
2   Japan    Left-handed
3   USA  Right-handed
4   Japan    Right-handed
5   Japan    Left-handed
6   Japan    Right-handed
7   USA  Right-handed
8   USA  Left-handed
9   Japan    Right-handed
10  USA  Right-handed"""
data = pd.read_table(StringIO(data), sep="\s+")

# + deletable=true editable=true
data

# + deletable=true editable=true
pd.crosstab(data.Nationality, data.Handedness, margins=True)

# + deletable=true editable=true
pd.crosstab([tips.time, tips.day], tips.smoker, margins=True)

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS

# + [markdown] deletable=true editable=true
# ## Conclusion
