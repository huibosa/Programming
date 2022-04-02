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

# +
from matplotlib import pyplot as plt

plt.style.use("fivethirtyeight")

# +

slices = [120, 80, 30, 20]
labels = ["Sixty", "Forty", "Extra1", "Extra2"]
colors = ["blue", "red", "yellow"]

plt.pie(slices, labels=labels, colors=colors, wedgeprops={"edgecolor": "black"})

plt.title("My Awesome Pie Chart")
plt.tight_layout()
plt.show()

# +
slices = [59219, 55466, 47544, 36443, 35917]
labels = ["JavaScript", "HTML/CSS", "SQL", "Python", "Java"]
explode = [0, 0, 0, 0.1, 0]

plt.pie(
    slices,
    labels=labels,
    explode=explode,
    shadow=True,
    startangle=90,
    autopct="%1.1f%%",
    wedgeprops={"edgecolor": "black"},
)
plt.title("My Awesome Pie Chart")
plt.tight_layout()
plt.show()
