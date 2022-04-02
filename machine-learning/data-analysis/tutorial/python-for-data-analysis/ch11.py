# -*- coding: utf-8 -*-
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
# # Time Series

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
# ## Date and Time Data Types and Tools

# + deletable=true editable=true
from datetime import datetime

now = datetime.now()
now
now.year, now.month, now.day

# + deletable=true editable=true
delta = datetime(2011, 1, 7) - datetime(2008, 6, 24, 8, 15)
delta
delta.days
delta.seconds

# + deletable=true editable=true
from datetime import timedelta

start = datetime(2011, 1, 7)
start + timedelta(12)
start - 2 * timedelta(12)

# + [markdown] deletable=true editable=true
# ### Converting Between String and Datetime

# + deletable=true editable=true
stamp = datetime(2011, 1, 3)
str(stamp)
stamp.strftime("%Y-%m-%d")

# + deletable=true editable=true
value = "2011-01-03"
datetime.strptime(value, "%Y-%m-%d")
datestrs = ["7/6/2011", "8/6/2011"]
[datetime.strptime(x, "%m/%d/%Y") for x in datestrs]

# + deletable=true editable=true
from dateutil.parser import parse

parse("2011-01-03")

# + deletable=true editable=true
parse("Jan 31, 1997 10:45 PM")

# + deletable=true editable=true
parse("6/12/2011", dayfirst=True)

# + deletable=true editable=true
datestrs = ["2011-07-06 12:00:00", "2011-08-06 00:00:00"]
pd.to_datetime(datestrs)

# + deletable=true editable=true
idx = pd.to_datetime(datestrs + [None])
idx
idx[2]
pd.isnull(idx)

# + [markdown] deletable=true editable=true
# ## Time Series Basics

# + deletable=true editable=true
from datetime import datetime

dates = [
    datetime(2011, 1, 2),
    datetime(2011, 1, 5),
    datetime(2011, 1, 7),
    datetime(2011, 1, 8),
    datetime(2011, 1, 10),
    datetime(2011, 1, 12),
]
ts = pd.Series(np.random.randn(6), index=dates)
ts

# + deletable=true editable=true
ts.index

# + deletable=true editable=true
ts + ts[::2]

# + deletable=true editable=true
ts.index.dtype

# + deletable=true editable=true
stamp = ts.index[0]
stamp

# + [markdown] deletable=true editable=true
# ### Indexing, Selection, Subsetting

# + deletable=true editable=true
stamp = ts.index[2]
ts[stamp]

# + deletable=true editable=true
ts["1/10/2011"]
ts["20110110"]

# + deletable=true editable=true
longer_ts = pd.Series(
    np.random.randn(1000), index=pd.date_range("1/1/2000", periods=1000)
)
longer_ts
longer_ts["2001"]

# + deletable=true editable=true
longer_ts["2001-05"]

# + deletable=true editable=true
ts[datetime(2011, 1, 7) :]

# + deletable=true editable=true
ts
ts["1/6/2011":"1/11/2011"]

# + deletable=true editable=true
ts.truncate(after="1/9/2011")

# + deletable=true editable=true
dates = pd.date_range("1/1/2000", periods=100, freq="W-WED")
long_df = pd.DataFrame(
    np.random.randn(100, 4),
    index=dates,
    columns=["Colorado", "Texas", "New York", "Ohio"],
)
long_df.loc["5-2001"]

# + [markdown] deletable=true editable=true
# ### Time Series with Duplicate Indices

# + deletable=true editable=true
dates = pd.DatetimeIndex(["1/1/2000", "1/2/2000", "1/2/2000", "1/2/2000", "1/3/2000"])
dup_ts = pd.Series(np.arange(5), index=dates)
dup_ts

# + deletable=true editable=true
dup_ts.index.is_unique

# + deletable=true editable=true
dup_ts["1/3/2000"]  # not duplicated
dup_ts["1/2/2000"]  # duplicated

# + deletable=true editable=true
grouped = dup_ts.groupby(level=0)
grouped.mean()
grouped.count()

# + [markdown] deletable=true editable=true
# ## Date Ranges, Frequencies, and Shifting

# + deletable=true editable=true
ts
resampler = ts.resample("D")

# + [markdown] deletable=true editable=true
# ### Generating Date Ranges

