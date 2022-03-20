#!/usr/bin/env python3

import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.impute import SimpleImputer


def score_dataset(X_train, X_val, y_train, y_val):
    model = RandomForestRegressor(n_estimators=10, random_state=0)
    model.fit(X_train, y_train)
    preds = model.predict(X_val)
    return mean_absolute_error(y_val, preds)


path = "./data/melb_data.csv"
data = pd.read_csv(path)
y = data["Price"]
X = data.select_dtypes(exclude=["object"])

X_train, X_valid, y_train, y_valid = train_test_split(
    X, y, train_size=0.8, test_size=0.2, random_state=1
)

null_cols = [col for col in X_train.columns if X_train[col].isnull().any()]


# imputation
my_imputer = SimpleImputer()
imputed_X_train = pd.DataFrame(my_imputer.fit_transform(X_train))
imputed_X_valid = pd.DataFrame(my_imputer.fit_transform(X_valid))

# imputation removed column names; put them back
imputed_X_train.columns = X_train.columns
imputed_X_valid.columns = X_valid.columns


############## Extension to imputation ##############
X_train_plus = X_train.copy()
X_valid_plus = X_valid.copy()

for col in null_cols:
    X_train_plus[col + "_was_missing"] = X_train_plus[col].isnull()
    X_valid_plus[col + "_was_missing"] = X_valid_plus[col].isnull()

my_imputer = SimpleImputer()
imputed_X_train_plus = pd.DataFrame(my_imputer.fit_transform(X_train_plus))
imputed_X_valid_plus = pd.DataFrame(my_imputer.fit_transform(X_valid_plus))

# imputation removed column names: put them back
imputed_X_train_plus.columns = X_train_plus.columns
imputed_X_valid_plus.columns = X_valid_plus.columns

print(score_dataset(imputed_X_train, imputed_X_valid, y_train, y_valid))
