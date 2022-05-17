# Data Type

``` mermaid
gantt
    dateFormat DD-MM-YYY
    axisFormat %m/%y

    title Example
    section example section
    activity :active, 01-02-2019, 03-08-2019
```
## 0. Data-Type Key words

1. Original K&R Keywords
    * `int`
    * `long`
    * `short`
    * `unsigned`
    * `char`
    * `float`
    * `double`
1. C90 K&R Keywords
    * `signed`
    * `void`
1. C99 Keywords
    * `_Bool`
    * `_Complex`
    * `_Imaginary`

The types created with these keywords can be divided into two families
    on the basis of how they are stored in the computer:
    *integer* types and *floating-point* types.

> * Bits: smallest unit of memory is a bit, can hold `0` and `1`
> * Byte: usual unit of computer memory.
>   * **A byte is 8 bits**.
>   * 256 possible bit patterns in an 8-bit byte.
> * Words: natural unit of memory for a given computer design.
>   * Lager word size enable faster transfer and allow
>        more memory to be accessed.

### Integer Versus Floating-Point Types

Floating-Point: involves breaking a number in to fractional part
    and an exponent part and store the part separately

* An integer has no fractional part; a floating-point number
    can have a fractional part.
* Floating-point numbers can represent a much larger range of values than
    integers can. See Table 3.3 near the end of this chapter.
* For some arithmetic operations, such as subtracting one large number
    from another, floating-point numbers are subject to greater loss of precision.
* floating-point values are often approximations of a true value.
  * 7.0 might be stored as a 6.99999 float value
* Floating_point operations were ***once*** much slower than integer operations

## 1. The int Type

* a signed integer
* range depends on computer system, typically, and `int` use one machine word

### Type `int` Constants

* When type a number without decimal point and without an exponent,
    C recognized it as an integer

### Octal and Hexadecimal

* each digit in a hexadecimal number corresponds to exactly 4 bits
  * hexadecimal digit 3 is 0011
  * hexadecimal digit 5 is 0101
  * hexadecimal digit 35 is 0011 0101
  * hexadecimal digit 53 is 0101 0011
* prefix of `0x` or `oX` means specifying a hexadecimal
* prefix of `0` means specifying a octal
* ***the number is always stored in the binary code used by the computer***

### Display Octal and Hexadecimal

* `%o` for octal
* `%x` for hexadecimal
* to display the C prefix, use `%#o` and `%#x`

```c
#include <stdio.h>
int main(void)
{
    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    return 0;
}
```

## 2. Other Integer Types

* `short int` or `short` may use less storage than `int`.(signed type)
* `long int` or `long` may use more storage than `int`.(signed type)
* `long long int` or `long long` may use less storage more `int`.(signed type)
  * At the minimum, it must use at least 64 bits.
* `unsigned int` or `unsigned` used for nonnegative values
  * a 16-bit unsigned int allows a range from 0 to 65535 in value
        instead of from –32768 to 32767 .
* `unsigned long int` or `unsigned long` and
    `unsigned short int` or `unsigned short`
* `short` , `short int` , `signed short` , and `signed short int` are all
    names for the same type.

---

* The minimum range for both `short` and `int` is –32,767 to 32,767,
    corresponding to a 16-bit unit
* the minimum range for `long` is –2,147,483,647 to 2,147,483,647,
    corresponding to a 32-bit unit
* For `unsigned short` and `unsigned int` , the minimum range is 0 to 65,535
* For `unsigned long` , the minimum range is 0 to 4,294,967,295
* The `long long type` is intended to support 64-bit needs.
    Its minimum range is a substantial
    –9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
* the minimum range for `unsigned long long` is
    0 to 18,446,744,073,709,551,615

---

When to use the various data types?

* First, consider `unsigned`
* Use `long` when use number `long` can handle and `int` can not
  * on systems for which long is bigger than int , using long can slow down
  calculations
* Use `short` to save storage space

### long Constants and long long Constants

* Depends on the size of the number, it will stored as the order of
    `int`, `long`, `unsigned long`, `long long`, `unsigned long long`