# + deletable=true editable=true
index = pd.date_range("2012-04-01", "2012-06-01")
index

# + deletable=true editable=true
pd.date_range(start="2012-04-01", periods=20)
pd.date_range(end="2012-06-01", periods=20)

# + deletable=true editable=true
pd.date_range("2000-01-01", "2000-12-01", freq="BM")

# + deletable=true editable=true
pd.date_range("2012-05-02 12:56:31", periods=5)

# + deletable=true editable=true
pd.date_range("2012-05-02 12:56:31", periods=5, normalize=True)

# + [markdown] deletable=true editable=true
# ### Frequencies and Date Offsets

# + deletable=true editable=true
from pandas.tseries.offsets import Hour, Minute

hour = Hour()
hour

# + deletable=true editable=true
four_hours = Hour(4)
four_hours

# + deletable=true editable=true
pd.date_range("2000-01-01", "2000-01-03 23:59", freq="4h")

# + deletable=true editable=true
Hour(2) + Minute(30)

# + deletable=true editable=true
pd.date_range("2000-01-01", periods=10, freq="1h30min")

# + [markdown] deletable=true editable=true
# #### Week of month dates

# + deletable=true editable=true
rng = pd.date_range("2012-01-01", "2012-09-01", freq="WOM-3FRI")
list(rng)

# + [markdown] deletable=true editable=true
# ### Shifting (Leading and Lagging) Data

# + deletable=true editable=true
ts = pd.Series(np.random.randn(4), index=pd.date_range("1/1/2000", periods=4, freq="M"))
ts
ts.shift(2)
ts.shift(-2)

# + [markdown] deletable=true editable=true
# ts / ts.shift(1) - 1

# + deletable=true editable=true
ts.shift(2, freq="M")

# + deletable=true editable=true
ts.shift(3, freq="D")
ts.shift(1, freq="90T")

# + [markdown] deletable=true editable=true
# #### Shifting dates with offsets

# + deletable=true editable=true
from pandas.tseries.offsets import Day, MonthEnd

now = datetime(2011, 11, 17)
now + 3 * Day()

# + deletable=true editable=true
now + MonthEnd()
now + MonthEnd(2)

# + deletable=true editable=true
offset = MonthEnd()
offset.rollforward(now)
offset.rollback(now)

# + deletable=true editable=true
ts = pd.Series(
    np.random.randn(20), index=pd.date_range("1/15/2000", periods=20, freq="4d")
)
ts
ts.groupby(offset.rollforward).mean()

# + deletable=true editable=true
ts.resample("M").mean()

# + [markdown] deletable=true editable=true
# ## Time Zone Handling

# + deletable=true editable=true
import pytz

pytz.common_timezones[-5:]

# + deletable=true editable=true
tz = pytz.timezone("America/New_York")
tz

# + [markdown] deletable=true editable=true
# ### Time Zone Localization and Conversion

# + deletable=true editable=true
rng = pd.date_range("3/9/2012 9:30", periods=6, freq="D")
ts = pd.Series(np.random.randn(len(rng)), index=rng)
ts

# + deletable=true editable=true
print(ts.index.tz)

# + deletable=true editable=true
pd.date_range("3/9/2012 9:30", periods=10, freq="D", tz="UTC")

# + deletable=true editable=true
ts
ts_utc = ts.tz_localize("UTC")
ts_utc
ts_utc.index

# + deletable=true editable=true
ts_utc.tz_convert("America/New_York")

# + deletable=true editable=true
ts_eastern = ts.tz_localize("America/New_York")
ts_eastern.tz_convert("UTC")
ts_eastern.tz_convert("Europe/Berlin")

# + deletable=true editable=true
ts.index.tz_localize("Asia/Shanghai")

# + [markdown] deletable=true editable=true
# ### Operations with Time Zone−Aware Timestamp Objects

# + deletable=true editable=true
stamp = pd.Timestamp("2011-03-12 04:00")
stamp_utc = stamp.tz_localize("utc")
stamp_utc.tz_convert("America/New_York")

# + deletable=true editable=true
stamp_moscow = pd.Timestamp("2011-03-12 04:00", tz="Europe/Moscow")
stamp_moscow

# + deletable=true editable=true
stamp_utc.value
stamp_utc.tz_convert("America/New_York").value

