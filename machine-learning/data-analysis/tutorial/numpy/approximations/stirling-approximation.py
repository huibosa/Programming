#!/usr/bin/env python3

# lgN! = lg1 + lg2 + lg3 + lg4 + ... + lgN ~ NlgN

import sys
import numpy as np
import matplotlib.pyplot as plt

N = int(sys.argv[1])

# lgNFact = np.log(np.array(list(map(math.factorial, np.arange(1, N+1)))))
lgNFact = np.cumsum(np.log(np.arange(1, N + 1)))
plt.plot(lgNFact, "k", label=r"$lg(N!)$")

NlgN = np.log(np.arange(1, N + 1)) * np.arange(1, N + 1)
plt.plot(NlgN, "r--", label=r"$Nlg(N)$")

plt.legend(loc="best")
plt.show()
