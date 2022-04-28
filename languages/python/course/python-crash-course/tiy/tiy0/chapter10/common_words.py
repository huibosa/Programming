def count_common_words(filename, word):
    try:
        with open(filename) as f:
            contents = f.read()
    except FileNotFoundError:
        pass
    else:
        return contents.lower().count(word)


print(count_common_words("alice.txt", "ch"))
