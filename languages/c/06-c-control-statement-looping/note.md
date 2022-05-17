## Three forms of program flow that a good language have

* Executing a sequence of statement
* Repeating a sequence of statement until some condition is met (*looping*)
* Using a test to decide between alternative sequences (*branching*)

> `scanf()` returns a `1` when successfully read a value.

### What is *Pseudocode*?

```pseudocode
initialize sum to 0
prompt user
read input
while the input is an integer,
   add the input to sum,
   prompt user,
   then read next input
after input completes, print sum
```

### C style Reading Loop

C allows a shortcut for loop condition: `while(status = scanf("%d", &num) == 1);`

```pseudocode
while getting and testing the value succeeds
    process the value
```

## Relational Operators and Expressions

### Notes
Limit using only `>` and `<` in floating-point comparisons
* `3 * 1/3` can be 1.0 or 0.999999
* Use `fabs()` in <math.h> fo floating-point test, which returns the
absolutely value of a floating-point number

## True and False

* True expression has the value `1`
* False expression has the value `0`
* All nonzero value is True
* Only 0 is recognized as False
* `while (a != 0)` can be replaced by `while (a)`

## The New _Bool Type

* Can only have a value of `1` (true) or `0` (false)
* When assigned a nonzero value, it is set to `1`;
* C99 provides a `stdbool.h`, which makes `bool` an alias for `_Bool`,
and defines `true` and `false` as symbolic constants for `1` and `0`.

## Precedence of Relational Operators

* The *relational operators* have a greater precedence than *assignment
operators*.
* Associating from left to right.

### Operator Precedence

| Operators (From High to Low Precedence) | Associativity            |
| :-:                                     | -                        |
| `()`                                    | L-R                      |
| `-` `+` `++` `--` `sizeof`              | R-L (*type*) (all unary) |
| `*` `/` `%`                             | L-R                      |
| `+` `-`                                 | L-R                      |
| `<` `>` `<=` `>=`                       | L-R                      |
| `==` `!=`                               | L-R                      |
| `=`                                     | R-L                      |

## The `while` Loop

### Form

```c
get first value
while (value meets test)
{
        process the value
        get next value
}
```

### General Comments

* expression to be True (or nonzero) or False (zero)
* The `while loop` is a *condition* loop
* The expression is an *entry condition*
* When *statement* not enclosed (not using a compound statement), only the
first statement (simple statement) after `while` part of the loop is processed.

> To skip over input to the first character isn't whitespace or a digit:
> 
> ```c
> while (scanf("%d, &num") == 1)
>     ;       // skip integer input
> ```

### Terminating a while Loop

* Statement change the value of *expression*
* `if` + `break` 

## The `for` Loop

### Form

```c
for (initialize ; test ;update)
    statement
```

### General Comments

* An *entry condition* loop
* The parentheses follow the `for` contains three expression:
  * *Initialization*
  * *Test condition*
  * *change* or *update*

### Nine variations of `for` loop

* Using the decrement operator instead of up\
`for (n = 1; n <= 100; n--);`
* Increasing the count by two, ten or more\
`for (n = 1; n <= 100; n=n+1);`
* Counting by characters instead of by numbers\
`for (ch = 'a'; ch <= 'z'; ch++);`
* Testing some condition other than the number of iteration\
`for (n = 1; n*n*n <= 100; n++);`
* Increasing quantity geometrically instead of arithmetically\
`for (n = 1; n <= 100; n=n*1.1);`
* Using any legal expression for the third expression\
`for (x = 1; y <= 100; y = (++x * 5)+50)`
* Leaving one or more expression blank. (`for` must have two semicolons)\
`for (n = 3; ans <= 25; )`
* The first expression need not initialize a variable\
`for (printf("Keep entering numbers!\n"); num != 6; )`
* The parameter of the loop can be altered by actions within the loop
`delta` can be altered within loop\
`for (n = 1; n < 100; n = n + delta)`

## More Assignment Operators

| Assignment Operators |
| :-:                  |
| `+=`                 |
| `-=`                 |
| `*=`                 |
| `/=`                 |
| `%=`                 |

* Having the same low priority as `=` does
* *May* produce more efficient machine code than longer forms.
* Popular use of squeezing some expression into a `for` expression

## The Comma Operator

### General Comments

Enabling adding more than one expression in the *initialization* or *update*
expression in a single `for` loop.

### Two Further Properties

* Guaranteeing the expression it separate are evaluated in a left-right
order.\
(In other words, the `comma` is a sequence point, enabling all
the side effect to the left of the `comma` take place before the
program moves to the right of the `comma`)
  * `ounces++, ost = ounces * FIRST_OZ`
  * `x = (y = 3, (z = ++y +2) + 5)`
  * `houseprice = 249,500` same as`houseprice = 249;500;`
  * `houseprice = (249,500);` assignes the 500 to `houseprice`
* Used as a separator
  * `char ch, date`
  * `printf("%d %d\n", chimps, chumps)`

## `do while` loop

### Form

```c
do
    statement;
while ( expression );
```

### General Comments

An *exit-condition* loop, in which the condition is checked after
each iteration of the loop. Guaranteeing that statements are executed
at least once.

> The `do while` loop it self is counted as a statement, requiring a
terminating semicolon.

### Example

```c
do
{
    prompt for password
    read user password
} while (input not equal to password);
```

## Which Loop To Use

### Same Output with `for` and `while` Loop

```c
for (initialize; test; update)
    body;
```

```c
initialize;
while (test)
{
    body;
    update;
}
```

### Prevailing Style

* `for` loop is better when involving initializing and updating a variable\
  `for (count=1; count<=100; count++)`
* `while` loop is better when otherwise\
`while (scanf("%ld", &num) == 1)`

## Nested Loops

* The `inner` loop runs through its full range of iteration for each single
iteration of the `outer` loop

## Arrays

### General Comments

Series of values of the same type, stored sequentially

* Numbers used to identify the array elements are called *subscripts*,
*indices* or *offsets*, and must be integers

> ### Pitfalls
> 
> When assigning value to a non-exist array element, the compiler would
> place data in locations possibly used for other data.
> 
> ```c
> float debts[20]
> 
> debts[20] = 324.324     // no such array element
> debts[33] = 324.3       // no such array element
> ```

## Using a `for` Loop with an Array

* You can use a `#define` to create a manifest constant to specify
the size of the array
* It's good to have a function *echo* the values just put in

> ### Program for power
> 
> * *driver* is a short program to test a function.
> * `scanf()` returns 2 when reads two values.

> ### Using Function with  Return values
> 
> * You can omit the *forward* declaration when put function definition
> before `main()`

### To define a function takes a `int` argument and returns a `long` value.

```c
long foo(int n)
{
        statements;
    return ((long) n) * n;
}
```
