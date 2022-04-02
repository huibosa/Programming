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
des = "/backup/data/pass17"

sensorPaths = []  ## store every sensors' path

for path, dirs, fnames in os.walk(des):
    for fname in fnames:
        if "sensors" in fname:
            sensorPaths.append(os.path.join(des, fname))


init = pd.DataFrame()  # dataframe for initial sensor info
final = pd.DataFrame()  # dataframe for final sensor info

for sensor in sensorPaths:  ## 0 to get init status, -1 to get final status
    temp = pd.read_csv(sensor)
    init = init.append(temp.iloc[0])
    final = final.append(temp.iloc[-1])

init.reset_index(inplace=True)
final.reset_index(inplace=True)
# -

# ## 2D Initial sensors distribution

plt.figure(figsize=(7, 8.5), dpi=80)
x = init["Z"]
y = init["X"]
plt.scatter(x, y)
plt.scatter(init.loc[258, "Z"], init.loc[258, "X"])
# plt.scatter(y, -x)
# plt.scatter(init.loc[258, 'X'], -init.loc[258, 'Z'])

# ## 2D Final Sensor Distribution

x = final["Z"]
y = final["X"]
plt.scatter(y, x)
plt.scatter(final.loc[258, "X"], final.loc[258, "Z"])

# ## 3D Initial sensors distribution

# +
x = init["Z"]
y = init["X"]
z = init["Y"]

ax = plt.axes(projection="3d")
ax.scatter3D(x, y, z)

# +
x = final["Z"]
y = final["X"]
z = final["Y"]

ax = plt.axes(projection="3d")
ax.scatter3D(x, y, z)
