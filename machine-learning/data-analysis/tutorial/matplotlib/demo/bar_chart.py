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

import numpy as np
from matplotlib import pyplot as plt

plt.style.use("fivethirtyeight")

# +
ages_x = [25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35]
x_indexes = np.arange(len(ages_x))
wd = 0.25

dev_y = [38496, 42000, 46752, 49320, 53200, 56000, 62316, 64928, 67317, 68748, 73752]
plt.bar(x_indexes - wd, dev_y, width=wd, color="#444444", label="All Devs")

py_dev_y = [45372, 48876, 53850, 57287, 63016, 65998, 70003, 70000, 71496, 75370, 83640]
plt.bar(x_indexes, py_dev_y, width=wd, color="#008fd5", label="Python")

js_dev_y = [37810, 43515, 46823, 49293, 53437, 56373, 62375, 66674, 68745, 68746, 74583]
plt.bar(x_indexes + wd, js_dev_y, width=wd, color="#e5ae38", label="JavaScript")

plt.legend()
plt.xticks(ticks=x_indexes, labels=ages_x)
plt.title("Median Salary (USD) by Age")
plt.xlabel("Ages")
plt.ylabel("Median Salary (USD)")

# plt.tight_layout()

plt.show()

# +
# import csv
import pandas as pd
from collections import Counter

# with open('./data.csv') as csvFile:
#     csvReader = csv.DictReader(csvFile)

data = pd.read_csv("./data.csv")
ids = data["Responder_id"]
lang_responses = data["LanguagesWorkedWith"]

languageCounter = Counter()

for response in lang_responses:
    languageCounter.update(response.split(";"))

languages = []
popularity = []

for item in languageCounter.most_common(15):
    languages.append(item[0])
    popularity.append(item[1])


languages.reverse()
popularity.reverse()

# plt.bar(languages, popularity)
plt.barh(languages, popularity)

plt.title("Most Popular Languages")
# plt.xlabel('Programming Languages')
plt.xlabel("Number of People Who Use")

plt.grid(False)
plt.tight_layout()
plt.show()
