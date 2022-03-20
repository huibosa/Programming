try:
    with open("alice.txt", encoding="utf-8") as f:
        contents = f.read()
except:
    print("no")
else:
    words = contents.split()
    print(len(words))
