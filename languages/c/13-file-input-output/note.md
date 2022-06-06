## Communicating with Files

### What is a File?

A named selection on a disk 

## The Text Mode and Binary Mode

All file content is in binary form (`0` and `1`).

* Text file:
Has text content, primarily uses the binary codes for characters to represent
text.

* Binary file:
The binary values in the file represent machine-language code or numeric
data (such as `long` and `double` values).

---

Unix uses the same file format for both kinds of content. 

* Pre-OS X Macintosh used `\r` to indicate a newline.
* Early MS-DOS files used `\r\n` to indicate a newline
* Unix Use `\n` to indicate a newline

Unix directories maintain a file-size count that programs can use to determine
when EOF is reached. (others have different ways). They have a format for
text files different from the Unix model:

* Early MS-DOS imbedded `Ctrl+Z` character to denote `EOF`, even though the
  actual file would be padded with additional `\0` to make the total size a
  multiple of 256 (a byte).
* Other systems might padding each line with `\0` to make every line of the
  same length,
* Or a system might encode the length of each line at the beginning of each
  line.

---

In the binary mode, byte of the file is accessible to a program.

In the text mode, what the program sees can differ from what is in the file.
With the text view, the local environment’s representation of such things as
the end of a line or end-of-file are mapped to the C view when a file is
read. Similarly, the C view is mapped to the local representation of output.

> For example, a C program compiled on an older Macintosh and using text mode
> would convert `\r` to `\n` when reading a file in text mode and convert `\n`
> to `\r` when writing to a file.
> 
> Or a C text-mode program compiled on an MS-DOS platform would convert `\r\n`
> to `\n` when reading from a file and convert `\n` to `\r\n` when writing to
> a file.

![binary&text_view](./images/binary_text_view.PNG)

When using the binary view of the same files,your program sees both the `\r`
and the `\n` characters in the MS-DOS text file; no mapping takes place.

### Levels of I/O

`Low-level I/O` uses the fundamental I/O services provided by the operating
system. `Standard high-level I/O` uses a standard package of C library
functions and `stdio.h` header file definitions.

The C standard supports only the standard I/O package.

### Standard Files

C programs automatically open three files on your behalf:

* Standard input. The standard input, provides input to your program. It’s the
  file that is read by `getchar()` and `scanf()`.
* Standard output. The standard output is where normal program output goes.  It
  is used by `putchar()`, `puts()`, and `printf()`.
* Standard error output. The purpose of the standard error output file is to
  provide a logically distinct place to send error messages. 

> For example, The *redirection* send output to a file instead of to the
> screen, while output sent to the standard error output still goes to the
> screen.

## Standard I/O

The standard I/O package has two advantages over low-level I/O.

* It has many specialized functions that simplify handling different I/O
  problems.
* Input and output are buffered. Information is transferred in large chunks
  (typically 512 bytes at a time or more) instead of a byte at a time.

```c
exit(EXIT_FAILURE)
exit(EXIT_SUCCESS)
```

To enable portability, the C standard (in `stdlib.h`) requires:

* Value `0` or the macro `EXIT_SUCCESS` to indicate successful termination.
* Macro `EXIT_FAILURE` to indicate unsuccessful termination.

```c
return 0;
exit(0);
```

Has the same effetct in the *initial call* to `main()`, while in a recursive
program:

* `exit()` still terminates the program.
* `return` passes control to the previous level of recursion until the original
  level is reached.

> `exit()` terminates the program even if called in a function other than
> `main()`.

### The `fopen()` Function

|Mode String|Meaning|
|:---:|---|
|`"r"`|Open a text file for reading|
|`"w"`|Open a text file for writing, truncating an existing file to zero length, or creatng the file if it does not exist.|
|`"a"`|Open a text file for writing, appending to the end of an existing file, or creating the file if it does not exist.|
|`"r+"`|Open a text file for update (reading and writing)|
|`"w+"`|Open a text file for update (reading and writing), first truncating the file to zero length if it exists or creating the file if it does not exist.|
|`"a+"`|Open a text file for update (reading and writing), appending to the end of an existing file, or creating the file if it does not yet exist; the whole file can be read, but writing can only be appended.|
|`"rb"`, `"wb"`, `"ab"`, `"ab+"`, `"a+b"`, `"wb+"`, `"w+b`"|Like the preceding modes, except they use binary mode instead of text mode.|
|`"wx"`, `"wbx"`, `"w+x"`, `"wb+x"`, `"w+bx"`|(C11) Like the non-x modes, except they fail if the file already exists and they open a file in exclusive mode, if possible.|

