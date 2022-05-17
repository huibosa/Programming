## Character Strings: An Introduction

### Type `char` Arrays and the *Null Character*

![strinarr](./images/strinarr.png)

* Strings are stored in an array of type `char`.
* Character in a string are stored in adacent memory cells.
* `\0` is the *null character*, use to mark the end of a string. Means the
array must have at least one more cell than the number of character to be stored.
* An array is an ordered sequence of data elements of one type, each elements
can store one `char`-type value.

![arrdeclare](./images/arrdeclare.png)

### Using strings

* When `scanf()` reads the input, it put the null character in to the `name`
array.
* `scanf()` stops reading at the first *whitespace* (blank, tab, or newline).

### Strings versus characters

![strvsch](./images/strvsch.png)

`"x"` and `'x'`:

* `'x'` is a basic type `char`, `"x"` is an array of `char`.
* Former has two characters: `'x'` and `\0`.

### The `strlen()` and `sizeof()` Functions

![strlen](./images/strlen.png)

The `strlen()`:

* Give the exact number of characters
* The *null character* tells `strlen` when to stop

The `sizeof()`

* Counts the *null character*.
* If program don't tell hoe much memory to set aside to store a phrase, the
`sizeof()` has to count the number of characters between the double quotes
itself.

The C99 and C11 standards use a `%zd` specifier for the type used by the
`sizeof()`.  This also applies for type returned by `strlen()`.

Whether to use the parentheses around `sizeof` depend on whether you want the
size of type or the size of a particular quatity.

## Constants and C Preprocessor

You can just type a constant in the expression or use a *symbolic constant*.

```c
circumference = 3.14159 * diameter;
circumference = pi * diameter;
```

```c
#define NAME value;
```

* When compiled, the `value` will substitute everywhere the `NAME` have been
used, which is called *compile-time substitution*
* Such defined constants are termed *manifest constants*

![preprocessor](./images/preprocessor.png)

> Naming conventions include prefixing a name with a `c_` or `k_` to indicate
a constant.

```c
#define BEEP 'a'
#define TEE 'T'
#define ESC '033'
#define OOPS "Now you have done it!"

// the following is wrong
#define TOES = 20
```

### The const Modifier

```c
const int MONTHS = 12;
```

* Make `MONTHS` a read only value: you can display `MONTHS` and use it, but
not alter the value.
* allows for declare a type
* There's a third way to create a constant -- `enum`

### Manifest Constants on the job

The `limits.h` and `float.h` supply detailed information about the size limit
of integer types and floating types.

The `limits.h`:

```c
#define INT_MAX +32767
#define INT_MIN -32768

printf("Maximum int value on this system = %d\n", INT_MAX);
```

`INT_MAX` and `INT_MIN` represent the largest and smallest possible values for
the `int` type. If your system uses a 32-bit `int`, the file would provide
different valus for the symbolic constants.

| Symbolic Constant | Represents                         |
| :---:             | ---                                |
| `CHAR_BIT`        | Number of bits in a `char`         |
| `CHAR_MAX`        | Maximum `char` value               |
| `CHAR_MIN`        | Minimum `char` value               |
| `SCHAR_MAX`       | Maximum `signed char` value        |
| `SCHAR_MIN`       | Minimum `signed char` value        |
| `UCHAR_MAX`       | Maximum `unsigned char` value      |
| `SHRT_MAX`        | Maximum `short` value              |
| `SHRT_MIN`        | Minimum `short` value              |
| `USHRT_MAX`       | Maximum `unsigned short` value     |
| `INT_MAX`         | Maximum `int` value                |
| `INT_MIN`         | Minimum `int` value                |
| `UINT_MAX`        | Maximum `unsigned int` value       |
| `LONG_MAX`        | Maximum `long` value               |
| `LONG_MIN`        | Minimum `long` value               |
| `ULONG_MAX`       | Maximum `unsigned long` value      |
| `LLONG_MAX`       | Maximum `long long` value          |
| `LLONG_MIN`       | Minimum `long long` value          |
| `ULLONG_MAX`      | Maximum unsigned `long long` value |

The `float.h` file defines constants such as `FLT_DIG` and `DBL_DIG`, which
represent the number of significant figures supported by the `float` type and
the `double` type.

