# Arrays and Pointers

## Arrays

Array
: a series of elements of one data type.

Arrays declaration
: Give the array size and type for elements

### Initialization

* Without being initialized, the array elements will have any value that
  happens to be at the location.
* While with partially initialized, the remaining elements get the value 0.
* A common and recommend practice is to use the symbolic constant to represent
  the array size.
* Use `const` to initialize a read-only array, which make the program treat
  each elements in the array as a constant.

Note Storage Class Caveat:

* Arrays can be created using different storage class.
* Without specified, the arrays use the automatic storage class
* In some other class, the elements will have the value `0`, if not initialized.

You can omit the array size from the braces, and use a `for` loop like this:

```c
const int days[] = {31,28,31,30,31,30,31,31,30,31};

for (index = 0; index < sizeof days / sizeof day[0]; index++) {
  //...
}
```

* With a empty brace to initialize the array, the array size is the number of
  items in the list.
* `sizeof days` gives the size of the whole array, in bytes.
* `sizeof days[0]` gives the size of one elements in the array (*all the
  elements has the same type, so they have the same size*).

> Potential disadvantage of automatic counting: Errors in the number of
> elements could pass unnoticed.

### Designated Initializers (C99)

```c
int array[6], = {[5] = 212};
int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
```

*Designated initializers*
: Allows you to pick and choose which elements are initialized.

1. If the code follows a designed initializer with further values, these further
   values are used to initialize the subsequent elements.
2. If a particular elements is initialized more than once, the last
   initialization will take effect.

Suppose you don’t specify the array size?

```c
int stuff[] = {1, [6] = 23};       // what happens?
int staff[] = {1, [6] = 4, 9, 10}; // what happens?
```

The compiler will make the array big enough to accommodate the initialization
values.

### Assigning Array Values

You can use a for loop to assign values to the array elements.

> Note
>
> * C doesn't allow assigning one array to another as a unit.
> * Nor can you use the list-in-braces form.

### Array Bounds

In one complier, using out-of-bounds array indices will result in the
program altering the value of other variables

### Specifying an Array Size

*Constant integer expression*
: One formed from integer constants, such as a `sizeof`

*Variable length array* or *VLA*
: A new breed of array when use a `const` to specify a array size after C99.

## Multidimensional Arrays

```c
float rain[5][12];
```

* `Rain` is a five-element array of 12-element array of float

![2darray](./images/2darray.png)

In a for loop:

* To keep one *indices* constant, put it at the outer loop.
* Each time the outer loop cycled once, the inner loop cycled its full
  allotment

## Initializing a Two-Dimensional Array