> For systems such as Unix and Linux that have just one file type, the modes
with the `b` are equivalent to the corresponding modes lacking the `b`.

The new C11 writes mode with `x` provide:

* When open an existing file, `fopen()` with `x` will failed.
* The `x` modes keeps other programs or threads from accessing the file until
the current process closses the file.

The `fopen()` returns a `file pointer` after successfully opens a file.

* The file pointer is of type pointer-to-`FILE`
* `FILE` is a derived type defined in `stdio.h`.
* The pointer points to a data object containing information about the file,
including information about the buffer used for the file’s I/O.

The `fopen()` function returns the null pointer (defined in `stdio.h`) if it
cannot open the file. The `fopen()` function can fail because:

* The disk is full,
* The file is not in the searched directory,
* The name is illegal,
* Access is restricted,
* A hardware problem
* ...

### The `getc()` and `putc()` Functions

They are like the `fread()` `fwrite()` functions without buffer.

```c
// get a character from the file identified by fp
ch = getc(fp);

// put the character ch into the file identified by the FILE pointer fpout
putc(ch, fpout);
```

### End-of-File

The `getc()` function returns the special value EOF if it tries to read a
character and discovers it has read the end of the file. So a C program
discovers it has reached the end of a file only *after* it tries to read
past the end of the file.

To avoid attempting to read an empty file, an entry-condition loop for
file input is needed.

```c
// good design #1
int ch;             // int to hold EOF
FILE * fp;
fp = fopen("wacky.txt", "r");
ch = getc(fp);      // get initial input
while (ch != EOF)
{
    putchar(ch);    // process input
    ch = getc(fp);  // get next input
}

// good design #2
int ch;
FILE * fp;
fp = fopen("wacky.txt", "r");
while ((ch = getc(fp)) != EOF)
{
    putchar(ch);    // process input
}

// bad design
int ch;
FILE * fp;
fp = fopen("wicky.txt", "r");
while (ch != EOF)   // ch undetermined value first use
{
    ch = getc(fp);   // get input
    putchar(ch);    // process input
}
```

The bad design has two problems:

* The first time `ch` is compared with `EOF`, it has not yet been assigned a
  value.
* If `getc()` does return `EOF`, the loop tries to process `EOF` as if it were
  a valid character.

> (Not recommanded) To fix the defect, you could initialize `ch` to a dummy
> value and stick an `if` statement inside the loop.

### The `fclose()` Function

Returns a value of `0` if successful, and EOF if not:

```c
if (fclose(fp) != 0)
    printf("Error in closing file %s\n", argv[1]);
```

The `fclose()` function can fail if:

* The disk is full.
* A removable storage device has been removed,
* There has been an I/O error.
* ...

### Pointers to the Standard Files

| Standard        | File Pointer | Normally      |
| ---             | ---          | ---           |
| Standard input  | `stdin`      | Your keyboard |
| Standard output | `stdout`     | Your screeen  |
| Standard error  | `stderr`     | Your screeen  |

## A Simple-Minded File-Condensing Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 81

