def foo(x, y, **kwargs):
    dicts = {
        "x": x,
        "y": y,
    }

    for i, j in kwargs.items():
        dicts[i] = j

    return dicts


print(foo(1, 2, asdfl=3, sadf=4))
