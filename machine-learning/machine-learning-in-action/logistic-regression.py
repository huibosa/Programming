import numpy as np
import matplotlib.pyplot as plt


def loadDataSet():
    dataMat = []
    labelVec = []

    with open("./data/testSet.txt") as f:
        for line in f.readlines():
            lineArr = line.strip().split()
            dataMat.append([1.0, float(lineArr[0]), float(lineArr[1])])
            labelVec.append(int(lineArr[2]))

    return np.array(dataMat), np.array(labelVec)


def sigmoid(inX):
    return 1.0 / (1 + np.exp(-inX))


def gradAscent(dataMat, labelVec):
    labelMat = labelVec.reshape(labelVec.shape[0], 1)

    alpha = 0.001
    maxCycles = 500
    weights = np.ones((dataMat.shape[1], 1))

    for _ in range(maxCycles):
        h = sigmoid(dataMat @ weights)
        error = labelMat - h
        weights = weights + alpha * dataMat.T @ error

    return weights


def plotBestFit(wei):
    weights = wei.copy()
    dataMat, labelVec = loadDataSet()

    xcord1 = dataMat[np.where(labelVec == 1), 1]
    ycord1 = dataMat[np.where(labelVec == 1), 2]
    xcord2 = dataMat[np.where(labelVec != 1), 1]
    ycord2 = dataMat[np.where(labelVec != 1), 2]

    fig = plt.figure()
    ax = fig.add_subplot(111)

    ax.scatter(xcord1, ycord1, s=30, c="r", marker="s")
    ax.scatter(xcord2, ycord2, s=30, c="green", marker="s")

    x = np.arange(-3.0, 3.0, 0.1)
    y = (-weights[0] - weights[1] * x) / weights[2]
    ax.plot(x, y)

    ax.set_xlabel("X1")
    ax.set_ylabel("X2")

    plt.show()


def stocGradAscent0(dataMat, labelVec):
    labelMat = labelVec.reshape(labelVec.shape[0], 1)
    m, n = dataMat.shape

    alpha = 0.01
    weightVec = np.ones(n)
    for i in range(m):
        h = sigmoid(np.sum(labelMat[i] * weightVec))
        error = labelMat[i] - h
        weightVec = weightVec + alpha * error * dataMat[i]

    return weightVec


def stocGradAscent1(dataMat, labelVec, numIter=150):
    m, n = dataMat.shape
    weightVec = np.ones(n)

    for j in range(numIter):
        dataIndex = list(range(m))
        for i in range(m):
            alpha = 4 / (1.0 + j + i) + 0.01
            randIndex = int(np.random.uniform(0, len(dataIndex)))

            h = sigmoid(dataMat[randIndex] @ weightVec)
            error = labelVec[randIndex] - h
            weightVec = weightVec + alpha * error * dataMat[randIndex]
            del dataIndex[randIndex]

    return weightVec


def classifyVector(inX, weights):
    prob = sigmoid(sum(inX @ weights))
    ret = 1.0 if prob > 0.5 else 0.0
    return ret


def colicTest():
    pass
