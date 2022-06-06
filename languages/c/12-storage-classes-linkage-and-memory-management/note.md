[toc]

## Storage Classes

Storage classes
: Models for storing data in memory.

Object
: Chunk of phisical memory storing data, An object can hold one or more values.
An object might not yet actually have a stored value, but it will be of the
right size to hold an appropriate value.

Identifier
: An identifier is a modifiable lvalue if it refers to a memory location and
if its type is arithmetic, structure, union, or pointer. 

Lvalue
: `Lvalue` refers to memory location which identifies an object. `lvalue`
may appear as either left hand or right hand side of an assignment operator
(`=`). lvalue often represents as identifier.

Rvalue
: Refers to data value that is stored at some address in memory. A `rvalue`
is an expression that can’t have a value assigned to it which means `r-value`
can appear on right but not on left hand side of an assignment operator(`=`).  

Modifiaber lvalue
: Expressions referring to modifiable locations.

Storage duration
: How long the object stays in memory.

Scope and linkage
: Together indicate which parts of a program can use it.

---

```c
int entity = 3;
```

This declaration:

* Creates an *identifier* `entity`.
* Provides a value to be stored in the object.

---------------------------------------------------------------------------

```c
int * pt = &entity;
int ranks[10];
```

* `pt` is an identifier. It designates an object that holds an address.
* The expression `*pt` is not an identifier because it’s not a name. However,
  it does designate an object, in this case the same object that `entity`
  designates, and it's an *lvalue*.
* `ranks + 2 * entity` is neither an identifier (not a name) nor an lvalue
  (doesn’t designate the contents of a memory location).
* But the expression `*(ranks + 2 * entity)` is an lvalue because it does
  designate the value of a particular memory location.
* The declaration of `ranks`, creates an object capable of holding ten `int`s,
  and each member of the array also is an object.

---------------------------------------------------------------------------

```c
const char * pc = "Behold a string literal"
```

* The program stores the string literal contents in memory.
* The array of character values is an object. Each character in the array also
  is an object, which can be accessed individually.
* `pc` is an identifier and holds the address of the string, which is a
  modifiable lvalue.
* The `const` prevents you from altering the contents of a pointed-to string
  but not from changing which string is pointed to.
* `*pc` is an lvalue, which designates the data object holding the `'B'`
  character. (but not a modifiable one).
* The string literal itself, because it designates the object holding the
  character string, is an lvalue, but not a modifiable one.

> The different storage classes offer different combinations of scope, linkage
> and storage duration

## Scope

Scope describes the region or regions of a program that can access an
identifier.

A C variable has one of the following scopes:

* Block scope
* Function scope
* Function prototype scope
* File scope

### Block scope

A variable defined inside a block has `block scope`, and it is visible from the
point it is defined until the end of the block containing the definition.

A block is a region of code contained within an opening brace and the matching
closing brace.

The program examples to date have used block scope almost exclusively for
variables.

*Formal function parameters* have block scope and belong to the block
containing the function body. 

------------------------------------------------------------------------------

C99 expanded the concept of a block to include the code controlled by
a *for loop*, *while loop*, *do while loop*, or *if statement*, even
if no brackets are used.
 
The variable `i` is considered to be part of the for loop block.

```c
for (int i = 0; i < 10; i++)
    printf("A C99 feature: i = %d", i);
```

### Function scope

Function scope applies just to labels used with `goto` statements. This
means that even if a label first appears inside an inner block in a function,
its scope extends to the whole function.

### Function prototype scope

```c
int mighty(int mouse, double large);
```

* *Function prototype scope* applies to variable names use in functions.
* Function prototype scope runs from the point the variable is defined to the
  end of the prototype declaration.
* All the compiler cares about when handling a function prototype argument is
  the types; the names don’t matter.

------------------------------------------------------------------------------

If you use names in the brackets, they have to be names declared earlier in
the prototype.

```c
void use_a_VLA(int n, int m, ar[n][m]);
```

### File scope

* A variable defined outside of any function has *file scope*.
* A variable with file scope is visible from the point it is defined to the end
  of the file containing the definition.
