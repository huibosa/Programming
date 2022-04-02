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
#     display_name: Python 3.8.10 64-bit
#     language: python
#     name: python3
# ---

import matplotlib.pyplot as plt
import numpy as np


def showTempGraph(x, max, min, xlabel):
    delta = max - min
    fig, ax = plt.subplots()
    # ax.plot(x, max, '-v', label='Max Temperature', linewidth=2)
    ax.plot(x, min, "-v", label="Min Temperature", linewidth=2)
    # ax.plot(x, delta, '-v', label='Delta Temperature', linewidth=2)

    ax.legend()
    ax.set_xlabel(xlabel)
    ax.set_ylabel("Temperature")
    ax.set_ylim([880, 920])


def showStressGraph(x, max, min, xlabel):
    delta = max - min
    fig, ax = plt.subplots()
    ax.plot(x, max, "-v", label="Max Stress-Effective", linewidth=2)
    # ax.plot(x, min, '-v', label='Min Stress-Effective', linewidth=2)
    # ax.plot(x, delta, '-v', label='Delta Stress-Effective', linewidth=2)

    ax.legend()
    ax.set_xlabel(xlabel)
    ax.set_ylabel("Stress")
    ax.set_ylim([450, 550])


feedAngle = np.array([12, 14, 16])
headOffset = np.array([20, 30, 50])

maxTempForFeedAngle = np.array([1310, 1300, 1350])
minTempForFeedAngle = np.array([914, 867, 908])
showTempGraph(feedAngle, maxTempForFeedAngle, minTempForFeedAngle, "Feed Angle")

maxTempForHeadOffest = np.array([1310, 1370, 1310])
minTempForHeadOffest = np.array([886, 901, 914])
showTempGraph(headOffset, maxTempForHeadOffest, minTempForFeedAngle, "Head Offset")

maxStressForFeedAngle = np.array([500, 522, 492])
minStressForFeedAngle = np.array([12.1, 12.3, 13.3])
showStressGraph(feedAngle, maxStressForFeedAngle, minStressForFeedAngle, "Feed Angle")

maxStressForHeadOffset = np.array([508, 500, 500])
minStressForHeadOffset = np.array([16.6, 18.0, 12.1])
showStressGraph(feedAngle, maxStressForHeadOffset, minStressForHeadOffset, "Feed Angle")