| Symbolic Constant | Represents                                                                             |
| :---:             | ---                                                                                    |
| `FLT_MANT_DIG`    | Number of bits in the mantissa of a `float`                                            |
| `FLT_DIG`         | Minimum number of significant decimal digits for a `float`                             |
| `FLT_MIN_10_EXP`  | Minimum base-10 negative exponent for a `float` with a full set of significant figures |
| `FLT_MAX_10_EXP`  | Maximum base-10 positive exponent for a `float`                                        |
| `FLT_MIN`         | Minimum value for a positive `float` retaining full precision                          |
| `FLT_MAX`         | Maximum value for a positive `float`                                                   |
| `FLT_EPSILON`     | Difference between 1.00 and the least `float` value greater than 1.00                  |

## Exporing and Exploiting `printf()` and `scanf()`

Called *input/output functions*, or *I/O* functions for short.

### The `printf()` Function

These `%d` or `%c` notations are called `conversion specifications` because they
specify how the data is to be converted into displayable form.

|Conversion|Output Specification|
|:---:|---|
|`%a`|Floating-point number hexadecimal digits and p-notation(C99/C11)|
|`%A`|Floating-point number hexadecimal digits and P-notation(C99/C11)|
|`%c`|Single character|
|`%d`|Signed decimal integer|
|`%e`|Floating-point number, e-notation|
|`%E`|Floating-point number, e-notation|
|`%f`|Floating-point number, decimal notation|
|`%g`|Use `%f` or `%e`, depending on the value. The `%e` style is used if the exponent is less than −4 or greater than or equal to the precision.|
|`%G`|Use `%f` or `%E`, depending on the value. The `%E` style is used if the exponent is less than −4 or greater than or equal to the precision.|
|`%i`|Signed decimal integer (same as `%d`)|
|`%o`|Unsigned octal integer|
|`%p`|A pointer|
|`%s`|Character string|
|`%u`|Unsigned decimal integer|
|`%x`|Unsigned hexadecimal integer, using hex digits `0f`.|
|`%X`|Unsigned hexadecimal integer, using hex digits `0F`.|
|`%%`|Prints a percent sign|

### Using printf()

```c
printf(Control-string, item1, item2, ...);
```

![ctlstr](./images/ctlstr.png)

```c
#define PI 3.14159

printf("The value of pi is %f.\n", PI);
```

*Control string* is a character string describing how the item are to be printed.
contains:
* Characters that are actually printed
* Conversion specifications

![ctlstr2](./images/ctlstr2.png)

```c
printf("Farewell! thou art too dear for my possessing,\n");
printf("%c%d\n", '$', 2 * cost);
```

*Item* can be variables, constants or expressions
*Control string* should contain a conversion specifier for each item

### Conversion Specification Modifier for `printf()`

The `printf()` modifier:

|Modifier|Meaning|Example|
|:---:|---|---|
|flag|Five flags (`-`, `+`, `space`, `#`, and `0`). Zero or more flags may be present|`%-10d`|
|digits(s)|Minimum field width. A wider field will be used if the printed number or string won't fit in the field.|`%4d`|
|.digit(s)|Precision. For `%e`, `%E`, and `%f` conversions, the number of digits to be printed to the right of the decimal. For `%g` and `%G` conversions, the maximum number of significant digits. For `%s` conversions, the maximum number of characters to be printed. For integer conversions, the minimum number of digits to appear; leading zeros are used if necessary to meet this minimum. Using only `.` implies a following zero, so `%.f` is the same as `%.0f`.|`%5.2f`prints a `float` in a field five characters wide with two digits after the decimal point.|
|`h`|Used with an integer conversion specifier to indicate a `short int` or `unsigned short int` value|`%hu`, `%hx`, `%6.4hd`|
|`hh`|Used with an integer conversion specifier to indicate a `signed char` or `unsigned char` value|`%hhu`, `%hhx`, `%6.4hhd`|
|`j`|Used with an integer conversion specifier to indicate an `intmax_t` or `uintmax_t` value; these are types defined in `stdint.h`|`%jd`, `%8jX`|
|`l`|Used with an integer conversion specifier to indicate a `long int` or `unsigned long int`|`%ld`, `%8lu`|
|`ll`|Used with an integer conversion specifier to indicate a `long long int` or `unsigned long long int`|`%lld`, `%8llu`|
|`L`|Used with an follow-point conversion specifier to indicate a `long double` value|`%Lf`, `%10.4Le`|
|`t`|Used with an integer conversion specifier to indicate a `ptrdiff_t` value. This is the type corresponding to the difference between two pointers. (C99).|`%td`, `%12ti`|
|`z`|Used with an integer conversion specifier to indicate a `size_t` value. This is the type returned by `sizeof`. (C99).|`%zd`, `%12zx`|

