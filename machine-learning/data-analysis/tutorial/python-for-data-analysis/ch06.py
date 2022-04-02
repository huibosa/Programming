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
# # Data Loading, Storage,

# + deletable=true editable=true
import numpy as np
import pandas as pd

np.random.seed(12345)
import matplotlib.pyplot as plt

plt.rc("figure", figsize=(10, 6))
np.set_printoptions(precision=4, suppress=True)

# + [markdown] deletable=true editable=true
# ## Reading and Writing Data in Text Format

# + deletable=true editable=true
# !cat examples/ex1.csv

# + deletable=true editable=true
df = pd.read_csv("examples/ex1.csv")
df

# + deletable=true editable=true
pd.read_table("examples/ex1.csv", sep=",")

# + deletable=true editable=true
# !cat examples/ex2.csv

# + deletable=true editable=true
pd.read_csv("examples/ex2.csv", header=None)
pd.read_csv("examples/ex2.csv", names=["a", "b", "c", "d", "message"])

# + deletable=true editable=true
names = ["a", "b", "c", "d", "message"]
pd.read_csv("examples/ex2.csv", names=names, index_col="message")

# + deletable=true editable=true
# !cat examples/csv_mindex.csv
parsed = pd.read_csv("examples/csv_mindex.csv", index_col=["key1", "key2"])
parsed

# + deletable=true editable=true
list(open("examples/ex3.txt"))

# + deletable=true editable=true
result = pd.read_table("examples/ex3.txt", sep="\s+")
result

# + deletable=true editable=true
# !cat examples/ex4.csv
pd.read_csv("examples/ex4.csv", skiprows=[0, 2, 3])

# + deletable=true editable=true
# !cat examples/ex5.csv
result = pd.read_csv("examples/ex5.csv")
result
pd.isnull(result)

# + deletable=true editable=true
result = pd.read_csv("examples/ex5.csv", na_values=["NULL"])
result

# + deletable=true editable=true
sentinels = {"message": ["foo", "NA"], "something": ["two"]}
pd.read_csv("examples/ex5.csv", na_values=sentinels)

# + [markdown] deletable=true editable=true
# ### Reading Text Files in Pieces

# + deletable=true editable=true
pd.options.display.max_rows = 10

# + deletable=true editable=true
result = pd.read_csv("examples/ex6.csv")
result

# + deletable=true editable=true
pd.read_csv("examples/ex6.csv", nrows=5)

# + deletable=true editable=true
chunker = pd.read_csv("examples/ex6.csv", chunksize=1000)
chunker

# + deletable=true editable=true
chunker = pd.read_csv("examples/ex6.csv", chunksize=1000)

tot = pd.Series([])
for piece in chunker:
    tot = tot.add(piece["key"].value_counts(), fill_value=0)

tot = tot.sort_values(ascending=False)

# + deletable=true editable=true
tot[:10]

# + [markdown] deletable=true editable=true
# ### Writing Data to Text Format

# + deletable=true editable=true
data = pd.read_csv("examples/ex5.csv")
data

# + deletable=true editable=true
data.to_csv("examples/out.csv")
# !cat examples/out.csv

# + deletable=true editable=true
import sys

data.to_csv(sys.stdout, sep="|")

# + deletable=true editable=true
data.to_csv(sys.stdout, na_rep="NULL")

# + deletable=true editable=true
data.to_csv(sys.stdout, index=False, header=False)

# + deletable=true editable=true
data.to_csv(sys.stdout, index=False, columns=["a", "b", "c"])

# + deletable=true editable=true
dates = pd.date_range("1/1/2000", periods=7)
ts = pd.Series(np.arange(7), index=dates)
ts.to_csv("examples/tseries.csv")
# !cat examples/tseries.csv

# + [markdown] deletable=true editable=true
# ### Working with Delimited Formats

# + deletable=true editable=true
# !cat examples/ex7.csv

# + deletable=true editable=true
import csv

f = open("examples/ex7.csv")

reader = csv.reader(f)

# + deletable=true editable=true
for line in reader:
    print(line)

# + deletable=true editable=true
with open("examples/ex7.csv") as f:
    lines = list(csv.reader(f))

