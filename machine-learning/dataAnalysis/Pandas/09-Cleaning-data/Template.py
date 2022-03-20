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

na_vals = ["NA", "Missing"]
df = pd.read_csv(
    "../data/survey_results_public.csv", index_col="Respondent", na_values=na_vals
)
scheme_df = pd.read_csv("../data/survey_results_schema.csv", index_col="Column")

pd.set_option("display.max_columns", 85)
pd.set_option("display.max_rows", 85)

df.head()

df["YearsCode"].unique()


df["YearsCode"].replace("Less than 1 year", 0, inplace=True)
df["YearsCode"].replace("More than 50 years", 51, inplace=True)

df["YearsCode"] = df["YearsCode"].astype(float)

df["YearsCode"].mean()

df["YearsCode"].median()
