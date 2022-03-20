[toc]

## Sample Problem: Creating an Inventory of Books

Three main skills to acquire:

* Setting up a format or layout for a structure.
* Declaring a variable to fit that layout
* Gaining access to the individual components of a structure variable.

## Setting Up the Structure Declaration

```c
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
```

* Does not create an actual data object.
* Occasionally, a structure declaration is called a *template*, but it's
  different from the *template* in C++.
* The word `book` is the optional *tag*--a label can be used to refer to this
  structure (the tag must be used).
* The `title` portion is a `char` array with `MAXTITL` elements, a member can
  be any C data type--includes other structures.
* The declaration can be placed outside any function, while if the declaration
  is placed inside a function, its tag can be used only inside that function.

## Defining a Structure Variable

You can declare two variables of the `struct book` type or even a pointer to
the structure.

```c
strct book doyle, panshin, * ptbook;
```

In essence, the book structure declaration creates a new type called `struct
book`.

![memforstruct](./images/memforstruct.png)

```c
struct book library;

// is short for
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} library;          // follow declaration with variable name

// or to conbine the process of declaring a structure and process of defining
// a structure variable into one step.


struct {          // no tag
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
} library;
```

* You can conbine the process of declaring a structure and process of defining
  a structure variable into one step.

### Initializing a Structure

```c
struct book library = {
    "The Pious Pirate and the Devious Damsel",
    "Renee Vivotte",
    1.95
};
```

* Use a comma-separated list of initializers enclosed in braces.
* Each initializer should match the type of the structure member being
  initialized.
* To make the associations more obvious, we gave each member its own line of
  initialization, but all the compiler needs are commas to separate one
  member’s initialization from the next.

> If you initialize a variable with static storage duration (such as static
> external linkage, static internal linkage, or static with no linkage), you
> have to use constant values. This applies to structures, too. If you are
> initializing a structure with static storage duration, the values in the
> initializer list must be constant expressions. If the storage duration is
> automatic, the values in the list need not be constants.

### Gaining Access to Structure Members

You can access the individual member of a structure by using a subscript, a dot
(`.`), the structure member operator.

If you have a second structure variable of the same type, you can use the same
method:

```c
struct book bill, newt;

s_gets(bill.title, MAXTITL);
s_gets(newt.title, MAXTITL);
```

### Initializer for Structures

C99 and C11 provide designated initializers for structures.

```c
// to initialized just the value member of a book structure
struct book surprise = {.value = 10.99};

// You can use designated initializer in any order:
struct book gift = { .value = 25.99,
                     .author = "James Broadfool",
                     .title = "Rue for the Toad"};
```

A regular initializer following a designated initializer provides a value for
the member following the designated member. Also, the last value supplied for a
particular member is the value it gets.

```c
struct book gift = { .value = 18.90,
                     .author = "Philionna Pestle",
                      0.25}
```

* The value `0.25` is assigned to the `value` member because it is the one
  immediately listed after the author member in the structure declaration.
* The new value of `0.25` supersedes the value of `18.90` provided earlier.

## Arrays of Structures

### Structures and Memory

> The 2.c program uses an array of 100 structures. Because the array is an
> automatic storage class object, the information is typically placed on the
> stack. Such a large array requires a good-sized chunk of memory, which can
> cause problems.
> 
> If you get a runtime error, perhaps complaining about the stack size or stack
> overflow, your compiler probably uses a default size for the stack that is
> too small for this example.
> 
> To fix things, you can:
> 
> * Use the compiler options to set the stack size to 10,000 to accommodate the
>   array of structures,
> * Or you can make the array static or external (so that it isn’t placed in
>   the stack),
> * Or you can reduce the array size to 16.

### Declaring an Array of Structures

```c
struct book library[MAXBKS];
```

* This declares `library` to be an array with `MAXBKS` elements.
* Each element of this array is a structure of `book` type.
* The name `library` itself is not a structure name, it is the name of the
  array whose elements are type `struct book` structures.

![arrayofstruct](./images/arrayofstruct.png)

### Identifying Members of an Array of Structures

```c
library[0].value        // the value associated with the first array element
library[4].title        // the title associated with the fifth array element

library.value[2]        // WRONG
library[2].value        // RIGHT

library                 // an array of book structure
library[2]              // an array element, hence a book structure
library[2].title        // a char array (the title member of library[2])
library[2].title[4]     // a char in the title member array
```