# + deletable=true editable=true
header, values = lines[0], lines[1:]

# + deletable=true editable=true
data_dict = {h: v for h, v in zip(header, zip(*values))}
data_dict

# + [markdown] deletable=true editable=true
# class my_dialect(csv.Dialect):
#     lineterminator = '\n'
#     delimiter = ';'
#     quotechar = '"'
#     quoting = csv.QUOTE_MINIMAL

# + [markdown] deletable=true editable=true
# reader = csv.reader(f, dialect=my_dialect)

# + [markdown] deletable=true editable=true
# reader = csv.reader(f, delimiter='|')

# + [markdown] deletable=true editable=true
# with open('mydata.csv', 'w') as f:
#     writer = csv.writer(f, dialect=my_dialect)
#     writer.writerow(('one', 'two', 'three'))
#     writer.writerow(('1', '2', '3'))
#     writer.writerow(('4', '5', '6'))
#     writer.writerow(('7', '8', '9'))

# + [markdown] deletable=true editable=true
# ### JSON Data

# + deletable=true editable=true
obj = """
{"name": "Wes",
 "places_lived": ["United States", "Spain", "Germany"],
 "pet": null,
 "siblings": [{"name": "Scott", "age": 30, "pets": ["Zeus", "Zuko"]},
              {"name": "Katie", "age": 38,
               "pets": ["Sixes", "Stache", "Cisco"]}]
}
"""

# + deletable=true editable=true
import json

result = json.loads(obj)
result

# + deletable=true editable=true
asjson = json.dumps(result)

# + deletable=true editable=true
siblings = pd.DataFrame(result["siblings"], columns=["name", "age"])
siblings

# + deletable=true editable=true
# !cat examples/example.json

# + deletable=true editable=true
data = pd.read_json("examples/example.json")
data

# + deletable=true editable=true
print(data.to_json())
print(data.to_json(orient="records"))

# + [markdown] deletable=true editable=true
# ### XML and HTML: Web Scraping

# + [markdown] deletable=true editable=true
# conda install lxml
# pip install beautifulsoup4 html5lib

# + deletable=true editable=true
tables = pd.read_html("examples/fdic_failed_bank_list.html")
len(tables)
failures = tables[0]
failures.head()

# + deletable=true editable=true
close_timestamps = pd.to_datetime(failures["Closing Date"])
close_timestamps.dt.year.value_counts()

# + [markdown] deletable=true editable=true
# #### Parsing XML with lxml.objectify

# + [markdown] deletable=true editable=true
# <INDICATOR>
#   <INDICATOR_SEQ>373889</INDICATOR_SEQ>
#   <PARENT_SEQ></PARENT_SEQ>
#   <AGENCY_NAME>Metro-North Railroad</AGENCY_NAME>
#   <INDICATOR_NAME>Escalator Availability</INDICATOR_NAME>
#   <DESCRIPTION>Percent of the time that escalators are operational
#   systemwide. The availability rate is based on physical observations performed
#   the morning of regular business days only. This is a new indicator the agency
#   began reporting in 2009.</DESCRIPTION>
#   <PERIOD_YEAR>2011</PERIOD_YEAR>
#   <PERIOD_MONTH>12</PERIOD_MONTH>
#   <CATEGORY>Service Indicators</CATEGORY>
#   <FREQUENCY>M</FREQUENCY>
#   <DESIRED_CHANGE>U</DESIRED_CHANGE>
#   <INDICATOR_UNIT>%</INDICATOR_UNIT>
#   <DECIMAL_PLACES>1</DECIMAL_PLACES>
#   <YTD_TARGET>97.00</YTD_TARGET>
#   <YTD_ACTUAL></YTD_ACTUAL>
#   <MONTHLY_TARGET>97.00</MONTHLY_TARGET>
#   <MONTHLY_ACTUAL></MONTHLY_ACTUAL>
# </INDICATOR>

# + deletable=true editable=true
from lxml import objectify

path = "datasets/mta_perf/Performance_MNR.xml"
parsed = objectify.parse(open(path))
root = parsed.getroot()

