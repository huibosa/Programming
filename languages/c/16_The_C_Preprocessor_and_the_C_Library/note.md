* The preprocessor looks at your program before it is compiled.
* Following your preprocessor directives, the preprocessor replaces the
  symbolic abbreviations in your program with the directions they represent.
* The preprocessor can include other files at your request, and it can select
  which code the compiler sees.
* The preprocessor doesn’t know about C. Basically, it takes some text and
  converts it to other text.

## First Steps in Translating a Program

* The compiler starts its work by mapping characters appearing in the source
  code to the source character set.
* Second, the compiler locates each instance of a backslash (`\`) followed by a
  newline character (`\n`) and deletes them.
* Next, the compiler breaks the text into a sequence of preprocessing tokens
  and sequences of whitespace and comments.
* Finally, the program is ready for the preprocessing phase, and the
  preprocessor looks for potential preprocessing directives, indicated by a `#`
  symbol at the beginning of a line.

## Manifest Constants: `#define`

```c
#include <stdio.h>
#define TWO 2       /* you can use comments if you like   */
#define OW "Consistency is the last refuge of the unimagina\
tive. -Oscar Wilde" /* a backslash continues a definition */
                    /* to the next line                   */
#define FOUR TWO*TWO
#define PX printf("X is %d.\
        \n",x);
#define FMT "X is %d\n"

int main(void)
{
    int x = TWO;

    PX;
    x = FOUR;
    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");

    return 0;
}
```

* A directive can appear anywhere in the source file, and the definition holds
  from its place of appearance to the end of the file.
* Preprocessor directives run until the first newline following the `#`. While
  you can use the combination `backslash/newline` to spread the directive over
  several physical lines.
* The ANSI and subsequent standards permit the `#` symbol to be preceded by
  spaces or tabs, and it allows for space between the `#` and the remainder of
  the directive (older versions don't).

![1](./images/directive.png)

Each `#define` line (logical line, that is) has three parts.

* The first part is the `#define` directive itself.
* The second part is your chosen abbreviation, known as a macro.
* Some macros, represent values; they are called object-like macros. (C also
  has function-like macros) 
* The third part (the remainder of the line) is termed the replacement list or
  body.
* This process of going from a macro to a final replacement is called macro
  expansion.

> A macro definition can include other macros. (Some compiler do not support
> this nesting feature.)

```c
#define LIMIT 20
const int LIM = 50;
static int data1[LIMIT];    // valid
static int data1[LIM];      // not required to be valid
const int LIM2 = 2 * LIMIT; // valid
const int LIM3 = 2 * LIM;   // not required to be valid
```

* In C, the array size for nonautomatic arrays is supposed to be an integer
  constant expression, meaning that it’s a combination of integer constants,
  such as `5`, enumeration constants, and `sizeof` expressions.
* This doesn’t include values declared using `const`.
* In C++ you can use const values as part of constant expressions.
* However, an implementation may accept other forms of constant expressions.

### Tokens

* Technically, the body of a macro is considered to be a string of tokens
  rather than a string of characters.
* C preprocessor tokens are the separate “words” in the body of a macro
  definition. They are separated from one another by whitespace.

```c
#define FOUR 2*2
#define FOUR 2 * 2
```

* The first definition has one token, the sequence `2*2`.
* The first definition has three tokens, `2`, `*`, `3`.

```c
#define EIGHT 4     *     8
```

* A preprocessor that interprets the body as a character string would replace
  EIGHT with `4     *     8`.
* A preprocessor that interprets the body as tokens will replace `EIGHT` with
  three tokens separated by single spaces: `4 * 8`.
* The character string interpretation views the spaces as part of the body.
* The token interpretation views the spaces as separators between the tokens of
  the body.

> In practice, some C compilers have viewed macro bodies as strings rather than
> as tokens. The difference is of practical importance only for usages more
> intricate than what we’re attempting here.

> Incidentally, the C compiler takes a more complex view of tokens than the
> preprocessor does.  The compiler understands the rules of C and doesn’t
> necessarily require spaces to separate tokens. For example, the C compiler
> would view `2*2` as three tokens because it recognizes that each 2 is a
> constant and that `*` is an operator.

### Redefining Constants

Implementations differ on redefinition policy.

* Some consider it an error unless the new definition is the same as the old.
* Others allow redefinition, perhaps issuing a warning.

---

Having the same definition means the bodies must have the same tockens in the
same order.

```c
#define SIX 2 * 3
#define SIX 2        *         3

#define SIX 2*3
```

* The first two definitions both have the same three tokens, and the extra
  spaces are not part of the body. 
* The third definition it has just one token, not three, so it doesn’t match.

## Using Arguments with `#define`

```c
#define SQUARE(X) X*X

z = SQUARE(2);
```

Function-like macro definitions have one or more arguments in parentheses, and
these arguments then appear in the replacement portion.

![2](./images/funcmacro.png)


```c
#define SQUARE(X) X*X

int x = 5;

printf("Evaluating SQUARE(x+2): ");
```

* The preprocessor doesn’t make calculations, it just substitutes character
  sequences.
* Wherever the definition shows an `x`, the preprocessor substitutes the
  characters `x+2`.
* `x*x` becomes `x+2*x+2`

> Use as many parentheses as necessary to ensure that operations and
> associations are done in the right order.

This example pinpoints an important difference between a function call and a
macro call.

* A function call passes the value of the argument to the function while the
  program is running.
* A macro call passes the argument token to the program before compilation;
  it’s a different process at a different time.

---

```c
SQUARE(++x)
```

* Becomes `++x*++x`
* Because the order of operations is left open, some compilers render the
  product `7*6`.
* Yet other compilers might increment both terms before multiplication,
  yielding `7*7`,or 49.

> In general, don’t use increment or decrement operators with macros. Note
> that `++x` would work as a function argument because it would be evaluated to
> `6` , and then the value `6` would be sent to the function.

### Creating Strings from Macro Arguments: The `#` Operator

To include the macro argument in a string. Within the replacement part of a
function-like macro, the `#` symbol becomes a preprocessing operator that
converts tokens into strings.

For example, say that `x` is a macro parameter, and then `#x` is that parameter
name converted to the string `"x"` . This process is called *stringizing*.

---

```c
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x)*(x)))

int y = 5;

PSQR(y);
PSQR(2 + 4);
```

* In the first call to the macro, `#x` was replaced by `"y"` , and in the
  second call `#x` was replaced by `"2 + 4"`.
* ANSI C string concatenation then combined these strings with the other
  strings in the `printf()` statement to produce the final strings that were
  used.

For example, the first invocation becomes this:

```c
printf("The square of " "y" " is %d.\n",((y)*(y)));
```

---

### Preprocessor Glue: The `##` Operator

* The `##` operator can be used in the replacement section of a function-like
  macro.
* Additionally, it can be used in the replacement section of an object-like
  macro.
* The `##` operator combines two tokens into a single token.

```c
#define XNAME(n) x ## n
XNAME(4)
```

* `XNAME(4)` becomes `x4`.

### Variadic Macros: `...` and `__VA_ARGS__`

> Some functions, such as `printf()`, accept a variable number of arguments.
> The `stdvar.h` provides tools for creating user-defined functions with a
> variable number of arguments. 

Although not used in the standard, the word `variadic` has come into currency
to label this facility. (However, the process that has added `stringizing` and
`variadic` to the C vocabulary has not yet led to labeling functions or macros
with a fixed number of arguments as fixadic functions and normadic macros.)

The idea is that the final argument in an argument list for a macro definition
can be ellipses. If so, the predefined macro `__VA_ARGS__` can be used in the
substitution part to indicate what will be substituted for the ellipses. 

```c
#define PR(...) printf(__VA_ARGS__)

PR("Howdy");
PR("weight = %d, shipping = $%.2f\n", wt, sp);
```

* `__VA_ARGS__` expands to one argument in the first inovation.
* `__VA_ARGS__` expands to three arguments in the second inovation.

## Macro or Function

> Some compilers limit the macro definition to one line, and it is probably
> best to observe that limit, even if your compiler does not.

* A macro produces inline code, which might use more space. (If you use the
  macro 20 times, you get 20 lines of code inserted into your program).
* Program control must shift to where the function is and then return to the
  calling program, and this takes longer than inline code.
* Macros have an advantage in that they don’t worry about variable types. (This
  is because they deal with character strings, not with actual values.)

```c
#define MAX(X,Y)    ((X) > (Y) ? (X) : (Y))
#define ABS(X,Y)    ((X) <  0 ? -(X) : (Y))
#define ISSIGN(X,Y)    ((X) == '+' || (X) == '-' ? 1 : 0)
```

* Remember that there are no spaces in the macro name, but that spaces can
  appear in the replacement string. ANSI C permits spaces in the argument list.
* Use parentheses around each argument and around the definition as a whole.
* Use capital letters for macro function names.
* A macro that is used once in a program probably won’t make any noticeable
  improvement in running time.
* A macro inside a *nested loop* is a much better candidate for speed
  improvements.

## File Inclusion: `#include`

* When the preprocessor spots an `#include` directive, it looks for the
  following filename and includes the contents of that file within the current
  file.
* The `#include` directive in your source code file is replaced with the text
  from the included file.

```c
#include <stdio.h>              // Searches directive >> system directory
#include "hot.h"                // searches your current working directory
#include "usr/biff/p.h"         // searches the /usr/biff directory
```

ANSI C doesn’t demand adherence to the directory model for files because not
all computer systems are organized similarly. In general, the method used to
name files is system dependent.

* On a Unix system, the angle brackets tell the preprocessor to look for the
  file in one or more standard system directories.
* The double quotation marks tell it to first look in your current directory
  (or some other directory that you have specified in the filename) and then
  look in the standard places
* IDEs also have a standard location or locations for the system header files.
  Many provide menu choices for specifying additional locations to be searched
  when angle brackets are used.
* As with Unix, using double quotes means to search a local directory first,
  but the exact directory searched depends on the compiler. Some search the
  same directory as that holding the source code; some search the current
  working directory; and some search the same directory as that holding the
  project file.

Including a large header file doesn’t necessarily add much to the size of your
program. The content of header files, for the most part, is information used by
the compiler to generate the final code, not material to be added to the final
code.

### Header Files: An Example

This header file includes many of the kinds of things commonly found in header
files. Note that none of these things are excutable code; rather they are
information that the compiler uses when it creates excutable code:

* `#define` directives.
* Structure declarations.
* `typedef` statements.
* Function prototypes.

Executable code normally goes into a source code file, not a header file.

```c
// names_st.h -- names_st strcture header file
// constants
#include <string.h>
#define SLEN 32

// structure declarations
struct names_st
{
    char first[SLEN];
    char last[SLEN];
};

// typedefs
typedef struct names_st names;

// function prototype
void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);
```

```c
// names_st.c -- define names_st functions
#include <stdio.h>
#include "6.h"                      /* include the header file */

// function definitions
void get_names(names * pn)
{
    printf("Please enter your first name: ");
    s_gets(pn->first, SLEN);
    printf("Please enter your last name: ");
    s_gets(pn->last, SLEN);
}

void show_names(const names * pn)
{
    printf("%s %s", pn->first, pn->last);
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // look for newline
        if (find)                   // if the address is not NULL,
            *find = '\0';           // place a null character there
        else
        while (getchar() != '\n')
            continue;               // dispose of rest of line
    }
    return ret_val;
}
```

```c
// useheader.c -- use the names_st structure
#include <stdio.h>
#include "names_st.h"

// remember to link with 7.c

int main(void)
{
    names candidate;

    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");

    return 0;
}
```

* Both source code files use the `names_st` structure, so both have to include
  the `names_st.h` header file.
* You need to compile and link the `names_st.c` and the `useheader.c` source
  code files.
* Declarations and the like go into the `names_st.h` header file; function
  definitions go into the `names_st.c` source code file.

### Use for Header Files

 The most common forms of header contents include the following:

* Manifest constants--A typical `stdio.h` file, for instance, defines `EOF`,
  `NULL`, and `BUFSIZ` (the size of the standard I/O buffer).
* Macro functions--For example, `getchar()` is usually defined as
  `getc(stdin)`, `getc()` is usually defined as a rather complex macro, and the
  `ctype.h` header typically contains macro definitions for the ctype
  functions.
* Function declarations--The `string.h` header (`strings.h` on some older
  systems), for example, contains function declarations for the family of
  string functions. Under ANSI C and later, the declarations are in function
  prototype form.
* Structure template definitions--The standard I/O functions make use of a
  `FILE` structure containing information about a file and its associated
  buffer. The `stdio.h` file holds the declaration for this structure.
* Type definitions--You might recall that the standard I/O functions use a
  pointer-to-`FILE` argument. Typically, `stdio.h` uses a `#define` or a
  `typedef` to make `FILE` represent a pointer to a structure. Similarly, the
  `size_t` and `time_t` types are defined in header files.

You can use header files to declare external variables to be shared by several
files. For example, if you’ve developed a family of functions that share a
variable for reporting a status of some kind, such as an error condition. In
that case, you could define a file-scope, external-linkage variable in the
source code file containing the function declarations:

```c
int status = 0;     // file scope, source code file
```

```c
extern int status;  // int header file
```

* This code would then appear in any file in which you included the header
  file, making the variable available to those files that use that family of
  functions.
* This declaration also would appear, through inclusion, in the function source
  code file.
* But it’s okay to have both a defining declaration and a reference declaration
  in the same file, as long as the declarations agree in type.

Another candidate for inclusion in a header file is a variable or array with
file scope, internal linkage, and `const` qualification.

* The `const` part protects against accidental changes.
* The `static` part means that each file including the header gets its own copy
  of the constants so that there isn’t the problem of needing one file with a
  defining declaration and the rest with reference declarations.

## Other Directives

The preprocessor provides several directives that help the programmer produce
code that can be moved from one system to another by changing the values of
some `#define` macros.

* The `#undef` directive cancels an earlier `#define` definition.
* The `#if`, `#ifdef`, `#ifndef`, `#else`, `#elif`, and `#endif` directives
  allow you to specify different alternatives for which code is compiled.
* The `#line` directive lets you reset line and file information.
* The `#error` directive lets you issue error messages.
* The `#pragma` directive lets you give instructions to the compiler.

### The `#undef` Directive

```c
#define LIMIT 400

#undef LIMIT
```

* The `#undef` removes that definition.
* You can redefine `LIMIT` so that it has a new value.
* Even if LIMIT is not defined in the first place, it is still valid to
  undefine it.
* If you want to use a particular name and you are unsure whether it has been
  used previously, you can undefine it to be on the safe side.

### Being Defined--The C Preprocessor Perspective

* If the identifier is a macro name created by a prior `#define` directive in
  the same file and it hasn’t been turned off by an `#undef` directive, it’s
  defined.
* If the identifier is not a macro but is, say, a file-scope C variable, it’s
  not defined as far as the preprocessor is concerned.

A defined macro can be an object-like macro, including an empty macro, or a
function-like macro:

```c
#define LIMIT 1000              // LIMIT is defined
#define GOOD                    // GOOD is defined
#define A(X) ((-(X)*(X))        // A is defined
#int q;                         // q not a macro, hence not defined
#undef GOOD                     // GOOD not defined
```

* Note that the scope of a `#define` macro extends from the point it is
  declared in a file until it is the subject of an `#undef` directive or until
  the end of the file, whichever comes first.
* Also note that the position of the `#define` in a file will depend on the
  position of an `#include` directive if the macro is brought in via a header
  file.

> A few predefined macros, such as `__DATE__` and `__FILE__` (discussed later
> this chapter), are always considered defined and cannot be undefined.

### Conditional Compilation

#### The `#ifdef`, `#else`, `#endif` Directives

```c
#ifdef MAVIS
    #include "horse.h"      // gets done if MAVIS is #defined
    #define STABLES       5
#else
    #include "cow.h"        // gets done if MAVIS isn'nt #defined
    #define STABLES       15
#endif

// for a old implementation
#ifdef MAVIS
#   include "horse.h"      // gets done if MAVIS is #defined
#   define STABLES       5
#else
#   include "cow.h"        // gets done if MAVIS isn'nt #defined
#   define STABLES       15
#endif
```

* If you have a old implementation, you might have to move all the directives,
  or at least the `#` symbols, to flush left
* The `#ifdef` directive says that if the following identifier (`MAVIS`) has
  been defined by the preprocessor, follow all the directives and compile all
  the C code up to the next `#else` or `#endif`, whichever comes first.
* If there is an `#else`, everything from the `#else` to the `#endif` is done
  if the identifier isn’t defined.
* These conditional structures can be nested.
* You can use these directives to mark blocks of C statements.

```c
#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;

    for (int i = 0; i <= LIMIT; i++)
    {
        total += 2*i*i + 1;
#ifdef JUST_CHECKING
        printf("i=%d, running total = %d\n", i, total);
#endif
    }
    printf("Grand total = %d\n", total);

    return 0;
}
```

You can use this approach, for example, to help in program debugging.

* Define `JUST_CHECKING` and use a judicious selection of `#ifdefs`, and the
  compiler will include program code for printing intermediate values for
  debugging.
* After everything is working, you can remove the definition and recompile.
* If, later, you find that you need the information again, you can reinsert the
  definition and avoid having to retype all the extra print statements.
* Another possibility is using `#ifdef` to select among alternative chunks of
  codes suited for different C implementations.

#### The `#ifndef` Directive

`#ifndef` is the negative of `#ifdef`. This directive is often used to define a
constant if it is not already defined.

```c
/* arrays.h */
#ifndef SIZE
    #define SIZE 100
#endif
```

* The definition in the first header file included becomes the active
  definition and subsequent definitions in other header files are ignored.

```c
#include "arrays.h"          /* SIZE == 100 */
```

```c
#define SIZE 10
#include "arrays.h"          /* SIZE == 10 */
```

* You might do this, for example, to test a program using a smaller array size.
* When it works to your satisfaction, you can remove the `#define SIZE 10`
  statement and recompile.
* That way, you never have to worry about modifying the header array itself.

The `#ifndef` directive is commonly used to prevent multiple inclusion of a
file. Suppose the following file is included several times.

```c
/* things.h */
#ifndef THINGS_H_
    #define THINGS_H_
    /* rest of the include file */
#endif
```

Why would you include a file more than once? The most common reason is that
many include files include other files, so you may include a file explicitly
that another include file has already included.

Why is this a problem? Some items that appear in include files, such as
declarations of structure types, can appear only once in a file.

The standard C header files use the `#ifndef` technique to avoid multiple
inclusions. One problem is to make sure the identifier you are testing hasn’t
been defined elsewhere.

Vendors typically solve this by using the filename as the identifier, using
uppercase, replacing periods with an underscore, and using an underscore (or,
perhaps, two underscores) as a prefix and a suffix.  

```c
#ifndef _STDIO_H
#define _STDIO_H

/* contents of a file*/

#endif
```

#### The `#if` and `#elif` Directives

The `#if` directive is followed by a constant integer expression that is
considered true if nonzero, and you can use C's relational and logical operator
with it:

```c
#if SYS == 1
#include "ibm.h"
#endif
```

You can use the `#elif` directive (not available in some older implementations)
to extend an `if-else` sequence.

```c
#if SYS == 1
    #include "ibmpc.h"
#elif SYS == 2
    #include "vax.h"
#elif SYS == 3
    #include "mac.h"
#else
    #include "general.h"
#endif
```

Newer implementations offer a second way to test whether a name is defined.

```c
#ifdef VAX

#if defined (VAX)       /* newer implementations */
```

* `defined` is a preprocessor operator that returns `1` if its argument is
  `#defined` and `0` otherwise.
* The advantage of this newer form is that it can be used with `#elif`. Using
  it, you can rewrite the previous example this way:

```c
#if defined (IBMPC)
    #include "ibpmc.h"
#elif defined (VAX)
    #include "vax.h"
#elif defined (MAC)
    #include "mac.h"
#else
    #include "general.h"
#endif
```

* You may need to define `VAX` somewhere earlier in the file:

```c
#define VAX
```

* One use for these conditional compilation features is to make a program more
  portable.
* By changing a few key definitions at the beginning of a file, you can set up
  different values and include different files for different systems.

### Predefined Macros

| Macro              | Meaning                                                                                                        |
|:------------------:|----------------------------------------------------------------------------------------------------------------|
| `__DATE__`         | A character string literal in the form “Mmm dd yyyy” representing the date of preprocessing, as in Nov 23 2013 |
| `__FILE__`         | A character string literal representing the name of the current source code file                               |
| `__LINE__`         | An integer constant representing the line number in the current source code file                               |
| `__STDC__`         | Set to 1 to indicate the implementation conforms to the C Standard                                             |
| `__STDC_HOSTED__`  | Set to 1 for a hosted environment; 0 otherwise                                                                 |
| `__STDC_VERSION__` | For C99, set to `199901L`; for C11, set to `201112L`                                                           |
| `__TIME__`         | The time of translation in the form “hh:mm:ss”                                                                 |

The C99 standard provides for one called `__func__`.

* It expands to a string representing the name of the function containing the
  identifier.
* For this reason, the identifier has to have function scope, whereas macros
  essentially have file scope.
* Therefore, `__func__` is a C language predefined identifier rather than a
  predefined macro.

### `#line` and `#error`

The `#line` directive lets you reset the line numbering and the filename as
reported by the `__LINE__` and `__FILE__` macros.

```c
#line 1000          // reset current line number to 1000
#line 10 "cool.c"   // reset line number to 10, file name to cool.c
```

The `#error` directive causes the preprocessor to issue an error message that
includes any text in the directive. If possible, the compilation process should
halt.

```c
#if __STDC_VERSION__ != 201112L
#error Not C11

#endif
```

* The compilation process failed when the compiler used an older standard and
  succeeded when it use the C11 standard

### `#pragma`

Modern compilers have several settings that can be modified by command-line
arguments or by using an IDE menu. The `#pragma` lets you place compiler
instructions in the source code.

For example, while C99 was being developed, it was referred to as C9X, and one
compiler used the following pragma to turn on C9X support:

```c
#pragma c9x on
```

Generally, each compiler has its own set of pragmas. They might be used, for
example:

* To control the amount of memory set aside for automatic variables.
* or to set the strictness of error checking or to enable nonstandard language
  features.

> The C99 standard does provide for three standard pragmas of rather technical
> nature that we won’t discuss here.

---

C99 also provides the `_Pragma` preprocessor operator. It converts a string
into a regular pragma.

```c
_Pragma("nonstandardtreatmenttypeB on")

// equivalent to

#pragma nonstandardtreatmenttypeB on
```

Because the operator doesn't use the `#` symbol, you can use it as part of a
macro expansion:

```c
#define PRAGMA(X) _Pragma(#X)
#define LIMRG(X) PRAGMA(STDC CX_LIMITED_RANGE  X)

/* Then code like this */

LIMRG ( ON )
```

---

```c
#define LIMRG(X) _Pragma(STDC CX_LIMITED_RANGE #X)
```

* The definition doesn’t work because it relies on concatenation, but the
  compiler doesn’t concatenate strings until after preprocessing is complete.

---

The `_Pragma` operator does a complete job of “destringizing”; that is, escape
sequences in a string are converted to the character represented.

```c
_Pragma("use_bool \"true \"false")

// becomes

#pragma use_bool "true" "false
```

### Generic Selection

The term *generic programming* indicates code that is not specific to a
particular type but which, once a type is specified, can be translated into
code for that type.

C++, for example, lets you create generic algorithms in the form of templates
that the compiler can then use to instantiate code automatically for a
specified type.

C doesn’t have anything quite like that. However, C11 adds a new sort of
expression, called a `generic selection expression`,

* Can be used to select a value on the basis of the type of an expression, that
  is, on whether the expression type is `int`, `double`, or some other type.
* The generic selection expression is not a preprocessor statement, but its
  usual use is a part of a `#define` macro definition that has some aspects of
  generic programming.

---

```c
_Generic(x, int: 0, float: 1, double: 2, default: 3)
```

* Here `_Generic` is a new C11 keyword. The parentheses following `_Generic`
  contain several comma-separated terms.
* The first term is an expression, and each remaining item is a type followed
  by a colon followed by a value, such as `float: 1`.
* The type of the first term is matched to one of the labels, and the value of
  the whole expression is the value following the matched label.

For example, suppose `x` in the preceding expression is a type `int` variable.

* Then the type of `x` matches the `int: label`, making `0` the value of the
  whole expression.
* If the type doesn’t match a label, the value associated with the `default:
  label` is used for the whole expression.

---

```c
#define MYTYPE(X) _Generic((X),\
    int: "int",\
    float: "float",\
    double: "double",\
    default: "other"\
)
```

* The macro invocation `MYTYPE(5)` evaluates to the string `"int"`

## Inline Functions (C99)

* Normally, a function call has overhead. That means it takes execution time to
  set up the call, pass arguments, jump to the function code.
* Making a function an inline function suggests that call to the function be as
  fast as possible. 
* Making a function an inline function may cause the compiler to replace the
  function call with inline code and/or perform some other sorts of
  optimizations, or it may have no effect.

```c
#include <stdio.h>
inline static void eatline()    // inline definition/prototype
{
    while (getchar() != '\n')
        continue;
}

int main(void)
{
    /* some code */

    eatline();                  /* function call */

    /* some code */
}
```

Seeing the inline declaration, the compiler could choose, for example, to
replace the `eatline()` function call with the function body. That is, the
effect could end up the same as if you had written this code instead: 


```c
#include <stdio.h>
inline static void eatline()    // inline definition/prototype
{
    while (getchar() != '\n')
        continue;
}

int main(void)
{
    /* some code */

    while (getchar() != '\n')         /* function call replaced */
        continue;

    /* some code */
}
```

* You can’t take the inline function's address. (Actually, you can take the
  address, but then the compiler will generate a non-inline function.) 
* An inline function may not show up in a debugger.
* An inline function should be short.
* The inline function definition has to be in the same file as the function
  call. (An inline function ordinarily has internal linkage).
* If you have a multifile program, you need to put the inline function
  definition in a header file.  

```c
/* eatline.h */
#ifndef EATLINE_H_
#define EATLINE_H_
inline static void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
```

> An inline function is an exception to the rule of not placing executable code
> in a header file. Because the inline function has internal linkage, defining
> one in several files doesn’t cause problems.

C, unlike C++, also allows a mixture of inline definitions with external
definitions (function definitions with external linkage).

```c
/* file1.c */

/* some code */
inline static double square(double);
double square(double x)
{
    return x * x;
}

int main(void)
{
    double q = square(1.3);

    /* some code */
}
```

```c
/* file2.c */

/* some code */
double square(double x)
{
    return (int) (x*x);
}

void spam(double v)
{
    double dv = square(v);

    /* some code */
}
```

```c
/* file3.c */

/* some code */
inline double square(double x)
{
    return (int) (x * x + 0.5);
}

void masp(double w)
{
    double kw = square(w);
}
```

* `file1.c` has an `inline static` definition.  `main()` in `file1.c` uses the
  local `static` definition of `square()`. Because this definition also is
  `inline`, the compiler may (or may not) optimize the coding, perhaps inlining
  it.
* `file2.c` has an ordinary function definition, hence having external linkage.
  The `spam()` function in `file2.c` uses the `square()` definition in that
  file. That definition, having external linkage, is visible to the other
  files,
* `file3.c` has an `inline` definition that omits the `static` qualifier. the
  compiler is free to use either (or both!) the inline definition of `file3.c`
  or the external linkage definition from `file2.c`.

> If you omit `static` from an inline definition, as in `file3.c`, the `inline`
> definition is considered as an alternative that could be used instead of the
> external definition.  

> Note that GCC implemented `inline` functions prior to C99 using somewhat
> different rules, so the GCC interpretation of `inline` can depend on which
> compiler flags you use.

### `_Noreturn` Functions (C11)

* When C99 added the inline keyword, that keyword became the sole example of a
  function specifier.
* The keywords `extern` and `static` are termed storage-class specifiers and
  can be applied to data objects as well as to functions.)
