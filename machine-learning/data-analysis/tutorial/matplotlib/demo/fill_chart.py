# -*- coding: utf-8 -*-
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

df = pd.read_excel("./data.xlsx", index_col="X")

df.head()

df["差值"] = df["测量值"] - df["计算值"]
df.head()
df.T
