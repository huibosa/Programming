def list2str(words):
    ret = ", ".join(words[:-2])
    ret += ", "
    ret += ", and ".join(words[-2:])

    return ret


spam = ["apples", "bananas", "tofu", "cats"]

print(list2str(spam))