* C11 adds a second function specifier, `_Noreturn`, to indicate a function
  that, upon completion, does not return to the calling function.
* The `exit()` function is an example of a `_Noreturn` function, for once
  `exit()` is called, the calling function never resumes.
* Note that this is different from the `void return` type. A typical void
  function does return to the calling function; it just doesn’t provide an
  assignable value.

The purpose of `_Noreturn` is to:

* Informing the user and the compiler that a particular function won't return
  control to the calling program.
* Informing the compiler may enable it to make some code optimizations. 

## The C Library

### Gaining Access to the C Library

* There are aften several differnt places to find library functions.
* Different systems have different ways to reach these functions

#### Automatic Access

#### File Inclusion

#### Library Inclusion

* At some stage in compiling or linking a program, you might have to specify a
  library option.
* These libraries have to ve requested explicitly by using a compile-time
  option.
* A header file provides a function declaration or prototype.
* The library option tells system where to find the function code.

#### Using the library Descriptions

Here is how `fread()` is listed in older Unix documentation:

```c
#include <stdio.h>

fread(ptr, sizeof(* ptr), nitems, stream)
FILE * stream;
```

The ANSI C90 standard provides the following description:

```c
#include <stdio.h>
size_t fread(void * ptr, size_t size, size_t nmemb, FILE * stream);
```

