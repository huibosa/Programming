def fib(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


def fib_memo(n, memo={}):
    if n == 0 or n == 1:
        return 1
    try:
        return memo[n]
    except KeyError:
        result = fib_memo(n - 1, memo) + fib_memo(n - 2, memo)
        memo[n] = result
        return result


def fib_tab(n):
    tab = [1] * (n + 1)
    for i in range(2, n + 1):
        tab[i] = tab[i - 1] + tab[i - 2]
    return tab[n]


for i in range(120):
    print(fib_memo(i))

for i in range(120):
    print(fib_tab(i))