* The variable is also called *global variable*

```c
#include <stdio.h>
int units = 0;          /* a variable with file scope */
void critic(void);

int main(void) {
    /* some code */
}

void critic(void) {
    /* some code */
}
```

> C preprocessing essentially replaces an `#include` directive with the
> contents of the header file. Thus the compiler sees a single file containing
> information from your source code file and all the header files. This single
> file is called a *translation unit*.
>
> When we describe a variable as having file scope, it’s actually visible to
> the whole *translation unit*.
>
> If your program consists of several source code files, then it will consist
> of several *translation units*, with each translation unit corresponding to a
> source code file and its included files.

## Linkage

A C variable has one of the following linkages:

* External linkage
* Internal linkage
* No linkage

Variable with block scope, function scope and prototype scope has no linkage,
which means they are private to the block, function, or prototype.

Variable with file scope can have either internal or external linkage.

* A variable with external linkage can be used anywhere in a multifile program.
* A variable with internal linkage can be used anywhere in single translation
  unit.

(Informal terms) some common short cuts are:

* Use "file scope" for "file scope with internal linkage"
* Use "global scope: or "program scope" for "file scope with external linkage."

To tell whether a file scope variable has internal or external linkage is
to see if the storage class specifier `static` is used in the external
definition.

```c
int giants = 5; // file scope, external linkage
static int dodgers = 3; // file scope, internal linkage
int main() {
    /* some code */
}
/* some code */
```

## Storage Duration

Storage duration describes the persistence of the objects accessed by these
identifiers.

A C object has one of the following four storage durations:

* Static storage duration
* Thread storage duration
* Automatic storage duration
* Allocated storage duration

### Static Storage Duration (Variable with File Scope)

If an object has static storage duration, it exists throughout program
execution.

Variables with file scope (using internal or external linkage) have static
storage duration.

> Note that for file scope variables, the keyword `static` indicates the
> linkage type, not the storage duration.

### Thread Storage Duration

Thread storage duration comes into play in concurrent programming, in which
program execution can be divided into multiple threads.

An object with thread storage duration exists from when it’s declared until
the thread terminates.

Such an object is created when a declaration that would otherwise create a file
scope object is modified with the keyword `_Thread_local`. When a variable is
declared with this specifier, each thread gets its own private copy of that
variable.

### Automatic Storage Duration (Variable with Block Scope)

Variables with block scope normally have automatic storage duration.

These variables have memory allocated for them when the program enters the
block in which they are defined, and the memory is freed when the block is
exited.

> Variable-length arrays provide a slight exception in that they exist from the
> point of declaration to the end of the block rather than from the beginning
> of the block to the end.

To create a variable have block scope but static storage duration.
Declare it inside a block and add the keyword static to the declaration:

```c
void more(int number) {
    int index;
    static int ct = 0;
    ...
    return 0;
}
```

* The variable `ct` is stored in static memory.
* `ct` exists from the time the program is loaded until the program terminates.
  But its scope is confined to the `more()` function block.
* Only while this function executes can the program use `ct` to access the
  object it designates.
* However, one can allow indirect access by enabling the function to provide
  the address of the storage to other functions, for example, by a pointer
  parameter or return value.

### Five Storage Classes

| Storage classe                   | Duration  | Scope | Linkage  | How Declared                                       |
|----------------------------------|-----------|-------|----------|----------------------------------------------------|
| Automatic                        | Automatic | Block | None     | In a block                                         |
| Register                         | Automatic | Block | None     | In a block with the keyword `register`             |
| Static with the external linkage | Static    | File  | external | Outside of all functions                           |
| Static with the internal linkage | Static    | File  | Internal | Outside of all functions with the keyword `static` |
| Static with no linkage           | Static    | Block | None     | In a block with the keyword `static`               |

## Automatic Variables

A variable belonging to the automatic storage class has:

* Automatic storage duration
* Block scope,
* No linkage.

By default, any variable declared in a block or function header belongs to the
automatic storage class.

---

You can use the keyword `auto` to declare an automatic variable:

```c
int main(void) {
    auto int plox;
}
```

* The keyword `auto` is termed a *storage-class specifier*.
* Document that you are intentionally overriding an external variable
  definition.
* Or it is important not to change the variable to another storage class.

> C++ has repurposed the `auto` keyword for a quite different use, so simply
> not using `auto` as a storage-class specifier is better for C/C++
> compatibility.

*Block scope* and *no linkage* imply that only the block in which the variable
is defined can access that variable by name. (Of course, arguments can be used
to communicate the variable’s value and address to another function, but that
is indirect knowledge.)

------------------------------------------------------------------------------

When the program exits the block, the automatic variable disappears. Its memory
location now can be used for something else, although not necessarily.

```c
int loop(int n) {
    int m;                  // m in scope
    scanf("%d", &m);
    {
        int i;              // both m and i in scope
        for (i = m; i < n; i++)
            puts("i is local to a sub-block\n");
    }
    return m;               // m in scope, i gone
}
```

* The variable `i`doesn’t sit unused, occupying memory when it is no longer
  needed. 
* Variables `n` and `m`, being defined in the function head and in the outer
  block, are in scope for the whole function and exist until the function
  terminates.

---

When declaring a variable in an inner block that has the same name as one
in the outer block. The name defined inside the block is the variable used
inside the block which hides the outer definition. However, when execution
exits the inner block, the outer variable comes back into scope.

```c
// hiding.c -- variables in blocks
#include <stdio.h>
int main()
{
    int x = 30;                 // original x
    printf("x in outer block: %d at %p\n", x, &x);

    {
        int x = 77;             // new x, hides first x
        printf("x in inner block: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);

    while (x++ < 33)            // original x
    {
        int x = 100;            // new x, hides first x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);

    return 0;
}
```

### Block Without Braces

> In C99, an entire loop is a sub-block to the block containing it, and the
> loop body is a sub-block to the entire loop block.

### Initialization of Automatic Variables

You can initialize an automatic variable with a non-constant expression,
provided any variables used have been defined previously:

```c
int main(void)
{
    int ruth = 1;               // must be initialized with a value
    int rance = 5 * ruth;       // use previously defined variable
}
```

## Register Variables

Register variables are stored in the CPU registers (the fastest memory
available), where they can be accessed and manipulated more rapidly than
regular variables.

You can’t take the address of a register variable, because a register variable
may be in a register rather than in memory.

Registers are like automatic variables, they have:

* Block scope 
* No linkage
* Automatic storage duration.

```c
int main(void)
{
    register int quick;
}
```

Declaring a variable as a `register` class is more a request, the commplier
will check the number of registers. If there isn't any the variable becomes
an ordinary automatic variable. (but you still can't use the address operator
with it)

You can request formal parameter be register variable:

```c
void macho(register int n)
```

> The types that can be declared register may be restricted. For example, the
> registers in a processor might not be large enough to hold type `double`.

## Static Variable with Block Scope (local static variable)

Variables with file scope automatically (and necessarily) have static storage
duration.

As mentioned earlier, you also can create local variables having block scope
but static duration.

```c
#include <stdio.h>
void trystat(void);

int main(void)
{
    int count;

    for (count = 1; count <= 3; count++)
    {
        printf("Here comes iterations %d\n", count);
        trystat();
    }

    return 0;
}

void trystat(void)
{
    int fade = 1;           // first statement
    static int stay = 1;    // second statement

    printf("fade = %d and stay = %d\n", fade++, stay++);
}
```

* `fade` is initialized every time `trystat()` is called.
* `stay` is initialized only once, when `traystat()` is compiled.

As for the two statement:

* The first statement is really part of the `trystat()` function and is
  executed each time the function is called. It is a runtime action. 
* The second statement isn't actually part of the `trystat()` function.
  Placing the second statement in the `trystat()` function tells the compiler
  that only the `trystat()` function is allowed to see the variable; it’s not a
  statement that’s executed during runtime.

> Static variables are initialized to zero if you don’t explicitly initialize
> them to some other value. 
>
> Static variables and external variables are already in place after a program
> is loaded into memory.