* The `size_t` type is defined as the unsigned integer type that the `sizeof`
  operator returns, which is either `unsigned long` or `unsigned` int.
* The `stddef.h` file contains a typedef or a `#define` for `size_t`, as do
  several other files, including `stdio.h`, typically by including `stddef.h`.
* Many functions, including `fread()`, often incorporate the `sizeof` operator
  as part of an actual argument. The `size_t` type makes that formal argument
  match this common usage.

> Also, ANSI C uses pointer-to-`void` as a kind of generic pointer for
> situations in which pointers to different types may be used.

The `C99/C11` standards incorporate the new keyword `restrict` into the description:

```c
size_t fread(void * restrict ptr, size_t size,
             size_t nmemb, FILE * restrict stream);
```

## The Math Library

| Prototype                          | Declaration                                                |
|------------------------------------|------------------------------------------------------------|
| `double acos(double x)`            | Returns the angle (0 to π radians) whose cosine is x       |
| `double asin(double x)`            | Returns the angle (—π/2 to π/2 radians) whose sine is x    |
| `double atan(double x)`            | Returns the angle (−π/2 to π/2 radians) whose tangent is x |
| `double atan2(double y, double x)` | Returns the angle (−π to π radians) whose tangent is y / x |
| `double cos(double x)`             | Returns the cosine of x (x in radians)                     |
| `double sin(double x)`             | Returns the sine of x (x in radians)                       |
| `double tan(double x)`             | Returns the tangent of x (x in radians)                    |
| `double exp(double x)`             | Returns the exponential function of x (ex)                 |
| `double log(double x)`             | Returns the natural logarithm of x                         |
| `double log10(double x)`           | Returns the base 10 logarithm of x                         |
| `double pow(double x, double y)`   | Returns x to the y power                                   |
| `double sqrt(double x)`            | Returns the square root of x                               |
| `double cbrt(double x)`            | Returns the cube root of x                                 |
| `double ceil(double x)`            | Returns the smallest integral value not less than x        |
| `double fabs(double x)`            | Returns the absolute value of x                            |
| `double floor(double x)`           | Returns the largest integral value not greater than x      |

