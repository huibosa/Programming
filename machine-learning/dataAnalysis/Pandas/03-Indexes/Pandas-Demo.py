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
import pandas as pd

df = pd.read_csv("../data/survey_results_public.csv", index_col="Respondent")
scheme_df = pd.read_csv("../data/survey_results_schema.csv", index_col="Column")

pd.set_option("display.max_columns", 85)
pd.set_option("display.max_rows", 85)
# -

df.head()

scheme_df

scheme_df.loc["MgrIdiot", "QuestionText"]

scheme_df.sort_index(ascending=False, inplace=True)
scheme_df
