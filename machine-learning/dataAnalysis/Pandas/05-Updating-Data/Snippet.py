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

df.columns

df.columns = ["first_name", "last_name", "email"]
df

df.columns = [x.lower() for x in df.columns]
df

df.columns = df.columns.str.lower()
df

df.columns = df.columns.str.replace(" ", "_")

df.rename(columns={"first_name": "first", "last_name": "last"}, inplace=True)

df.loc[2] = ["John", "Smith", "JohnSmith@email.com"]

df.loc[2, ["last", "email"]] = ["Doe", "JohnDoe@email.com"]

df

# df.at[2, 'last'] = 'Doe'
df.loc[2, "last"] = "Doe"
df

filt = df["email"] == "JohnDoe@email.com"
df[filt]["last"] = "Smith"

filt = df["email"] == "JohnDoe@email.com"
df.loc[filt, "last"] = "Smith"

df["email"] = df["email"].str.lower()
df

df["email"].apply(len)


def update_email(email):
    return email.upper()


df["email"] = df["email"].apply(update_email)
df

df["email"] = df["email"].apply(lambda x: x.lower())
df

# apply to each series, 'rows' is the default
df.apply(len)

df.apply(len, axis="columns")

df.apply(pd.Series.min)

df.apply(lambda x: x.min())

df.applymap(len)

df.applymap(str.lower)

df["first"].map({"Corey": "Chris", "Jane": "Mary"})

df["first"] = df["first"].replace({"Corey": "Chris", "Jane": "Mary"})
df
