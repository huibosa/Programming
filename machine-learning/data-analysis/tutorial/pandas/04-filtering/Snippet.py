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

filt = df["last"] == "Doe"

df[filt]

df.loc[filt]

filt = (df["last"] == "Schafer") | (df["first"] == "John")
df.loc[~filt, "email"]
