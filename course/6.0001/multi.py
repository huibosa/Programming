def mult_iter(a, b):
    ret = 0
    while b > 0:
        b -= 1
        ret += a
    return ret


def mult(a, b):
    if b == 1:
        return a
    return a + mult(a, b - 1)


print(mult_iter(2, 3))
print(mult(2, 3))
