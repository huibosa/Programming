package main

import "fmt"

var depth int = 0

func rank0(val int, v []int) int {
	head := 0
	tail := len(v) - 1

	for head < tail {
		mid := head + (tail-head)/2
		if v[mid] > val {
			tail = mid - 1
		} else if v[mid] < val {
			head = mid + 1
		} else {
			return mid
		}
	}
	return -1
}

func rank1(a []int, val int) int {
	return rankRecur(a, val, 0, len(a)-1)
}

func rankRecur(a []int, val, head, tail int) int {
	fmt.Printf("Depth %v: head = %v, tail = %v\n", depth, head, tail)
	depth++

	if head > tail {
		return -1
	}

	mid := head + (tail-head)/2
	if a[mid] > val {
		return rankRecur(a, val, head, mid-1)
	} else if a[mid] < val {
		return rankRecur(a, val, mid+1, tail)
	}
	return mid
}
