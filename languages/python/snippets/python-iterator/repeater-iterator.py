#!/usr/bin/env python


class RepeaterIterator:
    def __init__(self, source):
        self.source = source

    def __next__(self):
        return self.source.value


class Repeater:
    def __init__(self, value):
        self.value = value

    def __iter__(self):
        return RepeaterIterator(self)


def main():
    repeater = Repeater("hello")

    # for item in repeater:
    #     print(item)

    # iterator = repeater.__iter__()
    # while True:
    #     item = iterator.__next__()
    #     print(item)

    iterator = iter(repeater)
    while True:
        print(next(iterator))


if __name__ == "__main__":
    main()
