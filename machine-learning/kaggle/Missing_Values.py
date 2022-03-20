#!/usr/bin/env python3

import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split

path = "./data/melb_data.csv"
data = pd.read_csv(path)

features = ["Rooms", "Bathroom", "Landsize", "Lattitude", "Longtitude"]
X = data[features]
y = data["Price"]
train_X, val_X, train_y, val_y = train_test_split(X, y, random_state=0)

model = RandomForestRegressor(random_state=1)
model.fit(train_X, train_y)
preds = model.predict(val_X)
print(mean_absolute_error(val_y, preds))
