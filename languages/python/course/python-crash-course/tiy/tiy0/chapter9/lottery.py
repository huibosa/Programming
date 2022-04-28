from random import choice

a = (
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    0,
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
)


def get_tic():
    b = []

    while len(b) < 15:
        i = choice(a)
        if i not in b:
            b.append(i)

    return b


win = get_tic()

count = 0

while True:
    my = get_tic()

    for j in my:
        if j not in win:
            count += 1
            break
    else:
        break
    if count > 100000:
        print("no")
        break

print(win)
print(my)
print(count)