j``c
 const float rain[YEARS][MONTHS] =
 {
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
 };  
 ```

* As long as you have the right number of entries, You can omit the interior
 braces and just retain the outermost braces
* With not enough entries, the array is filled subsequently, row by row,
and the remaining elements are initialized to 0.

![array_init](./images/array_init.png)

## More Dimensions

Typically, you would use three nested loops to process a three-dimensional
array, four nested loops to process a four-dimensional array, and so on.

> ### To visualize an array
>
> * You can visualize a one-dimensional array as a row of data, a
two-dimensional array as a table, and a three dimensional array as a stack of
table
> * Or to think a three dimensional array of arrays of arrays.

## Pointers and Arrays

> Array notation is simply a disguised use of pointers.

An example of this disguised use is that an array name is also the address
of the first element of the array.

If  `flizny` is an array, the following is true:  

```c
flizny == &flizny[0];     // name of array is the address of the first element  
```

When "add 1 to a pointer", C adds one *storage unit*, for arrays, means
its address is increased to the next *element*, not just the next byte.

### What is Pointer Exactly

> ***The value of a pointer is the address of the object to which it points***.
> How the address is represented internally is hardware dependent. Many
> computers, including PCs and Macintoshes, are *byte addressable*, meaning
> that each byte in memory is numbered sequentially. Here, the address of
> a large object, such as type `double` variable, ***typically is the address
> of the first byte of the object.***
> 
> Applying the `*` operator yields the value stored in the pointed-to object.
> 
> Adding 1 to the pointer increases its value by the size, in bytes, of
> the pointed to type

```c
dates + 2 == &date[2]           // same address
*(dates + 2) == dates[2]        // same address
```

The two different notation are the same thing:\
`ar[n]` means `*(ar + n)`\
You can think of it as "Go to memory location `ar`, move n units, and retrieve
the value there."

> The compiler produce the same code for either. It turns out to be important
when you have a function with an array as an argument.

![ptr&array](./images/ptr_arr.png)

## Functions, Arrays, and Pointers

```c
total = sum(array)          // function call
int sum(int * ar)           // prototype
```

An actual argument of an array name requires that the matching formal
parameter to be a pointer.

Only in the context of function prototype or function definition header,
you can substitute `int ar[]` for `int * ar`, such as:

```c
int sum(int ar[], int n);
```

---

All forms of the following *prototype* types are equivalent:

```c
int sum(int *ar, int n)
int sum(int *, int)
int sum(int ar[], int n)
int sum(int [], int)
```

---

In *function definition*, the following two forms are equivalent

```c
int sum(int *ar, int n)
int sum(int ar[], int n)
```

## Pass Array into a Function

### Passing Array and Its Size

```c
#include <stdio.h>
#define SIZE 10

int sum(int * ar, int n);

int main(void)
{
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n",
            sizeof(marbles));

    return 0;
}

int sum(int * ar, int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes.\n", sizeof(ar));

    return total;
}
```
> #### Note
>
> * The size of `marbles` is 40 bytes because it contains 10 `int`s, each 4
bytes.
> * The size of `ar` is 8 bytes because it's a pointer to the first
> element of `marbles`. (the system use 8 bytes for *storing address*).

### Using Pointer Parameters

> A function working on array use a pointer parameter to identify the beginning
of the array and an integer to indicate how many elements to process.
(The pointer also identifies the type of data in the array)

Another way to describe the array is by passing two pointers, with the first
indicating where the array starts (as before) and the second where the array
ends.

```c
#include <stdio.h>
#define SIZE 10
int sump(int * start, int * end);
int main(void)
{
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld.\n", answer);

    return 0;
}