## Nested Structure

```c
struct names
{
    char first[LEN];
    char last[LEN];
};

struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

// in main function
int main(void)
{
    struct guy fellow =
    {
        { "Ewen", "Villard"},
        "grilled salmon",
        "personality coach",
        68112.00
    };
    ...
}
```

## Pointer to Structures

### Declaring and Initializing a Structure Pointer

```c
struct names {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};


int main(void)
{
    struct guy fellow[2] = {
        {{ "Ewen", "Villard"}},
         "grilled salmon",
         "personality coach",
         68112.00
        },
        {{ "Rodney", "Swillbelly"}},
         "tripe",
         "tabloid editor",
         232400.00
        }

    struct guy * him;
}
```

This declaration does not create a new structure, but the pointer `him` can now
be made to point to any existing structure of the `guy` type.

```c
him = &fellow[0];

//
him = fellow;
```

Unlike the case for arrays, the name of a structure is not the address of the
structure; you need to use the `&` operator.

In the example, `fellow` is an array of structures, which means that
`fellow[0]` is a structure, so the codes initialized `him` by making it point
to `fellow[0]`.

Each `guy` structure occupies 84 bytes of memory:

* `names.first` is 20.
* `names.last` is 20.
* `favfood` is 20.
* `job` is 20.
* `income` is 4, the size of `float` on system.

> Incidentally, on some systems, the size of a structure may be greater than the
> sum of its parts. That’s because a system’s alignment requirements for data
> may cause gaps.
> 
> For example, a system may have to place each member at an even address or at
> an address that is a multiple of four. Such structures might end up with
> unused “holes” in them.

### Member Access by Pointer

To use `him` to get a value of a member of `fellow[0]`:

First method is to use the `->` operator:

```c
him->income is barney.income if him = &barney
him->income is fellow[0].income if him == &fellow[0]
```

In other words, a structure pointer followed by the `->` operator works the
same way as a structure name followed by the `.` operator.

> (You can’t properly say `him.income` because him is not a structure name.)

It is important to note that `him` is a pointer, but `him->income` is a member
of the pointed-to structure. So in this case, `him->income` is a `float`
variable.

Second method:

```c
fellow[0].income == (*him).income
```

In summary, if `him` is a pointer to a type `guy` structure named barney, the
following are all equivalent:

```c
barney.income == (*him).income == him->income       // assuming him == &barney
```

## Telling Functions About Structures

### Passing Structure Members

```c
// prototype
double sum(double, double);

// call
printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefound));

// definintion
double sum(double x, double y)
{
    return x + y;
}
```

If you want a called function to affect the value of a member in the calling
function, you can transmit the address of the member

```c
modify(&stan.bankfund);
```

### Using the Structure Address

```c
// prototype
double sum(const struct funds *);

// call
printf("Stan has a total of $%.2f.\n", sum(&stan));

// definintion
double sum(const struct funds * money)
{
    return money->bankfund + money->savefound;
}
```

You must use the `&` operator to get the structure’s address. Unlike the array
name, the structure name alone is not a synonym for its address.

### Passing a Structure as an Argument

```c
// prototype
double sum(struct funds moolah);

// call
printf("Stan has a total of $%.2f.\n", sum(stan));

// definintion
double sum(struct funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}
```

When `sum()` is called, an automatic variable called `moolah` is created
according to the funds template. The members of this structure are then
initialized to be copies of the values held in the corresponding members of the
structure stan.  Therefore, the computations are done by using a copy of the
original structure;

### More on Structure Features

```c
o_data = n_data         // assinging one structure to another

struct names right_field =
{
    "Ruthie",
    "George"
};

struct names captain = right_field;        // initialize a structure to another
```

* This causes each member of `n_data` to be assigned the value of the
  corresponding member of `o_data`.
* This works even if a member happens to be an array. Also, you can initialize
  one structure to another of the same type.

---

Using passing and structure return:

```c
struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char * s_get(char *, int);

int main(void)
{
    struct namect person;

    person = getinfo();
    person = makeinfo(person);
    showinfo(person);

    return 0;
}

struct namect getinfo(void)
{
    struct namect temp;

    printf("Please enter your first name.\n");
    s_get(temp.fname, NLEN);
    printf("Please enter your last name.\n");
    s_get(temp.lname, NLEN);

    return temp;
}

struct namect makeinfo(struct namect info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);

    return info;
}

void showinfo(struct namect info)
{
    printf("%s %s your name contains %d letters.\n",
            info.fname, info.lname, info.letters);
}
```

