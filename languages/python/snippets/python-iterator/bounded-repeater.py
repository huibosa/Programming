#!/usr/bin/env python


class BoundedRepeater:
    def __init__(self, value, max_repeats):
        self.value = value
        self.maxRepeats = max_repeats
        self.count = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.count >= self.maxRepeats:
            raise StopIteration
        self.count += 1
        return self.value


def main():
    repeater = BoundedRepeater("hello", 3)

    # for item in repeater:
    #     print(item)

    iterator = iter(repeater)
    while True:
        try:
            item = next(iterator)
        except StopIteration:
            break
        print(item)


if __name__ == "__main__":
    main()