int sump(int * start, int * end)
{
    int total = 0;

    while (start < end)
    {
        total += *start;
        start++;
    }

    return total;
}
```

Uses the fact that a pointer parameter is a variable, which means that
instead of using an index to indicate which element in the array to access,
the function can alter the value of the pointer it self, making it point to
each array element in turn.

* `for(i = 0; i < n; i++)` use the number of elements as a second argument,
and the loop use that value as part of the loop test
* `while(start < end)` use a second pointer to end the loop

> Note that the end actually point to the location after the final element
int the array. C guarantees that a point to the first location after
the end of array is valid.

> #### Note
> 
> `total += *start++;`  or `*(start++)`has a equivalent effect, because
> the `*` and `++` have the same precedence but associate from right to
> left, which means the `++` associate to `start`, not `*start`, so
> 
> * `*(start++)` is clearer.
> * `*++start` will meet our need but increase pointer first, then use
the value point to.
> * `(*start)++` will use the value of pointer point to and the increase
the value

> ### Comment: pointer and arrays
> 
> The two expression `ar[i]` and `*(ar+i)` are equivalent in meaning.
Both work if `ar` is the name of an array or a pointer variable.
>
> Pointer notation, when used with the increment operator, is closer to
machine language and may create more efficient code with some computers.

## Pointer Operations

### Assignment

You can assign an address to a pointer, the assign value can be:

* An array name.
* A variable preceded by address operator (`&`), (the address should be
compatible with the pointer type.)
* Another second pointer.

### Value Finding (Dereference)

The `*` operator gives the value stored in the pointed-to location. Therefore,
`*ptr1` is initially 100 , the value stored at location 0x7fff5fbff8d0 . 

### Taking a Pointer Address

Like all variables, a pointer variable has an address and a value. The `&`
operator tells where it is stored.

### Adding an integer to a pointer

When using `+` to add an integer to a pointer, the integer is multiplied
by *the number of bytes in the pointer-to type*, and the result is added to
the original address.

> The result of addition is undefined if it lies outside of the array
into which the original pointer points, except that the address one 
past the end element of the array is guaranteed to be valid.

### Incrementing a Pointer `++`

Incrementing a pointer to an array makes it moves to the next element
of the array.

> Note that the address of the pointer itself remained unchanged.

![ptr_incr](./images/ptr_incr.png)

### Subtracting an Integer from a Pointer

When subtracting, the integer is multiplied by the number of bytes in the
point-to type, and the result is subtracted from the original address.

> The result of the subtraction is undefined if it lies outside of the
array into which the original pointer, except that the address one 
past the end element of the array is guaranteed to be valid.  

### Decrementing a Pointer `--`

Incrementing a pointer to an array makes it point to one array element
before.

> You can use both the prefix and postfix forms of the increment and decrement
operators.

### Differencing

The difference between two array indicates the distance of the two point-to
elements. The result is in the same units of the type size.

`ptr2 - ptr1` has the value 2, meaning these pointers point ot objects
separated by two `int`s, not by 2 bytes.

Subtraction is valid as long as both pointer point to the same array (or
a position one pass the end)

> Applying  the operation to pointers to two different arrays might produce
a value or could lead to a runtime error.   

### Caveat

1. When incrementing or decrementing, the computer doesn't track if the pointer
still point to an array element.
2. Even though a pointer to one past the end element is valid, it’s not
guaranteed that such a one-past-the-end pointer can be dereferenced.

### DO NOT DEREFERENCE AN UNINITIALIZED POINTER

```c
int * pt;         // an uninitialized pointer
*pt = 5;          // a terrible error
```

Being uninitialized, `pt` could have a random value, so the `5` could be
send to a radom place.
 
> Remember, declaring a pointer only allocates memory to store the pointer
itself, but not allocate memory to store data.

### Example

Given

```c
int urn[3];
int * ptr1, * ptr2;
```

|Valid|Invalid|
|---|---|
|`ptr1++`|`urn++`|
|`ptr2 = ptr1 + 2`|`ptr2 = ptr2 + ptr1`|
|`ptr2 = urn + 1`|`ptr2 = urn * ptr1`|

## Protecting Array Contents

Passing an array to function may lead to the original data of the array
bing changed.

### Using `const` with Formal Parameters

Using the `const` when declaring the formal parameter in the prototype and
in the definition will help to protect the content of the array.

`int sum(const int ar[], int n)`
* The compiler will generate an error message when you accidentally modify
the content of the array
* Using `const` this way does not require the original array to be constant.

### More About `const`

The `const` lets yo create *constant arrays*, *constant pointers*, and
*pointer to constant*.

#### Constant Array

Use `const` to protect an array:

```c
const int days[MONTHS] = {...}

days[9] = 4;            // compile time error
```

#### Pointer to Constant

```c
double rates[5] = [...]
const double * pd = rates;

*pd = 29.89;      // not allowed
pd[2] = 222.22;   // not allowed
rates[0] = 99.99; // allowed because rates is not const  
```

The type `double` value to which `pd` points is a `const`, meaning you
can't use `pd` to change pointed-to values, while `rates` was not declared
as a constant, you can still use `rates` to change values

> Note that you can make `pd` point to somewhere else: `pd++`

A pointer-to-constant is normally used as a function parameter to indicate
that the function won’t use the pointer to change data.

#### Rules about pointer assignments and `const`

It's valid to assign the address of either constant data or non-constant
data to a point-to-data:

```c
double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
const double locked[4] = {0.08, 0.075, 0.0725, 0.07};
const double * pc = rates;    // valid
pc = locked;                  // valid
pc = &rates[3];               // valid   
```

For instance

```c
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);

