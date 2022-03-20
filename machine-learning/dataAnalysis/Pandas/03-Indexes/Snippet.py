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

# +
import pandas as pd

df = pd.DataFrame(people)
# -

df

df["email"]

df.set_index("email", inplace=True)

df

df.index

df.loc["CoreyMSchafer@gmail.com", "last"]

df.iloc[0]

df.reset_index(inplace=True)
df