---

You can’t use `static` for function parameters:

```c
int wontwork(static int flu);       // not allowed
```

## Static Variable with external Linkage (external storage class)

A static variable with external linkage has:

* File scope,
* External linkage,
* Static storage duration.

Variables of this type are called `external variables`.

You create an external variable by:

* Placing a defining declaration outside of any function.
* Or additionally be declared inside a function that uses it by using the
  `extern` keyword. 

> If a particular external variable is defined in one source code file and is
> used in a second source code file, declaring the variable in the second file
> with `extern` is mandatory. 

```c
int Errupt;             /* externally defined variable */
double Up[100];         /* externally defined array */
extern char Coal;       /* mandatory declaration if */
                        /* Coal defined in another file */
void next(void);

int main(void)
{
    extern int Errupt;  /* optional declaration */
    extern double Up[]; /* optional declaration */
    /* some code */
}
void next(void)
{
    /* some code */
}
```

> If you actually need to use a local variable with the same name as a global
> variable, you might opt to use the `auto` storage-specifier in the local
> declaration to document your choice.

```c
/* Example 1 */
int Hocus;
int magic();

int main(void)
{
    extern int Hocus;       // Hocus declared external
    /* some code */
}

int magic()
{
    extern int Hocus;       // same Hocus as above
    ...
}
```

```c
/* Example 2 */
int Hocus;
int magic();
int main(void)
{
    extern int Hocus;       // Hocus declared external
    ...
}
int magic()
{
                            // Hocus not declared but is known
    /* some code */
}
```

```c
/* Example 3 */
int Hocus;
int magic();
int main(void)
{
    int Hocus;              // Hocus declared, is auto by default
    ...
}

int Pocus;                  // external variable known to magic()
                            // but not to main()
int magic()
{
    auto int Hocus;         // local Hocus declared automatic

    /* some code */
}
```

### Initializing External Variables

* Like automatic variables, external variables can be initialized explicitly.
* Unlike automatic variables, external variables are initialized automatically
  to zero if you don’t initialize them. This rule applies to elements of an
  externally defined array, too.
* Unlike the case for automatic variables, you can use only constant
  expressions to initialize file scope variables:

```c
int x = 10;                 // ok, 10 is constant
int y = 3 + 20;             // ok, a constant expression
size_t z = sizeof(int);     // ok, a constant expression
int x2 = 2 * x;             // not ok, x is a variable
```

> As long as the type is not a variable array, a `sizeof` expression is
> considered a constant expression.

### Using an External Variable

```c
/* global.c -- uses an external variable */
#include <stdio.h>
int units = 0;                  /* an external variable */
void critic(void);
int main(void)
{
    extern int units;           /* an optional redeclaration */

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while ( units != 56)
        critic();
    printf("You must have looked it up!\n");

    return 0;
}
void critic(void)
{
    /* optional redeclaration omitted */
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &units);
}
```

### External Names

The C99 and C11 standards require compilers to recognize:

* The first 63 characters for local identifiers
* The first 31 characters for external identifiers.

### Definition and Declaration

```c
int tern = 1;               /* tern defined */
main()
{
    extern int tern;      /* use a tern defined elsewhere */
```

* The first declaration is called a *defining declaration*.
* The second is called a *referencing declaration*.

---

```c
extern int tern;
int main(void)
{
```

* This declaration does not cause space to be allocated. 
* The compiler will assume that the actual definition of `tern` is somewhere
  else in your program, perhaps in another file.

---

An external variable can be initialized only once, and that must occur when the
variable is defined.

```c
/* file one.c */
char permis = 'N';
```

```
/* file two.c */
extern char permis = 'Y';               /* error */
```

## Static Variable with Internal Linkage

```c
static int svil = 1;            // static variable, internal linkage
int main(void)
{
    /* some code */
}
```

Variables of this storage class have:

* Static storage duration.
* File scope.
* Internal linkage. 

The static variable with internal linkage can be used only by functions in
the same file. 

