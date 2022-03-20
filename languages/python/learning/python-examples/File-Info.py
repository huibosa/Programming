import os
import stat
import sys
import time

if sys.version_info >= (3, 0):
    raw_input = input

filename = raw_input("Enter a file name: ")
lineCount = 0
charCount = 0

try:
    with open(filename) as f:
        lineCount = (sum(1 for line in f))
        f.seek(0)
        charCount = (sum([len(line) for line in f]))
except FileNotFoundError as e:
    print(e)
    sys.exit(1)
except IOError:
    pass
except IsADirectoryError:
    pass

fileStats = os.stat(filename)
fileInfo = {
    "fname": filename,
    ""
}