### A Little Trigonometry

### Type Variants

* The C standard provides type `float ` and type `long double` versions of the
  standard functions, using an `f` or an `l` suffix on the function name.
* The C11 addition of the generic selection expression lets us define a generic
  macro that chooses the most appropriate version of a math function based on
  the argument type.

```c
#define RAD_TO_DEG (180 /(4 * atan(1)))

// generic square root function
#define SQRT(X) _Generic((X),\
    long double: sqrtl, \
    default: sqrt, \
    float: sqrtf)(X)

// generic sine function, angle in degrees
#define SIN(X) _Generic((X),\
    long double: sinl((X)/RAD_TO_DEG),\
    default:     sin((X)/RAD_TO_DEG),\
    float:       sinf((X)/RAD_TO_DEG)\
)
```

* The value of the `_Generic` expression is the name of a function, such as
  `sinf`.
* The name of a function is replaced by the address of the function, so the
  value of the `_Generic` expression is a pointer to a function.
* The entire `_Generic` expression is followed by `(X)`, and the combination of
  function-pointer(argument) calls the pointed-to function with the indicated
  argument.

> In short, for `SIN()`, the function call is inside the generic selection
> expression, while for `SQRT()` the generic selection expression evaluates to
> a pointer, which is then used to invoke a function.