* Each of the three functions creates its own copy of `person`, so this program
  uses four distinct structures instead of just one.

In the `makeinfo()` a new structure called `info` is created. The values stored
in person are `copied` to `info`, and the function works with the copy.
Therefore, when the number of letters is calculated, it is stored in `info`,
but not in `person`.

```c
person = makeinfo(person);
```

Copy the values stored in `info` into `person`. Note that the `makeinfo()`
function had to be declared type struct `namect` because it returns a
structure.

---

Handle structures by using pointers

```c
struct namect {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(struct namect *);
char * s_get(char * st, int n);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}

void getinfo(struct namect * pst)
{
    printf("Please enter your first name.\n");
    s_get(pst->fname, NLEN);
    printf("Please enter your last name.\n");
    s_get(pst->lname, NLEN);
}

void makeinfo(struct namect * pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(struct namect * pst)
{
    printf("%s %s, your name contains %d letters.\n",
            pst->fname, pst->lname, pst->letters);
}
```

* The `getinfo()` function transfers information from itself to `main()`.
* In particular, it gets names from the user and places them in the `person`
  structure, using the `pst` pointer to `locate` it.

### Structures or Pointer to Structures?

The two advantages of the *pointer argument method*:

* It works on older as well as newer C implementations and that it is quick;
* You just pass a single address.

The disadvantage is that you have less protection for your data. Some
operations in the called function could inadvertently affect data in the
original structure.  However, the ANSI C addition of the `const` qualifier
solves that problem.

---

One advantage of *passing structures* as arguments is that the function works
with copies of the original data, which is safer than working with the original
data. Also, the programming style tends to be clearer.

A *passing structure* version:

```c
struct vector {double x; double y;};

struct vector ans, a, b;
struct vector sum_vect(struct vector, struct vector);
...
ans = sum_vect(a,b);
```

A *pointer* version:

```c
struct vector ans, a, b;
void sum_vect(const struct vector *, const struct vector *, struct vector *);
...
sum_vect(&a, &b, &ans);
```

Two main disadvantage to *passing structures*:

* The two main disadvantages to passing structures are that older
  implementations might not handle the code and that it wastes time and space.
* It’s especially wasteful to pass large structures to a function that uses
  only one or two members of the structure. In that case, passing a pointer or
  passing just the required members as individual arguments makes more sense.

Typically, programmers:

* Using `structure pointers` as function arguments for reasons of efficiency,
  using `const` when needed to protect data from unintended changes.
* Using `passing structures` by value is most often done for structures that
  are small to begin with.

### Character Array or Character Pointer in a Structure

```c
#define LEN 20

struct names {
    char first[LEN];
    char last[LEN];
}

struct pnames {
    char * first;
    char * last;
}

struct names veep = {"Talia", "Summers"};
struct pnames treas = {"Brad", "Fallingjaw"};
printf("%s and %s\n", veep.first, treas.first);
```

* For the `struct names` variable `veep`,
  * The strings are stored inside the structure;
  * The structure has allocated a total of 40 bytes to hold the two names.
* For the `struct pnames` variable `treas`,
  * however, the strings are stored wherever the compiler stores string
    constants.
  * All the structure holds are the two addresses, which takes a total of 16
    bytes on our system.

In short, the pointers in a `pnames` structure allocates no space to store
strings, and should be used only to manage strings were created and allocated
elsewhere in the program. such as string constants or strings in arrays.

---

```c
struct names {
    char first[LEN];
    char last[LEN];
}

struct pnames {
    char * first;
    char * last;
}

struct names accountant;
struct pnames attorney;

puts("Enter the last name of your accountant:");
scanf("%s", accountant.last);
puts("Enter the last name of your attorney:");
scanf("%s", attorney.last);          /* here lies the danger */
```

* For the `accountant`, the name is stored in the `last` member of the
  `accountant` variable; this structure has an array to hold the string.
* For the `attorney`, `scanf()` is told to place the string at the address
  given by `attorney.last`. Because this is an uninitialized variable, the
  address could have any value, and the program could try to put the name
  anywhere.

### Structure, Pointer, and `malloc()`

