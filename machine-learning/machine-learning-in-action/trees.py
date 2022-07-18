#!/usr/bin/env python3

import numpy as np
import operator


def createDataSet():
    dataSet = [[1, 1, "yes"], [1, 1, "yes"], [1, 0, "no"], [0, 1, "no"], [0, 1, "no"]]
    labels = ["no surfacing", "flippers"]
    return dataSet, labels


def calcShannonEnt(dataSet):
    labelCount = {}
    for featVec in dataSet:  # the number of unique elements and their occurence
        currentLabel = featVec[-1]
        labelCount[currentLabel] = labelCount.get(currentLabel, 0) + 1

    shannonEnt = 0.0
    numEntries = len(dataSet)
    for key in labelCount:
        prob = float(labelCount[key]) / numEntries
        shannonEnt -= prob * np.log2(prob)

    return shannonEnt


def splitDataSet(dataSet, axis, value):
    retDataSet = []
    for featVec in dataSet:
        if featVec[axis] == value:
            reducedFeatVec = featVec[:axis]
            reducedFeatVec.extend(featVec[axis + 1 :])
            retDataSet.append(reducedFeatVec)
    return retDataSet


def chooseBestFeatureToSplit(dataSet):
    numFeatures = len(dataSet[0]) - 1
    baseEntropy = calcShannonEnt(dataSet)

    bestInfoGain = 0.0
    bestFeature = -1

    for i in range(numFeatures):
        featList = [row[i] for row in dataSet]
        uniqueVals = set(featList)

        newEntropy = 0.0
        for value in uniqueVals:  # calculate entropy for each unit
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet) / float(len(dataSet))
            newEntropy += prob * calcShannonEnt(subDataSet)

        infoGain = baseEntropy - newEntropy  # find best information gain
        if infoGain > bestInfoGain:
            bestInfoGain = infoGain
            bestFeature = i

    return bestFeature


def majorityCnt(classList):
    classCount = {}
    for vote in classList:
        classCount[vote] = classCount.get(vote, 0) + 1

    sortedClassCount = sorted(
        classCount.items(), key=operator.itemgetter(1), reverse=True
    )

    return sortedClassCount[0][0]


def createTree(dataSet, labels):
    classList = [row[-1] for row in dataSet]

    # stop when all classes are equal
    if classList.count(classList[0]) == len(classList):
        return classList[0]
    # when no more features, return majority
    if len(dataSet[0]) == 1:
        return majorityCnt(classList)

    bestFeatIndex = chooseBestFeatureToSplit(dataSet)  # get index feat
    bestFeatLabel = labels[bestFeatIndex]
    myTree = {bestFeatLabel: {}}
    del labels[bestFeatIndex]

    featValSet = set([row[bestFeatIndex] for row in dataSet])
    for val in featValSet:
        subLabels = labels[:]
        # values are either a class label or another dictionary
        myTree[bestFeatLabel][val] = createTree(
            splitDataSet(dataSet, bestFeatIndex, val), subLabels
        )

    return myTree
