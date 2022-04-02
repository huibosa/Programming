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

df["ConvertedComp"].median()

df.median()

df.describe()

df["ConvertedComp"].describe()

df["ConvertedComp"].count()

df["Hobbyist"].value_counts()

df["SocialMedia"]
scheme_df.loc["SocialMedia"]

df["SocialMedia"].value_counts()

df["SocialMedia"].value_counts(normalize=True)

df["Country"].value_counts()

filt = df["Country"] == "India"
# df.loc[filt]['SocialMedia'].value_counts()
df[filt]["SocialMedia"].value_counts()

country_group = df.groupby(["Country"])
country_group.get_group("United States")

country_group["SocialMedia"].value_counts(normalize=True).loc["United States"]

country_group["ConvertedComp"].median().loc["Germany"]

country_group["ConvertedComp"].agg(["median", "mean"]).loc["Canada"]

filt = df["Country"] == "India"
df.loc[filt]["LanguageWorkedWith"].str.contains("Python").sum()

# country_group['LanguageWorkedWith'].str.contains('Python').sum()
country_group["LanguageWorkedWith"].apply(lambda x: x.str.contains("Python").sum())

country_respondents = df["Country"].value_counts()
country_respondents

country_use_python = country_group["LanguageWorkedWith"].apply(
    lambda x: x.str.contains("Python").sum()
)
country_use_python

python_df = pd.concat([country_respondents, country_use_python], axis="columns")
python_df

python_df.rename(
    columns={"Country": "NumRespondents", "LanguageWorkedWith": "NumKnowsPython"},
    inplace=True,
)
python_df

python_df["PctKnowsPython"] = (
    python_df["NumKnowsPython"] / python_df["NumRespondents"]
) * 100
python_df

python_df.sort_values(by="PctKnowsPython", ascending=False, inplace=True)
python_df.head(50)

python_df.loc["Japan"]
