[toc]

## Representing Stings and String I/O

Character string
: A `char` string terminated with a null character (`\0`)

## Character String Literals (String Constants)

*String literal* or *string constant*
: Anything enclosed in double quotation marks.

> C concatenates string literals if they are separated by nothing or by
> whitespace.

> Character string constants are placed in *static storage* class.

```c
printf("%s, %p, %c\n", "We", "are", *"space farers");
```

* `%p` print the address of the first character in the string.
* `*"space farers"` produce the value to which the address points, which is the
  first character of the string "space farers"

## Character Strings Arrays and Initialization

```c
// short form
const char m1[40] = "Limit yourself to one line's worth.";

// longer form
const char m1[40] = {  'L', 'i', 'm', 'i', 't', ' ', 'y', 'o', 'u', 'r', 's',
'e', 'l', 'f', ' ', 't', 'o', ' ', 'o', 'n', 'e', ' ', 'l', 'i', 'n', 'e',
'\'', 's', ' ', 'w', 'o', 'r', 't', 'h', '.', '\0' };  
```

* In the longer form, without the closing null character, you got a character
  array, not a string.
* When initializing, The number of the elements is at least one more than the
  string length.
* Any unused elements are automatically initialized to `\0`

![Initializing an array](./images/init_array.png)

---

Or you can omit size in an initialization:

```c
const char m2[] = "If you can't think of anything, fake it.";
```

* Which only work when initializing an array, when you need an array which you
  intend to fill later, you need to specify the size when you declare it.

```c
int n = 8;
char cookies[1];        // valid
char cakes[2 + 5];      // valid, size is a constant expression
char pies[2 * sizeof(long double) + 1)];      // valid
char crumbs[n];         // invalid prior to C99, a VLA after C99
```

---------------------------------------------------------------------------------

The name of a character array, yields the address of the first element of the
array:

```c
char car[10] = "Tata";
// car == &car[0], *car = 'T', and * (car + 1) == car[1] = 'a'
```

You can use a pointer notation to set up a string>

```c
const char * pt1 = "Something is pointing at me.";
// equals to
const char ar1[] = "Something is pointing at me.";
```

## Array Versus Pointer

In short, initializing the array copies a string from static storage to the
array, whereas initializing the pointer merely copies the address of the
string.

```c
char ar[] = MSG;
const char *pt = MSG;
printf("address of \"I'm special\": %p \n", "I'm special");
printf("              address ar: %p\n", ar);
printf("              address pt: %p\n", pt);
printf("          address of MSG: %p\n", MSG);
printf("address of \"I'm special\": %p \n", "I'm special");
```

* `pt` and `MSG` are the same address, while `ar` is a different address.
* The `"I'm special"` occurred twice but use one storage location (maybe
  different with another compiler).
* The part of memory used for static data is different from that used for
  dynamic memory, the memory used for `ar`. (Might not only with a different
  value, a particular compiler even use a different number of bits to represent
  the two kinds of memory)

### Array Form

The quoted string is stored in a data segment that is a part of the executable
file, when the program is loaded into memory, so is that string.  (The quoted
string is said to be in a *static memory*, but the memory for the array is
allocated only after the program begins running). At that time the string is
copied into the array.  At this time there are two copies of the string. One is
the string literal in static memory, and one is the string stored in the `ar1`
array.

In the array form:

* `ar1` is an address *constant*, which can't be changed by using `++ar1`
  (means change the location where the array is located).
* But you can use `ar1+1` to identify the next element in an array.

### Pointer Form

For the pointer form (`*pt1`), once the program being executed, it sets aside
one more storage location for the pointer *variable* `pt1` and stores the
address of the string in the pointer variable, which initially points to the
first character of the string, *but the value can be changed* (means you
can use `++pt1` to make it point to the second character)

* A string literal is considered to be `const` data.
* Because `pt1` point to that data, so it should be declared as point to
  constant data.
* You *can* change the value of `pt1`(i.e, where it points)
* You *can*'t use `pt1` to change the data itself.
* If you copy a string literal to an array, you are free to change data unless
  you declare the array as `const`.

### Array and Pointer Difference

