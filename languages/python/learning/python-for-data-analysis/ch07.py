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
# # Data Cleaning and Preparation

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
# ## Handling Missing Data

# + deletable=true editable=true
string_data = pd.Series(["aardvark", "artichoke", np.nan, "avocado"])
string_data
string_data.isnull()

# + deletable=true editable=true
string_data[0] = None
string_data.isnull()

# + [markdown] deletable=true editable=true
# ### Filtering Out Missing Data

# + deletable=true editable=true
from numpy import nan as NA

data = pd.Series([1, NA, 3.5, NA, 7])
data.dropna()

# + deletable=true editable=true
data[data.notnull()]

# + deletable=true editable=true
data = pd.DataFrame([[1.0, 6.5, 3.0], [1.0, NA, NA], [NA, NA, NA], [NA, 6.5, 3.0]])
cleaned = data.dropna()
data
cleaned

# + deletable=true editable=true
data.dropna(how="all")

# + deletable=true editable=true
data[4] = NA
data
data.dropna(axis=1, how="all")

# + deletable=true editable=true
df = pd.DataFrame(np.random.randn(7, 3))
df.iloc[:4, 1] = NA
df.iloc[:2, 2] = NA
df
df.dropna()
df.dropna(thresh=2)

# + [markdown] deletable=true editable=true
# ### Filling In Missing Data

# + deletable=true editable=true
df.fillna(0)

# + deletable=true editable=true
df.fillna({1: 0.5, 2: 0})

# + deletable=true editable=true
_ = df.fillna(0, inplace=True)
df

# + deletable=true editable=true
df = pd.DataFrame(np.random.randn(6, 3))
df.iloc[2:, 1] = NA
df.iloc[4:, 2] = NA
df
df.fillna(method="ffill")
df.fillna(method="ffill", limit=2)

# + deletable=true editable=true
data = pd.Series([1.0, NA, 3.5, NA, 7])
data.fillna(data.mean())

# + [markdown] deletable=true editable=true
# ## Data Transformation

# + [markdown] deletable=true editable=true
# ### Removing Duplicates

# + deletable=true editable=true
data = pd.DataFrame({"k1": ["one", "two"] * 3 + ["two"], "k2": [1, 1, 2, 3, 3, 4, 4]})
data

# + deletable=true editable=true
data.duplicated()

# + deletable=true editable=true
data.drop_duplicates()

# + deletable=true editable=true
data["v1"] = range(7)
data.drop_duplicates(["k1"])

# + deletable=true editable=true
data.drop_duplicates(["k1", "k2"], keep="last")

# + [markdown] deletable=true editable=true
# ### Transforming Data Using a Function or Mapping

# + deletable=true editable=true
data = pd.DataFrame(
    {
        "food": [
            "bacon",
            "pulled pork",
            "bacon",
            "Pastrami",
            "corned beef",
            "Bacon",
            "pastrami",
            "honey ham",
            "nova lox",
        ],
        "ounces": [4, 3, 12, 6, 7.5, 8, 3, 5, 6],
    }
)
data

# + deletable=true editable=true
meat_to_animal = {
    "bacon": "pig",
    "pulled pork": "pig",
    "pastrami": "cow",
    "corned beef": "cow",
    "honey ham": "pig",
    "nova lox": "salmon",
}

# + deletable=true editable=true
lowercased = data["food"].str.lower()
lowercased
data["animal"] = lowercased.map(meat_to_animal)
data

# + deletable=true editable=true
data["food"].map(lambda x: meat_to_animal[x.lower()])

# + [markdown] deletable=true editable=true
# ### Replacing Values

# + deletable=true editable=true
data = pd.Series([1.0, -999.0, 2.0, -999.0, -1000.0, 3.0])
data

# + deletable=true editable=true
data.replace(-999, np.nan)

# + deletable=true editable=true
data.replace([-999, -1000], np.nan)

# + deletable=true editable=true
data.replace([-999, -1000], [np.nan, 0])

# + deletable=true editable=true
data.replace({-999: np.nan, -1000: 0})

# + [markdown] deletable=true editable=true
# ### Renaming Axis Indexes

# + deletable=true editable=true
data = pd.DataFrame(
    np.arange(12).reshape((3, 4)),
    index=["Ohio", "Colorado", "New York"],
    columns=["one", "two", "three", "four"],
)

# + deletable=true editable=true
transform = lambda x: x[:4].upper()
data.index.map(transform)

# + deletable=true editable=true
data.index = data.index.map(transform)
data

# + deletable=true editable=true
data.rename(index=str.title, columns=str.upper)

# + deletable=true editable=true
data.rename(index={"OHIO": "INDIANA"}, columns={"three": "peekaboo"})

# + deletable=true editable=true
data.rename(index={"OHIO": "INDIANA"}, inplace=True)
data

# + [markdown] deletable=true editable=true
# ### Discretization and Binning

# + deletable=true editable=true
ages = [20, 22, 25, 27, 21, 23, 37, 31, 61, 45, 41, 32]

# + deletable=true editable=true
bins = [18, 25, 35, 60, 100]
cats = pd.cut(ages, bins)
cats

# + deletable=true editable=true
cats.codes
cats.categories
pd.value_counts(cats)

# + deletable=true editable=true
pd.cut(ages, [18, 26, 36, 61, 100], right=False)

# + deletable=true editable=true
group_names = ["Youth", "YoungAdult", "MiddleAged", "Senior"]
pd.cut(ages, bins, labels=group_names)

# + deletable=true editable=true
data = np.random.rand(20)
pd.cut(data, 4, precision=2)

# + deletable=true editable=true
data = np.random.randn(1000)  # Normally distributed
cats = pd.qcut(data, 4)  # Cut into quartiles
cats
pd.value_counts(cats)

