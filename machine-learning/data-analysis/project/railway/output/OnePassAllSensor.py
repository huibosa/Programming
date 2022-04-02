#!/usr/bin/env python


import pandas as pd
import matplotlib.pyplot as plt
import os


def getResultDirs(source):
    paths = []

    for i in range(1, 18):
        s = str(i)

        if len(s) == 1:
            path = os.path.join(source, "0", s)
        else:
            path = os.path.join(source, s)

        paths.append(path)

    return paths


def getSensorPaths(path):
    paths = []

    for path, _, fnames in os.walk(path):
        for fname in fnames:
            if "sensors" in fname:
                paths.append(os.path.join(path, fname))

    return paths


paths = getResultDirs("/backup/data/pass")
sensorPaths = []  ## store every sensors' path

for path in paths:
    sensorPaths.append(getSensorPaths(path))


init = pd.DataFrame()  # dataframe for initial sensor info
final = pd.DataFrame()  # dataframe for final sensor info

for sensor in sensorPaths:  ## 0 to get init status, -1 to get final status
    temp = pd.read_csv(sensor)
    init = init.append(temp.iloc[0])
    final = final.append(temp.iloc[-1])

init.reset_index(inplace=True)
final.reset_index(inplace=True)

# ## 2D Initial sensors distribution

plt.figure(figsize=(7, 8.5), dpi=80)
x = init["Z"]
y = init["X"]
plt.scatter(y, x)
plt.scatter(init.loc[258, "X"], init.loc[258, "Z"])
plt.show()

# ## 2D Final Sensor Distribution

# x = final['Z']
# y = final['X']
# plt.scatter(y, x)
# plt.scatter(final.loc[258, 'X'], final.loc[258, 'Z'])
