#!/usr/bin/python


def readlines():
    with open("sorted_output.txt") as f:
        lines = f.readlines()


def readline():
    with open("sorted_output.txt") as f:
        line = f.readline()
        lines = []
        while line:
            lines.append(line)
            line = f.readline()


def iterate():
    with open("sorted_output.txt") as f:
        lines = []
        for line in f:
            lines.append(line)


def comprehension():
    with open("sorted_output.txt") as f:
        lines = [line for line in f]