```c
int traveler = 1;           // external linkage
static int stayhome = 1;    // internal linkage
int main()
{
    extern int traveler;    // use global traveler
    extern int stayhome;    // use global stayhome

    /* some code */
}
```

* Both `traveler` and `stayhome` are global for this particular *translation
  unit*,
* But only `traveler` can be used by code in other translation units. 

## Multiple Files

To have a defining declaration in one file and referencing declarations in
the other files.

* Only the defining declaration should be used to initialize the variable.
* The others should use the `extern` keyword.

## Storage-Class Specifier Roundup

The C language has six keywords that are grouped together as storage-class
specifiers:

* `auto`
* `register`
* `static`
* `extern`
* `_Thread_local`
* `typedef` 

### `auto`

Indicates a variable with automatic storage duration.

It can be used only in declarations of variables with *block scope*, which
already have automatic storage duration, so its main use is documenting intent.

### `register`

Can be used only with variables of *block scope*.

It puts a variable into the register storage class, which amounts to a
request to minimize the access time for that variable.

Prevents you from taking the address of the variable.

### `static`

Creates an object with static duration, one that’s created when the program
is loaded and ends when the program terminates.

If static is used with a *file scope* declaration, scope is limited to that
one file.

If static is used with a *block scope* declaration, scope is limited to that
block.

* The object exists and retains its value as long as the program is running.
* But it can be accessed by the identifier only when code within the block is
  being executed.

A static variable with *block scope* has no linkage.

A static variable with *file scope* has internal linkage.

### `extern`

Declaring a variable that has been defined elsewhere.

If the declaration containing extern has *file scope*, the variable referred
to must have external linkage.

If the declaration containing extern has *block scope*, the referred-to
variable can have either external linkage or internal linkage, depending on
the defining declaration for that variable.

### Summary: Storage Classes

Automatic variables have:

* Block scope
* No linkage
* Automatic storage duration.

They are local and private to the block (typically a function) in which they
are defined.

Register variables have the same properties as automatic variables, but the
compiler may use faster memory or a register to store them.

You can’t take the address of a register variable.

---

Variables with static storage duration can have external linkage, internal
linkage, or no linkage.

When a variable is declared external to any function in a file, it’s an
external variable and has:

* File scope,
* External linkage
* Static storage duration.

If you add the keyword `static` to such a declaration, you get a variable with:

* Static storage duration
* File scope
* Internal linkage.

If you declare a variable inside a function and use the keyword `static`,
the variable has: 

* Static storage duration,
* Block scope,
* No linkage.

---

Memory for a variable with automatic storage duration is allocated when
program execution enters the block containing the variable declaration and
is freed when the block is exited.

* If uninitialized, such a variable has a garbage value.

Memory for a variable with static storage duration is allocated at compile
time and lasts as long as the program runs.

* If uninitialized, such a variable is set to `0`.

---

* A variable with block scope is local to the block containing the declaration.
* A variable with file scope is known to all functions in a file (or
  translation unit) following its declaration.
* If a file scope variable has external linkage, it can be used by other
  translation units in the program.
* If a file scope variable has internal linkage, it can be used just within the
  file in which it is declared.

## Storage Classes and Functions

Functions have storage classes, can be either:

* External (the default): can be accessed by functions in other files.
* Static: can be used only within the defining file.
* Inline function: added in C99.

```c
double gamma(double);                   // external by default
static double beta(int, int);
extern double delta(double, int);
```

* The functions `gamma()` and `delta()` can be used by functions in other files
  that are part of the program.
* But `beta()` cannot. Because this `beta()` is restricted to one file, you can
  use a different function having the same name in the other files.

One reason to use the static storage class is to create functions that are
private to a particular module, thereby avoiding the possibility of name
conflicts.

The usual practice is to use the `extern` keyword when declaring functions
defined in other files. This practice is mostly a matter of clarity because a
function declaration is assumed to be `extern` unless the keyword `static` is
used.

## Which Storage Class

There's a subtle pitfall in using external storage.

But one common exception are `const` data.

### "Need to know" principle

Keep the inner workings of each function as private to that function as
possible, sharing only those variables that need to be shared.