One instance in which it does make sense to use a pointer in a structure to
handle a string is if you use `malloc()` to allocate memory and use a pointer
to store the address. This approach has the advantage that you can ask
`malloc()` to allocate just the amount of space that’s needed for a string.
You can ask for 4 bytes to store "Joe" and 18 bytes for the Madagascan name

```c
// structure definintion
struct namect {
    char * fname;       // using pointers instead of arrays
    char * lname;
    int letters;
}

// new version of getinfo()
void getinfo (struct namect * pst)
{
    char temp[SLEN];

    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);

    // allocate memory to hold name
    pst->fname = (char *) malloc(strlen(temp) + 1);

    // copy name to allocated memory
    strcpy(pst->fname, temp);

    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void cleaup(struct namect * pst)
{
    free(pst->fname);
    free(pst->lname);
}
```

* The two strings are not stored in the structure. They are stored in the chunk
  of memory managed by `malloc()` .
* However, the addresses of the two strings are stored in the structure, and
  the addresses are what string-handling functions typically work with.

### Compound Literals Structures

You can use compound literals to create a structure to be used as a function
argument or to be assigned to another structure.

```c
(struct book) {"The idiot", "Fyodor Dostoyevsky", 6.99}
```

You can use compound literals as arguments to functions.

```c
struct rect {double x; double y;};
double rect_area(struct rect r){return r.x * r.y;}
...
double area;
area = rect_area((struct rect) {10.5, 20.5})
```

If a function expects an address:

```c
struct rect {double x, double y};
double rect_area(struct rect * rp){return rp->x * r->y;};
...
double area;
rect_area(&(struct rect) {10.5, 20.5});
```

Compound literals occurring outside of any function have static storage
duration, and those occurring inside a block have automatic storage
duration.

The same syntax rules hold for compound literals as hold for regular
initializer lists. (This means, for example, that you can use designated
initializers in a compound literal).

### Flexible Array Members (C99)

*Flexible array member* lets you declare a structure for which the last member
is an array with special properties.

* One special property is the array doesn't exist--at least, not immediately.
* Second special property is that, with the right code, you can use the
  flexible array member as if it did exist and has whatever number of elements
  you need.

Rules for declaring a flexible array member:

* The flexible array member must be the last member of the structure.
* There must be at least one other member.
* The flexible array is declared like an ordinary array, except that the
  brackets are empty.

```c
struct flex
{
    int count;
    double average;
    double scores[];        // flexible array member
}
```

You can’t use scores for anything, because no memory space is set-aside for it.
In fact, it’s not intended that you ever declare variables of the `struct flex`
type. Instead, you are supposed to declare a pointer to the struct flex type
and then use `malloc()` to allocate enough space for the ordinary contents of
`struct flex` plus any extra space you want for the flexible array member.

Let scores to represent an array of five double values:

```c
struct flex * pf;        // declare a pointer

// ask for space for a structure and an array
pf = malloc(sizeof(struct flex) + 5 * sizeof(double));

// then use pointer `pf` to access these memebers:
pf->count = 5;               // set count member
pf->scores[2] = 18.5;        // access an element of the array member
```

---

Structures with flexible array members do have some special handling
requirements: 

First, don't use structure assignment for copying:

```c
struct flex * pf1, * pf2;      // *pf1 and *pf2 are structures
...
*pf2 = *pf1;                // DON'T DO THIS
```

This would just copy the nonflexible members of the structure. Instead, use the
`memcpy()` function.

Second, don’t use this sort of structure with functions that pass structures by
value. The reason is the same; passing an argument by value is like assignment.
Instead, use functions that pass the address of the structure.

Third, don’t use a structure with a flexible array member as an element of an
array or a member of another structure.

### Anonymous Structures (C11)

An anonymous structure is a structure member that is an unnamed structure.

```c
struct names
{
    char first[20];
    char last[20];
};

struct person;
{
    int id;
    struct names name;      // nested structure member
}
struct person ted = {8483, {"Ted", "Grass"}};

// you could use the following expression to access "Ted"
puts(ted.name.first);
```

With C11, you can define person using a nested unnamed member structure:

```c
struct person
{
    int id;
    struct {char first[20], char last[20];};        // anonymous structure
}

// You could initialize this structure in the same fashion:
struct person ted = {8483, {"Ted", "Grass"}};

// But access is simplified as you use member names such as first as if they
// were person members:
puts(ted.first);
```

