## Primitive Builtin Types

```c
bool b = 42;            // b is true
int i = b;              // i has value 1
i = 3.14;               // i has value 3
double pi = i;          // pi has value 3.0
unsigned char c = -1;   // assuming 8-bit chars, c has value 255
signed char c2 = 256;   // assuming 8-bit chars, the value of c2 is undefined
```

```c
int i = 42;

if (i) {
    i = 0
}
```

```c
unsigned u = 10;
int i = -42;
std::cout << i + i << std::endl; // prints -84
std::cout << u + i << std::endl; // if 32-bit ints, prints 4294967264
```

```c
unsigned u1 = 42, u2 = 10;
std::cout << u1 - u2 << std::endl; // ok: result is 32
std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around
```

```c
for (int i = 10; i >= 0; --i) {
    std::cout << i << std::endl;
}

// WRONG: u can never be less than 0; the condition will always succeed
for (unsigned u = 10; u >= 0; --u) {
    std::cout << u << std::endl;
}

unsigned u = 11; // start the loop one past the first element we want to print
while (u > 0) {
    --u;         // decrement first, so that the last iteration will print 0
    std::cout << u << std::endl;
}
```

## Literals

```c
// decimal octal, and hexadecimal
20 /* decimal */
024 /* octal */
0x14 /* hexadecimal */

// floating-point literals
3.14159   3.14159E0    0.   0e0     .001

// character literals
'a' // character literal
"Hello World!"  // string literal

// multiline string literal
std::cout << "a really, really long string literal "
             "that spans two lines" << std::endl;
```

```c
std::cout << '\n';      // prints a newline
std::cout << "\tHi!\n"; // prints a tab followd by "Hi!" and a newline

std::cout << "Hi \x4dO\115!\n"; // prints Hi MOM! followed by a newline
std::cout << '\115' << '\n';    // prints M followed by a newline
```

```c
L'a'        // wide character literal, type is wchar_t
u8"hi!"     // utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
42ULL       // unsigned integer literal, type is unsigned long long
1E-3F       // single-precision floating-point literal, type is float
3.14159L    // extended-precision floating-point literal, type is long double
```

## Variables

```c
int sum = 0;
int value,          // sum, value, and units_sold have type int
int units_sold = 0; // sum and units_sold have initial value 0

Sales_item item;    // item has type Sales_item (see § 1.5.1 (p. 20))
                    // string is a library type, representing a variable-length
                    // sequence of characters
std::string book("0-201-78345-X"); // book initialized from string literal
```

```c
// ok: price is defined and initialized before it is used to initialize discount
double price = 109.99, discount = price * 0.16;
// ok: call applyDiscount and use the return value to initialize salePrice
double salePrice = applyDiscount(price, discount);
```

```c
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```

```c
long double ld = 3.1415926536;
int a{ld}, b = {ld};    // error: narrowing conversion required
int c(ld), d = ld;      // ok: but value will be truncated
```

```c
std::string empty;  // empty implicitly initialized to the empty string
Sales_item item;    // default-initialized Sales_item object
```

```c
extern int i;   // declares but does not define i
int j;          // declares and defines j
extern double pi = 3.1416; // definition
```

```c
// defines four different int variables
int somename, someName, SomeName, SOMENAME;
```

```c
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

```c
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2;       // error: a reference must be initialized

refVal = 2;         // assigns 2 to the object to which refVal refers, i.e., to ival
int ii = refVal;    // same as ii = ival

// ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
int &refVal3 = refVal;
// initializes i from the value in the object to which refVal is bound
int i = refVal; // ok: initializes i to the same value as ival

int i = 1024, i2 = 2048;    // i and i2 are both ints
int &r = i, r2 = i2;        // r is a reference bound to i; r2 is an int
int i3 = 1024, &ri = i3;    // i3 is an int; ri is a reference bound to i3
int &r3 = i3, &r4 = i2;     // both r3 and r4 are references

int &refVal4 = 10;          // error: initializer must be an object
double dval = 3.14;
int &refVal5 = dval;        // error: initializer must be an int object
```

```
int *ip1, *ip2;     // both ip1 and ip2 are pointers to int
double dp, *dp2;    // dp2 is a pointer to double; dp is a double

int ival = 42;
int *p = &ival;     // p holds the address of ival; p is a pointer to ival


double dval;
double *pd = &dval; // ok: initializer is the address of a double
double *pd2 = pd;   // ok: initializer is a pointer to double
int *pi = pd;       // error: types of pi and pd differ
pi = &dval;         // error: assigning the address of a double to a pointer to int

int ival = 42;
int *p = &ival;     // p holds the address of ival; p is a pointer to ival
cout << *p;         // * yields the object to which p points; prints 42

*p = 0;             // * yields the object; we assign a new value to ival through p
cout << *p;         // prints 0
```

```
int i = 42;
int &r = i;         // & follows a type and is part of a declaration; r is a reference
int *p;             // * follows a type and is part of a declaration; p is a pointer
p = &i;             // & is used in an expression as the address-of operator
*p = i;             // * is used in an expression as the dereference operator
int &r2 = *p;       // & is part of the declaration; * is the dereference operato
```

```
int *p1 = nullptr;  // equivalent to int *p1 = 0;
int *p2 = 0;        // directly initializes p2 from the literal constant 0
// must #include cstdlib
int *p3 = NULL;     // equivalent to int *p3 = 0;

int zero = 0;
pi = zero;          // error: cannot assign an int to a pointer
```

```
int i = 42;
int *pi = 0;        // pi is initialized but addresses no object
int *pi2 = &i;      // pi2 initialized to hold the address of i
int *pi3;           // if pi3 is defined inside a block, pi3 is uninitialized
pi3 = pi2;          // pi3 and pi2 address the same object, e.g., i
pi2 = 0;            // pi2 now addresses no object

pi = &ival;         // value in pi is changed; pi now points to ival
*pi = 0;            // value in ival is changed; pi is unchanged

int ival = 1024;
int *pi = 0;        // pi is a valid, null pointer
int *pi2 = &ival;   // pi2 is a valid pointer that holds the address of ival
if (pi)             // pi has value 0, so condition evaluates as false
// ...
if (pi2) // pi2 points to ival, so it is not 0; the condition evaluates as true
// ...
```

```
double obj = 3.14, *pd = &obj;
// ok: void* can hold the address value of any data pointer type
void *pv = &obj;    // obj can be an object of any type
pv = pd;            // pv can hold a pointer to any type
```
