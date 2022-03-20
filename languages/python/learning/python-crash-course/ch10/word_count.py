def count_words(filename):
    try:
        with open(filename) as f:
            contents = f.read()
    except:
        print(no)
    else:
        return len(contents.split())


filename = "alice.txt"
print(count_words(filename))
