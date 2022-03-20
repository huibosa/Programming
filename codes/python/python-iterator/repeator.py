#!/usr/bin/env python


class Repeater:
    def __init__(self, value):
        self.value = value

    def __iter__(self):
        return self

    def __next__(self):
        return self.value


def main():
    try:
        repeater = Repeater("Hello")
        for item in repeater:
            print(item)
    except KeyboardInterrupt:
        print("Interupt by user")


if __name__ == "__main__":
    main()
