## Reviewing Functions

*Function*
: A self-contained unit of program code desired to accomplish a particular
task. *Functions* may be called *subroutines* and *procedures* in other language
*Signature* of the function
: a prototype specifies both the type of value a function returns and the types
of arguments it expects.

### General Comments

* Function identifier in three separate context:
  * *Function prototype* 
    * The `;` indicates you are declaring a function, not define it.
    * The prototype can be put before `main()`, after `main()`, or inside
    `main()`
  * *Function call*
  * *Function definition*
* Functions have types.
* For compilers that don’t recognize ANSI C prototyping, just declare the type:
`void starbar()`
* Some very old compilers don’t recognize the `void` type. In that case,
use `int` for function don’t have a return value.

## Formal Parameters

Pre-ANSI C also recognize the following form:

```
void show_n_char(ch, num)
char ch;
int num;  
{
...
    }
```
* The arguments type are declare after the arguments name, but before the
braces.
* This form allows for comma to separate names to declare them same type.

## Prototyping a Function with Arguments

`void show_n_char(char, int)`
* The variable names can be omitted.
* Using a variable name in a prototype doesn't create variables.

## Actual Arguments

* The *formal parameter* is a variable in the called function.
* The *actual arguments* is the particular value assigned to the function
variable by calling function.

## Difference Between Formal Parameter and Actual Argument

A formal parameter is a variable that is defined in the function being called.
The actual argument is the value being appearing in the function call;
this value is assigned to the formal argument. You can think of the actual
argument as being the value to which the formal parameter is initialized
when the function is called.

## Function `return`

*Diver*
: A program designed to just test function

###  What if the function returns a type different from the declared type?

```c
int what_if(int n)
{
   double z = 100.0 / (double) n;
   return z;  // what happens?
}  
```

Then `z` is assigned `1.5625` . The return statement, however, returns
the `int` value  1 . 

## Function Type

* A function with a return value should be declared the same type as
the return value.
* Functions with no return value should be declared as type `void`.

> If no type is given for a function, older versions of C assume
that the function is type `int`.  
> While C99 standard drops support for this implicit assumption
of type `int`.

The functions can also be placed inside the function that use them:

```c
#include <stdio.h>
int main(void)
{
    int imin(int, int);      /* imin() declaration */
    int evil1, evil2, lesser;
```

You just need to make sure the function declaration comes just before you
use them

> In C, functions are grouped into families.The header file contain the
declaration for functions in the family. While the function definition resides
in a separate file of library functions

## ANSI C Function Prototyping

### No Arguments and Unspecified Arguments

A few functions, such as  printf() and  scanf() , take a variable number of
arguments.\
`int printf(const char *, ...);`

> You can move the whole function definition before the calling of
the function to avoid function prototype.

## Recursion

*Recursion*
: A function calls itself

### General Comments

* Each level of recursion has its own private variable, which can be
told by print the variable's address values.

### Recursion Fundamentals

> ```c
> void up_and_down(int n)
> {
>     printf("Level %d: n location %p\n", n, &n);
>     if (n < 5)
>         up_and_down(n + 1);
>     printf("Level %d: n location %p\n", n, &n);
> }
> ```
> 
> 1. Each level of function call has its own variables
> 2. Each function call is balanced with a return.
> 3. Statements in a recursive function that come **before** the recursive call are
> executed in the same order the functions are called.
> 4. Statements in a recursive function that come **after** the recursive
> call are executed in the opposite order from which the functions are called.
> 5. Fifth, although each level of recursion has its own set of variables, the
> code itself is not duplicate.
> 6. Finally, it’s vital that a recursive function contain something to halt
> the sequence of recursive calls.

### Tail Recursion

> Tail recursion or End recursion
> : The simplest form of recursion, the recursive call is at the end of the
> function, just before the `return` statement. Its act like a loop.
> 
> ```c
> long rfact(int n)    // recursive version
> {
>     long ans;
>     if (n > 0)
>         ans= n * rfact(n-1);
>     else
>         ans = 1;
> 
>     return and;
> }
> ```

