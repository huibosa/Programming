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
# # Data Analysis Examples

# + [markdown] deletable=true editable=true
# ## 1.USA.gov Data from Bitly

# + deletable=true editable=true
from numpy.random import randn
import numpy as np

np.random.seed(123)
import os
import matplotlib.pyplot as plt
import pandas as pd

plt.rc("figure", figsize=(10, 6))
np.set_printoptions(precision=4)
pd.options.display.max_rows = 20

# + [markdown] deletable=true editable=true
# In [5]: path = 'datasets/bitly_usagov/example.txt'
#
# In [6]: open(path).readline()
# Out[6]: '{ "a": "Mozilla\\/5.0 (Windows NT 6.1; WOW64) AppleWebKit\\/535.11
# (KHTML, like Gecko) Chrome\\/17.0.963.78 Safari\\/535.11", "c": "US", "nk": 1,
# "tz": "America\\/New_York", "gr": "MA", "g": "A6qOVH", "h": "wfLQtf", "l":
# "orofrog", "al": "en-US,en;q=0.8", "hh": "1.usa.gov", "r":
# "http:\\/\\/www.facebook.com\\/l\\/7AQEFzjSi\\/1.usa.gov\\/wfLQtf", "u":
# "http:\\/\\/www.ncbi.nlm.nih.gov\\/pubmed\\/22415991", "t": 1331923247, "hc":
# 1331822918, "cy": "Danvers", "ll": [ 42.576698, -70.954903 ] }\n'

# + deletable=true editable=true
import json

path = "datasets/bitly_usagov/example.txt"
records = [json.loads(line) for line in open(path)]

# + [markdown] deletable=true editable=true
# In [18]: records[0]
# Out[18]:
# {'a': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko)
# Chrome/17.0.963.78 Safari/535.11',
#  'al': 'en-US,en;q=0.8',
#  'c': 'US',
#  'cy': 'Danvers',
#  'g': 'A6qOVH',
#  'gr': 'MA',
#  'h': 'wfLQtf',
#  'hc': 1331822918,
#  'hh': '1.usa.gov',
#  'l': 'orofrog',
#  'll': [42.576698, -70.954903],
#  'nk': 1,
#  'r': 'http://www.facebook.com/l/7AQEFzjSi/1.usa.gov/wfLQtf',
#  't': 1331923247,
#  'tz': 'America/New_York',
#  'u': 'http://www.ncbi.nlm.nih.gov/pubmed/22415991'}

# + [markdown] deletable=true editable=true
# ### Counting Time Zones in Pure Python

# + deletable=true editable=true
time_zones = [rec["tz"] for rec in records]

# + deletable=true editable=true
time_zones = [rec["tz"] for rec in records if "tz" in rec]
time_zones[:10]


# + deletable=true editable=true
def get_counts(sequence):
    counts = {}
    for x in sequence:
        if x in counts:
            counts[x] += 1
        else:
            counts[x] = 1
    return counts


# + deletable=true editable=true
from collections import defaultdict


def get_counts2(sequence):
    counts = defaultdict(int)  # values will initialize to 0
    for x in sequence:
        counts[x] += 1
    return counts


# + deletable=true editable=true
counts = get_counts(time_zones)
counts["America/New_York"]
len(time_zones)


# + deletable=true editable=true
def top_counts(count_dict, n=10):
    value_key_pairs = [(count, tz) for tz, count in count_dict.items()]
    value_key_pairs.sort()
    return value_key_pairs[-n:]


# + deletable=true editable=true
top_counts(counts)

# + deletable=true editable=true
from collections import Counter

counts = Counter(time_zones)
counts.most_common(10)

# + [markdown] deletable=true editable=true
# ### Counting Time Zones with pandas

# + deletable=true editable=true
import pandas as pd

frame = pd.DataFrame(records)
frame.info()
frame["tz"][:10]

# + deletable=true editable=true
tz_counts = frame["tz"].value_counts()
tz_counts[:10]

# + deletable=true editable=true
clean_tz = frame["tz"].fillna("Missing")
clean_tz[clean_tz == ""] = "Unknown"
tz_counts = clean_tz.value_counts()
tz_counts[:10]

# + deletable=true editable=true
plt.figure(figsize=(10, 4))

# + deletable=true editable=true
import seaborn as sns

subset = tz_counts[:10]
sns.barplot(y=subset.index, x=subset.values)

# + deletable=true editable=true
frame["a"][1]
frame["a"][50]
frame["a"][51][:50]  # long line

