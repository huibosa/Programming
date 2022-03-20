[toc]

## The IO Classes

### Relationships among the IO Types

### No Copy or Assign for IO Objects

```cpp
ofstream out1, out2;
out1 = out2;              // error: cannot assign stream objects
ofstream print(ofstream); // error: can't initialize the ofstream parameter
out2 = print(out2);       // error: cannot copy stream objects
```

> Functions that do IO typically pass and return the stream through references.
> Reading or writing an IO obkject changes its state, so the reference must not
> be `const`

### Condition States

| IO Library Condition State |
| -------------------------- |
| `strm::iostate`            |
| `strm::badbit`             |
| `strm::failbit`            |
| `strm::eofbit`             |
| `strm::goodbit`            |
| `s.eof()`                  |
| `s.fail()`                 |
| `s.bad()`                  |
| `s.clear()`                |
| `s.clear(flags)`           |
| `s.setstate(flags)`        |
| `s.rdstate()`              |

```cpp
while (cin >> word)
    // ok: read operation successful . . .
```

#### Interrogating the State of a Stream

* The `badbit` indicates a system-level failure, such as an unrecoverable read
  or write error. It is usually not possible to use a stream once `badbit` has
  been set.
* The `failbit` is set after a recoverable error, such as reading a character
  when numeric data was expected. It is often possible to correct such problems
  and continue using the stream. Reaching end-of-file sets both `eofbit` and
  `failbit`.
* The `goodbit`, which is guaranteed to have the value 0, indicates no failures
  on the stream.
* If any of `badbit`, `failbit`, or `eofbit` are set, then a condition that
  evaluates that stream will fail.

> `fail()` returns true if `bad` is set

#### Managing the Condition State

```cpp
// remember the current state of cin
auto old_state = cin.rdstate();   // remember the current state of cin
cin.clear();                      // make cin valid
process_input(cin);               // use cin
cin.setstate(old_state);          // now reset cin to its old state
```

```cpp
// turns off failbit and badbit but all other bits unchanged
cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
```

### Managing the Output Buffer

#### Flusing the Output Buffer

```cpp
cout << "hi!" << endl;   // writes hi and a newline, then flushes the buffer
cout << "hi!" << flush;  // writes hi, then flushes the buffer; adds no data
cout << "hi!" << ends;   // writes hi and a null, then flushes the buffer
```

#### The `unitbuf` Manipulator

```cpp
cout << unitbuf;       // all writes will be flushed immediately
// any output is flushed immediately, no buffering
cout << nounitbuf;     // returns to normal buffering
```

> Buffers are not flushed if the program crashes

#### Tying Input and Output Streams Together

> Interactive systems usually should tie their input stream to their output
> stream.

```cpp
cin.tie(&cout);   // illustration only: the library ties cin and cout for us
// old_tie points to the stream (if any) currently tied to cin
ostream *old_tie = cin.tie(nullptr); // cin is no longer tied
// ties cin and cerr; not a good idea because cin should be tied to cout
cin.tie(&cerr);   // reading cin flushes cerr, not cout
cin.tie(old_tie); // reestablish normal tie between cin and cout
```

## File Input and Output

| fstream-Specific Operations |
| --------------------------- |
| `fstream fstrm`             |
| `fstream fstrm(s)`          |
| `fstream fstrm(s, mode)`    |
| `fstrm.open(s)`             |
| `fstrm.open(s, mode)`       |
| `fstrm.close()`             |
| `fstrm.is_open()`           |

### Using File Stream Objects

```cpp
ifstream in(ifile); // construct an ifstream and open the given file
ofstream out;       // output file stream that is not associated with any file
```

#### Using an `fstream` in Place of an `iostream&`

```cpp
ifstream input(argv[1]);   // open the file of sales transactions
ofstream output(argv[2]);  // open the output file
Sales_data total;          // variable to hold the running sum
if (read(input, total)) {  // read the first transaction
    Sales_data trans;      // variable to hold data for the next transaction
    while(read(input, trans)) {    // read the remaining transactions
        if (total.isbn() == trans.isbn()) //  check isbns
            total.combine(trans);  // update the running total
        else {
            print(output, total) << endl; //  print the results
            total = trans;         // process the next book
        }
    }
    print(output, total) << endl;  // print the last transaction
} else                             // there was no input
    cerr << "No data?!" << endl;
```

