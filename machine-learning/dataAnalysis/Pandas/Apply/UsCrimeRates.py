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
#     display_name: 'Python 3.9.7 64-bit (''DataAnalysis'': venv)'
#     name: python3
# ---

import pandas as pd
import numpy as np

crime = pd.read_csv("../data/US_Crime_Rates_1960_2014.csv")
crime.head()

crime.info()

crime["Year"] = pd.to_datetime(crime["Year"], format="%Y")
crime.info()

crime = crime.set_index("Year", drop=True)
crime.head()

crime.drop("Total", axis=1, inplace=True)
crime.head()

# +
crimes = crime.resample("10AS").sum()

population = crime["Population"].resample("10AS").max()

crimes["Population"] = population

crimes
# -

crime.idxmax()