show_array(rates, 5);           // valid
show_array(locked, 5);          // valid
mult_array(rates, 5, 1.2);      // valid
mult_array(locked, 5, 1.2);     // invalid
```

Attempt to modify constant array (`locked`) using a `non-const` identifier,
(`ar` in `mult_array()`)result in undefined behavior.

Only the address of non-const data can be assigned to regular pointer:

```c
double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
const double locked[4] = {0.08, 0.075, 0.0725, 0.07};
double * pnc = rates;          // valid
pnc = locked;                  // not valid
pnc = &rates[3];               // valid  
```

> Using `const` in a function parameter definition not only protects data,
it also allows the function to work with arrays that have been declared
`const`.


### More Possible Uses of `const`

Declare and initialize a pointer so that it can't be made to point
elsewhere, be aware of the position of the `const`
 
```c
double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
double * const pc = rates;    // pc points to beginning of the array
pc = &rates[2];               // not allowed to point elsewhere
*pc = 92.99;                  // ok -- changes rates[0]  >
```

Such a pointer can be used to change values, but can point only to the
location originally assigned to it.

Use `const` twice to create a pointer that can either change where it's
pointing nor change the value to which it points:

```c
double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
const double * const pc = rates;
pc = &rates[2];               // not allowed
*pc = 92.99;                  // not allowed  
```

## Pointers and Multidimensional Arrays

For `int zippo[4][2]`:

* `zippo` is the first address of the array's first element, so
`zippo == &zippo[0]`
* `zippo[0]` is itself an array of two integers, so `zippo[0] == &zippo[0][0]`
* `zippo[0]` is the address of an int-sized object, and `zippo` is the address
of a two-int-sized object.
* Because both the integer and the array of two integers begin at the same
location, so `zippo == &zippo[0]`

When adding `1` to the pointer:

* `zippo` refers to an object two `int`s in size.
* `zippo[0]` refers to an object one `int` in size.
* `zippo + 1` has a different value from `zippo[0] + 1`.

Dereferencing a pointer or an address:

* `zippo[0][0]`, `*(zippo[0])` represents the value stored in `zippo[0][0]`
* `*zippo` represents the value of its first element, `zippo[0]`, which
is the address `&zippo[0][0]`, so `*zippo` is `&zippo[0][0]`
* Applying the differencing operator to both expressions ->
`**zippo` equals to `*&zippo[0][0]`, which is `zippo[0][0]`
* `zippo` is an address of an address and must be dereferenced twice
to get an ordinary value. (use `*` twice or `[ ]` twice, also one `*`
and one `[ ]`).

> An address of an address or a pointer to a pointer is an example of
`double indirection`.

> `zippo[2][1]` equals to `*(*(zippo+2) + 1)`
>
> | Expression          | Explanation                                                                    |
> | -                   | -                                                                              |
> | `zippo`             | the address of the first two-int element                                       |
> | `zippo+2`           | the address of the third two-int element                                       |
> | `*(zippo+2)`        | the third element, a two-int array, the address of its first element, an `int` |
> | `*(zippo+2) + 1`    | the address of the second element of the two-int array, an int                 |
> | `*(*(zippo+2) + 1)` | the value of the second `int` in the third row (`zippo[2][1]`)                 |
> 
> So use the array notation to extract the value of a two-dimensional array
rather than pointer notation.

![arr_of_arr](./images/arrofarr.png)

### Pointers to Multidimensional Arrays

To declare a pointer variable `pz` that point to a two-dimensional array,
`pz` must point to an array of two `int`s:

```c
int (* pz)[2];          // pz points to an array of 2 ints

