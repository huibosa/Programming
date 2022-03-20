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
#     display_name: Python 3
#     language: python
#     name: python3
# ---

# + [markdown] deletable=true editable=true
# # Introduction to Modeling Libraries

# + deletable=true editable=true
import numpy as np
import pandas as pd

np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
PREVIOUS_MAX_ROWS = pd.options.display.max_rows
pd.options.display.max_rows = 20
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## Interfacing Between pandas and Model Code

# + deletable=true editable=true
import pandas as pd
import numpy as np

data = pd.DataFrame(
    {
        "x0": [1, 2, 3, 4, 5],
        "x1": [0.01, -0.01, 0.25, -4.1, 0.0],
        "y": [-1.5, 0.0, 3.6, 1.3, -2.0],
    }
)
data
data.columns
data.values

# + deletable=true editable=true
df2 = pd.DataFrame(data.values, columns=["one", "two", "three"])
df2

# + deletable=true editable=true
model_cols = ["x0", "x1"]
data.loc[:, model_cols].values

# + deletable=true editable=true
data["category"] = pd.Categorical(["a", "b", "a", "a", "b"], categories=["a", "b"])
data

# + deletable=true editable=true
dummies = pd.get_dummies(data.category, prefix="category")
data_with_dummies = data.drop("category", axis=1).join(dummies)
data_with_dummies

# + [markdown] deletable=true editable=true
# ## Creating Model Descriptions with Patsy

# + [markdown] deletable=true editable=true
# y ~ x0 + x1

# + deletable=true editable=true
data = pd.DataFrame(
    {
        "x0": [1, 2, 3, 4, 5],
        "x1": [0.01, -0.01, 0.25, -4.1, 0.0],
        "y": [-1.5, 0.0, 3.6, 1.3, -2.0],
    }
)
data
import patsy

y, X = patsy.dmatrices("y ~ x0 + x1", data)

# + deletable=true editable=true
y
X

# + deletable=true editable=true
np.asarray(y)
np.asarray(X)

# + deletable=true editable=true
patsy.dmatrices("y ~ x0 + x1 + 0", data)[1]

# + deletable=true editable=true
coef, resid, _, _ = np.linalg.lstsq(X, y)

# + deletable=true editable=true
coef
coef = pd.Series(coef.squeeze(), index=X.design_info.column_names)
coef

# + [markdown] deletable=true editable=true
# ### Data Transformations in Patsy Formulas

# + deletable=true editable=true
y, X = patsy.dmatrices("y ~ x0 + np.log(np.abs(x1) + 1)", data)
X

# + deletable=true editable=true
y, X = patsy.dmatrices("y ~ standardize(x0) + center(x1)", data)
X

# + deletable=true editable=true
new_data = pd.DataFrame(
    {"x0": [6, 7, 8, 9], "x1": [3.1, -0.5, 0, 2.3], "y": [1, 2, 3, 4]}
)
new_X = patsy.build_design_matrices([X.design_info], new_data)
new_X

# + deletable=true editable=true
y, X = patsy.dmatrices("y ~ I(x0 + x1)", data)
X

# + [markdown] deletable=true editable=true
# ### Categorical Data and Patsy

# + deletable=true editable=true
data = pd.DataFrame(
    {
        "key1": ["a", "a", "b", "b", "a", "b", "a", "b"],
        "key2": [0, 1, 0, 1, 0, 1, 0, 0],
        "v1": [1, 2, 3, 4, 5, 6, 7, 8],
        "v2": [-1, 0, 2.5, -0.5, 4.0, -1.2, 0.2, -1.7],
    }
)
y, X = patsy.dmatrices("v2 ~ key1", data)
X

# + deletable=true editable=true
y, X = patsy.dmatrices("v2 ~ key1 + 0", data)
X

# + deletable=true editable=true
y, X = patsy.dmatrices("v2 ~ C(key2)", data)
X

