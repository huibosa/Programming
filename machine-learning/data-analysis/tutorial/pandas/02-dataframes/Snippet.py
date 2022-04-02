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

# +
person = {"first": "Corey", "last": "Schafer", "email": "CoreyMSchafer@gmail.com"}

people = {"first": ["Corey"], "last": ["Schafer"], "email": ["CoreyMSchafer@gmail.com"]}

people = {
    "first": ["Corey", "Jane", "John"],
    "last": ["Schafer", "Doe", "Doe"],
    "email": ["CoreyMSchafer@gmail.com", "JaneDoe@email.com", "JohnDoe@email.com"],
}
# -

people["email"]

import pandas as pd

df = pd.DataFrame(people)

df

df["email"]

type(df["email"])

df.email

df[["last", "email"]]

df.columns

df.iloc[[0, 1], 2]

df.loc[[0, 1], ["email", "last"]]
