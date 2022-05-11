def newton(x):
    epsilon = 0.001
    g = x / 2

    while g * g - x > epsilon:
        g = g - (g * g - x) / (2 * g)

    return g


def normal(x):
    epsilon = 0.001
    g = x / 2

    while g * g - x >= epsilon:
        g = (g + x / g) / 2

    return g


if __name__ == "__main__":
    x = int(input("Input: "))
    # print("Sqrt: ", newton(x))
    print("Sqrt: ", normal(x))
