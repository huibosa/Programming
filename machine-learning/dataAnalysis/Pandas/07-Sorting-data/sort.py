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

df = pd.read_csv("./data/survey_results_public.csv", index_col="Respondent")
scheme_df = pd.read_csv("./data/survey_results_schema.csv", index_col="Column")

pd.set_option("display.max_columns", 85)
pd.set_option("display.max_rows", 85)

df.sort_values(by=["Country", "ConvertedComp"], ascending=[True, False], inplace=True)

df[["Country", "ConvertedComp"]].head(50)

df["ConvertedComp"].nlargest(10)

df.nlargest(10, "ConvertedComp")

df.nsmallest(10, "ConvertedComp")