# + deletable=true editable=true
results = pd.Series([x.split()[0] for x in frame.a.dropna()])
results[:5]
results.value_counts()[:8]

# + deletable=true editable=true
cframe = frame[frame.a.notnull()]

# + deletable=true editable=true
cframe = cframe.copy()

# + deletable=true editable=true
cframe["os"] = np.where(cframe["a"].str.contains("Windows"), "Windows", "Not Windows")
cframe["os"][:5]

# + deletable=true editable=true
by_tz_os = cframe.groupby(["tz", "os"])

# + deletable=true editable=true
agg_counts = by_tz_os.size().unstack().fillna(0)
agg_counts[:10]

# + deletable=true editable=true
# Use to sort in ascending order
indexer = agg_counts.sum(1).argsort()
indexer[:10]

# + deletable=true editable=true
count_subset = agg_counts.take(indexer[-10:])
count_subset

# + deletable=true editable=true
agg_counts.sum(1).nlargest(10)

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
# Rearrange the data for plotting
count_subset = count_subset.stack()
count_subset.name = "total"
count_subset = count_subset.reset_index()
count_subset[:10]
sns.barplot(x="total", y="tz", hue="os", data=count_subset)


# + deletable=true editable=true
def norm_total(group):
    group["normed_total"] = group.total / group.total.sum()
    return group


results = count_subset.groupby("tz").apply(norm_total)

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
sns.barplot(x="normed_total", y="tz", hue="os", data=results)

# + deletable=true editable=true
g = count_subset.groupby("tz")
results2 = count_subset.total / g.total.transform("sum")

# + [markdown] deletable=true editable=true
# ## MovieLens 1M Dataset

# + deletable=true editable=true
import pandas as pd

# Make display smaller
pd.options.display.max_rows = 10

unames = ["user_id", "gender", "age", "occupation", "zip"]
users = pd.read_table(
    "datasets/movielens/users.dat", sep="::", header=None, names=unames
)

rnames = ["user_id", "movie_id", "rating", "timestamp"]
ratings = pd.read_table(
    "datasets/movielens/ratings.dat", sep="::", header=None, names=rnames
)

mnames = ["movie_id", "title", "genres"]
movies = pd.read_table(
    "datasets/movielens/movies.dat", sep="::", header=None, names=mnames
)

# + deletable=true editable=true
users[:5]
ratings[:5]
movies[:5]
ratings

# + deletable=true editable=true
data = pd.merge(pd.merge(ratings, users), movies)
data
data.iloc[0]

# + deletable=true editable=true
mean_ratings = data.pivot_table(
    "rating", index="title", columns="gender", aggfunc="mean"
)
mean_ratings[:5]

# + deletable=true editable=true
ratings_by_title = data.groupby("title").size()
ratings_by_title[:10]
active_titles = ratings_by_title.index[ratings_by_title >= 250]
active_titles

# + deletable=true editable=true
# Select rows on the index
mean_ratings = mean_ratings.loc[active_titles]
mean_ratings

# + deletable=true editable=true
mean_ratings = mean_ratings.rename(
    index={
        "Seven Samurai (The Magnificent Seven) (Shichinin no samurai) (1954)": "Seven Samurai (Shichinin no samurai) (1954)"
    }
)

# + deletable=true editable=true
top_female_ratings = mean_ratings.sort_values(by="F", ascending=False)
top_female_ratings[:10]

# + [markdown] deletable=true editable=true
# ### Measuring Rating Disagreement

# + deletable=true editable=true
mean_ratings["diff"] = mean_ratings["M"] - mean_ratings["F"]

# + deletable=true editable=true
sorted_by_diff = mean_ratings.sort_values(by="diff")
sorted_by_diff[:10]

# + deletable=true editable=true
# Reverse order of rows, take first 10 rows
sorted_by_diff[::-1][:10]

# + deletable=true editable=true
# Standard deviation of rating grouped by title
rating_std_by_title = data.groupby("title")["rating"].std()
# Filter down to active_titles
rating_std_by_title = rating_std_by_title.loc[active_titles]
# Order Series by value in descending order
rating_std_by_title.sort_values(ascending=False)[:10]

# + [markdown] deletable=true editable=true
# ## US Baby Names 1880–2010

# + [markdown] deletable=true editable=true
# In [4]: names.head(10)
# Out[4]:
#         name sex  births  year
# 0       Mary   F    7065  1880
# 1       Anna   F    2604  1880
# 2       Emma   F    2003  1880
# 3  Elizabeth   F    1939  1880
# 4     Minnie   F    1746  1880
# 5   Margaret   F    1578  1880
# 6        Ida   F    1472  1880
# 7      Alice   F    1414  1880
# 8     Bertha   F    1320  1880
# 9      Sarah   F    1288  1880

