def get_content(filename):
    try:
        with open(filename) as f:
            contents = f.read()
    except FileNotFoundError:
        pass
    else:
        print(contents.rstrip().title())


get_content("cats.txt")
get_content("dogs.txt")
