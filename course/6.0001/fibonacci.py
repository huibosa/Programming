d = {1: 1, 2: 2}


def fib_efficient(i):
    if i in d:
        return d[i]
    ans = fib_efficient(i - 2) + fib_efficient(i - 1)
    d[i] = ans
    return ans


if __name__ == "__main__":
    x = int(input("Number: "))
    print("Fib(x) = ", fib_efficient(x))
