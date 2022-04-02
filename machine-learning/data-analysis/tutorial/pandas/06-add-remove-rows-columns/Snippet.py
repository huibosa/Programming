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

people = {
    "first": ["Corey", "Jane", "John"],
    "last": ["Schafer", "Doe", "Doe"],
    "email": ["CoreyMSchafer@gmail.com", "JaneDoe@email.com", "JohnDoe@email.com"],
}

import pandas as pd

df = pd.DataFrame(people)

df

df["first"] + " " + df["last"]

df["full_name"] = df["first"] + " " + df["last"]
df

df.drop(columns=["first", "last"], inplace=True)
df

df["full_name"].str.split(" ", expand=True)

df[["first", "last"]] = df["full_name"].str.split(" ", expand=True)

df

df.append({"first": "Tony"}, ignore_index=True)

people = {
    "first": ["Tony", "Steve"],
    "last": ["Stark", "Rogers"],
    "email": ["Ironman@avenge.com", "Cap@avenge.com"],
}
df2 = pd.DataFrame(people)

df2

df = df.append(df2, ignore_index=True)
df

df.drop(index=4, inplace=True)
df

filt = df["last"] == "Doe"
df.drop(index=df[filt].index, inplace=True)
df