# + deletable=true editable=true
# !head -n 10 datasets/babynames/yob1880.txt

# + deletable=true editable=true
import pandas as pd

names1880 = pd.read_csv(
    "datasets/babynames/yob1880.txt", names=["name", "sex", "births"]
)
names1880

# + deletable=true editable=true
names1880.groupby("sex").births.sum()

# + deletable=true editable=true
years = range(1880, 2011)

pieces = []
columns = ["name", "sex", "births"]

for year in years:
    path = "datasets/babynames/yob%d.txt" % year
    frame = pd.read_csv(path, names=columns)

    frame["year"] = year
    pieces.append(frame)

# Concatenate everything into a single DataFrame
names = pd.concat(pieces, ignore_index=True)

# + deletable=true editable=true
names

# + deletable=true editable=true
total_births = names.pivot_table("births", index="year", columns="sex", aggfunc=sum)
total_births.tail()
total_births.plot(title="Total births by sex and year")


# + deletable=true editable=true
def add_prop(group):
    group["prop"] = group.births / group.births.sum()
    return group


names = names.groupby(["year", "sex"]).apply(add_prop)

# + deletable=true editable=true
names

# + deletable=true editable=true
names.groupby(["year", "sex"]).prop.sum()


# + deletable=true editable=true
def get_top1000(group):
    return group.sort_values(by="births", ascending=False)[:1000]


grouped = names.groupby(["year", "sex"])
top1000 = grouped.apply(get_top1000)
# Drop the group index, not needed
top1000.reset_index(inplace=True, drop=True)

# + [markdown] deletable=true editable=true
# pieces = []
# for year, group in names.groupby(['year', 'sex']):
#     pieces.append(group.sort_values(by='births', ascending=False)[:1000])
# top1000 = pd.concat(pieces, ignore_index=True)

# + deletable=true editable=true
top1000

# + [markdown] deletable=true editable=true
# ### Analyzing Naming Trends

# + deletable=true editable=true
boys = top1000[top1000.sex == "M"]
girls = top1000[top1000.sex == "F"]

# + deletable=true editable=true
total_births = top1000.pivot_table("births", index="year", columns="name", aggfunc=sum)

# + deletable=true editable=true
total_births.info()
subset = total_births[["John", "Harry", "Mary", "Marilyn"]]
subset.plot(
    subplots=True, figsize=(12, 10), grid=False, title="Number of births per year"
)

# + [markdown] deletable=true editable=true
# #### Measuring the increase in naming diversity

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
table = top1000.pivot_table("prop", index="year", columns="sex", aggfunc=sum)
table.plot(
    title="Sum of table1000.prop by year and sex",
    yticks=np.linspace(0, 1.2, 13),
    xticks=range(1880, 2020, 10),
)

# + deletable=true editable=true
df = boys[boys.year == 2010]
df

# + deletable=true editable=true
prop_cumsum = df.sort_values(by="prop", ascending=False).prop.cumsum()
prop_cumsum[:10]
prop_cumsum.values.searchsorted(0.5)

# + deletable=true editable=true
df = boys[boys.year == 1900]
in1900 = df.sort_values(by="prop", ascending=False).prop.cumsum()
in1900.values.searchsorted(0.5) + 1


# + deletable=true editable=true
def get_quantile_count(group, q=0.5):
    group = group.sort_values(by="prop", ascending=False)
    return group.prop.cumsum().values.searchsorted(q) + 1


diversity = top1000.groupby(["year", "sex"]).apply(get_quantile_count)
diversity = diversity.unstack("sex")

# + deletable=true editable=true
fig = plt.figure()

# + deletable=true editable=true
diversity.head()
diversity.plot(title="Number of popular names in top 50%")

# + [markdown] deletable=true editable=true
# #### The “last letter” revolution

# + deletable=true editable=true
# extract last letter from name column
get_last_letter = lambda x: x[-1]
last_letters = names.name.map(get_last_letter)
last_letters.name = "last_letter"

table = names.pivot_table(
    "births", index=last_letters, columns=["sex", "year"], aggfunc=sum
)

# + deletable=true editable=true
subtable = table.reindex(columns=[1910, 1960, 2010], level="year")
subtable.head()

# + deletable=true editable=true
subtable.sum()
letter_prop = subtable / subtable.sum()
letter_prop