## A Random Number Function and a Static Variable

```c
static unsigned long int next = 1;

int rand1(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void srand1(unsigned int seed)
{
    next = seed;
}
```

```c
#include <stdio.h>
extern void srand1(unsigned int x);         // the extern is optional
extern int rand1(void);

int main(void)
{
    int count;
    unsigned seed;

    printf("Please enter your choice for seed.\n");
    while (scanf("%u", &seed) == 1)
    {
        srand1(seed);
        for (count = 0; count < 5; count++)
            printf("%d\n", rand1());
        printf("Please enter next seed (q to quit):\n");
    }
    printf("Done\n");

    return 0;
}
```

### Note Automated Reseeding

The exact type for the return value of `time()` is system dependent and is
given the label `time_t`, but you can use a type cast:

```c
#include <time.h>
    srand1((unsigned int) time(0));         /* initialize seed */
```

In general, `time()` takes an argument that is the address of a type `time_t`
object. In that case, the time value is also stored at that address. However,
you can pass the null pointer (`0`) as an argument, in which case the value is
supplied only through the return value mechanism.

## Roll 'Em

`rand()` produces an integer in the range 0 to `RAND_MAX`, which is defined
in `stdlib.h`, typically `INT_MAX` .

```c
#include <stdlib.h>
int rollem(int sides)
{
    int roll;

    roll = rand() % sides + 1;

    return roll;
}
```

## Allocate Memory: `malloc()` and `free()`

Both `malloc()` and `free()` have prototypes in the `stdlib.h` header file.

### The `malloc()` Function

The `malloc()` function takes one argument: the number of bytes of memory
you want.

The memory is anonymous; `malloc()` allocates memory but it doesn’t assign
a name to it. it just return the address of the first byte of that block.

You can assign that address to a pointer variable and use the pointer to
access the memory.

Because `char` represents a byte, `malloc()` has traditionally been defined
as type pointer-to-`void`.


The `malloc()` function can be used to return pointers to arrays, structures,
and so forth, so normally the return value is typecast to the proper value.

If `malloc()` fails to find the required space, it returns the null pointer.

---

```c
double * ptd;
ptd = (double *) malloc(30 * sizeof(double));
```

> Note that ptd is declared as a pointer to a single `double` and not to a
> block of 30 `double` values.

---

Three ways to create an array:

* Declare an array using constant expressions for the array dimensions and use
  the array name to access elements. Such an array can be created using either
  static or automatic memory.
* Declare a variable-length array using variable expressions for the array
  dimensions and use the array name to access elements. (Recall that this is a
  C99 feature.) This feature is available only for automatic memory.
* Declare a pointer, call `malloc()` , assign the return value to the pointer,
  and use the pointer to access elements. The pointer can be either static or
  automatic.

---

The second and third methods can create a `dynamic array`, one that’s
allocated while the program runs and that you can choose a size for while
the program runs.

```c
double item[n];             // pre C99: not allowed if n is a variable
ptd = (double *) malloc(n * sizeof(double));        // okay
```

The typecast to `(double *)` is optional in C but required in C++

### The `free()` Function

The `free()` function takes as its argument an address returned earlier
by `malloc()` and frees up the memory that had been allocated. 

you can’t use `free()` to free memory allocated by other means, such as
declaring an array.

The `free()` function frees only the block of memory to which its argument
points.

Some operating systems will free allocated memory automatically when a
program finishes, but others may not.

### The Importance of `free()`

The amount of static memory is fixed at compile time; it does not change
while the program is running.

The amount of memory used for automatic variables grows and shrinks
automatically as the program executes.

But the amount of memory used for allocated memory just grows unless you
remember to use `free()`. In that case, the pointer, being an automatic
variable, disappears. But the several bytes of memory it used to pointed to
still exist.

### The `calloc()` Function

```c
long * newmem;

newmem = (long *) calloc(100, sizeof(long))
```

* `calloc()` takes two arguments, both are unsigned integers (type `size_t`)
* The first argument is the number of memory cells you want.
* The second argument is the size of each cell in bytes.

