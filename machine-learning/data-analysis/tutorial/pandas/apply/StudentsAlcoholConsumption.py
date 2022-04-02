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

df = pd.read_csv("../data/student-mat.csv")
df.head()

stuAlcoh = df.loc[:, "school":"guardian"]
stuAlcoh.head()

capitalizer = lambda x: x.capitalize()

stuAlcoh["Mjob"].apply(capitalizer)
stuAlcoh["Fjob"].apply(capitalizer)

stuAlcoh.tail()

stuAlcoh["Mjob"] = stuAlcoh["Mjob"].apply(capitalizer)
stuAlcoh["Fjob"] = stuAlcoh["Fjob"].apply(capitalizer)


def majority(x):
    return True if x > 17 else False


stuAlcoh["legal_drinker"] = stuAlcoh["age"].apply(majority)
stuAlcoh.head()


def times10(x):
    if type(x) is int:
        return 10 * x
    return x


stuAlcoh.applymap(times10).head()
