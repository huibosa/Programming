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

df = pd.read_csv("../data/survey_results_public.csv", index_col="Respondent")
scheme_df = pd.read_csv("../data/survey_results_schema.csv", index_col="Column")

pd.set_option("display.max_columns", 85)
pd.set_option("display.max_rows", 85)

df.head()

filt = df["Country"] == "India"
india_df = df.loc[filt]
india_df.head()

india_df.to_csv("../data/modified.csv")

india_df.to_csv("../data/modified.tsv", sep="\t")

india_df.to_excel("../data/modified.xlsx")

test = pd.read_excel("../data/modified.xlsx", index_col="Respondent")

test.head()

india_df.to_json("../data/modified.json")
