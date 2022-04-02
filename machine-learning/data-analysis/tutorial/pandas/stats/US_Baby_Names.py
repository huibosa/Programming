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
#     display_name: 'Python 3.9.7 64-bit (''DataAnalysis'': venv)'
#     name: python3
# ---

import pandas as pd
import numpy as np

babyNames = pd.read_csv("../data//US_Baby_Names_right.csv")
babyNames.info()

babyNames.head(10)

babyNames.drop(["Unnamed: 0", "Id"], axis=1, inplace=True)

babyNames["Gender"].value_counts()

babyNames.drop("Year", axis=1, inplace=True)

names = babyNames.groupby("Name").sum()
print(names.shape)
names.sort_values("Count", ascending=False).head()

len(names)

names["Count"].idxmax()
# names[names['Count'] == names['Count'].max()]

filt = names["Count"] == names["Count"].min()
len(names[filt])

filt = names["Count"] == names["Count"].median()
len(names[filt])

names["Count"].std()

names.describe()