```c
char heart[] = "I love Title!";
const char *head = "I love Millie!";

// both can use the array notation
for (i = 0; i < 6, i++) {
    putchar(heart[i]);
}

for (i = 0; i < 6, i++) {
    putchar(head[i]);
}

// both can use pointer notation
for (i = 0; i < 6, i++) {
    putchar(*(heart + i));
}

for (i = 0; i < 6, i++) {
    putchar(*(head + i));
}

// only the pointer version can use the increment operator
while (*(head) != '\0')
    putchar(*(head++));

head = heart;           // valid
heart = head;           // invalid
```

* The array name `heart` is a constant, the pointer `head` is a variable.
* `head = heart` does not make Millie string (stored in `*head`) vanish; it
  just changes the address stored in `head`, unless you've saved the address of
  "I love Millie" elsewhere, however, you won't be able to access that string
  when `head` points to another location.  

```c
// to alter heart message
heart[7] = 'M';
*(heart + 7) = 'M';
```

* The elements of an array are variables (unless the array was declared as
  `const`), but the `name` is not a variable.

---

It is recommend to use the `const` modifier:

For a pointer initialization doesn't use `const` modifier, the following may
result in a segmentation error.

```c
char * word = "frame";

word[1] = 'l';          // may be allowed, but undefined.
```

* The compiler can choose to represent all identical string literal with a
  single copy in memory. 

```c
char * p1 = "Klingon";
p1[0] = 'F';        // ok?
printf("Klingon");
printf(": Beware the %ss1\n", "Klingon");
```

* The above statements could all refer to a single memory location of string
  "Klingon". (the compiler can replace each instance of "Klingon" with the same
  address)
* Under this circumstance, changing `pi[0]` to 'F' would affects all uses of
  the string.

```c
const char * p1 = "Klingon";        // recommended usage
```

* Don't use a pointer to a string if you plan to alter the string (initializing
  a (non-const) array.
* Initializing a `non-const` array with a string literal, poses no such
  problem, because the array gets a copy of the original string.

### Arrays of Character Strings

```c
const char * mytalents[LIM] = {
    "Adding numbers swiftly",
    "Multiplying accurately", "Stasing data",
    "Following instructions to the letter",
    "Understanding the C language"
};

char yourtalents[LIM][SLEN] = {
    "Walking in a straight line.",
    "Sleeping", "Watching television",
    "Mailing letters", "Reading email"
};
```

* `mytalents` array is an array of five pointers, taking up 40 bytes.
* `yourtalents` is an array of five arrays, each of 40 `char` values, occupying
  200 bytes.
* Pointers in `mytalents` point to the location of the string literal used for
  initialization, which are stored in static memory.
* Arrays in `yourtalents` contain copies of the string literals, so each string
  is stored twice
* Furthermore, the allocation of memory in the arrays is inefficient, for each
  element of `yourtalents` has to be the same size, and that size has to be at
  least large enough to hold the longest string.    

To visualizing this difference:

* Think of `yourtalents` as a rectangular two-dimensional array, with each row
  being of the same length, 40 bytes.
* Think of `mytalents` as a ragged array, one in which the row length varies.

The strings pointed to by the `mytalents` array elements don't necessarily have
to be stored consecutively in memory.

![Rectangular versus ragged array](images/rect_vs_ragged_arr.png)

If you want to alter strings or set aside space for string input, don't use
pointer to string literals.

* Because the pointers in `mytalents` point to string literals, these strings
  shouldn’t be altered.
* The contents of `yourtalents`, however, can be changed.

## Pointers and Strings

Pointers have same value, but have different address.

```c
const char * mesg = "Don't be a fool!";
const char * copy;

copy = mesg;
printf("%s\n", copy);
printf("mesg = %s; &mesg = %p; value = %p\n",
        mesg, &mesg, mesg);
printf("copy = %s; &copy = %p; value = %p\n",
        copy, &copy, copy);
```

## String Input

### Uninitialized Pointer

```c
char * name;
 
scanf("%s", name);
```

The `scanf()` copies information to the address given by the argument, while
the `name` is uninitialized pointer, which might point to anywhere.

Simplest course is to include an explicit array in the declaration:
 
```c
char name[81];
```

Now `name` is the address of an allocated block of 81 bytes.

### The Unfortunate `gets()` Function

`gets()`
: Reads until `\n`, discards `\n`, stores the remaining characters, adding `\0`
to create a C string. 

