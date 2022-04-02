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
#     display_name: Python 3.9.2 64-bit
#     name: python3
# ---

import pandas as pd

d_parser = lambda x: pd.datetime.strptime(x, "%Y-%m-%d %I-%p")
df = pd.read_csv("./ETH_1h.csv", parse_dates=["Date"], date_parser=d_parser)

df.head()

df.shape

df.loc[0, "Date"]

df["Date"] = pd.to_datetime(df["Date"], format="%Y-%m-%d %I-%p")

df["Date"]

df.loc[0, "Date"].day_name()
