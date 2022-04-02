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

# # This file deals with one sensor in all passes

import pandas as pd
import matplotlib.pyplot as plt
import os

# ## Store the paths of one particular sensor

# +
target = "/backup/data"

sensorFiles = []
pattern = r"sensors323.csv"  # modify the sensor here

for dirpaths, dirnames, filenames in os.walk(target):
    for fname in filenames:
        if pattern in fname:
            sensorFiles.append(os.path.join(dirpaths, fname))

sensorFiles.sort()

# +
data = pd.DataFrame()  # create an empty dataframe

for item in sensorFiles:
    temp = pd.read_csv(item)  # store one pass
    data = data.append(temp)
# -

data = pd.read_csv(sensorFiles[3])
data.head()

data.reset_index(inplace=True)
plt.plot(data["X"])
