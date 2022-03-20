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
import datetime

data = pd.read_csv("../data/wind.csv", sep="\s+", parse_dates=[[0, 1, 2]])
data.head()


# +
def fix_century(x):
    year = x.year - 100 if x.year > 1989 else x.year
    return datetime.date(year, x.month, x.day)


data["Yr_Mo_Dy"] = data["Yr_Mo_Dy"].apply(fix_century)

data.head()

# +
data["Yr_Mo_Dy"] = pd.to_datetime(data["Yr_Mo_Dy"])

data = data.set_index("Yr_Mo_Dy")

data.head()
# -

data.isnull().sum()

data.shape[0] - data.isnull().sum()
# data.notnull().sum()

data.sum().sum() / data.notna().sum().sum()

data.describe(percentiles=[])

data.min(axis=1)

# +
day_stats = pd.DataFrame()

data_stats["min"] = data.min(axis=1)
