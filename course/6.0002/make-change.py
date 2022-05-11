def make_change(coin_vals, change):
    tab = [change]

    for _ in range(change):
        if tab[-1] == 0:
            break

        n = 0
        for n in reversed(coin_vals):
            if n < tab[-1]:
                break

        tab.append(tab[-1] - n)

    print(tab)
    return len(tab) - 1


def make_change2(coin_vals, change):
    tab = []

    while sum(tab) != change:
        i = 0
        for i in reversed(coin_vals):
            if i < change - sum(tab):
                break
        tab.append(i)

    return tab


# 11
# 11, 3,
# 11, 3, 1
# 11, 3, 1, 0


coin_vals = [1, 2, 5, 10, 20, 50, 100]
change = 541

tab = make_change2(coin_vals, change)

for i in tab:
    print(f"{i}: {tab.count(i)}")