> The `calloc()` function sets all the bits in the block to zero.

### Dynamic Memory Allocation and Variable-Length Arrays

```c
int vlamal()
{
    int n;
    int * pi;
    scanf("%d", &n);
    pi = (int *) malloc(n * sizeof(int))
    int ar[n];
    pi[2] = ar[2] = -5;
}
```

Difference:

VLA is  automatic storage. The memory space used by the VLA is freed
automatically when the execution leaves the defining block

The array created using `malloc()` needn’t have its access limited to one
function:

For example, one function could create an array and return the pointer, giving
the calling function access. Then the calling function could call `free()` when
it is finished.

It’s okay to use a different pointer variable with `free()` than with
`malloc();` what must agree are the addresses stored in the pointers.

You should not try to free the same block of memory twice.

```c
int n = 5;
int m = 6;
int ar2[n][m];          // n x m VLA
int (* p2)[6];          // works pre-C99
int (* p3)[m];          // requires VLA support
p2 = (int (*)[6]) malloc(n * 6 * sizeof(int));      // n * 6 array
p3 = (int (*)[m]) malloc(n * m * sizeof(int));   // n * m array, requires VLA
ar2[1][2] = p2[1][2] = 12;
```

### Storage Classes and Dynamic Memory Allocation

You can think of a program as dividing its available memory into three
separate sections:

* One for static variables with external linkage, internal linkage, and no
  linkage;
* One for automatic variables;
* One for dynamically allocated memory.

The amount of memory needed for the static duration storage class is known at
compile time, and each variable of these classes comes into being when the
program starts and expires when the program ends.

An automatic variable comes into existence when a program enters the block of
code containing the variable’s definition and expires when its block of code
is exited.  This section of memory is typically handled as a *stack*. That
means new variables are added sequentially in memory as they are created and
then are removed in the opposite order as they pass away.

Dynamically allocated memory comes into existence when `malloc()` or a related
function is called, and it’s freed when free() is called. Memory persistence is
controlled by the programmer, not by a set of rigid rules, so a memory block
can be created in one function and disposed of in another function. Because of
this, the section of memory used for dynamic memory allocation can end up
fragmented—that is, unused chunks could be interspersed among active blocks of
memory. Also, using dynamic memory tends to be a slower process than using
stack memory.

> Dynamically allocated data occupies a region often called a *memory heap* or
> *free store*).

## ANSI C Type Qualifiers

Variable characterized by:

* Type
* Storage class
* `const`
* `volatile`
* `restrict`
* `_Atomic`

You can use the same qualifier more than once in a declaration, and the
superfluous ones are ignored:

```c
const const const int n = 6; // same as const int n = 6;
```

```c
typedef const int zip;
const zip q = 8;
```

### The `const` Type Qualifier

#### Using const with Pointers and Parameter Declarations

```c
const float * pf;       /* pf points to a constant float value */
float * const pt;       /* pt is a const pointer */
const float * const ptr;
flat const * pfc;       // same as const float * pfc;
```

In short, a `const` anywhere to the left of the `*` make the data constant, and
a `const` to the right of the `*` makes the pointer itself constant.

In a prototype and a function header, the parameter declaration `const int
array[]` is the same as `const int * array`.

#### Using `const` with Global Data

To share `const` data across file. There are two strategiet

```c
/* file1.c -- defines some global constants */
const double PI = 3.14159;
const char * MONTHS[12] =
    {"January", "February", "March", "April", "May", "June", "July",
     "August", "September", "October", "November", "December"};
```

```c
/* file2.c -- use global constants defined elsewhere */
extern const double PI;
extern const * MONTHS[];
```

---

Or to place the constant in an `include` file.

```c
/* constant.h -- defines some global constants */
static const double PI = 3.14159;
static const char * MONTHS[12] =
    {"January", "February", "March", "April", "May", "June", "July",
     "August", "September", "October", "November", "December"};
```

```c
/* file1.c -- use global constants defined elsewhere */
#include "constant.h"
```

```c
/* file2.c -- use global constants defined elsewhere */
#include "constant.h"

```