int main(int argc, char * argv[]) {
    FILE *in, *out;       // declare two FILE pointers
    int ch;
    char name[LEN];          // storage for output filename
    int count = 0;

    // check for command-line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // set up input
    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // set up output
    strncpy(name, argv[1], LEN - 5);    // copy filename

    name[LEN - 5] = '\0';               // in case the argv[2] string
                                        // is longer than `LEN - 5`,

    strcat(name, ".red");               // append .red

    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
```

No null character is copied if the argv[2] string is longer than `LEN - 5`,
You can’t add extensions to extensions under traditional DOS. (The proper
MS-DOS approach is to replace any existing extension with `.red`, so the
reduced version of `strange.c` would be `strange.red`. You could use the
`strchr()` function to locate the period, if any, in a name and copy only
the part of the string before the period.)

## File I/O: `fprintf()`, `fscanf()`, `fgets()`, and `fputs()`

### The `fprintf()` and `fscanf()` Functions

Works like `printf()` and `scanf()`, except that they requres an additional
first argument to identify the proper file.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE * fp;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File contents:");
    rewind(fp);             // go back to beginning of file

    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
```

* By using the `"a+"` mode, the program can both read and write in the file.
* The append mode only enables you to add material to the end of the file,
but the `"a+"` mode does enable you to read the whole file.  
* The `rewind()` command takes the program to the file beginning so that the
final while loop can print the file contents

### The `fgets()` and `fputs()` Functions

```c
fgets(buf, STLEN, fp)
```

* `buf` is the name of a char array
* `STLEN` is the maximum size of the string
* `fp` is the pointer-to-`FILE`.
* Returns `NULL` when reads an `EOF`

```c
fputs(buf, fp)
```

* `buf` is the string address
* `fp` is the file poniter

## Adventures in Random Access: `fseek()` and `ftell()`

```c
fseek(fp, 0L, SEEK_END);
last = ftell(fp);

for (count = 1L; count <= last; count++)
{
    fseek(fp, -count, SEEK_END);
    ch = getc(fp);
    if (ch != CNTL_Z && ch != '\r')
        putchar(ch);
}
```

This program uses the binary mode so that it can deal with both MS-DOS text
and Unix files.

### How `fseek()` and `ftell()` Work

`fseek()` has three arguments:

* First one is a FILE pointer to the file being searched.
* Second one is the `offset`, which tells how far to move from the starting
  point, which must be a `long` value, and can be positive (move forward),
  negative (move backward), or zero (stay put).
* Third one is the mode, which identifies the starting point.

|Mode|Measureed Offset From|
|---|---|
|`SEEK_SET`|Beginning of file|
|`SEEK_CUR`|Current position|
|`SEEK_END`|End of file|

```c
fseek(fp, 0L, SEEK_SET);        // go to the beginning of the file
fseek(fp, 10L, SEEK_SET);       // go 10 bytes into the file
fseek(fp, 2L, SEEK_CUR);        // advance 2 bytes from the current position
fseek(fp, 0L, SEEK_END);        // go to the end of the file
fseek(fp, -10L, SEEK_END);      // backup 10 bytes from the end of the file
```

`fseek()` returns:

* `0` if everything's ok.
* `-1` if there is an error, such as attempting to move past bounds of the
  file.

`ftell()`, is type `long`, and returns the current position.

In Unix, `ftell()` specifies the file position by returning the number of
bytes from the beginning, with the first byte being byte `0`, and so on.

Under ANSI C, this definition applies to files opened in the binary mode, but
not necessarily to files opened in the text mode. (That's one reason the above
code uses the binary mode).

```c
for (count = 1L; count < last; count++)
{
    feek(fp; -count; SEEK_END)
        ch = getc(fp);
    if (ch != '\032' && ch != '\r')
        putchar(ch);
}
```

### Binary and Text Mode

Unix has only one file format, so no special adjustments are needed.

Many MS-DOS editors mark the end of a text file with the character `Ctrl+Z`,
which marks the end of file when opened in the text mode.

When the same file is opened in the binary mode, however, the `Ctrl+Z`
character is just another character in the file, and the actual `end-of-file`
comes later. (might come immediately after the `Ctrl+Z`, or the file could be
padded with null characters to make the size a multiple of, say, 256.

Null characters don’t print under DOS, and we included code to prevent the
program from trying to print the Ctrl+Z character.

MS-DOS represents a text file newline with the `\r\n` combination.
A C program “sees” `\r\n` as:

* `\n` in text mode.
* `\r\n` in binary mode.

The `ftell()` function may work differently in the text mode than in the
binary mode.  Many systems have text file formats that are different enough
from the Unix model that a byte count from the beginning of the file is not
a meaningful quantity.

ANSI C states that, for the text mode, `ftell()` returns a value that can be
used as the second argument to `fseek()`.

For MS-DOS, for example, `ftell()` can return a count that sees `\r\n` as a
single byte.

### Portability

* In binary mode, implementations need not support the `SEEK_END` mode. A more
portable approach is to read teh whole file byte-by-byte until the end.
* In text mode, the only calls to `fseek()` are guaranteed to work are these:

|Function Call|Effect|
|---|---|
|`feek(file, 0L, SEEK_SET`)|Go to the beginning of the file|
|`feek(file, 0L, SEEK_CUR`)|Stay at the current position|
|`feek(file, 0L, SEEK_END`)|Go to the file's end|
|`feek(file, ftell-pos, SEEK_SET`)|Go to position `ftell-pos` from the beginning;|

### The `fgetpos()` and `fsetpos()` Functions

Two new position functions to work with larger file sizes, use a `fpos_t` to
represent a position

A variable or data object of `fpos_t` type can specify a location within a file,
and it cannot be an array type, but its nature is not specified beyond that.

```c
int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
```

* When called, it places an `fpos_t` value in the location pointed to by `pos`;
the value describes a location in the file.
* The function returns zero if successful and a nonzero value for failure.