### Functions Using Array of Structures

```c
sum(&jones[0], N);
sum(jones, N);
```

* You can use the array name to pass the address of the first structure in the
  array to a function.
* You can then use array bracket notation to access the successive structures
  in the array.

## Saving the Structure Contents in a File

A database file could contain an arbitrary number of such data objects. The
entire set of information held in a structure is termed a *record*, and the
individual items are *fields*.

```c
fwrite(&primer, sizeof (struct book), 1, ptbook);
fread(&primer, sizeof (struct book), 1, ptbook);
```

One drawback to saving data in binary representation is that different systems
might use differ- ent binary representations, so the data file might not be
portable. Even on the same system, different compiler settings could result in
different binary layouts.

### A Structure-Saving Example

```c
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
                                    library[count].author,
                                    library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line of stop");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if ((count < MAXBKS))
            puts("Enter the next title.");
    }

    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (int i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n", library[count].title,
                                        library[count].author,
                                        library[count].value);
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }
    else
        puts("No books? Too bad.\n");

    puts("Bye.\n");
    fclose(pbooks);

    return 0;
}
```

## Structures: What Next

![tree](./images/tree.png)

A binary tree structure, with each individual structure (or node) connected to
the two below it.

## Unions: A Quick Look

* A type that enables you store different data types in the same memory space
  (but not simultaneouly).
* A typical use is a table designed to hold a mixture of types in some order
  that is neither regular nor known in advance.
* By using an array of `union`s, you can create an array of equal-sized units,
  each of which can hold a variety of data types.

```c
union hold
{
    int digit;
    double bigfl;
    char letters;
}

// defining tree union
union hold fit;         // union variable of hold type
union hold save[10];    // array of 10 union variables
union hold * pu;        // pointer to a variable of hold type
```

To define a `union`:

* The `union` hold an `int` value *or* a `double` value *or* a `char` value.
* The 1st declaration creates a single variable `fit`, the compiler allots
  enough space so that it can hold the largest of the described possibilities,
  which is a `double`, occupying 8 bytes.
* The 2nd declaration creates an array called save with 10 elements, each 8
  bytes in size.
* The 3rd declaration creates a pointer that can hold the address of a `hold
  union`.

---

To initialize a union:

```c
// initialize a union
union hold valA;
valA.letters = 'R';
union hold valB = valA;     // initialize one union to another
union hold valC = {88};     // initialize digit member of union
union hold valD = {.bigfl = 118.2};     // designated initializer
```

* You can initialize a `union` to another union of the same type.
* You can initialize the first element of a `union`.
* With C99, you can use a *designated initializer*.

### Using Unions

```c
fit.digit = 23;     // 23 is stored in fit; 2 bytes used
fit.bigfl = 2.0     // 23 is cleared, 2.0 store; 8 bytes used
fit.letter = 'h'    // 2.0 is cleared, h stored; 1 byte used
```

---

You can use the `->` operator with pointers to unions in the same fashion that
you use the operator with pointers to structures

```c
pu = &fit;
x = pu->digit;  // same as x = fit.digit
```

---

Don't do the following:

```c
fit.letter = 'A';
flnum = 3.02 * fit.bigfl;   // ERROR, ERROR, ERROR
```

* This sequence is wrong because a `char` type is stored, but the next line
  assumes that the content of fit is a `double` type.

> You can use one member to place values into a `union` and to then use a
> different member for viewing the contents. (See listing 15.4).

```c
struct owner
{
    char socsecurity[12];
    ...
};

struct leasecompany
{
    char name[40];
    char headquarters[40];
    ...
}

union data
{
    struct owner owncar;
    struct leasecompany leasecar;
}

struct car_data
{
    char make[15];
    int status;     /* 0 = owned, 1 = leased */
    union data ownerinfo;
    ...
}
```

## Anonymous Unions (C11)

An anonymous union is an unnamed member union of a structure or union.

```c
struct owner
{
    char socsecurity[12];
    ...
};

struct leasecompany
{
    char name[40];
    char headquarters[40];
    ...
};

struct car_data
{
    char make[15];
    int status;  /* 0 = owned, 1 = leased */
    union
    {
        struct owner owncar;
        struct leasecompany leasecar;
    };
    ...
}
```