`puts()`
: Displays a string, adding a `\n`.

`Segmentation fault`
: Ona a Unix system, indicating the program attempted to access memory not
allocated to it.

> `gets()` has a problem of not checking to see if the input line actually fits
> into the array. If the string is too long, you get *buffer overflow*.

### `fgets()` and `fputs()` Function

```c
fgets(char *restrict __s, int __n, FILE *restrict __stream)
```

`fgets()` differs from `gets()`:

* `fgets()` reads up to `n-1` character or through the `\n`, whichever comes
  first.
* If `fgets()` reads the `\n`, it stores it in the string (such as `\n\0`).
* It takes a third argument indicating which file to read. To read from the
  keyboard, use `stdin` as the argument.

`fgets()` often paired with `fputs()`, which:

* Works like `puts()`, except that it doesn't automatically append a `\n`.
* Takes a second argument to indicate which file to write to.
* For computer monitor we can use `stdout` as an argument.

> `fgets()` function returns a pointer to `char`
> * Normally it just returns the same address that was passed to it as the
>   first argument.
> * If the function encounters end-of-file, it returns a special pointer called
>   the *null pointer*, which is a pointer guaranteed not to point to valid
>   data so it can be used to indicate a special case. In code, it can be the
>   digit `0` or, more commonly , by the macro `NULL`. (The function also
>   returns `NULL` if there is some sort of read error.) 

---

```c
char words[STLEN];

puts("Enter strings (empty line to quit):");
// encounter end-of-line or a emt
while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    fputs(words, stdout);
puts("Done.");
```

* When `Return` is pressed, the input is stored in the buffer, which adds a
  `\n` to the input.
* On output, `fputs()` sends characters to another buffer, and when a `\n` is
  sent, the buffer contents are sent on to the display.

The fact that `fgets()` stores the `\n` presents a problem and an opportunity:

* Opportunity is the presence or absence of a `\n` in the stored string can be
  used to tell whether the whole line was read.
* Problem is that you might not want the `\n` as part of the string you store.

---

```c
// the following program shows how the `fgets()` manage to dispose of the
// rest of the input line
char words[STLEN];
int i;

puts("Enter strings (empty line to quit):");

// marches through the string until reaching a newline or
// null character, whichever comes first.
while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
    i = 0;

    // find till the newline character or the null character
    while (words[i] != '\n' && words[i] != '\0')
        i++;

    // if the character is a newline, replace it with a null character.
    if (words[i] == '\n')
        words[i] = '\0';
    // dispose of the rest of the input line
    else                // must have words[i] == '\0'
        while (getchar() != '\n')
            continue;
    puts(words);
}
```

### Null and Null

Null character and null pointer are different from one another.

* The null character, or `\0`, is the character used to mark the end of a C
  string. It's the character whose code is zero. Because that isn't the code of
  any character, it won't show up accidentally in some other part of the
  string.
* The null pointer, or `NULL`, has a value that doesn't correspond to a valid
  address of data. It's often used by function that otherwise return valid
  address to indicate some special occurrence, such as encountering end-of-file
  or failing to perform as expected.

So the `\0` is an integer type, while the `NULL` is a pointer type. What
sometimes causes confusion is that both can be represented numerically by the
value `0`. But, conceptually, they are different types of 0.  Also, while the
`\0`, being a character, is one byte, the `NULL`, being an address, typically
is four bytes.

### The `gets_s()` Function

C11's optional function, like `fgets()`, use an argument to limit the number of
character read.

```c
gets_s(words, STLEN)
```

Three main differences form `fgets()`:

* `gets_s()` just reads form the standard input.
* If `gets_s()` does read a `\n`; it discards it rather than storing it.
* If `gets_s()` reads the maximum number of characters and fails to read a
  `\n`, it will:
  1. It sets the first character of the destination array to the `\0`.
  2. It reads and discards subsequent input until a `\n` or `EOF` is
     encountered, (which means as long as the input line isn't too long,
     `gets_s()` behaves like `gets()`, making it easier to replace `gets()`
     with `gets_s()` rather than with `fgets()`).
  3. It returns the `NULL`.
  4. It invokes an implementation-dependent "handlers" function (or else one
     you've selected), which may cause the program to exit or abort.

Comparing `gets()`, `fgets()`, and `gets_s()`s:

* If the input line fits the target storage, all three works fine.
  * But `fgets()` does include the `\n` as part of the string, you may need to
    replace it with a `NULL`.
* If the input line doesn't fit
  * The `gets()` isn't safe.
  * The `gets_s()` function is safe, but if you don't want the program to abort
    or otherwise exit, you'll need to learn how to write and register special
    "handlers", if you manage to keep the program running, `gets_s()` disposes
    of the rest of the input line whether yo want or not.
  * The `fgets()` is the easiest to use, and you can choose to process the rest
    of the input line or to dispose of the rest of the input line.

### The `s_gets()` Function

```c
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)  // i.e., ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else            // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
```

* Serious flaw is that it is silent about encountering input that doesn’t fit.
* Another flaw is it doesn’t cope with misuse such as being passed a size of 1
  or less.

### The `scanf()` Function

> The `scanf()` is more a "get word" than a "get string" function

The `scanf()` function has two choices for terminating input. For either
choice, the string starts at the first non-whitespace character encountered.

* The string runs up to (but not including) the next whitespace character
  (`blank`, `tab`, or `\n`).
* If you specify a field width, as in `%10s` , the `scanf()` collects up to 10
  characters or up to the first whitespace character, whichever comes first.

|Input Statement|Original Input Queue|Name Contents|Remaining Queue|
|-|-|-|-|
|`scanf("%s", name)`|Fleebert Hup|Fleebert| Hup|
|`scanf("%5s", name)`|Fleebert Hup|Fleeb|ert Hup|
|`scanf("%5s", name)`|Ann Ular|Ann| Ular|

> The `scanf()` function returns an integer value that equals the number of
> items successfully read or returns `EOF` if it encounters the end of file.

> The `scanf()` function can create an *overflow* if the input word doesn’t fit
> the destination, which can be prevent by use the field-width option in the
> `%s` specifier.

## String Output

### The `puts()` Function

```c
char str1[80] = "An array was initialized to me.";
const char * str2 = "A pointer was initialized to me.";

puts(str1);
puts(str2);
puts(&str1[5]);
puts(str2+4);

return 0;
```

> The phrases in double quotation marks are string constants and are treated as
> addresses.

The `puts()` stop when it encounters the null character

```c
char side_a[] = "Side A";
char dont[] = {'W', 'O', 'W', '!'};
char side_b[] = "Side B";

puts(dont);  // dont is not a string
```

* `dont` lacks a closing null character, `puts()` won't know where to stop, it
  will keep printing from memory until find a null.

### The `fputs()` Function

The `fputs()` function is the file-oriented version of `puts()`. The main
differences are these:  

* The `fputs()` function takes a second argument indicating the file to which
  to write. (You can use `stdout` as an argument to output to your display).
* Unlike `puts()` , `fputs()` does not automatically append a `\n` to the
  output.  

---

`gets()` discards a `\n` on input, but `puts()` adds a `\n` on
output.

`fgets()` stores the `\n` on input, and `fputs()` doesn’t add a `\n`
on output

```c
char line[81];
while (gets(line))          // same as while (gets(line) != NULL)
    puts(line);
```

```c
char line[81];
while (fgets(line, 81, stdin))
    fputs(line, stdout);
```

### The `printf()` Function

Compared with `gets()`

* Takes a string address as an argument.
* Formats various data types.
* **Takes longer for the computer to execute.**
* Easy to combine strings for one line of printing.

## Create Your Own I/O Functions

You can create your own I/O functions by building on `getchar()` and
`putchar()`

```c
void put1(const char * string)
{
    while (*string != '\0')
        putchar(*string++);
}

// or with array notation
void put1(const char * string)
{
    int i = 0;
    while (string][i] != '\0')
        putchar(string[i++]);
}

int put2(const char * string)
{
    int count = 0;
    while (*string) {
        putchar(*string++);
        count++;
    }
    putchar('\n');

    return count;
}

num = put2("pizza");
```

---

Many C programmers would use the following test for the `while` loop:

```c
while (*string)
```

When  string points to the `\0`, `*string` has the value `0`, which terminates
the loop. 

## String Functions

ANSI C uses the `string.h` header file to provide the prototypes for
string-handling functions.

### The `strlen()` Function

```c
#include <stdio.h>
#include <string.h>
void fit(char *, unsigned int);

int main(void) {
    char mesg[] = "Things should be as simple as possible,"
        " but not simpler.";

    puts(mesg);
    fit(mesg,38);
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39);        // the address of mesg[39]

    return 0;
}

void fit(char * string, unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
}
```

![The puts() function and the null character](./images/puts_null.png)

### The `strcat()` Function

The `strcat()` (for *string concatenation*) function takes two strings for
argument. A copy of the second string is tacked onto the end of the first, and
this combined version becomes the new first string.  

```c
#include <stdio.h>
#include <string.h>
#define SIZE 80
char * s_gets(char *, int);
int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";

    puts("What is your favorite flower?");
    if (s_gets(flower, SIZE)) {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("bye");

    return 0;
}
```

* The second string is not altered.
* The `strcat()` function is type `char *` (that is, a pointer-to-char).
* It returns the value of its first argument.

### The `strncat()` Function

Takes a second argument indicating the maximum number of characters to add.

```c
char flower[SIZE];
char addon[] = "s smell like old shoes.";
char bug[BUGSIZE];
int available;

puts("What is your favorite flower?");
s_gets(flower, SIZE);
if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
    strcat(flower, addon);
puts(flower);
puts("What is your favorite bug?");
s_gets(bug, BUGSIZE);
avaiable = BUGSIZE - strlen(bug) - 1;
strncat(bug, addon, avaiable);
puts(bug);
```

### The `strcmp()` Function

The `strcmp()` compares strings, until it finds corresponding character that
differs in the numeric representation, typically the ASCII values,

> The `strcmp()` is for comparing strings, so don't use character arguments,
> such as `'A'`.  To compare character arguments, use the *relational operator*
> instead.

```c
char input[LIM][SIZE];
int ct = 0;

printf("Enter up to %d lines (type quit to quit): \n", LIM);
while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
        strcmp(input[ct], STOP) != 0) {
    ct++;
}
printf("%d strings entered\n", ct);

// to enter an empty line to quit (Return)
while (ct < LIM && s_gets(input[ct], SIZE) != NULL
                && input[ct][0] != '\n')
```

* `intput[ct]` is the string entered and `intput[ct][0]` is the first character
  of that string.
* When an empty line is entered, `s_gets()` place the  `\0` in the first
  element.

### The `strncmp()` Variation

The `strncmp()` function compares the strings until they differ or until it has
compared a number of characters specified by a third argument.

```c
const char * list[LISTSIZE] =
{
    "astronomy", "astounding",
    "astrophysics", "ostracize",
    "asterism", "astrophobia"
};
int count = 0;

for (int i = 0 ; i < LISTSIZE; i++)
    if (strncmp(list[i], "astro", 5) == 0) {
        printf("Found: %s\n", list[i]);
            count++;
    }
printf("The list contained %d words beginning"
        " with astro.\n", count);
```

### The `strcpy()` and `strncpy()` Functions

In short, `strcpy()` takes two string pointers as arguments:

* The second pointer, which points to the original string, can be a declared
  pointer, an array name, or a string constant.
* The first pointer, which points to the copy, should point to a data object,
  such as an array, roomy enough to hold the string.  

> Declaring an array allocates storage space for data; Declaring a pointer only
> allocates storage space for one address.

> The `strcpy()` is the string equivalent of the assignment operator.

```c
char qwords[LIM][SIZE];
char temp[SIZE];
int i = 0;

printf("Enter %d words beginning with q:\n", LIM);
while (i < LIM && s_gets(temp, SIZE)) {
    if (temp[0] != 'q')
        printf("%s doesn't begin with q!\n", temp);
    else {
        strcpy(qwords[i], temp);
        i++;
    }
}
puts("Here are the words accepted:");
for (i = 0; i < LIM; i++)
    puts(qwords[i]);
```

```c
char target[20];
x = 50;                     /* assignment for numbers */
strcpy(target, "Hi ho!");   /* assignment for strings*/
target = "So long";         /* syntax error */
```

```c
char * str;                                 // without initialization
strcpy(str, "The C of Tranquility");        // a problem
```

The `strcpy()` function has two more properties:

1. It is type `char *`, it returns the value of its first argument--the address
   of a character.
2. Second, the first argument need not point to the beginning of an array; this
   lets you copy just part of an array.  

```c
const char * orig = WORDS;
char copy[SIZE] = "Be the best that you can be.";
char * ps;

puts(orig);
puts(copy);
ps = strcpy(copy + 7, orig);
puts(copy);
puts(ps);
```

![hello](./images/strcpy.png)

* `ps` points to the eighth element (index of 7) of `copy` because the first
  argument is `copy + 7`. Therefore, `puts(ps)` print the string starting at
  that point.

### The `strncpy()` Function

It takes a third argument, which is the maximum number of characters to copy.

```c
char qwords[LIM][TARGSIZE];
char temp[SIZE];
int i = 0;

printf("Enter %d words beginning with q:\n", LIM);
while (i < LIM && s_gets(temp, SIZE))
{
    if (temp[0] != 'q')
        printf("%s doesn't begin with q!\n", temp);
    else {
        strncpy(qwords[i], temp, TARGSIZE - 1);
        qwords[i][TARGSIZE - 1] = '\0';
        i++;
    }
}

puts("Here are the words accepted:");
for (i = 0; i < LIM; i++)
    puts(qwords[i]);
```

The function call `strncpy`(target, source, n) copies up to `n` characters or
up through the `\0` (whichever comes first) from `source` to `target`.
Therefore, if the number of characters in `source` is less than `n` , the
entire string is copied, including the `\0`.

The function never copies more than `n` characters, so if it reaches the limit
before reaching the end of the source string, no `\0` is added.  As a result,
the final product may or may not have a `\0`. For this reason, the program sets
`n` to one less than the size of the target.

```c
strncpy(qwords[i], temp, TARGSIZE - 1);
qwords[i][TARGSIZE - 1] = '\0';
```

### The `sprintf()` Function

* Declared in `stdio.h`, works like `printf()`,
* Writes to a string instead of writing to a display.
* The first argument to `sprintf()` is the address of the target string.
* The remaining arguments are the same as for `printf()`.

### Other String Functions

```c
char * strcpy(char * restrict s1, const char * restrict s2);
```

* Copies the string (include the `\0`) pointed to by `s2` to the location
  pointed to by `s1`.
* The return value is `s1`.

---

```c
char * strncpy(char * restrict s1, const * restrict s2, size_t n);
```

* Copies to the location pointed to by `s1` no more than `n` characters from
  the string pointed to by `s2`.
* No characters after a `\0` are copied and, if the source string is shorter
  than `n` characters, the target string is padded with `\0`. If the source
  string has `n` or more characters, no `\0` is copied. The return value is
  `s1`. 
* The return value is `s1`.

---
  
```c
char * strcat(char * restrict s1, const char * restrict s2); 
```

* The string pointed to by `s2` is copied to the end of the string pointed to
  by `s1`.
* The first character of the `s2` string is copied over the `\0` of the `s1`
  string.
* The return value is `s1` . 

---

```c
char * strncat(char * restrict s1, char * restrict s1, size_t n);
```

* No more than the first `n` characters of the `s2` string are appended to the
  `s1` string, with the first character of the `s2` string being copied over
  the `\0` of the `s1` string.
* The `\0` and any characters following it in the `s2` string are not copied,
  and a `\0` is appended to the result.
* The return value is `s1`.  

---

```c
int strcmp(const char * s1, const char * s2);
```

* Returns a positive value if the `s1` string follows the `s2` string in the
  machine collating sequence,
* Returns value `0` if the two strings are identical.
* Returns a negative value if the first string precedes the second string in
  the machine collating sequence.  

---

```c
int strncmp(const char * s1, const char * s2, size_t n);
```

This function works like `strcmp()` , except that the comparison stops after
`n` characters or when the first `\0` is encountered, whichever comes first.

---

```c
char * strchr(const char * s, int c);
```

* Returns a pointer to the first location in the string `s` that holds the
  character `c`. (The terminating `\0` is part of the string, so it can be
  searched for.)
* Returns the `NULL` if the character is not found.

---

```c
char * strpbrk(const char * s1, const char * s2); 
```

* Returns a pointer to the *first* location in the string `s1` that holds any
  character found in the `s2` string.
* Returns the `NULL` if no character is found.

---

```c
char * strrchr(const char * s, int c);
```

* Returns a pointer to the *last* occurrence of the character `c` in the string
  `s` . (The terminating `\0` is part of the string, so it can be searched
  for).
* Returns the `NULL` if the character is not found.

---

```c
char * strstr(const * s1, const char * s2);
```

* Returns a pointer to the first occurrence of string `s2` in string `s1`.
* Returns the `NULL` if the string is not found.

---

```c
size_t strlen(const char * s);
```

* This function returns the number of characters, not including the terminating
`\0`, found in the string `s`.

> `size_t` type is whatever type the `sizeof` operator returns, can be any
> `int` type, such as `unsigned int` or `unsigned long` depend on the system.

---

Rewrite `s_gets()`

```c
char line[80];
char * find;

fgets(line, 80, stdin);
find = strchr(line, '\n');      // look for a newline
if (find)                       // if the address is not NULL,
   *find = '\0';              // place a null character there
else
    while (getchar() != '\n')
        continue;
```

## A String Example: Sorting Strings

### Sorting Pointers Instead of Strings

```c
#include <stdio.h>
#include <string.h>

#define SIZE 81         // string length limit, including \0
#define LIM 20          // maximum number of lines to be read
#define HALT ""         // null string to stop input

void stsrt(char * string[], int num);       // string-sorting function
char * s_gets(char * st, int n);

int main(void)
{
    char input[LIM][SIZE];      // array to store input
    char * ptstr[LIM];          // array of pointer variables
    int ct = 0;                 // intput count
    int k;                      // output count

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");

    while (ct < LIM && s_gets(input[ct], SIZE) != NULL
           && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];      // send ptrs to strings
        ct++;
    }

    stsrt(ptstr, ct);

    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++)
        puts(ptstr[k]);

    return 0;
}

// string-pointer-sorting function
void stsrt(char * strings[], int num)
{
    char * temp;
    int top, seek;

    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top], strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
```

![sorting_string_pointers](./images/sorting.png)

### The Selection Sort Algorithm

```c
for n = first to n = next-to-last element,
    find lagest remaining number and place it in the nth element
```

```c
for n - second element to last element,
compare nth element with first element; if nth is greater, swap values
```

## The `ctype.h` Character Functions and Strings

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 81
void ToUpper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIM];
    char * find;

    puts("Please enter a line:");
    fgets(line, LIM, stdin);
    find = strchr(line, '\n');
    if (find)
        *find = '\0';
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n",
            PunctCount(line));

    return 0;
}

