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

s1 = pd.Series(np.random.randint(1, high=5, size=100, dtype="l"))
s2 = pd.Series(np.random.randint(1, high=4, size=100, dtype="l"))
s3 = pd.Series(np.random.randint(1000, high=30001, size=100, dtype="l"))

housemkt = pd.concat([s1, s2, s3], axis=1)
housemkt.head()

housemkt.rename(columns={0: "bedrs", 1: "bathrs", 2: "price_sqr_meter"}, inplace=True)
housemkt.head()

# +
bigColumn = pd.concat([s1, s2, s3], axis=0)

bigColumn = bigColumn.to_frame()

bigColumn.head()
# -

bigColumn.reset_index(drop=True, inplace=True)
bigColumn
