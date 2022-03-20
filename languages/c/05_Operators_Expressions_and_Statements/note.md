## Fundamental Operators

### Assignment Operator

| Name                | Symbol |
| ---                 | :---:  | --- |
| Assignment Operator | `=`    |

### Arithmetic Operator

| Name                              | Symbol      | Comment                                |
| ---                               | :---:       | ---                                    |
| Addition Operator                 | `+`         | have alias of binary, dyadic, operator |
| Subtraction Operator              | `-`         | have alias of binary, dyadic, operator |
| Sign Operator                     | `-` and `+` | have alias of unary operator           |
| Multiplication Operator           | `*`         | <++>                                   |
| Division Operator                 | `/`         | <++>                                   |
| Modulus Operator                  | `%`         | <++>                                   |
| Increment and Decrement Operators | `++` `--`   | <++>                                   |

### Miscellaneous Operator

| Name            | Symbol |
| ---             | :---:  | --- |
| Sizeof Operator | sizeof |
| Cast Operator   | (type) |

## Some Terminology

| Name                  | Definition                                           |
| ---                   | ---                                                  |
| data object           | <++>                                                 |
| object                | alias for data object                                |
| lvalue                | <++>                                                 |
| object locator        | <++>                                                 |
| modifiable lvalue     | value can be changed                                 |
| non-modifiable lvalue | value can be changed                                 |
| rvalue                | quantities can be assigned to modifiable value       |
| expression            | a substitute for rvalue                              |
| operand               | <++>                                                 |
| operator              | <++>                                                 |
| truncation            | any fraction result of integer division is discarded |
| expression tree       | <++>                                                 |
| side effect           | the modification of a data object                    |

## Assignment

* C accepts a triple assignment.

## Division

* Integer division does not round to the nearest integer, but always truncates
  * before C99, the division engages with the *round down*
  * after: ***truncate toward zero***
* As for a mix-type division, the numbers are converts to a single type

## Operator Precedence

### Operator in Order of Decreasing Precedence

| Operator         | Associativity |
| :---:            | :---:         |
| `()`             | Left to right |
| `+` `-` (unary)  | Right to left |
| `*` `/`          | Left to right |
| `+` `-` (binary) | Left to right |
| `=`              | Right to left |

## Some Additional Operator

### The `sizeof` operator and the `size_t` Type

* When the operand is a Type, it must be enclosed in a parentheses
* returns a value of type `size_t`
  * display by the specifier `%zd`
* `typedef` allows create an alias for an existing type
  * `typedef double real`

### Modulus Operator

* help control the flow of a program
* `a % b == a - (a / b) * b`

### Increment and Decrement Operators

| Operator        | Mode         | Explanation                    |
| :-:             | -            | -                              |
| `++a` and `--a` | prefix mode  | get th value after a changed   |
| `a++` and `a--` | postfix mode | get the value before a changed |

Produces slightly more efficient machine language code, which depends on the
complier.

> They have a high precedence, just lower to parentheses

> Better not to use the above mentioned operator twice in one expression

## Expressions and Statements

Expression
: An expression is a combination of operators and operands.

Statements
: A statement is a command to the computer.

### Expression

> ### Subexpressions
> For `2 * 3 + 4 * 5`, it is equivalent to `(2 * 3) + (4 * 5)`\
> so `2 * 3` and `4 * 5` are subexpressions.

#### every expression has a value

| Expression      | Value |
| :-:             | :-:   |
| -4 + 6          | 2     |
| c = 3 + 8       | 11    |
| 5 > 3           | 1     |
| 6 + (c = 3 + 8) | 17    |

### Statements

* *null statement*
* *expression statement*
* *declaration statement*
* *assignment statement*
* *function statement*
* *compound statement*
* *structured statement*
* *return statement*

| Statements              | Examples                           |
| -                       | -                                  |
| Declaration statement   | int toes;                          |
| Assignment              | toes = 12;                         |
| Function call statement | printf("%d\n", toes);              |
| Structured statement    | while (toes < 20) toes = toes + 2; |
| Return statement        | return 0;                          |
| null                    | `;`                                |

### Side Effects and Sequence Points

Side Effects
: The modification of a data object, main intent of a statement is evaluating
expression

Sequence Points
: A point in program execution at which all side effects are evaluated;
before going on to the next step;\
Marked by a semicolon `;`;\
The end of any full expression is a sequence point.

Full Expression
: Not a subexpressions fo a lager expression;

Compound Statements
: Blocks

## Type Conversions

### Basic rules

* `char` and `short`, both `signed` and `unsigned`, are converted to
`int` and `unsigned int`.
* `float` is converted to `double`
* Converted to lager type is called a *promotions*
* Operations involve two types, both values are converted to the higher one's
type
* Type rankings:
    1. `long double`
    1. `double`
    1. `float`
    1. `unsigned long long`
    1. `unsigned int`
    1. `int`
* The final result of the calculations is converted to the type of the
variable being assigned a value, may cause *promotion*, or *demotion*
* When passed as arguments, `char` and `short` are converted to `int`,
and `float` to `double`

### Demotion Not fit

| Start          | Destination      | Consequence              | Examples                    |
| -              | -                | -                        | -                           |
| integer        | unsigned integer | extra bit are ignored    | to `unsigned char`, get 256 |
| integer        | signed integer   | implementation-dependent | <++>                        |
| floating-point | integer          | <++>                     | <++>                        |

## The Cast Operator

* Demand the precise type conversion you want
* `mice = (int) 1.6 + (int) 1.7`

## Function with Arguments

Prototype
: Function declaration describe function's return value and its arguments

* Declare an argument creates a *formal argument* or *formal parameter*
* *assign* a value or *pass* a value
* Variable names are private to the function.
* With the *prototype* define the type of the argument, an automatic
*typecast* will occur.

> ### Arguments Versus Parameters (C99)
>
> * *argument* for actual argument or actual parameter
> * *parameter* for formal argument or formal parameter

> ### Note
> 
> When the variable in the *expression* of a *while loop* hasn't been assign
> to a value, the comparison will made to a garbage value that happens to
> be at the memory location.
