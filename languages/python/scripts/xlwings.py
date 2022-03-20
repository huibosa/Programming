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

import xlwings as xw

wb = xw.Book()    # create a new book    

# sht = wb.sheets['Sheet1'] # instantiate a sheet object
sht = wb.sheets[0]          # use index to connect sheet

# +
# read sheet value
sht.range('A1').value = 'Foo 1'
sht.range('A1:C3').value = 'Foo 2'
sht.range((1,1)).value = 'Foo 3'
sht.range((1,1), (3,3)) = 'Foo 4'
sht.range('NamedRange') = 'Foo 5'
sht.range(sht.range('A1'), sht.range('B2')).value = 'Foo 6'

sht.range('A1').value = [['Foo 1', 'Foo 2', 'Foo 3'], [10.0, 20.0, 30.0]]
sht.range('A1').expand().value

# +
import pandas as pd

df = pd.DataFrame([[1,2], [3,4]], columns=['a', 'b'])
sht.range('A1').value = df
sht.range('A1').options(pd.DataFrame, expand='table').value
# -

import matplotlib.pyplot as plt
fig = plt.figure()
plt.plot([1, 2, 3, 4, 5])
sht.pictures.add(fig, name='Myplot', update=True)
