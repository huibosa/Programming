#!/usr/bin/env python3

from sklearn.tree import DecisionTreeRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
import pandas as pd


def get_mae(max_leaf_nodes, train_X, val_X, train_y, val_y):
    model = DecisionTreeRegressor(max_leaf_nodes=max_leaf_nodes, random_state=0)
    model.fit(train_X, train_y)
    val_predictions = model.predict(val_X)

    mae = mean_absolute_error(val_y, val_predictions)
    return mae


path = "./data/melb_data.csv"
data = pd.read_csv(path)

y = data["Price"]
features = ["Rooms", "Bathroom", "Landsize", "Lattitude", "Longtitude"]
X = data[features]

train_X, val_X, train_y, val_y = train_test_split(X, y, random_state=0)

candidate_max_leaf_size = [5, 50, 100, 250, 500, 5000]

# for max_leaf_nodes in candidate_max_leaf_size:
#     my_mae = get_mae(max_leaf_nodes, train_X, val_X, train_y, val_y)
#     print('Max leaf nodes: %d \t\t Mean AbsoluteError:  %d' %(max_leaf_nodes, my_mae))

scores = {
    leaf_size: get_mae(leaf_size, train_X, val_X, train_y, val_y)
    for leaf_size in candidate_max_leaf_size
}

best_tree_size = min(scores, key=scores.get)
print(best_tree_size)