* Octal and hexadecimal constants stored follow the order of
    int, unsigned `int`, `long`, `unsigned long`,
    `long long`, `unsigned long long`
* `l` or `L` as a suffix to cause a small constant `long`
  * `7l` or `7L`
* `ll` or `LL` to indicate a `long long` constants
  * `7ll` or `7LL`
* `ull` or `ULL` for `unsigned long long`

### Printing short, long, long long, and unsigned Types

* `%u` for `unsigned int`
* `%ld` for `long`, `%lx` for `long hexa`, `%lo` for `long octal`
* `%hd` for `short`, `hx` for `short hexa`, `%ho` for `short octal`
* `%lu` for `unsigned long`, `%hu` for `unsigned short`

## 3. Type char

* technically a integer type
* typically defined as an 8-bit unit of memory.
* C defines a byte to be the number of bits used by type `char`
  * one can have a system with a 16-bit or 32-bit byte and char type.

### Declaring char Variables

`char grade = 'A';`\
`char grade = 65;`\
`beep = '\007';`

### Printing Characters

## Portable Types: stdint.h and inttypes.h

* `<stdint.h>`
* *exact-width type*
  * `int32_t` for 32-bit signed integer
  * exactly 32-bits
* *minimum width types*
  * `int_least8_t` is an alias for smallest available type for 8 bit
  * on a 16-bit machine, `int8_t` would not be defined,
        but a `int_least8_t` can be implemented as a 16-bit integer
* *fastest minimum width types*
  * `int_fast8_t` as an alias for integer type that allowed fastest 8-bit
  signed value
* *maximum width type*
  * `intmax_t` stands for a type can hold any signed integer value
  * `uintmax_t` likely
* `inttypes`
  * `PRId32` as a string for the appropriate specifier for a 32-bit
    signed value.

## float, double and long double

### float

* `float` is able to represent at least six significant figures
* `float` allows a range at least 1.0e-37 to 1.0e37
* Often, system use 32bits to store a floating-point number
  * 8 bits for exponent and its sign
  * 24 bits for non-exponent part (called *mantissa* or *significand*),
        and its sign

### double

* minimum number of significant figures to 10
* typical `double` use 64 bits instead of 32.
  * some system use all 32 additional bits for non-exponent part
  * some use some of the 32 additional part to accommodate a lager exponent
  * either above setting has at least 13 significant figures

### long double

* at least as precise as double

### declaring Floating-point variables

* `float noah, jonah;`
* `double trouble;`
* `float planck = 6.63e-34;`
* `long double gnp;`

### floating-point constant(literals)

* valid floating point constants
  * `3.14159`
  * `.2`
  * `4e16`
  * `.8E-5`
  * `100.`
* By default, the complier assumes floating-point numbers as `double`
    precisions
  * for `some = 4.0 * 2.0;`, `4.0` and `2.0` are stored as `double`,
        only the answer is transferred to `float`, enables greater
        precision, but slow down a program
  * `f` or `F`
    * `2.3f` and `9.11E9F`
    * `l` or `L`
    * `54.3l` and `4.32e4L`
* some complier give support to hexadecimal float-point constant\
    `0xa.1fp10`
  * `a` for 10 in hex
  * `.lf` for 1/16th plus 15/256th
  * `p10` for 2.0e10

## Review

A6:
| Constant  | Type         | Specifier |
| --------  | ----         | --------- |
| 12        | int          | %d        |
| 0x3       | unsigned int | %#x       |
| 'c'       | char         | %c        |
| 2.34E08   | double       | %e        |
| '\040'    | char         | %c        |
| 7.0       | double       | %f        |
| 6L        | long         | %ld       |
| 6.0f      | float        | %f        |
| 0x5.b6p12 | float        | %a        |

A7:
| Constant | Type        | Specifier |
| ---      | ---         | ---       |
| 012      | int         | %#o       |
| 2.9e05L  | long double | %Le       |
| 's'      | char        | %c        |
| 100000   | int         | %d        |
| '\n'     | char        | %c        |
| 20.0f    | float       | %f        |
| 0x44     | int         | %#x       |
| -40      | signed int  | %d        |
