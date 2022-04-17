import zipfile
import itertools

fileName = "a.zip"


def uncompress(fileName, password):
    try:
        with zipfile.ZipFile(fileName) as zfile:
            zfile.extractall("./", pwd=password.encode("utf-8"))
        return True
    except:
        return False


chars = "1234"
for c in itertools.permutations(chars, 4):
    password = "".join(c)
    result = uncompress(fileName, password)

    if not result:
        print("Extract failed: password")
    else:
        print("Extract successful: password")
        break
