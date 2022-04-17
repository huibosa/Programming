#!/usr/bin/env python3


def csv_reader(fname):
    for row in open(fname):
        yield row