> The standard only provides the return value of `sizeof` be an `unsigned`
> integer. Thus it could be `unsigned int`, `unsigned long`, or even `unsigned
> long long`
> 
> First, the `stddef.h` header file (included when you include stdio.h) defines
> `size_t` to be whatever the type your system uses for `sizeof`; this is called
> the *underlying type*.
> 
> Second, `printf()` uses the `y` modifier to indicate the corresponding type
> for printing.
> 
> Similarly, C defines the `ptrdiff_t` type and t modifier to indicate whatever
> underlying signed integer type the system used for the difference between
> two addresses.

> No special conversion specifier is needed for displaying type `float` because
`float` value were automatically converted to `double` before being used in
an expression or as an argument

The `printf()` Flags:

|Flag|Meaning|Example|
|:---:|---|---|
|`-`|The item is left-justified; that is, it is printed beginning at the left of the field|`%-20s`|
|`+`|With a plus sign if positive, and with a minus sign if negative|`%+6.2f`|
|`space`|With a leading space if positive, and with a minus sign if negative|`%6.2f`|
|`#`|Use an alternative form for the conversion specification. Produces an initial `0` for the `%o` form and an initial `0x` or `0X` for the `%x` or `%X` form, respectively. For all floating-point forms, `#` guarantees that a decimal-point character is printed, even if no digits follow. For `%g` and `%G` forms, it prevents trailing zeros from being removed|`%#o`, `%#8.0f`, `%+#10.3E`|
|`0`|For numeric forms, pad the field width with leading zeros instead of with spaces.  This flag is ignored if a `-` flag is present or if, for an integer form, a precision is specified|`%010d`, `%08.3f`|

### What Does a Conversion Specification Convert

A conversion specification converts a value stored in the computer in some
binary format to a series of characters (a string) to be displayed.

For example, the number 76 may be stored internally as binary 01001100.

* The `%d` conversion specifier converts this to the characters 7 and 6,
displaying 76.
* The `%x` conversion converts the same value (01001100) to the hexadecimal
representation `4c`.
* The `%c` converts the same value to the character representation `L`.

### Mismatched conversion


```c
#define PAGES 336
#define WORDS 65618
int main(void)
{
    short num = PAGES;
    short mnum = -PAGES;

    printf("num as short and unsigned short: %hd %hu\n", num, num);
    printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
    printf("num as int and char: %hd %c\n", num, num);
    printf("WORDS as int, short, and char: %d %hd %c\n", 
            WORDS, WORDS, WORDS);

    return 0;
```

---

When using a `%u` conversion to convert a negative value:

* `short int` is 2 bytes in size.
* The system use a method called *two's complement* to represent signed
  integers.
  * 0 ~ 32767 represent themselves, 32768 ~ 65535 represent negative number
* 65535 being -1, so `-336` is represented by `65536 - 336` or `65200`.
* 65534 being -2.

> Note: Not all system use this method.

---

When convert a value greater than 255 to a character:

* On one specific system, a `short int` is 2 bytes and a `char` is 1 byte.
* When using `%c` it looks only 1 byte out of 2 used to hold 336.
* This truncation divide the integer by 256 and keeping just the remainder.
(or to say the number is interpreted *modulo* 256).

![character](./images/charracter.png)

---

When printing a integer lager than the maximum `short int` (32767)

* 65618 is stored as a 4-byte `int` value
* When printing using `%hd`, `printf()` only look at the last 2 bytes, which
corresponding to using the remainder after dividing 65536.
* A remainder between 32767 and 65536 would be printed as a negetive number.

---

```c
float n1 = 3.0;
double n2 = 3.0;
long n3 = 2000000000;
long n4 = 1234567890;

printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
printf("%ld %ld\n", n3, n4);
printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
```

When print `n3` a type `long` value using the `%e` specifier:

* First, the `%e` specifier causes `printf()` to expect a type `double` value,
which is an 8-`byte` value on this system.  When `printf()` looks at `n3`,
which is a 4-`byte` value on this system, it also looks at the adjacent 4
`bytes`. Therefore, it looks at an 8-`byte` unit in which the actual `n3` is
embedded.
* Second, it interprets the bits in this unit as a floating-point number. Some
bits, for example, would be interpreted as an exponent. So even if `n3` had
the correct number of bits, they would be interpreted differently under `%e`
than under `%ld`. The net result is nonsense.

> `float` is converted to `double` when used as arguments to `printf()`

### Passing Arguments

When computer put values on stack, it is guided by the value types, not the
conversion specifier

```c
printf("%ld %ld %ld %ld\n", n1, n2, n3)
```

When the computer puts these values on the *stack*, it is guided by the types
of the variables, not by the conversion specifiers.

Consequently, for `n1`, it places 8 bytes on the stack (float is converted to
double), and 8 more bytes for `n2`, followed by 4 bytes each for `n3` and `n4`.
Then control shifts to the printf() function.

`printf()` reads the values off the stack but, when it does so, it reads
them according to the conversion specifiers.

* `printf()` reads the first 4 bytes in the stack as its first value. This is
just the first half of n1, and it is interpreted as a `long` integer.
* The next `%ld` specifier reads 4 more bytes; this is just the second half of
`n1` and is interpreted as a second `long` integer.
* The third and fourth instances of `%ld` cause the first and second halves
of n2 to be read and to be interpreted as two more long integers,
* So although we have the correct specifiers for `n3` and `n4`, `printf()`
is reading the wrong bytes.

![stack](./images/stack.png)
  
### The Return value of `printf()`

The `printf()` returns the number of characters it printed. If there is an
output error, `printf()` returns a negative value. (Some ancient versions of
`printf()` have different return values.)


### Printing long strings

```c
    // put line breaks between elements
    printf("The printf() function printed %d characters.\n",
            rv);

    // wrong try
    printf("The printf() function printed %d
                characters.\n", rv);


    // use two printf()
    printf("Here's one way to print a ");
    printf("long string.\n");

    // use "\", which must be put the far left or extra space will show
    printf("Here's another way to print a \
long string.\n");

    // one quote string with another, separate only by whitespace
    printf("Here's the newest way to print a "
            "long string.\n");
```
## Using `scanf()`

`scanf()` converts string input into other forms:

* Integers
* Floating-point numbers
* Characters
* C strings

The `scanf()` uses whitespaces (newlines, tabs, and spaces) to divide input
into separate field. It matches up consecutive conversion specifications to
consecutive fields, skipping over whitespace in between.

> The only exception to this is the %c specification, which reads the very next
character, even if that character is whitespace.

* If two words separate by the whitespace is give to the `scanf()`, only the
  fist one is read, the second one is left in the 'buffer', which will be read
  when next `scanf()` comes.
* `printf()` use `%f`, `%e`, `%E`, `%g`, and `%g` for both `float` and
  `double`, while `scanf()` just use them for `float`.

### ANSI C Conversion Specifier for `scanf()`

|Conversion specifier|Meaning|
|:---:|---|
|`%c`|Interpret input as a character|
|`%d`|Interpret input as a signed decimal integer|
|`%e`, `%f`, `%g`, `%a`|Interpret input as a floating-point number (`%a` is C99)|
|`%e`, `%f`, `%g`, `%a`|Interpret input as a floating-point number (`%A` is C99)|
|`%i`|Interpret input as a signed decimal integer|
|`%o`|Interpret input as a signed octal integers|
|`%p`|Interpret input as a pointer (an addresse)|
|`%s`|Interpret input as a string. Input begins with the first non-whitespace character and includes everything up to the next whitespace character|
|`%u`|Interpret input as an unsigned decimal integer|
|`%x`, `%x`|Interpret input as a signed hexadecimal integer|

### conversion modifier for scanf()

> When more than one in a specifier, they should appear in the same order as
shown follow.