# + deletable=true editable=true
data["key2"] = data["key2"].map({0: "zero", 1: "one"})
data
y, X = patsy.dmatrices("v2 ~ key1 + key2", data)
X
y, X = patsy.dmatrices("v2 ~ key1 + key2 + key1:key2", data)
X

# + [markdown] deletable=true editable=true
# ## Introduction to statsmodels

# + [markdown] deletable=true editable=true
# ### Estimating Linear Models

# + deletable=true editable=true
import statsmodels.api as sm
import statsmodels.formula.api as smf


# + deletable=true editable=true
def dnorm(mean, variance, size=1):
    if isinstance(size, int):
        size = (size,)
    return mean + np.sqrt(variance) * np.random.randn(*size)


# For reproducibility
np.random.seed(12345)

N = 100
X = np.c_[dnorm(0, 0.4, size=N), dnorm(0, 0.6, size=N), dnorm(0, 0.2, size=N)]
eps = dnorm(0, 0.1, size=N)
beta = [0.1, 0.3, 0.5]

y = np.dot(X, beta) + eps

# + deletable=true editable=true
X[:5]
y[:5]

# + deletable=true editable=true
X_model = sm.add_constant(X)
X_model[:5]

# + deletable=true editable=true
model = sm.OLS(y, X)

# + deletable=true editable=true
results = model.fit()
results.params

# + deletable=true editable=true
print(results.summary())

# + deletable=true editable=true
data = pd.DataFrame(X, columns=["col0", "col1", "col2"])
data["y"] = y
data[:5]

# + deletable=true editable=true
results = smf.ols("y ~ col0 + col1 + col2", data=data).fit()
results.params
results.tvalues

# + deletable=true editable=true
results.predict(data[:5])

# + [markdown] deletable=true editable=true
# ### Estimating Time Series Processes

# + deletable=true editable=true
init_x = 4

import random

values = [init_x, init_x]
N = 1000

b0 = 0.8
b1 = -0.4
noise = dnorm(0, 0.1, N)
for i in range(N):
    new_x = values[-1] * b0 + values[-2] * b1 + noise[i]
    values.append(new_x)

# + deletable=true editable=true
MAXLAGS = 5
model = sm.tsa.AR(values)
results = model.fit(MAXLAGS)

# + deletable=true editable=true
results.params

# + [markdown] deletable=true editable=true
# ## Introduction to scikit-learn

# + deletable=true editable=true
train = pd.read_csv("datasets/titanic/train.csv")
test = pd.read_csv("datasets/titanic/test.csv")
train[:4]

# + deletable=true editable=true
train.isnull().sum()
test.isnull().sum()

# + deletable=true editable=true
impute_value = train["Age"].median()
train["Age"] = train["Age"].fillna(impute_value)
test["Age"] = test["Age"].fillna(impute_value)

# + deletable=true editable=true
train["IsFemale"] = (train["Sex"] == "female").astype(int)
test["IsFemale"] = (test["Sex"] == "female").astype(int)

# + deletable=true editable=true
predictors = ["Pclass", "IsFemale", "Age"]
X_train = train[predictors].values
X_test = test[predictors].values
y_train = train["Survived"].values
X_train[:5]
y_train[:5]

# + deletable=true editable=true
from sklearn.linear_model import LogisticRegression

model = LogisticRegression()

# + deletable=true editable=true
model.fit(X_train, y_train)

# + deletable=true editable=true
y_predict = model.predict(X_test)
y_predict[:10]

# + [markdown] deletable=true editable=true
# (y_true == y_predict).mean()

# + deletable=true editable=true
from sklearn.linear_model import LogisticRegressionCV

model_cv = LogisticRegressionCV(10)
model_cv.fit(X_train, y_train)

# + deletable=true editable=true
from sklearn.model_selection import cross_val_score

model = LogisticRegression(C=10)
scores = cross_val_score(model, X_train, y_train, cv=4)
scores

# + [markdown] deletable=true editable=true
# ## Continuing Your Education

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS
