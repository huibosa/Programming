#!/usr/bin/env python3

import numpy as np
import operator
from os import listdir


def createDataSet():
    group = np.array([[1.0, 1.1], [1.0, 1.0], [0, 0], [0, 0.1]])
    labels = ["A", "A", "B", "B"]
    return group, labels


def classify0(inX, dataSet, labels, k):
    # calculate Euclidian distance
    diffMat = inX - dataSet
    sqDiffMat = diffMat**2
    sqDistances = sqDiffMat.sum(axis=1)
    distances = sqDistances**0.5

    # sort distance
    sortedDisIndices = distances.argsort()

    classCount = {}
    for i in range(k):
        voteIlabel = labels[sortedDisIndices[i]]  # derefererce to corresponding label
        classCount[voteIlabel] = classCount.get(voteIlabel, 0) + 1

    sortedClassCount = sorted(
        classCount.items(), key=operator.itemgetter(1), reverse=True
    )

    return sortedClassCount[0][0]


def file2matrix(filename):
    with open(filename) as f:
        lines = f.readlines()
        retMat = np.zeros((len(lines), 3))
        retLabels = []

        for i, line in enumerate(lines):
            line = line.strip()
            listFromLine = line.split("\t")
            retMat[i, :] = listFromLine[0:3]
            retLabels.append(int(listFromLine[-1]))

    return np.array(retMat), np.array(retLabels)


def autoNorm(dataSet):
    minVals = dataSet.min(0)
    maxVals = dataSet.max(0)
    ranges = maxVals - minVals
    normDataSet = np.zeros_like(dataSet)
    normDataSet = (dataSet - minVals) / ranges
    return normDataSet, ranges, minVals


def datingClassTest():
    datingDataMat, datingLabels = file2matrix("./data/datingTestSet2.txt")
    normMat, _, _ = autoNorm(datingDataMat)

    m = normMat.shape[0]
    hoRatio = 0.10
    numTestVecs = int(m * hoRatio)

    errorCount = 0.0
    for i in range(numTestVecs):
        classifierResult = classify0(
            normMat[i, :], normMat[numTestVecs:m, :], datingLabels[numTestVecs:m], 5
        )
        print(
            f"the classifier came back with: {classifierResult}, the real answer is: {datingLabels[i]}"
        )
        if classifierResult != datingLabels[i]:
            errorCount += 1.0
    print(f"the total error rate is {errorCount / numTestVecs}")


def classfyPerson():
    resultList = ["not at all", "in small doses", "in large doses"]
    percentTats = float(input("percentage of time spent playing video games? "))
    ffMiles = float(input("frequent flier miles earned per year? "))
    iceCream = float(input("liters of ice cream comsumed per year? "))

    datingDataMat, datingLabels = file2matrix("./data/datingTestSet2.txt")
    normMat, ranges, minVals = autoNorm(datingDataMat)
    inArr = np.array([ffMiles, percentTats, iceCream])

    classifierResult = classify0((inArr - minVals) / ranges, normMat, datingLabels, 3)
    print(f"You will probably like this person: {resultList[classifierResult-1]}")


def img2vector(filename):
    returnVect = np.zeros((1, 1024))
    with open(filename) as f:
        for i in range(32):
            lineStr = f.readline().rstrip("\n")
            for j in range(32):
                returnVect[0, 32 * i + j] = int(lineStr[j])
    return returnVect


def handwritingClassTest():
    hwLabels = []
    trainingFileList = listdir("./data/trainingDigits")
    m = len(trainingFileList)
    trainingMat = np.zeros((m, 1024))

    for i in range(m):
        fileNameStr = trainingFileList[i]
        fileStr = fileNameStr.split(".")[0]
        classNumStr = int(fileStr.split("_")[0])

        hwLabels.append(classNumStr)
        trainingMat[i, :] = img2vector("./data/trainingDigits/" + fileNameStr)

    testFileList = listdir("./data/testDigits")
    errorCount = 0.0
    mTest = len(testFileList)
    for i in range(mTest):
        fileNameStr = testFileList[i]
        fileStr = fileNameStr.split(".")[0]
        classNumStr = int(fileStr.split("_")[0])

        vectorUndertest = img2vector("./data/testDigits/" + fileNameStr)
        classifierResult = classify0(vectorUndertest, trainingMat, hwLabels, 3)
        print(
            f"the classifier came back with: {classifierResult}, the real answer is {classNumStr}"
        )
        if classifierResult != classNumStr:
            errorCount += 1.0
    print(f"\nthe total number of errors is: {errorCount}")
    print(f"\nthe total error rate is: {errorCount / float(mTest)}")
