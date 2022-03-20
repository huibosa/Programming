## Single-Character I/O: `gotchas()` and `pitcher()`

Echoing the input
: Fetch characters from keyboard input and send them to screen.

### General Comments

> `getchar()` and `putchar()` are not true functions, but are defined using
preprocessor macros.

## Buffers

### General Comments

*Unbuffered* or *direct* input.
: On some old systems, the text input would be echoed immediately,
desirable for some interactive programs, like games.

*Buffered input*
: While the delayed echoing, illustrates *buffered* input, the characters
are stored in a *buffer*, some computer designs don't permit unbuffered input.

*Echoed input*
: Character you type shows on screen

*Unechoed input*
: The keystrokes don't show.

### Advantages

* Less time-consuming
* Easily to fix mistakes.

### Two Varieties

*Fully buffered* I/O
: The buffer is flushed when it is full, usually occurs with file input.
The buffer size depends on the system, common values are
512 bytes and 4096 bytes.

*Line-buffered* I/O
: The buffer is flushed whenever a newline character shows up.
Keyboard input is normally lin buffered.

## Files, Streams, and Keyboard Input

*File*
: An area of memory in which information is stored. Normally kept in 
some sort of permanent memory, such as a hard disk, USB flash drive...

*Low-level* I/O
: C can deal with files by using the basic file tools of the host operating
system. While among different computer systems, it's impossible to build
a universal low-level I/O functions.

*Standard I/O package*
: C also deal with file on a second level, involving creating a standard model
and a standard set of I/O functions for dealing with files. At this higher
level , you only need to deal with a uniform interface, and leave the
other work to C implementations

*Stream*
: An idealized flow of data to which the actual input or output is mapped. C
deals with a stream instead of directly with a file. The process of opening a
file becomes one of associating a stream with the file, and reading and writing
take place via the stream.

* C treats the input and output device as files opened automatically by every C
  programs.
* Keyboard input is represented by a stream called `stdin`, and output to the
  screen is represented a stream called `stdout`.

## The End of File

### The `Ctrl-Z`
* C input functions come equipped with a built-in, end-of-file detector.
* One method to detect the end of file is to place a special character in the
  file to mark the end. The method once used was put a `Ctrl-Z` to mark the end
  of file

### Track The Size of the File

* If a program has read the size of the file, the file has reached the end.
* This method allows file to hold all characters, including `Ctrl+Z`.

### The `EOF`

* C having the `getchar()` return a special value when the end of a file is
  reached, That is a `EOF` (end of file).
* `getchar()` and `scanf()` returns an `EOF` when detects the end of file
* The `sdtio` defines the `EOF` as `#define EOF (-1)`
* The `EOF` represents a value that signals the end of file was detected, not a
  symbol in the file.

```c
#include <stdio.h>
int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
}
```

* The `getchar` is type `int`, so it can read EOF value.
* You don't have to define EOF.
* On most Unix and Linux systems, `Ctrl+D` at the *beginning* of a line will
  gives the end-of-file signal, while some micro-computing recognizes a
  `Ctrl+Z` at the beginning, and some recognizes `Ctrl+Z` anywhere.

## Redirection and Files

### General Comments

By default, a C program using standard I/O package looks to the standard
input as its source for input (such as a keyboard).This is the stream
identified as `stdin`.but you can tell it to seek input from a file
instead of from a keyboard.

* `Redirection` is associated with operating system, not C.
* `Redirection` enables to use a file instead of keyboard for input, and
  enables to use a file instead of screen for output.

### Two Ways to work with files

* Use special functions that open, close, read, write in files.
* Use a program designed to work with a keyboard and screen, but *redirect*
  input and output to different channels--to and from files.
* `getchar()` get data from stream without caring where the stream gets data.

## Redirection

### Terms

*Text file*
: Containing text. Data stored as human-readable characters.

### General Comments

Redirection enables to use keyboard-input programs with files. To do
this the program has to test for the end of file.

### Redirecting Input

In the following paragraph, `prog` is the executable program,
and `file1` and `file2` is the text file.

```
prog < words
```

* The `<` is a Unix and Linux and DOS/Windows redirection operator, causing the
  words file to be associated with the `sdtin` stream, channeling the file
  contents into the `prog` program.
* The `prog` only know that a stream of characters is being fed to it.

### Redirecting Output

`prog > file1`

1. Make a new file `file1`
2. Redirects the output of `prog` to `file1`
3. The screen displays what you type, and the copies go to `file1`

* The redirection reassigned the `stdout` from the display device to `file1`
* Existed `file1` will be erased and then replaced.

### Combined Redirection

1. `prog < file1 > file2`
2. `prog > file1 < file2`

* `1` and `2` has teh save effect. Because teh order of redirection operations
  doesn't matter.

`prog < file1 > file1`

* Don't use the same file for both input and output to the same command. The
  original `file1` will be truncated by `>` to zero length before it is ever
  used as input.

### Rules

1. A redirection operator connects an *executable* program with a data file. It
   can not be used to connects one data file to another, nor can be used to
   connects one program to another.
2. Input cannot be taken from more than one file, nor can output be directed to
   more than one file by using these operators.
3. **Normally**, spaces between the names and operators are optional.

With `fish` and `beets` as text files, `addup` and `count` as executable
programs:

```
fish > beets                <-- Violates the first rule
addup < count               <-- Violates the first rule
addup > fish < beets        <-- Violates the second rule
addup > beets fish          <-- Violates the second rule
```

> `>>` enables to add data to the end of an existing file
> `|` enables to connect the output of one program to the input of second
> program.

## Creating a Friendlier User Interface

### Working with Buffered Input

> Use a `while` loop and `continue` to discard the newline character.

### Mixing Numeric and Character Input

> Unlike `scanf()`, the `getchar()` doesn't skip over newline characters.

## Input Validation

```c
 long get_long(void)
 {
    long input;
    char ch;
 
    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
 
    return input;
 }  
```

The code can be used to discard the invalid input.

## The Input Stream and Nubmers

### General Comments

* Input consists of characters, but `scanf()` can convert input to an integer or
floating-point value.
* `getchar()` and `scanf()` using `%c` accepts any character.

### Examples

`is 28 12.4`\
To a C program it looks like a stream of bytes.

`42`

* Using a `scanf()` with a `%c` specifier, it will just read `4` character and
  stored it in a `char` variable.
* While with a `%s` specifier, it will read two characters, and stores them in
  a character string.
* With a `%d` specifier, `scanf()` calculate the integer then stored the
  integer binary representation of that value in an `int` variable
* With a `%f` specifier, calculates that they correspond to the number `42.0`,
  expresses that value in the internal floating-point representation, and
  stores the result in a `float` variable.   

## Menu Browsing

### Form

```
 get choice 
 while choice is not 'q' 
     switch to desired choice and execute it 
```

### General Comments

* A menu offers the user a choice of responses.
* Using a graphical interface can make it easier to control input by
limiting choices.

### Smoother Expression

* Smoothness when processing correct input and smooth-ness when handling
incorrect input
* One way is to let the `get choice` part screen out inappropriate responses
so only valid input can be passed to `switch`
