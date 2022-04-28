# Description   : Checks to see if a directory exists in the users home directory, if not then create it

import os

MESSAGE = "The dictionary already exist"
TESTDIR = "testdir"

try:
    home = os.path.expanduser("~")
    print(home)

    if not os.path.exists(os.path.join(home, TESTDIR)):
        os.makedirs(os.path.join(home, TESTDIR))
    else:
        print(MESSAGE)
except Exception as e:
    print(e)
