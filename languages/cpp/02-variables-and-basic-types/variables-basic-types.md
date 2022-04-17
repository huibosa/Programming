[toc]

## Primitive Built-in Types

### Arithmetic Types

| Type          | Meaning                           | Minimum Size          |
| ------------- | --------------------------------- | --------------------- |
| `bool`        | boolean                           | NA                    |
| `char`        | character                         | 8 bits                |
| `wchar_t`     | wide character                    | 16 bits               |
| `char16_t`    | Unicode character                 | 16 bits               |
| `char32_t`    | Unicode character                 | 32 bits               |
| `short`       | short integer                     | 16 bits               |
| `int`         | integer                           | 16 bits               |
| `long`        | long integer                      | 32 bits               |
| `long long`   | long integer                      | 64 bits               |
| `float`       | single-precision floating-point   | 6 significant digits  |
| `double`      | double-precision floating-point   | 10 significant digits |
| `long double` | extended-precision floating-point | 10 significant digits |

#### Signed and Unsigned Types

### Type Conversions

```cpp
bool b = 42;            // b is true
int i = b;              // i has value 1
i = 3.14;               // i has value 3
double pi = i;          // pi has value 3.0
unsigned char c = -1;   // assuming 8-bit chars, c has value 255
signed char c2 = 256;   // assuming 8-bit chars, the value of c2 is undefined
```

```cpp
int i = 42;
if (i) // condition will evaluate as true
    i = 0;
```

#### Expression Involving Unsigned Types

> If we use both unsigned and int values in an arithmetic expression, the `int`
> value ordinarily is converted to `unsigned`.

```cpp
unsigned u = 10;
int i = 42;
std::cout << i + i << std::endl;    // prints -84
std::cout << u + i << std::endl;    // if 32-bit ints, prints 4294967264
```

```cpp
unsigned u1 = 42, u2 = 10;
std::cout << u1 - u2 << std::endl; // ok: result is 32
std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around
```

```cpp
for (int i = 10; i >= 0; --i)
    std::cout << i << std::endl;
```

```cpp
// WRONG: u can never be less than 0; the condition will always succeed
for (unsigned u = 10; u >= 0; --u)
    std::cout << u << std::endl;

unsigned u = 11; // start the loop one past the first element we want to print
while (u > 0) {
     --u;        // decrement first, so that the last iteration will print 0
    std::cout << u << std::endl;
}
```

### Literals

#### Integer and Floating-Point Literals

Character and Character String Literals:

| Prefix | Meaning                     | Type       |
| ------ | --------------------------- | ---------- |
| `u`    | Unicode 16 character        | `char16_t` |
| `U`    | Unicode 32 character        | `char32_t` |
| `L`    | wide character              | `wchar_t`  |
| `u8`   | utf-8 (string literal only) | `char`     |

Integer Literals:

| Suffix       | Minimum Type |
| ------------ | ------------ |
| `u` or `U`   | `unsigned`   |
| `l` or `L`   | `long`       |
| `ll` or `LL` | `long long`  |

Floating-Point Literals

| Suffix     | Type          |
| ---------- | ------------- |
| `f` or `F` | `float`       |
| `l` or `L` | `long double` |


```cpp
// decimal octal, and hexadecimal
20 /* decimal */ 024 /* octal */ 0x14 /* hexadecimal */

```cpp
// floating-point literals
3.14159   3.14159E0    0.   0e0     .001
```

#### Character and Character String Literals

```cpp
// character literals
'a' // character literal
"Hello World!"  // string literal

// multiline string literal
std::cout << "a really, really long string literal "
             "that spans two lines" << std::endl;
```

```cpp
std::cout << '\n';      // prints a newline
std::cout << "\tHi!\n"; // prints a tab followd by "Hi!" and a newline