### The `tgmath.h` Library (C99)

* The C99 standard provides a `tgmath.h` header file that defines type-generic
  macros.
* If a `math.h` function is defined for each of the three types `float`,
  `double`, and `long double`, the `tgmath.h` file creates a type-generic macro
  with the same name as the `double` version.
* If the compiler supports complex arithmetic, it supports the `complex.h`
  header file.

To invoke the `sqrt()` function instead of the `sqrt()` macro even though
`thmath.h` is included, you can enclose the function name in parentheses:

```c
#include <tgmath.h>

/* some code */

float x = 44.0;
double y;
y = sqrt(x);    // invoke macro, hence sqrtf(x)
y = (sqrt)(x);  // invoke function sqrt()
```

* This works because a function-like macro name has to be followed by an
  opening parenthesis, which using enclosing parentheses circumvents.
* Otherwise, aside from order of operations, parentheses don’t affect enclosed
  expressions, so enclosing a function name in parentheses still results in a
  function call.
* Indeed, because of C’s strangely contradictory rules about function pointers,
  you also can also use `(*sqrt)()` to invoke the `sqrt()` function.

## The General Utilities Library

### The `exit()` and `atexit()` Functions

* The `exit()` function is invoked automatically upon return from `main()`.
* The `atexit()` function let you specify particular functions to be called
  when `exit()` executes by registering the function to be called on exit.
