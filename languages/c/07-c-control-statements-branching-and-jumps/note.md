# C Control statements: Branching and Jumping 
## The `if` Statement

```c
if (expression)
    statement
```

* Braces is needed to add more than one statements

## `getchar()` and `putchar()`

### `getchar()`

* `ch = getchar()`
* Takes no arguments
* Returns the next character from input
* same as `scanf("%c", &ch)`

### `putchar()`

* `putchar(ch)`
* Same as `printf("%c", ch)`

### Features

Replace a form of:

```c
ch = getchar();
while (ch != '\n')
{
    ...
    ch = getchar();
}
```

with:

```
while ((ch = getchar()), != '\n')
{
    ...
}
```

* Deals only with characters.
* Don't need format specifiers
* Defined in `stdio.h`
* Are preprocessor `macros` rather than true functions
* The value of `(ch = getchar())` is the value of `ch`
* Consider `while (ch = getchar() != '\n')`

## The `ctype.h` Family of Character Functions

* Take a character as an argument and return nonzero (true) if the character
belongs to a particular category and zero otherwise.
* `isalpha()` returns a nonzero value if the argument is a letter.

### The `ctype.h` Character-Testing Functions

Punctuation character
: Any printing character other than a space or an alphanumeric character

Standard blank character
: space, horizontal tab, or newline

Whitespace character
: A space, newline, formfeed, carriage return, vertical tab, horizontal, tab
, or possibly, other locale-defined character.