> Use the keyword `static`. if not, including `constant.h` in `file1.c` and in
> `file2.c` would result in each file having a defining declaration of the same
> identifier. (Some compilers allow this)

### The `volatile` Type Qualifier

The `volatile` qualifier tells the compiler that a variable can have its value
altered by agencies other than the program, typically used for hardware
addresses and for data shared with other programs or threads running
simultaneously.

```c
volatile int loc1;      // locl is a volatile location
volatile int * ploc;    // ploc points to a volatile location
```

`loc1` to be a volatile value and `ploc` to point to a volatile value.

----------------------------------------------------------------------------------

```c
val1 = x;
/* some code not using x */
val2 = x;
```

A smart (optimizing) compiler might notice that you use `x` twice without
changing its value. It would temporarily store the `x` value in a register.
Then, when `x` is needed for `val2`, it can save time by reading the value from
a register instead of from the original memory location.

This procedure is called *caching*. Ordinarily, *caching* is a good
optimization, but not if `x` is changed between the two statements by some
other agency. If there were no `volatile` keyword, a compiler would have no way
of knowing whether this might happen. Therefore, to be safe, the compiler
couldn’t cache.

That was the pre-ANSI situation. Now, however, if the `volatile` keyword is not
used in the declaration, the compiler can assume that a value hasn’t changed
between uses, and it can then attempt to optimize the code.

A value can be both `const` and `volatile`. For example, the hardware clock
setting normally should not be changed by the program, making it `const`, but
it is changed by an agency other than the program, making it `volatile`.  The
order doesn’t matter:

```c
volatile const int loc;
const volatile int * ploc;
```

### The `restrict` Type Qualifier

The `restrict` keyword enhances computational support by giving the compiler
permission to optimize certain kinds of code.

It can be applied only to pointers, and it indicates that a pointer is the
sole initial means of accessing a data object.

```c
int ar[10];
int * restrict restar = (int *) malloc(10 * sizeof(int));
int * par = ar;

for (n = 0; n < 10; n++)
{
    par[n] += 5;
    restar[n] += 5;
    ar[n] *=2;
    par[n] += 3;
    restar[n] +=3;
}
```

The pointer `restar` is the sole initial means of access to the memory
allocated by `malloc()`

```c
restar[n] += 8;         // ok replacement
par[n] += 8;            // gives wrong answer
```

With the `restrict` keyword used, the compiler is free to look for
computational shortcuts.

```c
void * memcpy(void * restrict s1, const void * restrict s2, size_t n);
void * memmove(void * s1, const void * s2, size_t n);
```

* Each one copies n bytes from location `s2` to location `s1`.
* The `memcpy()` function requires that there be no overlap between the two
  locations, but `memmove()` doesn’t have that requirement.
* Declaring `s1` and `s2` as `restrict` means each pointer is a sole means of
  access, ***so they can’t access the same block of data***. This matches the
  requirement that there be no overlap.

The keywordd `restrict`

* Tells the compiler it is free to make certain assumptions concerning
  optimization.
* Tells the user to use only arguments that satisfy `restrict` requirements.

### The `_Atomic` Type Qualifier (C11)

In concurrent programming, while a thread performs an atomic operation on an
object of atomic type, other threads won’t access that object.

```c
int hogs;           // regular declaration
hogs = 12;          // regular assignment

// could be replaced by
_Atomic int hogs;               // hogs an atomic variable
atomic_storage(&hogs, 12);      // macro form stdatomic.h
```

Here, the storing of the value `12` in hogs is an atomic process during
which other threads won’t access hogs .

### New Places for Old Keywords

```c
void ofmouth(int * const a1, int * restrict a2, int n);     // older style
void ofmouth(int a1[const], int a2[restrict], int n);       // allowed by C99
```

The new rule allows you to use these two qualifiers with either pointer or
array notation in declaring function parameters.

```c
double stick(double ar[static 20]);
```

The keyword `static`

* Tells the compiler it is free to make certain assumptions concerning
  optimization.
* Tells the user to only provide arguments that satisfy the static
  requirements.