std::cout << "Hi \x4dO\115!\n"; // prints Hi MOM! followed by a newline
std::cout << '\115' << '\n';    // prints M followed by a newline
```

#### Escape Sequences

```cpp
std::cout << '\n';        // prints a newline
std::cout << "\tHi!\n";   // prints a tab followd by "Hi!" and a newline
```

```cpp
std::cout << "Hi \x4dO\115!\n";  // prints Hi MOM! followed by a newline
std::cout << '\115' << '\n';     // prints M followed by a newline
```

* Note that if a `\` is followed by more than three octal digits, only the
  first three are associated with the `\.`
* In contrast, `\x` uses up all the hex digits following it;

#### Specifying the Type of a Literal

```cpp
L'a'        // wide character literal, type is wchar_t
u8"hi!"     // utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
42ULL       // unsigned integer literal, type is unsigned long long
1E-3F       // single-precision floating-point literal, type is float
3.14159L    // extended-precision floating-point literal, type is long double
```

#### Boolean and Pointer Literals

```cpp
bool test = false;
```

## Variables

> C++ programmers tend to refer to variables as "variables" or "objects"
> interchangeably

### Variable Definitions

```cpp
int sum = 0, value, // sum, value, and units_sold have type int
    units_sold = 0; // sum and units_sold have initial value 0
Sales_item item;    // item has type Sales_item (see § 1.5.1 (p. 20))
// string is a library type, representing a variable-length sequence of characters
std::string book("0-201-78345-X"); // book initialized from string literal
```

#### Initializers

```cpp
// ok: price is defined and initialized before it is used to initialize discount
double price = 109.99, discount = price * 0.16;
// ok: call applyDiscount and use the return value to initialize salePrice
double salePrice = applyDiscount(price, discount);
```

#### List Initializations

```cpp
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

The compiler will not let us list initialize variables of built-in type if
the initializer might lead to the loss of information:

```cpp
long double ld = 3.1415926536;
int a{ld}, b = {ld};    // error: narrowing conversion required
int c(ld), d = ld;      // ok: but value will be truncated
```

#### Default Initialization

```cpp
std::string empty;  // empty implicitly initialized to the empty string
Sales_item item;    // default-initialized Sales_item object
```

### Variable Declarations and Definitions

To obtain a declaration that is not also a definition, we add the `extern`
keyword and may not provide an explicit initializer:

```cpp
extern int i;   // declares but does not define i
int j;          // declares and defines j
extern double pi = 3.1416; // definition
```

### Identifiers

```cpp
// defines four different int variables
int somename, someName, SomeName, SOMENAME;
```

#### Convention for Variable Names

### Scope of a Name

```cpp
#include <iostream>
int main()
{
int sum = 0;
// sum values from 1 through 10 inclusive
for (int val = 1; val <= 10; ++val)
    sum += val;     // equivalent to sum = sum + val
std::cout << "Sum of 1 to 10 inclusive is "
          << sum << std::endl;
return 0;
}
```

#### Nested Scopes

```c
#include <iostream>
// Program for illustration purposes only: It is bad style for a function
// to use a global variable and also define a local variable with the same name
int reused = 42; // reused has global scope
int main()
{
    int unique = 0; // unique has block scope
    // output #1: uses global reused; prints 42 0
    std::cout << reused << " " << unique << std::endl;
    int reused = 0; // new, local object named reused hides global reused
    // output #2: uses local reused; prints 0 0
    std::cout << reused << " " << unique << std::endl;
    // output #3: explicitly requests the global reused; prints 42 0
    std::cout << ::reused << " " << unique << std::endl;
    return 0;
}
```

## Compound Types

### References

```c
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2;       // error: a reference must be initialized

#### A Reference is an Alias

refVal = 2;         // assigns 2 to the object to which refVal refers, i.e., to ival
int ii = refVal;    // same as ii = ival

// ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
int &refVal3 = refVal;
// initializes i from the value in the object to which refVal is bound
int i = refVal; // ok: initializes i to the same value as ival
```

> Because references are not objects, we may not define a reference to a reference

#### Reference Definitions

```cpp
int i = 1024, i2 = 2048;    // i and i2 are both ints
int &r = i, r2 = i2;        // r is a reference bound to i; r2 is an int
int i3 = 1024, &ri = i3;    // i3 is an int; ri is a reference bound to i3
int &r3 = i3, &r4 = i2;     // both r3 and r4 are references
```