* If `flits` is a `car_data` structure, we can use `flits.owncar.socsecurity`
  instead of `flits.ownerinfo.owncar.socsecurity`.

## Summary: Structure and Union Operators

### The Membership Operator: `.`

```c
name.member;
```

* `name` is the name of a structure and `member` is a member specified by the
  structure template.
* The type of `name.member` is the type specified for member.
* the membership operator can also be used in the same fashion with unions.

```c
struct
{
    int code;
    float cost;
} item;

item.code = 1265;
```

### The Indirect Membership Operator: `->`

```c
ptrstr->member;
```

* `ptrstr` is a pointer to a structure and that `member` is a member specified
  by the structure template.
* The indirect membership operator can also be used in the same fashion with
  unions.

```c
struct {
    int code;
    float cost;
} item, * ptrst;

ptrst = &item;
ptrst->code = 3451;

// the following three expressions are equivalent
ptrst->code
item.code
(*ptrst).code
```

## Enumerated Types

*Enumerated type* can be used to declare symbolic names to represent integer
constants.

The purpose of enumerated types is to enhance the readability of a program. The
syntax is similar to that used for structures.

> Actually, `enum` constants are type `int`; therefore, they can be used
> wherever you would use an `int`.

```c
enum spectrum {red, orange, yellow, green, bule, violet};
enum spectrum color;
```

* The first declaration establishes `spectrum` as a tag name, which allows you
  to use `enum spectrum` as a type name.
* The second declaration makes `color` a variable of that type.
* The identifiers within the braces enumerate the possible values that a
  `spectrum` variable can have, the possible values for `color` are `red`,
  `orange`, `yellow`, and so on.
* These symbolic constants are termed enumerators.

```c
int color;
color = blue;
if (color == yellow)
    ...;
for (color = red; color <= violet; color++)
    ...;
```

* Enumerators such as `red` and `blue` are type `int`.
* Enumerated variables are more loosely constrained to be an integral type as
  long as the type can hold the enumerated constants.
* The enumerated constants for `spectrum` have the range 0–5, so a compiler
  could choose to use `unsigned char` to represent the `color` variable.

> Incidentally, some C enumeration properties don’t carry over to C++. For
> example, C allows you to apply the `++` operator to an enumeration variable,
> and the C++ standard doesn’t. So if you think your code might be incorporated
> into a C++ program some day, you should declare `color` as type `int` in the
> previous example. Then the code will work with either C or C++.

### `enum` Constants

```c
printf("red = %d, orange = %d\n", red, orange);

// will give the output
red = 0, orange = 1
```

### Default Values

```c
enum kids {nippy, slats, skippy, nina, liz};
```

* `nina` has the value `3`.

### Assigned Values

```c
enum levels {low = 100, medium = 500, high = 2000};
```

---

If you assign a value to one constant but not to the following constants, the
following constants will be numbered sequentially.

```c
enum fline {cat, lynx = 10, puma, tiger};
```

* Then `cat` is `0`, by default, and `lynx`, `puma`, and `tiger` are `10`,
  `11`, and `12`, respectively.

### `enum` Usage

> Note that the enumerated types are for internal use.

### Shared Namespace 

C uses the term namespace to identify parts of a program in which a name is
recognized.

Scope is part of the concept:

* Two variables having the same name but in different scopes don’t conflict;
* Two variables having the same name in the same scope do conflict.

There also is a category aspect to namespaces. Structure tags, union tags, and
enumeration tags in a particular scope all share the same namespace, and that
namespace is different from the one used by ordinary variables.

What this means is that you can use the same name for one variable and one tag
in the same scope without causing an error, but you can’t declare two tags of
the same name or two variables of the same name in the same scope.

```c
struct rect { double x; double y; };
int rect;   // not a conflict in C
```

> C++ doesn’t allow this.

## `typedef`: A Quick Look

The `typedef` facility is an advanced data feature that enables you to create
your own name for a type. It is similar to `#define` in that respect, but
with three differences:

* Unlike `#define`, `typedef` is limited to giving symbolic names to types only
  and not to values.
* The `typedef` interpretation is performed by the compiler, not the
  preprocessor.
* Within its limits, `typedef` is more flexible than `#define`.

```c
typedef unsigned char BYTE;

BYTE x, y[10], * z;
```

> Often, uppercase letters are used for these definintions to remind the user
> that the type name is really a symbolic abbreviation.