### Recursion and Reversal

> ```c
> void to_binary(unsigned long n) {
>     int r;
> 
>     r = n % 2;
>     if (n >= 2)
>         to_binary(n/2);
>     putchar(r = 0 ? '0' : '1');
> }
> 
> ```
> 
> It is need to store all the digits somewhere (in an array, for example)
> without using a recursive to do the algorithm.

> void to_binary(unsigned long n)
> {
>     int r;
> 
>     r = n % 2;
>     if (n >= 2)
>         to_binary(n / 2);
>     putchar(r == 0 ? '0' : '1');
> 
>     return;
> }

### Pros and Cons

> ```c
> unsigned long Fibonacci(unsigned n)
> {
>     if (n > 2)
>         return Fibonacci(n - 1) + Fibonacci(n - 2);
>     else
>         return 1;
> }
> ```
> 
> This function use a `double recursion`, leading to a weakness.\
> Each level requires twice the number of variables as the preceding level.

## Compiling Programs with Two or More Source Code Files  

### Unix

1. `cc file1.c file2.c` will compile both files and produce an executable file
called `a.out`.
2. And two object files `file1.o` and `file2.o` are produced.
3. If later file1.c was changed, the command `cc file1.c file2.o` can be used.

### Linux

Has a similar way like Unix.

### DOS Command-Line Compilers

Most works similar to Unix `cc` command, one difference is that an `.obj`
extension is generated.

### Windows and Apple IDE Compilers

pass

### Using Header Files

When put `main()` in one file and function definitions in another file,
you can store the function prototype in a header file rather than type
them in each time used.

C preprocessor is used to define constant in a program, to avoid retype
the `#define` directives, you can place them in a header file.

> `scanf("%*s")` can be used to skip the next white space.

## The & Operator

### General Comments

The unary `&` gives address where a variable is stored

### Altering Variables in the Calling Function

One common task in sorting problems is interchanging the values of two
variables.

## Pointers

*Pointer*
: A variable (or a data object) whose value is a memory address.

`ptr = &pooh        // assigns pooh's address to ptr`\
* `ptr` is the pointer variable
* `ptr` points to `pooh`.
* `ptr` is a variable
* `&pooh` is a constant

## The Indirection Operator: *

`*`
: *Indirection* operator or *dereferencing* operator

`val = *ptr;        // finding the value ptr points to`

`ptr = &pooh` and `val = &ptr` taken together amount to `val = bah`

## Declaring Pointers

`char * pc;`
* `pc` is a pointer
* `*pc` is type `char`
* The value (`*pc`) of what `pc` points to is of type `char`
* The type of `pc` is type "*pointer to char*"
* The value of `pc` is an address, and represented internally as an unsigned
integer on most system, but not an integer type.
* The space between the `*` and the pointer name is optional.

### Using Pointers to Communicate Between Functions

```c
...
interchange(&x, &y)
...

void interchange(int * u, int * v)
{
    temp = *u;
    *u = *v;
    *v = temp;
}
```

* The function transmit the address of `x` and `y`
* The `u` and `v` will have the address of `x` and `y`
* `temp = *u` gives the value of `x` to `temp`

> * `foo1(x)` to transmit the value of x.
>   * Requires `int foo2(int num)`
> * `foo(&x)` to transmit the address of x.
>   * Requires `int foo2(int * ptr)`
> * Use the second form if the function needs to alter variable int the calling
function

> ### Note
> 
> 1. `scanf("%d", &num)` reads a value and then use the address to store it.
> 2. `void interchange(int *, int *)` is valid in ANSI C prototype.

## Variables: Names, Addresses, and Value

* When writing a program, a variable has two attributes: *name* and *value*.
* When compiled and loaded, a variable have two attributes: *address*
and *value*, *address* is the computer view of name.

> In short, a regular variable makes the value the primary quantity and the
> address a derived quantity, via the `&` operator. A pointer variable makes
> the address the primary quantity and the value a derived quantity via
> the `*` operator.  