# + deletable=true editable=true
pd.qcut(data, [0, 0.1, 0.5, 0.9, 1.0])

# + [markdown] deletable=true editable=true
# ### Detecting and Filtering Outliers

# + deletable=true editable=true
data = pd.DataFrame(np.random.randn(1000, 4))
data.describe()

# + deletable=true editable=true
col = data[2]
col[np.abs(col) > 3]

# + deletable=true editable=true
data[(np.abs(data) > 3).any(1)]

# + deletable=true editable=true
data[np.abs(data) > 3] = np.sign(data) * 3
data.describe()

# + deletable=true editable=true
np.sign(data).head()

# + [markdown] deletable=true editable=true
# ### Permutation and Random Sampling

# + deletable=true editable=true
df = pd.DataFrame(np.arange(5 * 4).reshape((5, 4)))
sampler = np.random.permutation(5)
sampler

# + deletable=true editable=true
df
df.take(sampler)

# + deletable=true editable=true
df.sample(n=3)

# + deletable=true editable=true
choices = pd.Series([5, 7, -1, 6, 4])
draws = choices.sample(n=10, replace=True)
draws

# + [markdown] deletable=true editable=true
# ### Computing Indicator/Dummy Variables

# + deletable=true editable=true
df = pd.DataFrame({"key": ["b", "b", "a", "c", "a", "b"], "data1": range(6)})
pd.get_dummies(df["key"])

# + deletable=true editable=true
dummies = pd.get_dummies(df["key"], prefix="key")
df_with_dummy = df[["data1"]].join(dummies)
df_with_dummy

# + deletable=true editable=true
mnames = ["movie_id", "title", "genres"]
movies = pd.read_table(
    "datasets/movielens/movies.dat", sep="::", header=None, names=mnames
)
movies[:10]

# + deletable=true editable=true
all_genres = []
for x in movies.genres:
    all_genres.extend(x.split("|"))
genres = pd.unique(all_genres)

# + deletable=true editable=true
genres

# + deletable=true editable=true
zero_matrix = np.zeros((len(movies), len(genres)))
dummies = pd.DataFrame(zero_matrix, columns=genres)

# + deletable=true editable=true
gen = movies.genres[0]
gen.split("|")
dummies.columns.get_indexer(gen.split("|"))

# + deletable=true editable=true
for i, gen in enumerate(movies.genres):
    indices = dummies.columns.get_indexer(gen.split("|"))
    dummies.iloc[i, indices] = 1

# + deletable=true editable=true
movies_windic = movies.join(dummies.add_prefix("Genre_"))
movies_windic.iloc[0]

# + deletable=true editable=true
np.random.seed(12345)
values = np.random.rand(10)
values
bins = [0, 0.2, 0.4, 0.6, 0.8, 1]
pd.get_dummies(pd.cut(values, bins))

# + [markdown] deletable=true editable=true
# ## String Manipulation

# + [markdown] deletable=true editable=true
# ### String Object Methods

# + deletable=true editable=true
val = "a,b,  guido"
val.split(",")

# + deletable=true editable=true
pieces = [x.strip() for x in val.split(",")]
pieces

# + deletable=true editable=true
first, second, third = pieces
first + "::" + second + "::" + third

# + deletable=true editable=true
"::".join(pieces)

# + deletable=true editable=true
"guido" in val
val.index(",")
val.find(":")

# + deletable=true editable=true
val.index(":")

# + deletable=true editable=true
val.count(",")

# + deletable=true editable=true
val.replace(",", "::")
val.replace(",", "")

# + [markdown] deletable=true editable=true
# ### Regular Expressions

# + deletable=true editable=true
import re

text = "foo    bar\t baz  \tqux"
re.split("\s+", text)

# + deletable=true editable=true
regex = re.compile("\s+")
regex.split(text)

# + deletable=true editable=true
regex.findall(text)

# + deletable=true editable=true
text = """Dave dave@google.com
Steve steve@gmail.com
Rob rob@gmail.com
Ryan ryan@yahoo.com
"""
pattern = r"[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}"

# re.IGNORECASE makes the regex case-insensitive
regex = re.compile(pattern, flags=re.IGNORECASE)

# + deletable=true editable=true
regex.findall(text)

# + deletable=true editable=true
m = regex.search(text)
m
text[m.start() : m.end()]

# + deletable=true editable=true
print(regex.match(text))

# + deletable=true editable=true
print(regex.sub("REDACTED", text))

# + deletable=true editable=true
pattern = r"([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\.([A-Z]{2,4})"
regex = re.compile(pattern, flags=re.IGNORECASE)

# + deletable=true editable=true
m = regex.match("wesm@bright.net")
m.groups()

# + deletable=true editable=true
regex.findall(text)

# + deletable=true editable=true
print(regex.sub(r"Username: \1, Domain: \2, Suffix: \3", text))

# + [markdown] deletable=true editable=true
# ### Vectorized String Functions in pandas

# + deletable=true editable=true
data = {
    "Dave": "dave@google.com",
    "Steve": "steve@gmail.com",
    "Rob": "rob@gmail.com",
    "Wes": np.nan,
}
data = pd.Series(data)
data
data.isnull()

# + deletable=true editable=true
data.str.contains("gmail")

# + deletable=true editable=true
pattern
data.str.findall(pattern, flags=re.IGNORECASE)

# + deletable=true editable=true
matches = data.str.match(pattern, flags=re.IGNORECASE)
matches

# + deletable=true editable=true
matches.str.get(1)
matches.str[0]

# + deletable=true editable=true
data.str[:5]

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS

# + [markdown] deletable=true editable=true
# ## Conclusion
