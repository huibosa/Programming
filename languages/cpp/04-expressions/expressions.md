[toc]

## Fundamentals

> There is also one ternary operator that takes three operands, and one
> operator, function call, that takes an unlimited number of operands.

### Basic Concepts

#### Grouping Operators and Operands

#### Operands Conversions

#### Overloaded Operators

The number of operands and the precedence and the associativity of the
operator cannot be changed.

#### Lvalues and Rvalues

* An lvalue expression yields an object or a function.
* However, some lvalues, such as `const` objects, may not be the left hand
  operand of an assignment.
* Moreover, some expressions yield objects but return them as rvalues, not
  lvalues.
* Roughly speaking, when we use an object as an rvalue, we use the object’s
  value (its contents). When we use an object as an lvalue, we use the object’s
  identity (its location in memory).

We can use an lvalue when an rvalue is required, but we cannot use an rvalue
when an lvalue (i.e., a location) is required. When we use an lvalue in place
of an rvalue, the object’s contents (its value) are used. We have already used
several operators that involve lvalues.

* Assignment requires a (nonconst) lvalue as its left-hand operand and yields
  its left-hand operand as an lvalue.
* The address-of operator requires an lvalue operand and returns a pointer to
  its operand as an rvalue.
* The built-in dereference and subscript operators and the iterator dereference
  and string and vector subscript operators all yield lvalues.
* The built-in and iterator increment and decrement operators require lvalue
  operands and the prefix versions  also yield lvalues.


Lvalues and rvalues also differ when used with decltype. When we apply `decltype`
to an expression (other than a variable), the result is a reference type if the
expression yields an lvalue. As an example, assume `p` is an `int*`. Because
dereference yields an lvalue, `decltype(*p)` is `int&`. On the other hand, because
the address-of operator yields an rvalue, `decltype(&p)` is `int**`, that is, a
pointer to a pointer to type int.

### Precedence and Associativity

```cpp
6 + 3 * 4 / 2 + 2
// parentheses in this expression match default precedence and associativity
((6 + ((3 * 4) / 2)) + 2)
```

#### Parentheses Override Precedence and Associativity

```cpp
// parentheses result in alternative groupings
cout << (6 + 3) * (4 / 2 + 2) << endl; // prints 36
cout << ((6 + 3) * 4) / 2 + 2 << endl; // prints 20
cout << 6 + 3 * 4 / (2 + 2) << endl; // prints 9
```

#### When Precedence and Associativity Matter

```cpp
int ia[] = {0,2,4,6,8}; // array with five elements of type int
int last = *(ia + 4); // initializes last to 8, the value of ia [4]
last = *ia + 4; // last = 4, equivalent to ia [0] + 4
```

```cpp
cin >> v1 >> v2; // read into v1 and then into v2
```

### Order of Evaluation

```cpp
int i = f1() * f2();
```

For operators that do not specify evaluation order, it is an error for an
expression to refer to and change the same object. 

```cpp
int i = 0;
cout << i << " " << ++i << endl; // undefined
```

There are four operators that do guarantee the order in which operands are
evaluated. 

* The logical AND (`&&`) operator guarantees that its left-hand operand is
  evaluated first Moreover, we are also guaranteed that the right-hand operand
  is evaluated only if the left-hand operand is `true`.
* The logical OR (`||`) operator.
* The conditional (`? :`) operator.
* The comma (`,`) operator.

#### Order of Evaluation, Precedence, and Associativity

## Arithmetic Operators

When applied to a pointer or arithmetic value, unary plus returns a (possibly
promoted) copy of the value of its operand.

```cpp
int i = 1024;
int k = -i; // i is -1024
bool b = true;
bool b2 = -b; // b2 is true!
```

> For most operators, operands of type bool are promoted to int.

## Logicl and Relational Operators

#### Logical `AND` and `OR` Operators

#### Logical `NOT` Operator

#### The Relational Operators

#### Equality Tests and the bool Literals

## Assignment Operands

#### Assignment Is Right Associative

#### Assignment Has Low Precedence

> Because assignment has lower precedence than the relational operators,
> parentheses are usually needed around assignments in conditions.

#### Beware of Confusing Equality and Assignment Operators

#### Compound Assignment Operators

## Increment and Decrement Operators

* The prefix operators return the object itself as an lvalue.
* The postfix operators return a copy of the object’s original value as an
  rvalue.

