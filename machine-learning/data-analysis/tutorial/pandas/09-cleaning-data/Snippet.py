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
import numpy as np

people = {
    "first": ["Corey", "Jane", "John", "Chris", np.nan, None, "NA"],
    "last": ["Schafer", "Doe", "Doe", "Schafer", np.nan, np.nan, "Missing"],
    "email": [
        "CoreyMSchafer@gmail.com",
        "JaneDoe@email.com",
        "JohnDoe@email.com",
        None,
        np.nan,
        "Anonymous@email.com",
        "NA",
    ],
    "age": ["33", "55", "63", "36", None, None, "Missing"],
}

# +
df = pd.DataFrame(people)

df.replace("NA", np.nan, inplace=True)
df.replace("Missing", np.nan, inplace=True)
# -

df

df.dropna()
# default arguments
df.dropna(axis="index", how="any")

df.dropna(axis="index", how="all")
# df.dropna(axis='columns', how='any')

df.dropna(axis="index", how="all", subset=["email", "last"])

df.isna()

df.fillna("MISSING")

df.dtypes

df["age"].mean()

df["age"] = df["age"].astype(float)

df.dtypes

df["age"].mean()