* Using `BYTE` instead of `unsigned char` helps document that you plan to use
  `BYTE` variables to represent numbers rather than character codes.
* Using `typedef` also helps increase portability.

---

> For example, we’ve mentioned the `size_t` type, which represents the type
> returned by the `sizeof` operator, and the `time_t` type, which represents
> the type of value returned by the `time()` function. The C standard says
> `sizeof` and `time()` return integer types but leaves it up to the
> implementation to determine which type.

```c
time_t time(time_t *);
```

On one system, `time_t` can be `unsigned long`; on another, it can be `unsigned
long long`. As long as you include the `time.h` header file, your program can
access the appropriate definition, and you can declare `time_t` variables in
your code.

---

```c
#define BYTE unsigned char  // can be duplicated with a #define
```

```c
typedef char * STRING       // can not be duplicated with a #define

// STRING name, sign == char * name, * sign
```

* Without the keyword `typedef`, this example would identify `STRING` itself as
  a `pointer-to-char`.
* With the keyword, it makes `STRING` an identifier for `pointers-to-char`.

```c
typedef struct complex
{
    float real;
    float imag;
} COMPLEX
```

---

You can omit a tag when using `typedef` to a name a structure type:

```c
typedef struct {double x; double y} rect;

rect r1 = {3.0, 6.0};
rect r2;

// is equal to
struct {double x; double y;} r1 = {3.0, 6.0};
struct {double x; double y;} r2;
r2 = r1;
```

* If two structures are declared without a tag but with identical members (with
  both member names and types matching), C considers the two structures to be
  of the same type, so assigning `r1` to `r2` is a valid operation.

---

`typedef` names are often used for complicated types:

```c
typedef char (* FRPTC ()) [5];
```

* Makes `FRPTC` announce a type that is a ***function*** that returns a pointer
  to a five-element array of `char`.

## Fancy Declaration

| Modifier | SIgnificance         |
| :---:    | ---                  |
| `*`      | Indicates a pointer  |
| `()`     | Indicates a function |
| `[]`     | Indicates an array   |


```c
int board[8][8];    // an array of arrays of int
int ** ptr;         // a pointer to a pointer to int
int * risks[10];    // a 10-element array of pointer to int
int (* rusks)[10];  // a pointer to an array of 10 ints
int * oof[3][4];    // a 3 x 4 array of pointer to int
int (* uuf)[3][4];  // a pointer to a 3 x 4 array of ints
int (* uof[3])[4];  // a 3-element array of pointers to 4-element array of int
```

1. The `[]`, which indicates an array, and the `()`, which indicates a
   function, have the same precedence. This precedence is higher than that of
   the `*` indirection operator, which means that the following declaration
   makes `risks` an array of pointers rather than a pointer to an array:

```c
int * risks[10];
```

2. The `[]` and `()` associate from left to right. Thus, the next declaration
   makes `goods` an array of 12 arrays of 50 `ints`, not an array of 50 arrays
   of 12 `ints`:

```c
int goods[12][50];
```

3. Both `[]` and `()` have the same precedence, but because they associate from
   left to right, the following declaration groups `*` and `rusks` together
   before applying the brackets. This means that the following declaration
   makes `rusks` a pointer to an array of 10 `ints`:

```c
int (* rusks)[10];
```

---

```c
int * oof[3][4];
```

* The `[3]` has higher precedence than the `*`, and, because of the
  left-to-right rule, it is applied before the `[4]`. Hence, oof is an array
  with three elements.
* Next in order is `[4]`, so the elements of oof are arrays of four elements.
* The `*` tells us that these elements are pointers. The int completes the
  picture: `oof` is a three-element array of four-element arrays of pointers to
  `int`, or, for short, a 3×4 array of pointers to `int`. Storage is set aside
  for 12 pointers.

---

```c
int (* uuf)[3][4];
```

The parentheses cause the `*` modifier to have first priority, making `uuf`
a pointer to a 3×4 array of `ints`. Storage is set aside for a single pointer.

---

```c
char * fump(int);           // function returning to pointer to char
char (* frump)(int);        // pointer to a function that returns type char
char (* flump[3])(int);     // array of 3 pointers to functions that
                            // return type char
```

---