#### Combining Dereference and Increment in a Single Expression

#### Remember That Operands Can Be Evaluated in Any Order

## The Member Access Operators

## The Conditional Operator

#### Nesting Conditional Operators

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

#### Using a Conditional Operator in an Output Expression

```cpp
cout << ((grade < 60) ? "fail" : "pass"); // prints pass or fail
cout << (grade < 60) ? "fail" : "pass"; // prints 1 or 0!
cout << grade < 60 ? "fail" : "pass"; // error: compares cout to 60
```

```cpp
cout << (grade < 60); // prints 1 or 0
cout ? "fail" : "pass"; // test cout and then yield one of the two literals
                        // depending on whether cout is true or false
```

```cpp
cout << grade; // less-than has lower precedence than shift, so print grade first
cout < 60 ? "fail" : "pass"; // then compare cout to 60!
```

## The Bitwise Operators

* As usual, if an operand is a "small integer," its value is first promoted to
  a larger integral type. The operand(s) can be either signed or unsigned.
* If the operand is signed and its value is negative, then the way that the
  "sign bit" is handled in a number of the bitwise operations is machine
  dependent. Moreover, doing a left shift that changes the value of the sign
  bit is undefined.

#### Bitwise Shift Operator

#### Bitwise `NOT` Operator

>  Our `char` operand is first promoted to int. Promoting a `char` to int
>  leaves the value unchanged but adds 0 bits to the high order positions.

#### Bitwise `AND`, `OR` and `XOR` Operators

#### Using Bitwise Operators

```cpp
1UL << 27 // generate a value with only bit number 27 set
```

```cpp
quiz1 |= 1UL << 27; // indicate student number 27 passed
```

```cpp
quiz1 &= ~(1UL << 27); // student number 27 failed
```

```cpp
bool status = quiz1 & (1UL << 27); // how did student number 27 do?
```

#### Shift Operators (aka IO Operators) Are Left Associative

```cpp
cout << "hi" << " there" << endl;
( (cout << "hi") << " there" ) << endl;
```

The shift operators have midlevel precedence: lower than the arithmetic
operators but higher than the relational, assignment, and conditional
operators.

```cpp
cout << 42 + 10;    // ok: + has higher precedence, so the sum is printed
cout << (10 < 42);  // ok: parentheses force intended grouping; prints 1
cout << 10 < 42;    // error: attempt to compare cout to 42!
```

#### The `sizeof` Operator

```cpp
Sales_data data, *p;
sizeof(Sales_data); // size required to hold an object of type Sales_data
sizeof data; // size of data's type, i.e., sizeof(Sales_data)
sizeof p; // size of a pointer
sizeof *p; // size of the type to which p points, i.e., sizeof(Sales_data)
sizeof data.revenue; // size of the type of Sales_data's revenue member
sizeof Sales_data::revenue; // alternative way to get the size of revenue
```

> `sizeof` is right associative and has the same precedence as `*`

```cpp
// sizeof(ia)/sizeof(*ia) returns the number of elements in ia
constexpr size_t sz = sizeof(ia)/sizeof(*ia);
int arr2[sz]; // ok sizeof returns a constant expression § 2.4.4 (p. 65)
```

## Comma Operators

## Type Conversions

The implicit conversions among the arithmetic types are defined to preserve
precision, if possible.

#### When Implicit Conversions Occur

* In most expressions, values of integral types smaller than `int` are first
  promoted to an appropriate larger integral type.
* In conditions, non`bool` expressions are converted to `bool`.
* In initializations, the initializer is converted to the type of the variable;
  in assignments, the right-hand operand is converted to the type of the
  left-hand.
* In arithmetic and relational expressions with operands of mixed types, the
  types are converted to a common type.
* As we’ll see in Chapter 6, conversions also happen during function calls.

### The Arithmetic Conversions

The rules define a hierarchy of type conversions in which operands to an
operator are converted to the widest type. 

#### Integral Promotions

The types `bool`, `char`, `signed char`, `unsigned char`, `short`, and
`unsigned short` are promoted to int if all possible values of that type fit in
an `int`.

The larger `char` types (`wchar_t`, `char16_t`, and `char32_t`) are promoted to
the smallest type of `int`, `unsigned int`, `long`, `unsigned long`, `long
long`, or `unsigned long long` in which all possible values of that character
type fit.

