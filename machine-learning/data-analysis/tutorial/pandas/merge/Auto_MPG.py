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

# +
cars1 = pd.read_csv("../data/cars1.csv")
cars2 = pd.read_csv("../data/cars2.csv")

print(cars1.head())
print(cars2.head())
# -

cars1 = cars1.loc[:, "mpg":"car"]
cars1.head()

print(cars1.shape)
print(cars2.shape)

cars = cars1.append(cars2)
cars

nr_owners = np.random.randint(15000, high=73001, size=398, dtype="l")
nr_owners

cars["owners"] = nr_owners
cars.tail()
