#!/usr/bin/env python3


class Quick(object):
    def sort(self, a):
        self.subSort(a, 0, len(a) - 1)

    def subSort(self, a, lo, hi):
        if hi <= lo:
            return

        pivot = self.patition(a, lo, hi)
        self.subSort(a, lo, pivot - 1)
        self.subSort(a, pivot + 1, hi)

    def swap(self, a, i, j):
        a[i], a[j] = a[j], a[i]

    def patition(self, a, lo, hi):
        val = a[lo]
        p = lo
        q = hi + 1

        p += 1
        q -= 1
        while True:
            while a[p] < val:
                p += 1
                if p == hi:
                    break

            while a[q] > val:
                q -= 1
                if q == lo:
                    break

            if p >= q:
                break

            a[p], a[q] = a[q], a[p]

        a[lo], a[q] = a[q], a[lo]
        return q


arr = [2, 5, 1, 6, 7, 9, 1]

quick = Quick()
quick.sort(arr)

for i in arr:
    print(i, end=" ")