#### Operands of Unsigned Type

When the signedness differs and the type of the unsigned operand is the same as or
larger than that of the signed operand, the signed operand is converted to unsigned.

#### Understanding the Arithmetic Conversions

```cpp
bool flag;      char cval;
short sval;     unsigned short usval;
int ival;       unsigned int uival;
long lval;      unsigned long ulval;
float fval;     double dval;
3.14159L + 'a'; // 'a' promoted to int, then that int converted to long double
dval + ival;    // ival converted to double
dval + fval;    // fval converted to double
ival = dval;    // dval converted (by truncation) to int
flag = dval;    // if dval is 0, then flag is false, otherwise true
cval + fval;    // cval promoted to int, then that int converted to float
sval + cval;    // sval and cval promoted to int
cval + lval;    // cval converted to long
ival + ulval;   // ival converted to unsigned long
usval + ival;   // promotion depends on the size of unsigned short and int
uival + lval;   // conversion depends on the size of unsigned int and long
```

### Other Implicit Conversions

Array to Pointer Conversions:

```cpp
int ia[10];     // array of ten ints
int* ip = ia;   // convert ia to a pointer to the first element
```

* This conversion is not performed when an array is used with `decltype` or as
  the operand of the address-of (`&`), `sizeof`, or `typeid` operators
* The conversion is also omitted when we initialize a reference to an array

Pointer Conversions:

* A constant integral value of 0 and 
* The literal `nullptr` can be converted to any pointer type;
* A pointer to any non`const` type can be converted to `void*`, and a pointer
  to any type can be converted to a `const void*`.

Conversions to `bool`:

```cpp
char *cp = get_string();
if (cp) /* ... */ // true if the pointer cp is not zero
while (*cp) /* ... */ // true if *cp is not the null character
```

Conversions to `const`:

We can convert a pointer to a non`const` type to a pointer to the corresponding
`const` type, and similarly for references.

```cpp
int i;
const int &j = i;   // convert a nonconst to a reference to const int
const int *p = &i;  // convert address of a nonconst to the address of a const
int &r = j, *q = p; // error: conversion from const to nonconst not allowed
```

> The reverse conversion—removing a low-level `const`—does not exist.

Conversions Defined by Classes:

```cpp
string s, t = "a value"; // character string literal converted to type string
while (cin >> s) // while condition converts cin to bool
```

### Explicit Conversions

#### Named Casts

```cpp
cast-name<type>(expression);
```

#### `static_cast`

```cpp
int i, j;
double slope = i/j;
```

```cpp
// cast used to force floating-point division
double slope = static_cast<double>(j) / i;
```

* A `static_cast` is often useful when a larger arithmetic type is assigned to
  a smaller type. 
* A `static_cast` is also useful to perform a conversion that the compiler will
  not generate automatically.

```cpp
void* p = &d; // ok: address of any nonconst object can be stored in a void*
// ok: converts void* back to the original pointer type
double *dp = static_cast<double*>(p);
```

#### `const_cast`

A `const_cast` changes only a low-level `const` in its operand:

```cpp
const char *pc;
char *p = const_cast<char*>(pc); // ok: but writing through p is undefined
```

> If the object was originally not a const, using a cast to obtain write access
> is legal. However, using a `const_cast` in order to write to a const object is
> undefined.

```cpp
const char *cp;
// error: static_cast can't cast away const
char *q = static_cast<char*>(cp);
static_cast<string>(cp); // ok: converts string literal to string
const_cast<string>(cp); // error: const_cast only changes constness
```

> A `const_cast` is most useful in the context of overloaded functions

#### `reinterpret_cast`

```cpp
int* p;
char* pc = reinterpret_cast<char*>(ip);

string str(pc);
```

> A `reinterpret_cast` is inherently machine dependent. Safely using
> `reinterpret_cast` requires completely understanding the types involved as
> well as the details of how the compiler implements the cast.

#### Old-style Casts

```cpp
type (expr); // function-style cast notation
(type) expr; // C-language-style cast notation
```

Depending on the types involved, an old-style cast has the same behavior as a
`const_cast`, a `static_cast`, or a `reinterpret_cast`. 

```cpp
char *pc = (char*) ip; // ip is a pointer to int
```

## Operator Precedence Table
