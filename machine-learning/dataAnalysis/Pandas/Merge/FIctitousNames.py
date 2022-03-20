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

# +
raw_data_1 = {
    "subject_id": ["1", "2", "3", "4", "5"],
    "first_name": ["Alex", "Amy", "Allen", "Alice", "Ayoung"],
    "last_name": ["Anderson", "Ackerman", "Ali", "Aoni", "Atiches"],
}

raw_data_2 = {
    "subject_id": ["4", "5", "6", "7", "8"],
    "first_name": ["Billy", "Brian", "Bran", "Bryce", "Betty"],
    "last_name": ["Bonder", "Black", "Balwner", "Brice", "Btisan"],
}

raw_data_3 = {
    "subject_id": ["1", "2", "3", "4", "5", "7", "8", "9", "10", "11"],
    "test_id": [51, 15, 15, 61, 16, 14, 15, 1, 61, 16],
}
# -

data1 = pd.DataFrame(raw_data_1, columns=["subject_id", "first_name", "last_name"])
data2 = pd.DataFrame(raw_data_2, columns=["subject_id", "first_name", "last_name"])
data3 = pd.DataFrame(raw_data_3, columns=["subject_id", "test_id"])

all_data = pd.concat([data1, data2])
all_data

all_data_col = pd.concat([data1, data2], axis=1)
all_data_col

pd.merge(all_data, data3, on="subject_id")

pd.merge(data1, data2, on="subject_id", how="inner")

pd.merge(data1, data2, on="subject_id", how="outer")
