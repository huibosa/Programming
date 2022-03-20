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

# # This file deals with the start and end situation of all sensors in one pass.

import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import os

# ## Get initial and final status of sensors

# +
des = "/backup/data/Pass01"

sensorPaths = []  ## store every sensors' path

for path, dirs, fnames in os.walk(des):
    for fname in fnames:
        if "sensors" in fname:
            sensorPaths.append(os.path.join(des, fname))
# dataframe to store sensor info
init = pd.DataFrame()
final = pd.DataFrame()

for sensor in sensorPaths:  ## 0 to get init status, -1 to get final status
    temp = pd.read_csv(sensor)
    init = init.append(temp.iloc[0])
    final = final.append(temp.iloc[-1])
# -

init.reset_index(inplace=True)
init.head()

filt = init["Z"] < -190
init[filt].sort_values("X", ascending=True)

filt = init["Z"] < 15
init[filt].sort_values(by="Z", ascending=False).head(20)

init["X"].median()
