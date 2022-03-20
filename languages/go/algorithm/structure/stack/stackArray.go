package stack

var stackArray []interface{}

func stackPush(n interface{}) {
	stackArray = append([]interface{}{n}, stackArray)
}

func stackLength() int {
	return len(stackArray)
}

func stackPeak() interface{} {
	return stackArray[0]
}

func stackEmpty() bool {
	return len(stackArray) == 0
}

func stackPop() interface{} {
	pop := stackArray[0]
	stackArray = stackArray[1:]
	return pop
}