```c
typdef int arr5[5];
typedef arr5 * p_arr5;
typedef p_arr5 arrp10[10];
arr5 togs; // togs an array of 5 int
p_arr5 p2; // p2 a pointer to an array of 5 int
arrp10 ap; // ap an array of 10 pointers to array-of-5-int
When you bring structures into the picture, the possibilities for decl
```

## Functions and Pointers

Typically, a function pointer is used as an argument to another function,
telling the second function which function to use.

For instance, sorting an array involves comparing two elements to see which
comes first. If the elements are numbers, you can use the `>` operator.  More
generally, the elements may be a string or a structure, requiring a function
call to do the comparison.

Functions have addresses, because the machine-language implementation of a
function consists of code loaded into memory. A pointer to a function can hold
the address marking the start of the function code.

When declaring a function pointer, you have to declare the type of function
pointed to. To specify the function type, you specify the function signature,
that is, the return type for the function and the parameter types for a
function.

```c
void ToUpper(char *);       // convert string to uppercase
```

* The type for the `ToUpper()` function is “function with `char *` parameter
  and return type void.” To declare a pointer called `pf` to this function
  type, do this: 

```c
void (* pf)(char *);        // pf a pointer-to-function
```
 
* The first parentheses pair associates the `*` operator with `pf`, meaning
  that `pf` is a pointer to a function. This makes `(*pf)` a function, which
  makes `(char *)` the parameter list for the function and `void` the return
  type.

---

When the first parentheses are are omitted:

```c
void * pf(char*)     // pf a function that returns a pointer
```

> To declare a pointer to a particular type of function, first declare a
> function of the desired type and then replace the function name with an
> expression of the form (`*pf`); `pf` then becomes a pointer to a function of
> that type.

---

You can assign to it the addresses of functions of the proper type.

```c
void ToUpper(char *);
void ToLower(char *);
int round(double);
void (*pf)(char *);

pf = ToUpper;   // valid, ToUpper is address of the function
pf = ToLower;   // valid, ToLower is address of the function
pf = round;     // invalid, round is the wrong type of function
pf = ToLower(); // invalid, ToLower() is not an address
```

* The name of a function can be used to represent the address of the function
* The pointer pf can point to any function that takes a char `*` argument and
  has a return type of `void`, but not to functions with other characteristics.

---

To use a function pointer to access a function:

```c
void ToUpper(char *);
void ToLower(char *);
void (* pf)(char *);
char mis[] = "Nina Metier";

pf = ToUpper;
(*pf)(mis);         // apply ToUpper to mis (syntax 1)
pf = ToLower;
pf(mis);            // apply ToLower to mis (syntax 2)
```

* The first approach: Because `pf` points to the `ToUpper` function, `*pf` is
  the `ToUpper` function, so the expression `(*pf)(mis)` is the same as
  `ToUpper(mis)`. `ToUpper` and `(*pf)` are equivalent.
* The second approach: Because the name of a function is a pointer, you can use
  a pointer and a function name interchangeably, hence `pf(mis)` is the same as
  `ToLower(mis)`. `pf` and `ToLower` are equivalent.

---

One of the most common uses of a function pointer is an argument to function

```c
void show(void (*fp)(char*), char * str);
```

```c
show(ToLower, mis);     // show() uses ToLower() function: fp = ToLower
show(pf, mis)           // show() uses function pointed to by pf: fp = pf

void show(void (* fp)(char *), char * str)
{
    (*fp)(str);     // apply chosen function to str
    puts(str);      // display result
}
```

---

Functions with return values can be used two different ways as arguments to
other functions.

```c
function1(sqrt);        // passes address of sqrt function
function(sqrt(4.0));    // passes return value of sqrt function
```

---

To use `typedef`:

```c
typedef void (*V_FP_CHARP)(char *);
void show (V_FP_CHARP fp, char *);
V_FP_CHARP pfun;
```

Or declare and initialize an array of pointers, and modify the `showmenu()`
function so it is type `int`...

```c
V_FP_CHARP arpf[4] = {ToUpper, ToLower, Transpose, Dummy};

index = showmenu();
while (index >= 0 && index <= 3)
{
    strcpy(copy, line);         /* make copy for show() */
    show(arpf[index], copy);    /* use selected function */
    index = showmenu();
}
```

---

All four ways in which a function can be used: 

* In defining a function
* In declaring a function
* In calling a function
* As a pointer

![foousage](./images/foousage.png)