# + deletable=true editable=true
from pandas.tseries.offsets import Hour

stamp = pd.Timestamp("2012-03-12 01:30", tz="US/Eastern")
stamp
stamp + Hour()

# + deletable=true editable=true
stamp = pd.Timestamp("2012-11-04 00:30", tz="US/Eastern")
stamp
stamp + 2 * Hour()

# + [markdown] deletable=true editable=true
# ### Operations Between Different Time Zones

# + deletable=true editable=true
rng = pd.date_range("3/7/2012 9:30", periods=10, freq="B")
ts = pd.Series(np.random.randn(len(rng)), index=rng)
ts
ts1 = ts[:7].tz_localize("Europe/London")
ts2 = ts1[2:].tz_convert("Europe/Moscow")
result = ts1 + ts2
result.index

# + [markdown] deletable=true editable=true
# ## Periods and Period Arithmetic

# + deletable=true editable=true
p = pd.Period(2007, freq="A-DEC")
p

# + deletable=true editable=true
p + 5
p - 2

# + deletable=true editable=true
pd.Period("2014", freq="A-DEC") - p

# + deletable=true editable=true
rng = pd.period_range("2000-01-01", "2000-06-30", freq="M")
rng

# + deletable=true editable=true
pd.Series(np.random.randn(6), index=rng)

# + deletable=true editable=true
values = ["2001Q3", "2002Q2", "2003Q1"]
index = pd.PeriodIndex(values, freq="Q-DEC")
index

# + [markdown] deletable=true editable=true
# ### Period Frequency Conversion

# + deletable=true editable=true
p = pd.Period("2007", freq="A-DEC")
p
p.asfreq("M", how="start")
p.asfreq("M", how="end")

# + deletable=true editable=true
p = pd.Period("2007", freq="A-JUN")
p
p.asfreq("M", "start")
p.asfreq("M", "end")

# + deletable=true editable=true
p = pd.Period("Aug-2007", "M")
p.asfreq("A-JUN")

# + deletable=true editable=true
rng = pd.period_range("2006", "2009", freq="A-DEC")
ts = pd.Series(np.random.randn(len(rng)), index=rng)
ts
ts.asfreq("M", how="start")

# + deletable=true editable=true
ts.asfreq("B", how="end")

# + [markdown] deletable=true editable=true
# ### Quarterly Period Frequencies

# + deletable=true editable=true
p = pd.Period("2012Q4", freq="Q-JAN")
p

# + deletable=true editable=true
p.asfreq("D", "start")
p.asfreq("D", "end")

# + deletable=true editable=true
p4pm = (p.asfreq("B", "e") - 1).asfreq("T", "s") + 16 * 60
p4pm
p4pm.to_timestamp()

# + deletable=true editable=true
rng = pd.period_range("2011Q3", "2012Q4", freq="Q-JAN")
ts = pd.Series(np.arange(len(rng)), index=rng)
ts
new_rng = (rng.asfreq("B", "e") - 1).asfreq("T", "s") + 16 * 60
ts.index = new_rng.to_timestamp()
ts

# + [markdown] deletable=true editable=true
# ### Converting Timestamps to Periods (and Back)

# + deletable=true editable=true
rng = pd.date_range("2000-01-01", periods=3, freq="M")
ts = pd.Series(np.random.randn(3), index=rng)
ts
pts = ts.to_period()
pts

# + deletable=true editable=true
rng = pd.date_range("1/29/2000", periods=6, freq="D")
ts2 = pd.Series(np.random.randn(6), index=rng)
ts2
ts2.to_period("M")

# + deletable=true editable=true
pts = ts2.to_period()
pts
pts.to_timestamp(how="end")

# + [markdown] deletable=true editable=true
# ### Creating a PeriodIndex from Arrays

# + deletable=true editable=true
data = pd.read_csv("examples/macrodata.csv")
data.head(5)
data.year
data.quarter

# + deletable=true editable=true
index = pd.PeriodIndex(year=data.year, quarter=data.quarter, freq="Q-DEC")
index
data.index = index
data.infl

# + [markdown] deletable=true editable=true
# ## Resampling and Frequency Conversion

# + deletable=true editable=true
rng = pd.date_range("2000-01-01", periods=100, freq="D")
ts = pd.Series(np.random.randn(len(rng)), index=rng)
ts
ts.resample("M").mean()
ts.resample("M", kind="period").mean()

