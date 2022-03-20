## 1.4.35 Time costs for pushdown stacks.

Justify the entries in the table below, which shows typical time costs for
various pushdown stack implementations, using a cost model that counts both
data references (references to data pushed onto the stack, either an array
reference or a reference to an object’s instance variable) and objects created.
cost to push N int values

data structure
linked list
resizing array
item type
data referencesobjects created
int2NN
Integer3N2N
int~5 Nlg N
Integer~5 N~N
Time costs for pushdown stacks (various implementations)
1.4.36 Space usage for pushdown stacks. Justify the entries in the table below, which