|Name|True If the Argument Is|Examples
|-|-|-|
|`isalnum()`|Alphanumeric (alphabetic or numeric)|
|`isalpha()`|Alphabetic|
|`isblank()`|A standard blank character (`space`, `\t`, or `\n`)  or any additional locale specific character so specific|
|`iscntrl()`|A control character, such as `^b`|
|`isdigit()`|A digit|
|`isgraph()`|A printing character other than a space|
|`islower()`|A lowercase character|
|`isupper()`|An uppercase character|
|`isprint()`|A printing character|
|`ispunct()`|A punctuation character (any printing character other than a space or an alpha numeric character)|
|`isspace()`|A whitespace character(a `space`, `\n`, formfeed, carriage return, vertical tab, horizontal tab, or, possibly, other locale-defined character|
|`isxdigit()`|A hexadecimal-digit character|

### The `ctype.h` Character-Mapping Functions

|Name|Action|
|-|-|
|`tolower()`|<++>|
|`toupper()`|<++>|

## Multiple Choice `else if`

* The *nested* `if else` form and `else if` form are equivalent
* The compiler limits, the C99 standard requires that a minimum of 127 levels
of nesting.

## Paring `else` with `if`

```c
if (expression)
    if(expression)
        statement
else
    statement
```

* An `else` goes with the most recent `if` *unless braces indicate otherwise*

To make `else` goes with first `if`

```c
if (expression)
{
    if(expression)
        statement
}
else
    statement
```

## Logical

|Operator|Meaning|
|:-:|-|
|`&&`|and|
|`||`|or|
|`!`|not|

## Alternate Spellings: The `iso646.h` Header File

* C99 added alterative spellings of the logical operators, which defined in
`iso.646.h` header file
* You can use `and` instead of `&&`, `or` instead of `||`, and `not` insted of
`!`

### Alternative Representations of Logical Operators
|Traditional|`iso646.h`|
|:-:|:-:|
|`&&`|`and`|
|`||`|`or`|
|`!`|`not`|

## Precedence

* The `!` operator has a very high precedence
  * Higher than `*`
  * Same as `++`
  * Just below `()`
* The `&&` has higher precedence than `||`
  * Both below relational operators
  * Both above assignment

## Order of Evaluation

* The logical expression are evaluated from **left to right**.
* The `&&` and `||` are sequence points, so all side effects take place before
a program moves from one operand to the next.
* Guarantees that as soon as an element is found that invalidates the
expression as a whole, the evaluation stops.
  * `if (number != 0 && 12/number ==2)`
    * If the number has the value 0, the relational expression is not evaluated
    any further.

## Ranges

* `if (range >= 90 && range <= 100)`
* As for `if (90 <= range <= 100)`, it's a *sematic error*, not a syntax error.

### To Test Whether a Character is a Lowercase Letter

`if (ch >= 'a' && <= 'z')`
* Works for ASCII
* More portable way is to use `islower()`

## The Condition Operator: `? :`

### Comments

`expression1 ? expression2 : expression3`

If *expression1* is true (nonzero), the whole conditional expression has the
same value as *expression2*...

* *Conditional expression* uses the `? :` conditional operator
* `? :` is a two-part operator with three operand
* It's called *ternary* operator, like *unary* and *binary* 
* Can always replaced by a `if else` statement, but it is more compact, and may
result in more compact program code depends on the compiler.

### Example

`x = (y < 0 ? -y : y);`
* If y is less than zero, x = -y; otherwise, x = y.
* Same as:
```c
if (y < 0)
    x = -y;
else
    x = y;
```

## The `continue` Statement

### General Comments

* Can be used in three loop forms.
* When encountered, the rest of the on-going iteration is skipped, and the
next iteration is started.
* Affects only the innermost structure containing it when in nested structures.
* **Works just with loops**

### Two ways to avoid `continue`:
  * Omitting the `continue` and make the remaining part of the loop an `else`
  block.
  * Or just reverse the expression of `if` statement

### Advantages

* Make code concise and enhance readability
* Used as a placeholder:

```c
while (getchar() != '\n')
    ;

// can be replaced by
while (getchar() != '\n')
    continue;
```

### Where does the loop resume?

* For `while` and `do while`, the next expression evaluated is the loop
test condition.
* For `for`, the next actions is to evaluate the update expression and then
the loop test expression.

## The `break` Statement

### General Comments

* Can break the loop that encloses it and proceed to next stage of the program.
* When inside nested loops, it affects only the innermost loop containing it.
* Some times used to leave the loop when there are two separate reason to
leave.
* An essential adjunct to the `switch` statement
* **Works with loops and `switch`**

### Examples

```c
while (ch = getchar() != '\n')
{
    if (ch == '\t')
        break;
    putchar(ch);

// Can be replaced by:
while ((ch = getchar()) != '\n' && ch != '\t')
    putchar(ch);
}
```

### To avoid `break`

* Adding some additional logic expressions

## The `switch` Statement

### Form

```c
switch (integer expression)
{
    case constant1:
        statements      <--optional
    case constant2:
        statements      <--optional
    default:
        statements      <--optional
}
```

### General Comments

* To choose one of several alternatives
* The test expression should be one with an integer value (including `char`)
* The `case` labels must be integer-type (including `char`) constants or
integer constant expressions (expressions containing only integer constants),
means you can't use a variable for a `case` label

### Usage

1. Scans the list of *labels* until it finds one matching the value.
2. The program jumps to that line.
3. When there is no match, if `default:` exist, jumps there. Otherwise, the
program proceeds to the statement following the switch.

### `break` in `switch`

* Break out of the switch, and skip to the next statement after `switch`
* Without `break`, every statement from matched label to the end of `switch`
will be processed.

> When there's no action in one `case`, the program will continue process to the next
line, until a `break` is met, regard less of the remaining `case`

## Reading Only The First Character of a Line

### Form

```c
// skip rest of input line
while (getchar() != '\n')
    continue;
```

```c
if (ch == '\n')
    continue
```

### General Comments

* The function return value is not assigned to `ch`
* The last character discarded is the newline (\n) character, the next character to
be read is the first character of the next line
* The `toupper()` from `ctype.h` can convert all letters to uppercase

## The `goto` Statement

### Examples

```c
if (size > 12)
    goto a;
goto b;

a: cost = cost * 1.05;
flag = 2;
b: bill = cost * flag;
```

### General Comments
* `goto` staTement has two part--the `goto` and a label name.

### Usage

> Only use the `goto` when you need to get out of a nested set of loops