# + deletable=true editable=true
import matplotlib.pyplot as plt

fig, axes = plt.subplots(2, 1, figsize=(10, 8))
letter_prop["M"].plot(kind="bar", rot=0, ax=axes[0], title="Male")
letter_prop["F"].plot(kind="bar", rot=0, ax=axes[1], title="Female", legend=False)

# + deletable=true editable=true
plt.subplots_adjust(hspace=0.25)

# + deletable=true editable=true
letter_prop = table / table.sum()
dny_ts = letter_prop.loc[["d", "n", "y"], "M"].T
dny_ts.head()

# + deletable=true editable=true
plt.close("all")

# + deletable=true editable=true
fig = plt.figure()

# + deletable=true editable=true
dny_ts.plot()

# + [markdown] deletable=true editable=true
# #### Boy names that became girl names (and vice versa)

# + deletable=true editable=true
all_names = pd.Series(top1000.name.unique())
lesley_like = all_names[all_names.str.lower().str.contains("lesl")]
lesley_like

# + deletable=true editable=true
filtered = top1000[top1000.name.isin(lesley_like)]
filtered.groupby("name").births.sum()

# + deletable=true editable=true
table = filtered.pivot_table("births", index="year", columns="sex", aggfunc="sum")
table = table.div(table.sum(1), axis=0)
table.tail()

# + deletable=true editable=true
fig = plt.figure()

# + deletable=true editable=true
table.plot(style={"M": "k-", "F": "k--"})

# + [markdown] deletable=true editable=true
# ## USDA Food Database

# + [markdown] deletable=true editable=true
# {
#   "id": 21441,
#   "description": "KENTUCKY FRIED CHICKEN, Fried Chicken, EXTRA CRISPY,
# Wing, meat and skin with breading",
#   "tags": ["KFC"],
#   "manufacturer": "Kentucky Fried Chicken",
#   "group": "Fast Foods",
#   "portions": [
#     {
#       "amount": 1,
#       "unit": "wing, with skin",
#       "grams": 68.0
#     },
#
#     ...
#   ],
#   "nutrients": [
#     {
#       "value": 20.8,
#       "units": "g",
#       "description": "Protein",
#       "group": "Composition"
#     },
#
#     ...
#   ]
# }

# + deletable=true editable=true
import json

db = json.load(open("datasets/usda_food/database.json"))
len(db)

# + deletable=true editable=true
db[0].keys()
db[0]["nutrients"][0]
nutrients = pd.DataFrame(db[0]["nutrients"])
nutrients[:7]

# + deletable=true editable=true
info_keys = ["description", "group", "id", "manufacturer"]
info = pd.DataFrame(db, columns=info_keys)
info[:5]
info.info()

# + deletable=true editable=true
pd.value_counts(info.group)[:10]

# + deletable=true editable=true
nutrients = []

for rec in db:
    fnuts = pd.DataFrame(rec["nutrients"])
    fnuts["id"] = rec["id"]
    nutrients.append(fnuts)

nutrients = pd.concat(nutrients, ignore_index=True)

# + deletable=true editable=true
nutrients

# + deletable=true editable=true
nutrients.duplicated().sum()  # number of duplicates
nutrients = nutrients.drop_duplicates()

# + deletable=true editable=true
col_mapping = {"description": "food", "group": "fgroup"}
info = info.rename(columns=col_mapping, copy=False)
info.info()
col_mapping = {"description": "nutrient", "group": "nutgroup"}
nutrients = nutrients.rename(columns=col_mapping, copy=False)
nutrients

# + deletable=true editable=true
ndata = pd.merge(nutrients, info, on="id", how="outer")
ndata.info()
ndata.iloc[30000]

# + deletable=true editable=true
fig = plt.figure()

# + deletable=true editable=true
result = ndata.groupby(["nutrient", "fgroup"])["value"].quantile(0.5)
result["Zinc, Zn"].sort_values().plot(kind="barh")

# + deletable=true editable=true
by_nutrient = ndata.groupby(["nutgroup", "nutrient"])

get_maximum = lambda x: x.loc[x.value.idxmax()]
get_minimum = lambda x: x.loc[x.value.idxmin()]

max_foods = by_nutrient.apply(get_maximum)[["value", "food"]]

# make the food a little smaller
max_foods.food = max_foods.food.str[:50]

# + deletable=true editable=true
max_foods.loc["Amino Acids"]["food"]

# + [markdown] deletable=true editable=true
# ## 2012 Federal Election Commission Database