void ToUpper(char * str)
{
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char * str)
{
    int count = 0;

    while (*str) {
        if (ispunct(*str))
            count++;
        str++;
    }

    return count;
}
```

> The `toupper()` function alters only characters that are lowercase. However,
> very old implementation of C don't do that check automatically, so old code
> normally does something like this:
 
```c
if (islower(*str))
    *str = toupper(*str);
```

> The `ctype.h` functions are usually implemented as *macros*. These are C
> prepro- cessor constructions that act much like functions but have some
> important differences. 

## Command-Line Arguments

```c
#include <stdio.h>
int main(int argc, char * argv[])
{
    printf("The command ine has %d arguments:\n", argc - 1);
    for (int count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");

    return 0;
}
```

```bash
$repeat Resistance is futile
```

* C compilers allow `main()` to have no arguments or else to have two
  arguments.  (Some implementations allow additional arguments, but that would
  be an extension of the strandard)
* The first argument is the number of strings in the command line, this `int`
  argument is called `argc` for *argument count*.
* The system uses `spaces` to tell when one string ends and the next begins
  (including command name).
* The program stores the command line strings in memory and stores the address
  of each string in an array of pointers. The address of this array is stored
  in the second argument.
* By convention, this pointer to pointers is called `argv`, for *argument
  values* .

When possible (some operating systems don’t allow this), `argv[0]` is assigned
the name of the program itself. Then `argv[1]` is assigned the following
string, and so on.

```
argv[0] points to  repeat (for most systems)  
argv[1] points to  Resistance 
argv[2] points to  is 
argv[3] points to  futile 
```

---

```c
int main(int argc, char **argv)
```

* This alternative declaration for argv really is equivalent to char `*argv[]`.
* Says that `argv` is a pointer to a pointer to `char`.

---

Unix and DOS, allow the use of quotation marks to lump several words into a
single argument.

```c
repeat "I am hungry" now
```

* Would assign the string `"I am hungry"` to `argv[1]` and the string `"now"`
  to `argv[2]`.

### Command-Line Arguments in Integrated Environments

Integrated Windows environments don't use command lines to run programs. But
some have a project dialog to let you specify a command-line argument for a
particular project.

In other cases, you may be able to compile the program in the IDE and then open
an MS-DOS window to run the program in command-line mode. But it’s simpler if
your system has the option of running a command-line compiler such as GCC.

### Command-Line Arguments with the Macintosh

If you are using Xcode 4.6 (or similar version), you can provide command-line
arguments by going to the Products menu and selecting Scheme, Edit Scheme, Run.
Then select the Arguments tab and enter arguments in the Arguments Pass on
Launch. 

Or you can enter the Mac’s Terminal mode and the world of command-line Unix.
Then you can either locate the directory (Unix for folder) containing the
executable code for your program, or, if you have downloaded the command-line
tools, use `gcc` or `clang` to compile the program.

### String-to-Number Conversions

Numbers can be stored either as strings or in numeric form. Storing a number as
a string means storing the digit characters.

The number 213 can be stored:

* In a character string array as: `'2', '1', '3','\0'`.
* Or in a numeric form as an `int`.

> C requires numeric forms for numeric operations. But displaying numbers on
> your screen requires a string form.
> 
> * The `printf()` and `sprintf()` functions, through their `%d` and other
>   specifiers, convert numeric forms to string forms,
> * The `scanf()` can convert input strings into numeric forms.
> 
> C also has functions whose sole purpose is to convert string forms to numeric
> forms.  

To use numeric command-line arguments. You need first to convert string to a
number. If the number is a integer, you can use `atoi()` function (for
*alphanumeric to integer*).

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int i, times;

    if (argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usage: %s positive-number\n", argv[0]);
    else
        for (i = 0; i < times; i++)
            puts("Hello, good looking!");

    return 0;
}
```

* The command-line argument of `3` was stored in `3\0`.

> * The `atoi()` function still works if the string only begins with an
>   integer.  In that case, it converts characters until it encounters
>   something that is not part of an integer.
> * The `atoi()` function returns a value of `0` if its argument is not
>   recongnizable as a number. However, the C standard says the behavior in
>   that case is undefined.

---

```c
char number[LIM];
char * end;
long value;

puts("Enter a number (empty line to quit):");
while (s_gets(number, LIM) && number[0] != '\0')
{
    value = strtol(number, &end, 10);
    printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n",
            value, end, *end);
    value = strtol(number, &end, 16);
    printf("base 16 input, base 16 output: %ld, stopped at %s (%d)\n",
            value, end, *end);
    puts("Next number:");
}
puts("Bye!\n");
```

* The `strtol()` function goes up to base 36, using the letters through `'z'`
  as digits.
* The `strtod()` function does only base 10, so it uses just two arguments.

---

```c
char sign = '$';
```

* Character variable occupy one byte, so `sign` occupies one byte.
* But a character constant is stored in an `int`, So `'$'` typically would use
  2 or 4 bytes, however, only 1 byte of the `int` is actually used to stored
  the code for `'$'`.
* The string `"$"` used 2 bytes: one for `'$'`, another for '\0'.

---

Rewrite `strlen()` function:

```c
int strlen(const char * str)
{
    int count = 0;

    while (*str++)
        count++;

    return count;
}
```

---

```c
char * foo1(char * str)
{
    while (*str)
    {
        if (*str == ' ')
            return str;
        str++;
    }

    return NULL;
}

char * foo2(char * str)
{
    while (*str != ' ' && *str != '\0')
        str++;
    if (*str == '\0')
        return NULL;
    else
        return str;
}

char * foo3(const char * str)
{
    while (*str != ' ' && *str != '\0')
        str++;
    if (*str == '\0')
        return NULL;
    else
        return (char *) str;
}
```

* The expression `(char *)` string is called *casting away const*, which
  prevents the function from modifying the string but that allows the return
  value to be used to change the string.