# + [markdown] deletable=true editable=true
# ### Downsampling

# + deletable=true editable=true
rng = pd.date_range("2000-01-01", periods=12, freq="T")
ts = pd.Series(np.arange(12), index=rng)
ts

# + deletable=true editable=true
ts.resample("5min", closed="right").sum()

# + deletable=true editable=true
ts.resample("5min", closed="right").sum()

# + deletable=true editable=true
ts.resample("5min", closed="right", label="right").sum()

# + deletable=true editable=true
ts.resample("5min", closed="right", label="right", loffset="-1s").sum()

# + [markdown] deletable=true editable=true
# #### Open-High-Low-Close (OHLC) resampling

# + deletable=true editable=true
ts.resample("5min").ohlc()

# + [markdown] deletable=true editable=true
# ### Upsampling and Interpolation

# + deletable=true editable=true
frame = pd.DataFrame(
    np.random.randn(2, 4),
    index=pd.date_range("1/1/2000", periods=2, freq="W-WED"),
    columns=["Colorado", "Texas", "New York", "Ohio"],
)
frame

# + deletable=true editable=true
df_daily = frame.resample("D").asfreq()
df_daily

# + deletable=true editable=true
frame.resample("D").ffill()

# + deletable=true editable=true
frame.resample("D").ffill(limit=2)

# + deletable=true editable=true
frame.resample("W-THU").ffill()

# + [markdown] deletable=true editable=true
# ### Resampling with Periods

# + deletable=true editable=true
frame = pd.DataFrame(
    np.random.randn(24, 4),
    index=pd.period_range("1-2000", "12-2001", freq="M"),
    columns=["Colorado", "Texas", "New York", "Ohio"],
)
frame[:5]
annual_frame = frame.resample("A-DEC").mean()
annual_frame

# + deletable=true editable=true
# Q-DEC: Quarterly, year ending in December
annual_frame.resample("Q-DEC").ffill()
annual_frame.resample("Q-DEC", convention="end").ffill()

# + deletable=true editable=true
annual_frame.resample("Q-MAR").ffill()

# + [markdown] deletable=true editable=true
# ## Moving Window Functions

# + deletable=true editable=true
close_px_all = pd.read_csv("examples/stock_px_2.csv", parse_dates=True, index_col=0)
close_px = close_px_all[["AAPL", "MSFT", "XOM"]]
close_px = close_px.resample("B").ffill()

# + deletable=true editable=true
close_px.AAPL.plot()
close_px.AAPL.rolling(250).mean().plot()

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
appl_std250 = close_px.AAPL.rolling(250, min_periods=10).std()
appl_std250[5:12]
appl_std250.plot()

# + deletable=true editable=true
expanding_mean = appl_std250.expanding().mean()

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
close_px.rolling(60).mean().plot(logy=True)

# + deletable=true editable=true
close_px.rolling("20D").mean()

# + [markdown] deletable=true editable=true
# ### Exponentially Weighted Functions

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
aapl_px = close_px.AAPL["2006":"2007"]
ma60 = aapl_px.rolling(30, min_periods=20).mean()
ewma60 = aapl_px.ewm(span=30).mean()
ma60.plot(style="k--", label="Simple MA")
ewma60.plot(style="k-", label="EW MA")
plt.legend()

# + [markdown] deletable=true editable=true
# ### Binary Moving Window Functions

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
spx_px = close_px_all["SPX"]
spx_rets = spx_px.pct_change()
returns = close_px.pct_change()

# + deletable=true editable=true
corr = returns.AAPL.rolling(125, min_periods=100).corr(spx_rets)
corr.plot()

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
corr = returns.rolling(125, min_periods=100).corr(spx_rets)
corr.plot()

# + [markdown] deletable=true editable=true
# ### User-Defined Moving Window Functions

# + deletable=true editable=true
plt.figure()

# + deletable=true editable=true
from scipy.stats import percentileofscore

score_at_2percent = lambda x: percentileofscore(x, 0.02)
result = returns.AAPL.rolling(250).apply(score_at_2percent)
result.plot()

# + deletable=true editable=true
pd.options.display.max_rows = PREVIOUS_MAX_ROWS

# + [markdown] deletable=true editable=true
# ## Conclusion