A reference may be bound only to an object, not to a literal or to the result
of a more general expression:

```cpp
int &refVal4 = 10;          // error: initializer must be an object
double dval = 3.14;
int &refVal5 = dval;        // error: initializer must be an int object
```

### Pointers

```cpp
int *ip1, *ip2;     // both ip1 and ip2 are pointers to int
double dp, *dp2;    // dp2 is a pointer to double; dp is a double
```

#### Taking the Address of an Object

```cpp
int ival = 42;
int *p = &ival;     // p holds the address of ival; p is a pointer to ival
```

```cpp
double dval;
double *pd = &dval; // ok: initializer is the address of a double
double *pd2 = pd;   // ok: initializer is a pointer to double
int *pi = pd;       // error: types of pi and pd differ
pi = &dval;         // error: assigning the address of a double to a pointer to int
```

#### Pointer Value

The value (i.e., the address) stored in a pointer can be in one of four states:

1. It can point to an object.
2. It can point to the location just immediately past the end of an object.
3. It can be a null pointer, indicating that it is not bound to any object.
4. It can be invalid; values other than the preceding three are invalid.

#### Using a Pointer to Access an Object

```cpp
int ival = 42;
int *p = &ival;     // p holds the address of ival; p is a pointer to ival
cout << *p;         // * yields the object to which p points; prints 42

*p = 0;             // * yields the object; we assign a new value to ival through p
cout << *p;         // prints 0
```

#### Key Concept: Some Symbols Have Multiple Meanings

```cpp
int i = 42;
int &r = i;    // & follows a type and is part of a declaration; r is a reference
int *p;        // * follows a type and is part of a declaration; p is a pointer
p = &i;        // & is used in an expression as the address-of operator
*p = i;        // * is used in an expression as the dereference operator
int &r2 = *p;  // & is part of the declaration; * is the dereference operator
```

#### Null Pointers

```cpp
int *p1 = nullptr;  // equivalent to int *p1 = 0;
int *p2 = 0;        // directly initializes p2 from the literal constant 0
// must #include cstdlib
int *p3 = NULL;     // equivalent to int *p3 = 0;

```cpp
int zero = 0;
pi = zero;          // error: cannot assign an int to a pointer
```

#### Assignment and Pointers

```cpp
int i = 42;
int *pi = 0;        // pi is initialized but addresses no object
int *pi2 = &i;      // pi2 initialized to hold the address of i
int *pi3;           // if pi3 is defined inside a block, pi3 is uninitialized
pi3 = pi2;          // pi3 and pi2 address the same object, e.g., i
pi2 = 0;            // pi2 now addresses no object

pi = &ival;         // value in pi is changed; pi now points to ival
*pi = 0;            // value in ival is changed; pi is unchanged
```

#### Other Pointer Operations

```cpp
int ival = 1024;
int *pi = 0;        // pi is a valid, null pointer
int *pi2 = &ival;   // pi2 is a valid pointer that holds the address of ival
if (pi)             // pi has value 0, so condition evaluates as false
// ...
if (pi2) // pi2 points to ival, so it is not 0; the condition evaluates as true
// ...
```

> Note that it is possible for a pointer to an object and a pointer one past
> the end of a different object to hold the same address. Such pointers will
> compare equal.

#### `void*` Pointers

```cpp
double obj = 3.14, *pd = &obj;
// ok: void* can hold the address value of any data pointer type
void *pv = &obj;    // obj can be an object of any type
pv = pd;            // pv can hold a pointer to any type
```

### Understanding Compound Type Declarations

```cpp
// i is an int; p is a pointer to int; r is a reference to int
int i = 1024, *p = &i, &r = i;
```

#### Defining Multiple Variables

```cpp
int* p;         // legal but might be misleading
int* p1, p2;    // p1 is a pointer to int; p2 is an int
int* p1, *p2;   // both p1 and p2 are pointers to int
```

```cpp
int* p1;        // p1 is a pointer to int
int* p2;        // p1 is a pointer to int
```

#### Pointers to Pointers

```cpp
int ival = 1024;
int *pi = &ival;    // pi points to an int
int **ppi = &pi;    // ppi points to a pointer to an int
```

```cpp
cout << "The value of ival\n"
     << "direct value: " << ival << "\n"
     << "indirect value: " << *pi << "\n"
     << "doubly indirect value: " << **ppi
     << endl;