* The `atexit()` takes a function pointer as its argument.

#### Using `atexit()`

* ANSI guarantees that you can place at least 32 functions on the list. Each
  function is added with a separate call to `atexit()`.
* When the `exit()` function is finally called, it executes these functions,
  with the last function added being executed first.
* The functions registered by `atexit()` should be type `void` functions taking
  no arguments. Typically they would perform housekeeping tasks, such as
  updating a program-monitoring file or resetting environmental variables.

#### Using `exit()`

After exit() executes the functions specified by atexit(), it does some tidying
of its own.

* It flushes all output streams, closes all open streams, and closes temporary
  files created by calls to the standard I/O function `tmpfile()`.
* Then `exit()` returns control to the host environment and, if possible,
  reports a termination status to the environment.
* Traditionally, Unix programs have used `0` to indicate successful termination
  and nonzero to report failure.
* Unix return codes don’t necessarily work with all systems, so ANSI C defined
  macros called `EXIT_FAILURE` and `EXIT_SUCCESS` can be used portably to
  indicate failure and success.
* `exit()` also accepts `0` for that purpose.
* Under ANSI C, using the `exit()` function in a nonrecursive main() function
  is equivalent to using the keyword return.
* `exit()` also terminates programs when used in functions other than `main()`.

### The `qsort()` Function