# + deletable=true editable=true
fec = pd.read_csv("datasets/fec/P00000001-ALL.csv")
fec.info()

# + deletable=true editable=true
fec.iloc[123456]

# + deletable=true editable=true
unique_cands = fec.cand_nm.unique()
unique_cands
unique_cands[2]

# + deletable=true editable=true
parties = {
    "Bachmann, Michelle": "Republican",
    "Cain, Herman": "Republican",
    "Gingrich, Newt": "Republican",
    "Huntsman, Jon": "Republican",
    "Johnson, Gary Earl": "Republican",
    "McCotter, Thaddeus G": "Republican",
    "Obama, Barack": "Democrat",
    "Paul, Ron": "Republican",
    "Pawlenty, Timothy": "Republican",
    "Perry, Rick": "Republican",
    "Roemer, Charles E. 'Buddy' III": "Republican",
    "Romney, Mitt": "Republican",
    "Santorum, Rick": "Republican",
}

# + deletable=true editable=true
fec.cand_nm[123456:123461]
fec.cand_nm[123456:123461].map(parties)
# Add it as a column
fec["party"] = fec.cand_nm.map(parties)
fec["party"].value_counts()

# + deletable=true editable=true
(fec.contb_receipt_amt > 0).value_counts()

# + deletable=true editable=true
fec = fec[fec.contb_receipt_amt > 0]

# + deletable=true editable=true
fec_mrbo = fec[fec.cand_nm.isin(["Obama, Barack", "Romney, Mitt"])]

# + [markdown] deletable=true editable=true
# ### Donation Statistics by Occupation and Employer

# + deletable=true editable=true
fec.contbr_occupation.value_counts()[:10]

# + deletable=true editable=true
occ_mapping = {
    "INFORMATION REQUESTED PER BEST EFFORTS": "NOT PROVIDED",
    "INFORMATION REQUESTED": "NOT PROVIDED",
    "INFORMATION REQUESTED (BEST EFFORTS)": "NOT PROVIDED",
    "C.E.O.": "CEO",
}

# If no mapping provided, return x
f = lambda x: occ_mapping.get(x, x)
fec.contbr_occupation = fec.contbr_occupation.map(f)

# + deletable=true editable=true
emp_mapping = {
    "INFORMATION REQUESTED PER BEST EFFORTS": "NOT PROVIDED",
    "INFORMATION REQUESTED": "NOT PROVIDED",
    "SELF": "SELF-EMPLOYED",
    "SELF EMPLOYED": "SELF-EMPLOYED",
}

# If no mapping provided, return x
f = lambda x: emp_mapping.get(x, x)
fec.contbr_employer = fec.contbr_employer.map(f)

# + deletable=true editable=true
by_occupation = fec.pivot_table(
    "contb_receipt_amt", index="contbr_occupation", columns="party", aggfunc="sum"
)
over_2mm = by_occupation[by_occupation.sum(1) > 2000000]
over_2mm

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
over_2mm.plot(kind="barh")


# + deletable=true editable=true
def get_top_amounts(group, key, n=5):
    totals = group.groupby(key)["contb_receipt_amt"].sum()
    return totals.nlargest(n)


# + deletable=true editable=true
grouped = fec_mrbo.groupby("cand_nm")
grouped.apply(get_top_amounts, "contbr_occupation", n=7)
grouped.apply(get_top_amounts, "contbr_employer", n=10)

# + [markdown] deletable=true editable=true
# ### Bucketing Donation Amounts

# + deletable=true editable=true
bins = np.array([0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000])
labels = pd.cut(fec_mrbo.contb_receipt_amt, bins)
labels

# + deletable=true editable=true
grouped = fec_mrbo.groupby(["cand_nm", labels])
grouped.size().unstack(0)

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
bucket_sums = grouped.contb_receipt_amt.sum().unstack(0)
normed_sums = bucket_sums.div(bucket_sums.sum(axis=1), axis=0)
normed_sums
normed_sums[:-2].plot(kind="barh")

# + [markdown] deletable=true editable=true
# ### Donation Statistics by State

# + deletable=true editable=true
grouped = fec_mrbo.groupby(["cand_nm", "contbr_st"])
totals = grouped.contb_receipt_amt.sum().unstack(0).fillna(0)
totals = totals[totals.sum(1) > 100000]
totals[:10]

# + deletable=true editable=true
percent = totals.div(totals.sum(1), axis=0)
percent[:10]

# + [markdown] deletable=true editable=true
# ## Conclusion