|Modifier|Meaning|Example|
|:---:|---|---|
|`*`|Suppress assignment (see text)|`%*d`|
|digits(s)|Maximum field width. Input stops when the maximum field width is reached or when the first whitespace character is encountered, whichever comes first.|`%10s`|
|`hh`|Read an integer with a `signed char` or `unsigned char`|`%hhd`, `%hhu`|
|`ll`|read an integer with a `long long` or `unsigned long long` (C99)|`%lld`, `%llu`|
|`h` `l` `l`|`%hd` and `%hi` indicate that the value will be stored in a `short int`. `%ho`, `%hx`, and `%hu` indicate that the value will be stored in an `unsigned short int`. `%ld` and `%li` indicate that the value will be stored in a `long`. `%lo`, `%lx`, and `%lu` indicate that the value will be stored in `unsigned long`.  `%le`, `%lf`, and `%lg` indicate that the value will be stored in type `double`.  Using `L` instead of `l` with `e`, `f`, and `g` indicates that the value will be stored in type `long double`. In the absence of these modifiers, `d`, `i`, `o`, and `x` indicate type `int`, and `e`, `f`, and `g` indicate type float.||
|`j`|When followed by an integer specifier, indicates using `intmax_t` or `uintmax_t` type (C99)|`%jd`, `%ju`|
|`z`|When followed by an integer specifier, incdicates using the type returned by `sizeof` (C99))|`%zd`, `%zo`|
|`t`|When followed by an integer specifier, indicates using the type used to represent the difference between two pointers (C99).|`%td`, `%tx`|

> Some of the features have been ommited, which primarily facilitate reading
selected data from highly formatted sources, such as punched cards or other
data records.

### The `scanf()` View of Input

When using a `%d` specifier to read an integer:

* The `scanf()` skips over whitespace character until finds a non-whitespace
character.
* Begins reading input a character at a time, expects a digit or a sign
(`+` or `-`), when find one, it saves it and continues reading until encounters
a nondigit.
* Then `scanf()` places the nondigit back into the input.

> When the first non-whitespace character an `A` instead of a digit
> 
> * Then `scanf()` stops right there and places the `A` back in the input. No
> value is assigned to the specified variable, and the next time the program
> reads input, it starts at the `A` again.
> * If your program has only `%d` specifiers, `scanf()` will never get past
> that A.
> * If you use a `scanf()` statement with several specifiers, C requires the
> function to stop reading input at the first failure.

---

The `%x` specifier requires that `scanf()` recognize the hexadecimal digits `a–f`
and `A–F`. Floating-point specifiers require `scanf()` to recognize decimal
points, e-notation, and the new p-notation.

---

If you use an `%s` specifier, any character other than whitespace is acceptable,
so `scanf()` skips whitespace.

---

When using a `%c` specifier, if the next input character is a space or a
newline, a space or a newline is assigned to the indicated variable; whitespace
is not skipped.

### Regular Characters in the Format String

```c
scanf("%d,%d" &n, &m);
```
The `scanf()` function interprets this to mean that you will type a number,
type a comma, and then type a second number:

* 88,121
* 88,`space`121
* 88,`newline`121

---

A space in the format string means to skip over any whitespace before the next
input item:

```c
scanf("%d ,%d", &n, &m);
```

Will accept:

* 88,121
* 88`spacespace`,121
* 88`space`,`spacespace`121


Except for `%c`, the specifiers automatically skip over whitespace preceding an
input value:

```c
scanf("%d%d", &n, &m)   // behaves same as
scanf("%d %d", &n, &m)
```

If `%c` is preceded by a space in the format string `string()` does skip to
the first non-whitespace character:

```c
scanf("%c", &ch)`       // reads first character
scanf(" %c", &ch)`      // reads the first non-whitespace character
```

### The `Scanf()` Return Value

Returns the number of items that successfully reads

* When reads no value, returns `0`
* Return `EOF` when detects end-of-file

### The `*` Modifier with `printf()` and `scanf()`

As for `printf()`:

Using `*` instead of a number for the field width

If you have the conversion specifier `%*d`, the argument list should include a
value for `*` and a value for `d`. The technique also can be used with
floating-point values to specify the precision as well as the field width:

```c
unsigned width, precision;
int number = 256;
double weight = 242.5;

printf("Enter a field width:\n");
scanf("%u", &width);
printf("The number is: %*d:\n", width, number);
printf("Now enter a width and a precision:");
scanf("%u %u", &width, &precision);
printf("Weight = %*.*f\nDone!\n", width, precision, weight);
```

As for `scanf()` When placed between the `%` and the specifier letter, `*`
causes that function to skip over corresponding input.

```c
printf("Please enter three integers:");
scanf("%*d %*d %d", &n);
printf("The last integers was %d\n", n);
```

### Usage Tips for printf()

### Locale Choices