# + deletable=true editable=true
data = []

skip_fields = ["PARENT_SEQ", "INDICATOR_SEQ", "DESIRED_CHANGE", "DECIMAL_PLACES"]

for elt in root.INDICATOR:
    el_data = {}
    for child in elt.getchildren():
        if child.tag in skip_fields:
            continue
        el_data[child.tag] = child.pyval
    data.append(el_data)

# + deletable=true editable=true
perf = pd.DataFrame(data)
perf.head()

# + deletable=true editable=true
from io import StringIO

tag = '<a href="http://www.google.com">Google</a>'
root = objectify.parse(StringIO(tag)).getroot()

# + deletable=true editable=true
root
root.get("href")
root.text

# + [markdown] deletable=true editable=true
# ## Binary Data Formats

# + deletable=true editable=true
frame = pd.read_csv("examples/ex1.csv")
frame
frame.to_pickle("examples/frame_pickle")

# + deletable=true editable=true
pd.read_pickle("examples/frame_pickle")

# + deletable=true editable=true
# !rm examples/frame_pickle

# + [markdown] deletable=true editable=true
# ### Using HDF5 Format

# + deletable=true editable=true
frame = pd.DataFrame({"a": np.random.randn(100)})
store = pd.HDFStore("mydata.h5")
store["obj1"] = frame
store["obj1_col"] = frame["a"]
store

# + deletable=true editable=true
store["obj1"]

# + deletable=true editable=true
store.put("obj2", frame, format="table")
store.select("obj2", where=["index >= 10 and index <= 15"])
store.close()

# + deletable=true editable=true
frame.to_hdf("mydata.h5", "obj3", format="table")
pd.read_hdf("mydata.h5", "obj3", where=["index < 5"])

# + deletable=true editable=true
os.remove("mydata.h5")

# + [markdown] deletable=true editable=true
# ### Reading Microsoft Excel Files

# + deletable=true editable=true
xlsx = pd.ExcelFile("examples/ex1.xlsx")

# + deletable=true editable=true
pd.read_excel(xlsx, "Sheet1")

# + deletable=true editable=true
frame = pd.read_excel("examples/ex1.xlsx", "Sheet1")
frame

# + deletable=true editable=true
writer = pd.ExcelWriter("examples/ex2.xlsx")
frame.to_excel(writer, "Sheet1")
writer.save()

# + deletable=true editable=true
frame.to_excel("examples/ex2.xlsx")

# + deletable=true editable=true
# !rm examples/ex2.xlsx

# + [markdown] deletable=true editable=true
# ## Interacting with Web APIs

# + deletable=true editable=true
import requests

url = "https://api.github.com/repos/pandas-dev/pandas/issues"
resp = requests.get(url)
resp

# + deletable=true editable=true
data = resp.json()
data[0]["title"]

# + deletable=true editable=true
issues = pd.DataFrame(data, columns=["number", "title", "labels", "state"])
issues

# + [markdown] deletable=true editable=true
# ## Interacting with Databases

# + deletable=true editable=true
import sqlite3

query = """
CREATE TABLE test
(a VARCHAR(20), b VARCHAR(20),
 c REAL,        d INTEGER
);"""
con = sqlite3.connect("mydata.sqlite")
con.execute(query)
con.commit()

# + deletable=true editable=true
data = [
    ("Atlanta", "Georgia", 1.25, 6),
    ("Tallahassee", "Florida", 2.6, 3),
    ("Sacramento", "California", 1.7, 5),
]
stmt = "INSERT INTO test VALUES(?, ?, ?, ?)"
con.executemany(stmt, data)
con.commit()

# + deletable=true editable=true
cursor = con.execute("select * from test")
rows = cursor.fetchall()
rows

# + deletable=true editable=true
cursor.description
pd.DataFrame(rows, columns=[x[0] for x in cursor.description])

# + deletable=true editable=true
import sqlalchemy as sqla

db = sqla.create_engine("sqlite:///mydata.sqlite")
pd.read_sql("select * from test", db)

# + deletable=true editable=true
# !rm mydata.sqlite

# + [markdown] deletable=true editable=true
# ## Conclusion