int * pax[2];           // pax is an array of two points-to-int pointers
```

* Parentheses is needed because `[ ]` has a higher precedence than `*`
* The second declaration creates *two* pointer to an array of two `int`s.

You can represent individual elements by using array notation or pointer
notation with either an array name or a pointer.

```c
zippo[m][n] == *(*(zippo + m) + n)
pz[m][n] == *(*(pz + m) + n)
```

### Pointer Capability

You can assign a `int` to a `double` variable without using a type conversion,
while you can't do the same for pointers.

```c
int n = 5;
double x;
int * p1 = &n;
double * pd    = &x;
x = n;                // implicit type conversion
pd = p1;              // compile-time error
```

---

With a more complex types

```c
int * pt;
int (*pa)[3];
int ar1[2][3];
int ar2[3][2];
int **p2;           // a pointer to a pointer

pt = &ar1[0][0];  // both pointer-to-int
pt = ar1[0];      // both pointer-to-int
pt = ar1;         // not valid
pa = ar1;         // both pointer-to-int[3]
pa = ar2;         // not valid
p2 = &pt;         // both pointer-to-int *
*p2 = ar2[0];     // both pointer-to-int
p2 = ar2;         // not valid  
```

* `pt` points to a single `int`, but `ar1` points to an array of three `int`s
* `pa` points to an array of three `int`s, so it is compatible with `ar1`,
not `ar2`, which points to an array of two `int`s.

In the last two examples:

* `p2` is a pointer-to-pointer-to-int, whereas `ar2` is a pointer-to-array-of-
two-ints (or, pointer-to-int[2])
* `*p2` is a type pointer-to-int, `ar2[0]` is a pointer to its first element,
`ar2[0][0]`.

---

```c
int x = 20;
const int y = 23;
int * p1 = &x;
const int * p2 = &y;
const int ** pp2;
p1 = p2;   // not safe -- assigning const to non-const
p2 = p1;   // valid    -- assigning non-const to const
pp2 = &p1; // not safe -- assigning nested pointer types  

```

* Assigning a `const` pointer to a non-const pointer is not safe, because you
could use the new pointer to alter `const` data. While the code could compile,
perhaps with a warning
* But assigning a non-const pointer to a `const` pointer is okay, provided
that **you're dealing with just one level of indirection**

When go to two levels of indirection, such assignments are no longer safe:

```c
const int **pp2;
int *p1;
const int n = 13;
pp2 = &p1; // allowed, but const qualifier disregarded
*pp2 = &n; // valid, both const, but sets p1 to point at n
*p1 = 10;  // valid, but tries to change const n  
```

---

### C `const` and C++ `const`

```c
const int y;
const int * p2 = &y;
int *p1;
p1 = p2;            // error in C++, possible warning in C
```

In C++ you are not allowed to assign a `const` pointer to a non-const
pointer, which can be done in C, bu the behavior is undefined if you try
to use `p1` to alter `y`

### Functions and Multidimensional Arrays

```c
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);
int sum2d(int (*ar)[COLS], int rows);
```

* The number of columns is built into the function, but the number of rows
is left open. Means the function will work with arrays with either number
of rows at least the number of columns is 4.
* `ar` and `junk` are the same type: pointer-to-array-of-four-ints.

```c
int sum2(int ar[3][4], int rows);   // valid declaration, 3 ignored
```

```c
typedef int arr4[4];              // arr4 array of 4 int
typedef arr4 arr3x4[3];           // arr3x4 array of 3 arr4
int sum2(arr3x4 ar, int rows);    // same as next declaration
int sum2(int ar[3][4], int rows); // same as next declaration
```

---

To declare a pointer corresponding to an N-dimensional array, you must
supply values for all but the leftmost set of brackets.

```
int sum4d(int ar[][12][20][30], int rows);

// equals to 