```c
int fsetpos(FILE *stream, const fpos_t *pos);
```

* When called, it uses the `fpos_t` value in the location pointed to by `pos` to
set the file pointer to the location indicated by that value.
* The function returns zero if successful and a nonzero value for failure.
* The `fpos_t` value should have been obtained by a previous call to
`fgetpos()`.

## Behind the Scenes with Standard I/O

The first step in using standard I/O is to use `fopen()` to open a file.

* The `stdin`, `sdout` , and `stderr` files are opened automatically.
* Sets up a buffer (two buffers for read-write modes).
* Sets up a data structure containing data about the file and about the buffer.
* Returns a pointer to this *structure* so that other functions know where to
find it.
* The `fopen()` function is said to “open a stream”.
  * If the file is opened in the text mode, you get a text stream,
  * If the file is opened in the binary mode, you get a binary stream.

The data structure typically includes:

* A file position indicator to specify the current position in the stream.
* It also has indicators for errors and end-of-file,
* a pointer to the beginning of the buffer,
* a file identifier,
* and a count for the number of bytes actually copied into the buffer.

The next step is to call on one of the input functions declared in `stdio.h`,
calling any one of these functions causes a chunk of data to be copied from
the file to the buffer. The buffer size is implementation dependent, but
typically 512 or 4,096 (tend to get larger)

The initial function call sets values in the structure pointed to by `fp`.
In particular, the current position in the stream and the number of bytes
copied into the buffer are set. Usually the current position starts at byte 0.

After the data structure and buffer are initialized, the input reads input data
from the buffer. As it does so, the file position indicator is set to point to
the character following the last character read.

> Because all the input functions from the `stdio.h` family use the same buffer,
a call to any one function resumes where the previous call to any of the
functions stopped.

When all the characters in the buffer is read, the function requests that the
next buffer-sized chunk of data be copied from the file into the buffer.

In this manner, the input functions can read all the file contents up to the
end of the file.

After a function reads the last character of the final buffer’s worth of data,
it sets the end-of-file indicator to true. The next call to an input function
then returns EOF .

## Other Standard I/O Functions

### The `ungetc()` Function

```c
int ungetc(int c, FILE * fp);
```

Pushes the character specified by c back onto the input stream.

You want a function to read characters up to, but not including, the next
colon. You can use `getchar()` or `getc()` to read characters until a colon is
read and then use `ungetc()` to place the colon back in the input stream.

![ungetc](./images/ungetc.PNG)

> The ANSI C standard guarantees only one pushback at a time. If an
implementation permits you to push back several characters in a row, the input
functions read them in the reversed order of pushing.

### The `fflush()` Function

```c
int fflush(FILE * fp);
```

* Sending any unwritten data in the output buffer to the output file identified
by `fp`, which is called *flushing a buffer*.
* If `fp` is the null pointer, all buffer is flushed.
* The effect of using `fflush()` on an input stream is undefined. You can use
it with an update stream (any of the read-write modes), provided that the most
recent operation using the stream was not input.

### The `setvbuf()` Function

```c
int setvbuf(FILE * restrict fp, char * restrict buf, int mode, size_t size);
```

* Setting up an alternative buffer to be used by the standard I/O functions.
* Called after the file has been opened and before any other operations have
  been performed on the stream.

The arguments:

* The pointer `fp` identifies the stream,
* The `buf` points to the storage to be used.
  * If the value of `buf` is not `NULL`, you must create the buffer.
  > For instance, you could declare an array of 1,024 `char`s and pass the
  > address of that array. 
  * If you use NULL for the value of `buf`, the function allocates a buffer itself.
* The `size` variable tells `setvbuf()` how big the array is.
* The `mode` is selected from the following choices:
  * `_IOFBF` means fully buffered (buffer flushed when full)
  * `_IOLBF` means line-buffered (buffer flushed when full or when a newline is
    written)
  * `_IONBF` means nonbuffered.
* The function returns zero if successful, nonzero otherwise.

> Suppose you have a program that works with stored data objects having, say, a
> size of 3,000 bytes each. You could use `setvbuf()` to create a buffer whose
> size is a multiple of the data object’s size.

### Binary I/O: `fread()` and `fwrite()`

`fprintf()` has a problem of converting numeric values to character data,
possibly altering the value.

The most accurate and consistent way to store a number is to use the same
pattern of bits that the computer does, (A `double` value should be stored in
a `double` unit). In this way the data is stored in *binary form*.  There is
no conversion from numeric forms to character sequences. The `fread()` and
`fwrite()` functions provide this binary service.