The `qsort()` function sorts an array of data objects.

```c
void qsort(void * base, size_t nmemb, size_t size,
        int (* compar)(const void *, const void *));
```

* The first argument is a pointer to the beginning of the array to be sorted.
* The second argument is the number of items to be sorted.
* Because `qsort()` converts its first argument to a `void` pointer, `qsort()`
  loses track of how big each array element is. To compensate, you must tell
  `qsort()` explicitly the size of the data object. That’s what the third
  argument is for. For example, if you are sorting an array of type `double`,
  you would use `sizeof(double)` for this argument.
* Finally, `qsort()` requires a pointer to the function to be used to determine
  the sorting order.

```c
int (* compar)(const void *, const void *)
```

* The comparison function should take two arguments: pointers to the two items
  being compared.
* It should return a positive integer if the first item should follow the
  second value, zero if the two items are the same, and a negative integer if
  the second item should follow the first.
* The `qsort()` will use this function, passing it pointer values that it
  calculates from the other information given to it.

#### Using `qsort()`

#### Using `mycomp()`

However, `qsort()` requires pointers to type `void`. The way to get around this
problem is to declare pointers of the proper type inside the function and
initialize them to the values passed as arguments.

```c
/* sort by increasing value */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values */
    const double * a1 = (const double *) p1;
    const double * a2 = (const double *) p2;

    if (*a1 < *a2) {
        return -1;
    } else if (*a1 == *a2) {
        return 0;
    } else {
    return 1;
    }
}
```

---

> #### note `void *` in C and C++

* In both languages, you can assign a pointer of any type to type `void *`.
* But C++ requires a type cast when assigning a `void *` pointer to a pointer
  of another type, whereas C doesn’t have that requirement.

```c
const double * a1 = (const double *) p1;
const double * a2 = (const double *) p2;
```

* In C, this type cast is optional; in C++ it is mandatory.

---

```c
struct names {
    char first[40];
    char last[40];
}

/* a call to qsort */
qsort(staff, 100, sizeof(struct names), comp);

/* comparison function */
#include <string.h>
int comp(const void * p1, const void * p2)  /* mandatory form */
{
    /* get right type of pointer */
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last, ps2->last);     /* compare last names */

    if (res != 0)
        return res;
    else        /* last names identical, so compare first names */ 
        return strcmp(ps1->first, ps2->first);
}
```

## The Assert Library

The assert library, supported by the `assert.h` header file, is a small one
designed to help with debugging programs.

It consists of a macro named `assert()`.

* The `abort()` function is prototyped in the `stdlib.h` header file.
* It takes as its argument an integer expression.
* If the expression evaluates as `false` (nonzero), the `assert()` macro writes
  an error message to the standard error stream (`stderr`) and calls the
  `abort()` function, which terminates the program.
* Typically, the argument is a relational or logical expression. If `assert()`
  does abort the program, it first displays the test that failed, the name of
  the file containing the test, and a line number.

> The idea is to identify critical locations in a program where certain
> conditions should be `true` and to use the `assert()` statement to terminate
> the program if one of the specified conditions is not `true`.

### Using `assert`

```c
assert(z >= 0);
```

You could accomplish something similar with an `if` statement. But the
`assert()` approach has several advantages:

* It identifies the file automatically.
* It identifies the line number where the problem occurs automatically.
* Finally, there’s a mechanism for turning the `assert()` macro on and off
  without changing code.

If you think you’ve eliminated the program bugs, place the macro definition:

```c
#define NDEBUG
```

* Before the location where `assert.h` is included and then recompile the
  program, and the compiler will deactivate all `assert()` statements in the
  file.