```

#### Reference to Pointers

```cpp
int i = 42;
int *p;        // p is a pointer to int
int *&r = p;   // r is a reference to the pointer p
r = &i; //  r refers to a pointer; assigning &i to r makes p point to i
*r = 0; //  dereferencing r yields i, the object to which p points; changes i to 0
```

## `const` Qualifier

```cpp
const int bufSize = 512;    // input buffer size
bufSize = 512;      // error: attempt to write to const object
```

```cpp
const int i = get_size();  // ok: initialized at run time
const int j = 42;          // ok: initialized at compile time
const int k;               // error: k is uninitialized const
```

#### Initialization and `const`

```cpp
int i = 42;
const int ci = i;   // ok: the value in i is copied into ci
int j = ci;         // ok: the value in ci is copied into j
```

#### By Default, `const` Object Are Local to a File

```cpp
const int bufSize = 512;    // input buffer size
```

* The compiler will usually replace uses of the variable with its corresponding
  value during compilation.

> `const` Variables are defined local to the file. When we define a `const`
> with the same name in multiple files, it is as if we had written difinitions
> for separate variables in each file.

```cpp
// file_1.cc defines and initializes a const that is accessible to other files
extern const int bufSize = fcn();
// file_1.h
extern const int bufSize; // same bufSize as defined in file_1.cc
```

### References to `const`

```cpp
const int ci = 1024;
const int &r1 = ci;   // ok: both reference and underlying object are const
r1 = 42;              // error: r1 is a reference to const
int &r2 = ci;         // error: non const reference to a const object
```

#### Initialization and References to `const`

We can initialize a reference to `const` from any expression that can be
converted to the type of the reference. In particular, we can bind a reference
to `const` to a non`const` object, a literal, or a more general expression:

```cpp
int i = 42;
const int &r1 = i;      // we can bind a const int& to a plain int object
const int &r2 = 42;     // ok: r1 is a reference to const
const int &r3 = r1 * 2; // ok: r3 is a reference to const
int &r4 = r * 2;        // error: r4 is a plain, non const reference
```

```cpp
double dval = 3.14;
const int& ri = dval;
// the compiler transform this code into
const int temp = dval;   // create a temporary const int from the double
const int& ri = temp;    // bind ri to that temporary
```

* Because binding a reference to a temporary is almost surely *not* what the
  programmer intended, the language makes it illegal.

#### A Reference to const May Refer to an Object That Is Not const

```cpp
int i = 42;
int& r1 = i;        // r1 bound to i
const int& r2 = i;  // r2 also bound to i; but cannot be used to change i
r1 = 0;             // r1 is not const; i is now 0
r2 = 0;             // error: r2 is a reference to const
```

### Pointers and `const`

```cpp
const double pi = 3.14;     // pi is const; its value may not be changed
double* ptr = &pi;          // error: ptr is a plain pointer
const double* cptr = &pi;   // ok: cptr may ponint to a double that is const
*cptr = 42;                 // error: cannot assign to *cptr
```

We can use a pointer to `const` to point to a non`const` object:

```cpp
double dval = 3.14;     // dval is a double; its value can be changed
cptr = &dval;           // ok: but can't change dval through cptr
```

#### `const` Pointers

```cpp
int errNumb = 0;
int* const curErr = &errNumb;  // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```

```cpp
*pip = 2.72;     // error: pip is a pointer to const
// if the object to which curErr points (i.e., errNumb) is nonzero
if (*curErr) {
    errorHandler();
    *curErr = 0; // ok: reset the value of the object to which curErr is bound
}
```

### Top-Level `const`

```cpp
int i = 0;
int *const p1 = &i;  // we can't change the value of p1; const is top-level
const int ci = 42;   // we cannot change ci; const is top-level
const int *p2 = &ci; // we can change p2; const is low-level
const int *const p3 = p2; // right-most const is top-level, left-most is not
const int &r = ci;  // const in reference types is always low-level
```