![binary_text_output](./images/binary_text_output.PNG)

> If all data in the file is interpreted as character codes, we say that the
> file contains text data. If some or all of the data is interpreted as numeric
> data in binary form, we say that the file contains binary data. (Also, files
> in which the data represents machine-language instructions are binary files.)

* ANSI C recognizes two modes for opening files: binary and text.
* Many operating systems recognize two file formats: binary and text.

Information can be stored or read as binary data or as text data. These are
all related, but not identical.

* You can open a text format file in the binary mode.
* You can store text in a binary format file.
* You can use `getc()` to copy files containing binary data.
* In general, however, you use the binary mode to store binary data in a binary
  format file.
* Similarly, you most often use text data in text files opened in the text
  format.

> Files produced by word processors typically are binary files because they
> contain a lot of nontext information describing fonts and formatting.

### The `size_t fwrite()` Function

```c
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb,
                FILE * restrict fp);
```

* The `fwrite()` function writes binary data to a file.
* The pointer `ptr` is the address of the chunk of data to be written.
* The `size_t` is defined in terms of the standard C types, which is the type
  returned by the `sizeof` operator, typically `unsigned int`.
* `size` represents the size, in bytes, of the chunks to be written.
* `nmemb` represents the number of chunks to be written.
* `fp` identifies to chunks to be written.

To save a data object (such as an array) that is 256 bytes in size:

```c
char buffer[256]
fwrite(buffer, 256, 1, fp);
```

Or save an array of 10 `double` values:

```c
double earnings[10];
fwrite(earnings, sizeof (double), 10, fp);
```

This call writes data from the `earnings` array to the file in 10 chunks,
each of size `double`.

The first argument of `fwrite()` is not a fixed type:

* The first example use `buffer`, which is type pointer to `char`.
* The second example use `earnings`, which is type pointer to `double`.
* Under ANSI C function prototyping, these actual arguments are converted to
  the pointer-to-`void` type, which acts as a sort of catch-all type for
  pointers.

The `fwrite()` function returns the number of items successfully written.
Normally equals `nmemb`, but can be less if there is a write error.

### The `size_t fread()` Function

```c
size_t fread(void * restrict ptr, size_t size, size_t nmemb,
                FILE * restrict fp);
```

* `ptr` is the address of the memory storage into which file data is read
* `fp` identifies the file to be read.
* Use this function to read data that was written to a file using `fwrite()`

For example, to recovor the array of 10 `doubles` saved in th previous example.

```c
double earnings[10];
fwrite(earnings, sizeof (double), 10, fp);
```

* This call copies 10 size `double` values into the earnings array.
* The `fread()` function returns the number of items successfully read.
* Normally, this equals `nmemb`, but it can be less if there is a read error
or if the end-of-file is reached.

### The `int feof(FILE * fp)` and `int ferror(FILE * fp)` Functions

The `feof()` and `ferror()` functions enable you to distinguish between:

* Reaching the end of a file.
* Occurring a read error.
* The `feof()` returns a nonzero value if the last input call detected the
end-of-file, and returns zero otherwise.
* The `ferror()` returns a nonzero value if read or write error has occurred,
and returns zero otherwise.

### An `fread()` and `fwrite()` Example

```c
int main(void)
{
    FILE * fa, * fs;        // fa for append file, fs for source file
    int files = 0;          // number of files appended
    char file_app[SLEN];    // name of append file
    char file_src[SLEN];    // name of source file
    int ch;

    puts("Enter name of the destinatino file:");
    s_get(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(fa, NULL, _IOLBF, BUFSIZE) != 0)
    {
        fputs("Can't craete output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of the first source file (empty line to quit):");
    while (s_get(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOLBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
        
            append(fs, fa);

            if (ferror(fs) != 0)
                fprintf(stderr, "Error in writing file %s", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s", file_app);

            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}
void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];              // allocate once

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, dest)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}
```

### Random Access with Binary I/O

```c
int main()
{
    double numbers[ARSIZE];
    double value;
    int i;
    const char * file = "numbers.dat";
    long pos;
    FILE * iofile;

    // create a set of double values
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);

    // attempt to open file
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }

    // write array in binary format to file
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);

    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for random access", file);
        exit(EXIT_FAILURE);
    }

    // read selected items from file
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
        pos = (long) i * sizeof(double);        // calculate offset
        fseek(iofile, pos, SEEK_SET);           // go there
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    
    // finsh up
    fclose(iofile);
    puts("Bye!");

    return 0;
```