* If problems pop up again, you can remove the `#define` directive (or comment
  it out) and then recompile, thus reactivating all the `assert()` statements.

### `_Static_assert` (C11)

The `assert()` expression is a runtime check. C11 adds a feature, the
`_Static_assert` declaration, that does a compile-time check.

So, `assert()` can cause a running program to abort, while `_Static_assert()`
can cause a program not to compile. The latter takes two arguments.

* The first is a constant integer expression, and the second is a string.
* If the first expression evaluates to `0` (or `_False`), the compiler displays
  the string and does not compile the program.

```c
#include <stdio.h>
#include <limits.h>
_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main(void)
{
    puts("char is 16 bits.");
    return 0;
}
```

* In terms of syntax, `_Static_assert` is treated as a declaration statement.
  It can appear in a function or external to a function.
* The requirement that the first argument to `_Static_assert` be an integer
  constant expression guarantees that it can be evaluated during compilation.
  (Recall that sizeof expressions count as integer constants.)
* So you can’t substitute `_Static_assert` for `assert`, because that program
  used `z > 0` for a test expression, and that’s a nonconstant expression that
  can be evaluated only while the program is running.

> The `assert.h` header makes `static_assert` an alias for the C keyword
> `_Static_assert`. That’s to make C more compatible with C++, which uses
> `static_assert` as its keyword for this feature.

## `memcpy()` and `memmove()` from `string.h` Library

```c
void * memcpy(void * restrict s1, const void * restrict s2, size_t n);
void * memmove(void * s1, const void * s2, size_t n);
```

* Both of these functions copy n bytes from the location pointed to by `s2` to
  the location pointed to by `s1`, and both return the value of `s1`.
* `memcpy()` is free to assume that there is no overlap between the two memory
  ranges.
* For `memmove()`, copying takes place as if all the bytes are first copied to
  a temporary buffer before being copied to the final destination. When there
  are overlapping ranges, The behavior is undefined.
* The third argument indicates the number of bytes to be copied.

> Note that for an array, the number of bytes is not, the number of elements.
> So if you were copying an array of 10 double values, you would use
> `10*sizeof(double)`, not 10, as the third argument.

* `memcpy()` doesn’t know or care about data types; it just copies bytes from
  one location to another. 
* You could, copy bytes from a structure to a character array.
* Also, there is no data conversion. If you had a loop doing
  element-by-element,

## Variable Arguments `stdarg.h`

1. Provide a function prototype using an ellipsis.
2. Create a `va_list` type variable in the function definition.
3. Use a macro to initialize the variable to an argument list.
4. Use a macro to access the argument list.
5. Use a macro to clean up.

```c
void f1(int n, ...);                // valid
int f2(const char * s, int k, ...); // valid
char f2(char c1, ..., char c2);     // invalid, ellipsis not last
double f3(...);                     // invalid, no parameter

// function call
f1(2, 200, 400);                    // 2 additional arguments
f1(4, 13, 117, 18, 23);             // 2 additional arguments
```

The rightmost parameter (the one just before the ellipses) plays a special
role;

* The standard uses the term `parmN` as a name to use in discussion. In the
  preceding examples, `parmN` would be `n` for the first case and `k` for the
  second case.

---

The `va_list` type, which is declared in the `stdargs.h` header file,
represents a data object used to hold the parameters corresponding to the
ellipsis part of the parameter list.

```c
double sum(int lim, ...)
{
    va_list ap;             // declare object to hold arguments
```

* `lim` is the `paraN` parameter, and it will indicate the number of arguments
  int the variable-argument list.
* After this, the function will use the `va_start`() macro, also defined in
  `stdargs.h`, to copy the argument list to the `va_list` variable.
* The macro has two arguments: the `va_list` variable and the `parmN`
  parameter.

---

Continuing with the previous example, the `va_list` variable is called `ap` and
the `parmN` parameter is call `lim`, so the call would look like this:

```c
va_start(ap, lim);          // initialize ap to argument list
```

---

The next step is gaining access to the contents of the argument list. This
involves using `va_arg()`, another macro.

* It takes two arguments: a type `va_list` variable and a type name.
* The first time it’s called, it returns the first item in the list;
* The next time it’s called, it returns the next item, and so on.
* The type argument specifies the type of value returned. For example, if the
  first argument in the list were a `double` and the second were an `int`, you
  could do this:

```c
double tic;
int toc;

/* some code */

tic = va_arg(ap, double);       // retrieve first argument
toc = va_arg(ap, int);          // retrieve second argument
```

* The argument type really has to match the specification.
* The automatic conversion of `double` to `int` that works for assignment
  doesn’t take place here.

---

Finally, you should clean up by using the `va_end()` macro. It may, for
example, free memory dynamically allocated to hold the arguments. This macro
takes a `va_list` variable as its argument:

```c
va_end(ap);                     // clean up
```

* After this, the variable `ap` may not be usable unless you use `va_start` to
  reinitialize it.

---

Because `va_arg()` doesn’t provide a way to back up to previous arguments, it
may be useful to preserve a copy of the `va_list` type variable.

C99 has added a macro for that purpose. It’s called `va_copy()`. Its two
arguments are both type `va_list` variables, and it copies the second argument
to the first:

```c
va_list ap;
va_list apcopy;
double
double tic;
int toc;

/* some code */

va_start(ap, lim);          // initialize ap to argument list
va_copy(apcopy, ap);        // make apcopy a copy of ap
tic = va_arg(ap, double);   // retrieve first argument
toc = va_arg(ap, int);      // retrieve second argument
```

* You could still retrive the first two items from `apcopy`, even though they
  have been removed from `ap`.