When we copy an object, top-level `const`s are ignored:

```cpp
i = ci;  // ok: copying the value of ci; top-level const in ci is ignored
p2 = p3; // ok: pointed-to type matches; top-level const in p3 is ignored
```

On the other hand, low-level const is never ignored. When we copy an object,
both objects must have the same low-level const qualification or there must be a
conversion between the types of the two objects.

```cpp
int* p = p3;    // error: p3 has a low-level const but p doesn't
p2 = p3;        // ok: p2 has the same low-level const qualification as p3
p2 = &i;        // ok: we can convert int* to const int*
int& r = ci;    // error: can't bind an ordinary int& to a const int object
const int& r2 = i;  // ok: can bind const int& to plain int
```

### `constexpr` and Constant Expression

A constant expression is an expression whose value cannot change and that can
be evaluated at compile time. A literal is a constant expression. A `const`
object that is initialized from a constant expression is also a constant
expression.

Whether a given object (or expression) is a constant expression depends on the
types and the initializers. For example:

```cpp
const int max_files = 20;   // max_files is a constant expression
const int limit = max_files + 1;    // limit is a constant expression
int staff_size = 27;        // staff_size is not a constant expression
constant int sz = get_size();   // sz is not a constant expression
```

#### `constexpr` Variables

Variables declared as `constexpr` are implicitly `const` and must be
initialized by constant expressions:

```cpp
constexpr int mf = 20;        // 20 is a constant expression
constexpr int limit = mf + 1; // mf + 1 is a constant expression
constexpr int sz = size();    // ok only if size is a constexpr function
```

#### Literal Types

The types we can use in a constexpr are known as "literal types" because they
are simple enough to have literal values.

* Of the types we have used so far, the arithmetic, reference, and pointer
  types are literal types.
* Our `Sales_item` class and the library IO and `string` types are not literal
  types.
* Variables defined inside a function ordinarily are not stored at a fixed
  address. Hence, we cannot use a constexpr pointer to point to such variables.
* On the other hand, the address of an object defined outside of any function
  is a constant expression, and so may be used to initialize a constexpr
  pointer.

#### Pointers and `constexpr`

When we define a pointer in a constexpr declaration, the constexpr specifier
applies to the pointer, not the type to which the pointer points:

```cpp
const int *p = nullptr;     // p is a pointer to a const int
constexpr int *q = nullptr; // q is a const pointer to int
```

```cpp
constexpr int *np = nullptr; // np is a constant pointer to int that is null
int j = 0;
constexpr int i = 42;  // type of i is const int
// i and j must be defined outside any function
constexpr const int *p = &i; // p is a constant pointer to the const int i
constexpr int *p1 = &j;      // p1 is a constant pointer to the int j
```

## Dealing with Types

### Type Aliases

```cpp
typedef double wages;   // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
```

```cpp
using SI = Sales_item;  // SI is a synonym for Sales_item
```

```cpp
wages hourly, weekly;    // same as double hourly, weekly;
SI item;                 // same as Sales_item item
```

#### Pointers, `const`, and Type Aliases

```cpp
const pstring cstr = 0; // cstr is a constant pointer to char
const pstring *ps;      // ps is a pointer to a constant pointer to char
```

```cpp
const char* cstr = 0;   // wrong interpretation of const pstring cstr
```

### The `auto` Type Specifier

```cpp
// the type of item is deduced from the type of the result of adding val1 and val2
auto item = val1 + val2; // item initialized to the result of val1 + val2
```

```cpp
auto i = 0, *p = &i;      // ok: i is int and p is a pointer to int
auto sz = 0, pi = 3.14;   // error: inconsistent types for sz and pi
```

#### Compound Types, `const`, and `auto`

When we use a reference as an initializer, the initializer is the corresponding
object. The compiler uses that object’s type for `auto`'s type deduction:

```cpp
int i = 0, &r = i;
auto a = r;  // a is an int (r is an alias for i, which has type int)
```

