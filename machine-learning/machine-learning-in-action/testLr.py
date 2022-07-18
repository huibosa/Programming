import logRegres

a, b = logRegres.loadDataSet()
wei = logRegres.stocGradAscent1(a, b, 100000)

logRegres.plotBestFit(wei)