int sum4d(int (*ar)[12][20][30], int rows);
```

The first set of brackets indicates a pointer, whereas the rest of brackets
escribe the type of data object being pointed to.

## Variable-Length Arrays (VLAs)

### Examples

```c
int quarters = 4;
int regions = 5;
double sales[regions][quarters];            // a VLA
```

> * They need to have the automatic storage class, which means they are declared
> either in a function without using the `static` or `extern` storage class
> modifiers or as function parameters.
> * You can’t initialize them in a declaration. Finally, under C11, VLAs are an
> optional feature rather than a mandatory feature, as they were under C99.  

> ### Note VLAs Do Not Change Size
>
> The term  variable in variable-length array does not mean that you can modify
the length of the array after you create it. Once created, a VLA keeps the
same size. What the term  variable does mean is that you can use a variable
when specifying the array dimensions when first creating the array.  

### A Function

```c
int sum2d(int rows, int cols, int ar[rows][cols]);      // ar a VLA

int sum2d(int, int, int ar[*][*]);            // name omitted
```

* The first two parameters have to be declared before `ar` in the parameter list.
* When names are omitted, you need to replace the omitted dimensions with
asterisk.

VLA declaration in a function parameter list doesn't actually create an
array, the VLA name really is a pointer.

```c
   int thing[10][6];
   twoset(10,6,thing);
   ...
}
void twoset(int n, int m, int ar[n][m])  // ar a pointer to
                                         // an array of m ints
{
   int temp[n][m];     // temp an n x m array of int
   temp[0][0] = 2;     // set an element of temp to 2
   ar[0][0] = 2;       // set thing[0][0] to 2
}  
```
* When `twoset()` is called, `ar` becomes a pointer to `thing[0]`, and `temp`
is created as a 10x6 array.
* Because both `ar` and `thing` are pointers to `thing[0]`, `ar[0][0]` access
the same data location as `thing[0][0]`

> Variable-length arrays also allow for *dynamic memory allocation*.

### `const` and Array Sizes

```c
const int SZ = 80;
...
double ar[SZ];
```

For C99/C11, you can use a `const` symbolic constant when declaring an array
if the array could otherwise be a VLA. So the definition would have to be
for an automatic storage class array declared inside a block.

## Compound Literals

Compound literals
: Constant that aren't symbolic.

```c
(int [2]){10, 20}           // a compound literal

(int []){50, 20, 90}            // a compound literal with 3 elements
```

---

Compound literals must be used when created:

```c
int * pt1;
pt1 = (int [2]) {10, 20};
```

Compound literals can be passed to a function as an actual argument with
a matching formal parameter.

```c
int sum(const int ar[], int n)
...
int total3;
total3 = sum ((int []){4,4,4,5,5,5}, 6);
```

* The first argument is a six-element array of `int`s that acts like the
address of the first element.
* Use a compound literal like this, you can pass information to a function
without having to create an array first, which is a typical use for compound
literals.

---

To get a two-dimensional array of `int`s

```c
int (*pt2)[4];          // declare a pointer to an array of 4-int arrays
pt2 = (int [2][4]) { {1,2,3,-9}, {4,5,6,-8} };
```

## Reviews

```c
float rootbeer[10], things[10][5], *pf, value = 2.2;
int i = 3;

rootbeer[2] = value;                // valid
scanf("%f", &rootbeer);             // invalid
rootbeer = value;                   // invalid
printf("%f", rootbeer);             // invalid
things[4][4] = rootbeer[3];         // valid
things[5] = rootbeer;               // invalid
pf = value;                         // invalid
pf = rootbeer;                      // valid
```

```c
// a
void foo1(double ar[], int n)
void foo2(int n, double ar[n])
foo1(trots, 20)
foo2(20, trots)

// b
void foo1(short ar[][30], int rows)
void foo2(int rows, int cols, ar[rows][cols])
foo1(clops, 10)
foo2(10, 30, clops)


// c
void foo1(short ar[][10][15], int rows)
void foo2(int x, int y, int z, ar[x][y][z])
foo1(shots, 5)
foo2(5, 10, 15, shots)
```

```c
show((int []) {8,3,9,2}, 4)

shows((int [][3]) {8,3,9,5,4,1}, 6)
```