`auto` ordinarily ignores top-level `const`s. As usual in initializations,
low-level consts, such as when an initializer is a pointer to const, are
kept:

```cpp
const int ci = i, &cr = ci;
auto b = ci;  // b is an int (top-level const in ci is dropped)
auto c = cr;  // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i;  // d is an int*(& of an int object is int*)
auto e = &ci; // e is const int*(& of a const object is low-level const)
```

```cpp
const auto f = ci;  // deduced of ci is int; f has type const int
```

```cpp
auto &g = ci;       // g is a const int& that is bound to ci
auto &h = 42;       // error: we can't bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal
```

A reference or pointer is part of a particular declarator and not part of the
base type for the declaration. As usual, the initializers must provide
consistent auto-deduced types:

```cpp
auto k = ci, &l = i;    // k is int; l is int&
auto &m = ci, *p = &ci; // m is a const int&;p is a pointer to const int
// error: type deduced from i is int; type deduced from &ci is const int
auto &n = i, *p2 = &ci;
```

### The `declare` Type Specifier

```cpp
decltype(f()) sum = X;  // sum has whaterever type f returns
```

When the expression to which we apply `decltype` is a variable, `decltype`
returns the type of that variable, including top-level `const` and references:

```cpp
const int ci = 0, &cj = ci;
decltype(di) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z;     // error: z is a reference and must be initialized
```

> It is worth noting that decltype is the only context in which a variable
> defined as a reference is not treated as a synonym for the object to which it
> refers.

#### `decltype` and Reference

When we apply `decltype` to an expression that is not a variable, we get the
type that that expression yields.

Generally speaking, `decltype` returns a reference type for expressions that
yield objects that can stand on the left-hand side of the assignment:

```cpp
// decltype of an expression can be a reference type
int i = 42, *p = &i, &r = i;
decltype(r + 0) b;  // ok: addition yields an int; b is an (uninitialized) int
decltype(*p) c;     // error: c is int& and must be initialized
```

As we’ve seen, when we dereference a pointer, we get the object to which the
pointer points. Moreover, we can assign to that object. Thus, the type deduced
by `decltype(*p)` is `int&`, not plain `int`.

When we apply `decltype` to a variable without any parentheses, we get the type
of that variable. If we wrap the variable’s name in one or more sets of
parentheses, the compiler will evaluate the operand as an expression.

```cpp
// decltype of a parenthesized variable is always a reference
decltype((i)) d;    // error: d is int& and must be initialized
decltype(i) e;      // ok: e is an (uninitialized) int
```

## Defining Our Own Data Structures

### Defining the `Sales_data` Type

```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
}
```

```cpp
struct Sales_data { /* ... */ } accum, trans, *salesptr;
// equivalent, but better way to define these objects
struct Sales_data { /* ... */ };
Sales_data accum, trans, *salesptr;
```

#### Class Data Members

### Using the `Sales_data` Class

#### Adding Two `Sales_data` Objects

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
int main()
{
    Sales_data data1, data2;
    // code to read into data1 and data2
    // code to check whether data1 and data2 have the same ISBN
    //    and if so print the sum of data1 and data2
}
```

#### Reading Data into a `Sales_data` Object

```cpp
double price = 0;   // price per book, used to calculate total revenue
// read the first transactions: ISBN, number of books sold, price per book
std::cin >> data1.bookNo >> data1.units_sold >> price;
// calculate total revenue from price and units_sold
data1.revenue = data1.units_sold * price;
```

#### Printing the Sum of Two `Sales_data` Objects

```cpp
if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    // print: ISBN, total sold, total revenue, average price per book
    std::cout << data1.bookNo << " " << totalCnt
              << " " << totalRevenue << " ";
    if (totalCnt != 0)
        std::cout << totalRevenue/totalCnt << std::endl;
    else
        std::cout << "(no sales)" << std::endl;
    return 0; // indicate success
} else {  // transactions weren't for the same ISBN
    std::cerr << "Data must refer to the same ISBN"
              << std::endl;
    return -1; // indicate failure
}
```

### Writing Our Own Header Files

#### A Brief Introduction to the Preprocessor

```cpp
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
```