#### The `open` and `close` Members

```cpp
ifstream in(ifile); // construct an ifstreamand open the given file
ofstream out;  // output file stream that is not associated with any file
out.open(ifile + ".copy");  // open the specified file
```

```cpp
if (out)     // check that the open succeeded
    // the open succeeded, so we can use the file
```

```cpp
in.close();               // close the file
in.open(ifile + "2");     // open another file
```

#### Automatic Construction and Destruction

```cpp
// for each file passed to the program
for (auto p = argv + 1; p != argv + argc; ++p) {
    ifstream input(*p);   // create input and open the file
    if (input) {          // if the file is ok, ''process'' this file
        process(input);
    } else
        cerr << "couldn't open: " + string(*p);
} // input goes out of scope and is destroyed on each iteration
```

> When an `fstream` object goes out of scope, the file it is bound to is
> automatically closed.

### File Modes

| File Modes |
| ---------- |
| `in`       |
| `out`      |
| `app`      |
| `ate`      |
| `trunc`    |
| `binary`   |

* `out` may be set only for an `ofstream` or `fstream` object.
* `in` may be set only for an `ifstream` or `fstream` object.
* `trunc` may be set only when `out` is also specified.
* `app` mode may be specified so long as `trunc` is not. If `app` is specified,
  the file is always opened in `output` mode, even if out was not explicitly
  specified.
* By default, a file opened in `out` mode is truncated even if we do not
  specify `trunc`. To preserve the contents of a file opened with `out`, either
  we must also specify `in`, in which case the file is open for both input and
  output will cover using the same file for intput and output.
* The `ate` and `binary` modes may be specified on any file stream object type
  and in combination with any other file modes.

#### Opening a File in `out` Mode Discards Existing Data

```cpp
// file1 is truncated in each of these cases
ofstream out("file1");   // out and trunc are implicit
ofstream out2("file1", ofstream::out);   // trunc is implicit
ofstream out3("file1", ofstream::out | ofstream::trunc);
// to preserve the file's contents, we must explicitly specify app mode
ofstream app("file2", ofstream::app);   // out is implicit
ofstream app2("file2", ofstream::out | ofstream::app);
```

#### File Mode Is Determined Each Time `open` Is Called

The file mode of a given stream may change each time a file is opened:

```cpp
ofstream out;   // no file mode is set
out.open("scratchpad"); // mode implicitly out and trunc
out.close();    // close out so we can use it for a different file
out.open("precious", ofstream::app);  // mode is out and app
out.close();
```

> Any time open is called, the file mode is set, either explicitly or
> implicitly.  Whenever a mode is not specified, the default value is used.

## `string` Streams

| `stringstream`-Specific Operations |
| ---------------------------------- |
| `sstream strm`                     |
| `sstream strm(s)`                  |
| `strm.str()`                       |
| `strm.str(s)`                      |

### Using an `istringstream`

```cpp
// members are public by default; see § 7.2 (p. 268)
struct PersonInfo {
    string name;
    vector<string> phones;
};

string line, word;  // will hold a line and word from input, respectively
vector<PersonInfo> people; // will hold all the records from the input
// read the input a line at a time until cin hits end-of-file (or another error)
while (getline(cin, line)) {
    PersonInfo info;      // create an object to hold this record's data
    istringstream record(line); // bind record to the line we just read
    record >> info.name;  // read the name
    while (record >> word)        // read the phone numbers
        info.phones.push_back(word);  // and store them
    people.push_back(info); // append this record to people
}
```

### Using `ostringtreams`s

```cpp
for (const auto &entry : people) {    // for each entry in people
    ostringstream formatted, badNums; // objects created on each loop
    for (const auto &nums : entry.phones) { // for each number
        if (!valid(nums)) {
            badNums << " " << nums;  // string in badNums
        } else
            // ''writes'' to formatted's string
            formatted << " " << format(nums);
    }
    if (badNums.str().empty())      // there were no bad numbers
        os << entry.name << " "     // print the name
           << formatted.str() << endl; // and reformatted numbers
    else                   // otherwise, print the name and bad numbers
        cerr << "input error: " << entry.name
             << " invalid number(s) " << badNums.str() << endl;
}
```
