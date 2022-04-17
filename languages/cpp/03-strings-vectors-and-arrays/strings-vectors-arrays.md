[toc]

## Namespace `using` Declarations

```cpp
using namesapce::name;
```

```cpp
#include <iostream>
// using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
int main()
{
    int i;
    cin >> i;       // ok: cin is a synonym for std::cin
    cout << i;      // error: no using declaration; we must use the full name
    std::cout << i; // ok: explicitly use cout from namepsace std
    return 0;
}
```

#### A Separate `using` Declaration Is Required for Each Name

#### Headers Should Not Include `using` Declarations

#### A Note to the Reader

## Library `string` Type

```cpp
#include <string>
using std::string
```

### Defining and Initializing `string`s

| Ways to Initializing a `string` |
| ------------------------------- |
| `string s1`                     |
| `string s2(s1)`                 |
| `string s2 = s1`                |
| `string s3("value")`            |
| `string s3 = "value"`           |
| `string s4(n, 'c')`             |


```cpp
string s1;          // default initialization; s1 is the empty string
string s2 = s1;     // s2 is a copy of  s1
string s3 = "hiya"; // s3 is a copy of the string literal
string s1(10, 'c'); // s4 is cccccccccc
```

#### Direct and Copy Forms of Initialization

```cpp
string s5 = "hiya";  // copy initialization
string s6("hiya");   // direct initialization
string s7(10, 'c');  // direct initialization; s7 is cccccccccc
```

```cpp
string s8 = string(10, 'c'); // copy initialization; s8 is cccccccccc
// as if we had written
string temp(10, 'c'); // temp is cccccccccc
string s8 = temp;     // copy temp into s8
```

### Operations on `string`s

| `string` Operations |
| ------------------- |
| `os << s`           |
| `is >> s`           |
| `getline(is, s)`    |
| `s.empty()`         |
| `s.size()`          |
| `s[n]`              |
| `s1 + s2`           |
| `s1 = s2`           |
| `s1 == s2`          |
| `s1 != s2`          |
|`<`,`<=`,`>`,`>=`    |

#### Reading and Writing `string`s

```cpp
// Note: #include and using declarations must be added to compile this code
int main()
{
    string s;          // empty string
    cin >> s;          // read a whitespace-separated string into s
    cout << s << endl; // write s to the output
    return 0;
}
```

```cpp
string s1, s2;
cin >> s1 >> s2; // read first input into s1, second into s2
cout << s1 << s2 << endl; // write both strings
```

#### Reading an Unknown Number of `string`s

```cpp
int main()
{
    string word;
    while (cin >> word)       // read until end-of-file
        cout << word << endl; // write each word followed by a new line
    return 0;
}
```

#### Using `getline` to Read an Entire Line

```cpp
int main()
{
    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line))
        cout << line << endl;
    return 0;
}
```

#### The `string empty` and `size` Operation

```cpp
// read input a line at a time and discard blank lines
while (getline(cin, line))
    if (!line.empty())
        cout << line << endl;
```

```cpp
string line;
// read input a line at a time and print lines that are longer than 80 characters
while (getline(cin, line))
    if (line.size() > 80)
        cout << line << endl;
```

#### The `string::size_type` Type

```cpp
auto len = line.size();     // len has type string::size_type
```

#### Comparing `string`s

```cpp
string str = "Hello";
string phrase = "Hello World";
string slang  = "Hiya";
```

#### Assignment for `string`s

```cpp
string st1(10, 'c'), st2; // st1 is cccccccccc; st2 is an empty string
st1 = st2; // assignment: replace contents of st1 with a copy of st2
           // both st1 and st2 are now the empty string
```

#### Adding Two `string`s

```cpp
string s1  = "hello, ", s2 = "world\n";
string s3 = s1 + s2;   // s3 is hello, world\n
s1 += s2;   // equivalent to s1 = s1 + s2
```

#### Adding Literals and `string`s

```cpp
string s1 = "hello", s2 = "world"; // no punctuation in s1 or s2
string s3 = s1 + ", " + s2 + '\n';
```

```cpp
ick here to view code image
string s4 = s1 + ", ";           // ok: adding a string and a literal
string s5 = "hello" + ", ";      // error: no string operand
string s6 = s1 + ", " + "world"; // ok: each + has a string operand
string s7 = "hello" + ", " + s2; // error: can't add string literals
```

```cpp
string s6 = (s1 + ", ") + "world";
```

```cpp
string tmp = s1 + ", ";  // ok: + has a string operand
s6 = tmp + "world";      // ok: + has a string operand
```

```cpp
string s7 = ("hello" + ", ") + s2; // error: can't add string literals
```

### Dealing with the Character in a `string`

| `cctype` Functions |
| ------------------ |
| `isalnum(c)`       |
| `isalpha(c)`       |
| `iscntrl(c)`       |
| `isdigit(c)`       |
| `isgraph(c)`       |
| `islower(c)`       |
| `isprint(c)`       |
| `ispunct(c)`       |
| `isspace(c)`       |
| `isupper(c)`       |
| `isxdigit(c)`      |
| `tolower(c)`       |
| `toupper(c)`       |

#### Processing Every Character? Use Range-Based `for`

```cpp
for (declaration : expression)
    statement
```

```cpp
string str("some string");
// print the characters in str one character to a line
for (auto c : str)      // for every char in str
    cout << c << endl;  // print the current character followed by a newline
```

```cpp
string s("Hello World!!!");
// punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
decltype(s.size()) punct_cnt = 0;
// count the number of punctuation characters in s
for (auto c : s)        // for every char in s
    if (ispunct(c))     // if the character is punctuation
        ++punct_cnt;    // increment the punctuation counter
cout << punct_cnt
     << " punctuation characters in " << s << endl;
```

#### Using a Range `for` to Change the Characters in a `string`

```cpp
string s("Hello World!!!");
// convert s to uppercase
for (auto &c : s)   // for every char in s (note: c is a reference)
    c = toupper(c); // c is a reference, so the assignment changes the char in s
cout << s << endl;
```

```cpp
c = toupper(c); // c is a reference, so the assignment changes the char in s
```

#### Processing Only Some Characters?

> Subscripting an empty `string` is undefined

```cpp
if (!s.empty())            // make sure there's a character to print
    cout << s[0] << endl;  // print the first character in s
```

```cpp
string s("some string");
if (!s.empty())             // make sure there's a character in s[0]
    s[0] = toupper(s[0]);   // assign a new value to the first character in s
```

#### Using a Subscript for Iteration

```cpp
// process characters in s until we run out of characters or we hit a whitespace
for (decltype(s.size()) index = 0;
     index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]); // capitalize the current character
```

#### Using a Subscript for Random Acess

```cpp
const string hexdigits = "0123456789ABCDEF"; // possible hex digits
cout << "Enter a series of numbers between 0 and 15"
     << " separated by spaces. Hit ENTER when finished: "
     << endl;
string result;        // will hold the resulting hexify'd string
string::size_type n;  // hold numbers from the input
while (cin >> n)
    if (n < hexdigits.size())    // ignore invalid input
        result += hexdigits[n];  // fetch the indicated hex digit
cout << "Your hex number is: " << result << endl;
```

## Library `vector` Type

```cpp
#include <vector>
using std::vector;
```

```cpp
vector<int> ivec;             // ivec holds objects of type int
vector<Sales_item> Sales_vec; // holds Sales_items
vector<vector<string>> file;  // vector whose elements are vectors
```

### Defining and Initializing `vector`s

| Ways to Initialize a `vector` |
| ----------------------------- |
| `vector<T> v1`                |
| `vector<T> v2(v1)`            |
| `vector<T> v3(n, val)`        |
| `vector<T> v4(n)`             |
| `vector<T> v5{a,b,c...}`      |
| `vector<T> v5 = {a,b,c...}`   |

```cpp
vector<string> svec; // default initialization; svec has no elements

vector<int> ivec;             // initially empty
// give ivec some values
vector<int> ivec2(ivec);      // copy elements of ivec into ivec2
vector<int> ivec3 = ivec;     // copy elements of ivec into ivec3
vector<string> svec(ivec2);   // error: svec holds strings, not ints
```

#### List Initializing a `vector`

```cpp
vector<string> articles = {"a", "an", "the"};
```

```cpp
vector<string> v1{"a", "an", "the"};  // list initialization
vector<string> v2("a", "an", "the");  // error

vector<int> ivec(10, -1);       // ten int elements, each initialized to - 1
vector<string> svec(10, "hi!"); // ten strings; each element is "hi!"
```

#### Value Initialization

```cpp
vector<int> ivec(10);    // ten elements, each initialized to 0
vector<string> svec(10); // ten elements, each an empty string
```

```cpp
vector<int> vi = 10;    // error: must use direct initialization to supply a size
```

#### List Initialization or Element Count?

```cpp
k here to view code image
vector<int> v1(10);    // v1 has ten elements with value 0
vector<int> v2{10};    // v2 has one element with value 10
vector<int> v3(10, 1); // v3 has ten elements with value 1
vector<int> v4{10, 1}; // v4 has two elements with values 10 and 1
```

> If we use braces and there is no way to use the initializers to list
> initialize the object,

```cpp
vector<string> v5{"hi"}; // list initialization: v5 has one element
vector<string> v6("hi"); // error: can't construct a vector from a string literal
vector<string> v7{10};       // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```

### Adding Elements to a `vector`

```cpp
vector<int> v2;        // empty vector
for (int i = 0; i != 100; ++i)
    v2.push_back(i);    // append sequential integers to v2
// at end of loop v2 has 100 elements, values 0 ... 99
```

```cpp
// read words from the standard input and store them as elements in a vector
string word;
vector<string> text;       // empty vector
while (cin >> word) {
    text.push_back(word);  // append word to text
}
```

#### Programming Implications of Adding Elements to a vector

> The body of a range for must not change the size of the sequence over which
> it is iterating.

### Other `vector` Operations

| `vector` Operations |
| ------------------- |
| `v.empty()`         |
| `v.size()`          |
| `v[n]`              |
| `v1 = v2`           |
| `v1 = {a,b,c...}`   |
| `v1 == v2;`         |
| `v1 != v2`          |
| `<`,`<=`,`>`,`>=`   |

```cpp
vector<int> v{1,2,3,4,5,6,7,8,9};
for (auto &i : v)     // for each element in v (note: i is a reference)
    i *= i;           // square the element value
for (auto i : v)      // for each element in v
    cout << i << " "; // print the element
cout << endl;
```

#### Computing a `vector` Index

```cpp
// count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
unsigned grade;
while (cin >> grade) {      // read the grades
    if (grade <= 100)       // handle only valid grades
        ++scores[grade/10]; // increment the counter for the current cluster
}
```

#### Subscripting Does Not Add Elements

```cpp
vector<int> ivec;   // empty vector
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec[ix] = ix;  // disaster: ivec has no elements
```

```cpp
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
    ivec.push_back(ix);  // ok: adds a new element with value ix
```

## Introducing Iterators

### Using Iterators

```cpp
// the compiler determines the type of b and e; see § 2.5.2 (p. 68)
// b denotes the first element and e denotes one past the last element in v
auto b = v.begin(), e = v.end(); // b and e have the same type
```

> If the container is empty, `begin` returns the same iterator as the one
> returned by `end`.

#### Iterators Operations

| Standard Container Iterator Operations |
| -------------------------------------- |
| `*iter`                                |
| `iter->mem`                            |
| `++iter`                               |
| `--iter`                               |
| `iter1 == iter2`                       |
| `iter1 != iter2`                       |

```cpp
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
    auto it = s.begin();    // it denotes the first character in s
    *it = toupper(*it);     // make that character uppercase
}
```

#### Moving Iterators from One Element to Another

> Because the iterator returned from end does not denote an element, it may not
> be incremented or dereferenced.

```cpp
// process characters in s until we run out of characters or we hit a whitespace
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
    *it = toupper(*it); // capitalize the current character
```

#### Iterator Types

```cpp
vector<int>::iterator it; // it can read and write vector<int> elements
string::iterator it2;     // it2 can read and write characters in a string
vector<int>::const_iterator it3; // it3 can read but not write elements
string::const_iterator it4;      // it4 can read but not write characters
```

#### The begin and end Operations

```cpp
vector<int> v;
const vector<int> cv;
auto it1 = v.begin();  // it1 has type vector<int>::iterator
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
```

```cpp
auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator
```

#### Combining Dereference and Member Access

```cpp
(*it).empty() // dereferences it and calls the member empty on the resulting
object
*it.empty()   // error: attempts to fetch the member named empty from it
              //     but it is an iterator and has no member named empty
```

```cpp
for (auto it = text.cbegin();
     it != text.cend() && !it->empty(); ++it)
    cout << *it << endl;
```

#### Some vector Operations Invalidate Iterators

### Iterator Arithmetic

| Operations Supported by `vector` and `string` Iterators |
| ------------------------------------------------------- |
| `iter + n`                                              |
| `iter - n`                                              |
| `iter += n`                                             |
| `iter -= n`                                             |
| `iter1 - iter2`                                         |
| `<`,`<=`,`>`,`>=`                                       |

#### Arithmetic Operations on Iterators

```cpp
// compute an iterator to the element closest to the midpoint of vi
auto mid = vi.begin() + vi.size() / 2;
```

> When we add or subtract an integral value and an iterator, the result must
> denote an element in the same vector (or string) or denote one past the end
> of the associated vector (or string).

```cpp
if (it < mid)
    // process elements in the first half of vi
```

#### Using Iterator Arithmetic

```cpp
// text must be sorted
// beg and end will denote the range we're searching
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end - beg)/2; // original midpoint
// while there are still elements to look at and we haven't yet found sought
while (mid != end && *mid != sought) {
    if (sought < *mid)     // is the element we want in the first half?
        end = mid;         // if so, adjust the range to ignore the second half
    else                   // the element we want is in the second half
        beg = mid + 1;     // start looking with the element just after mid
    mid = beg + (end - beg)/2;  // new midpoint
}
```

## Arrays

> Because arrays have fixed size, they sometimes offer better run-time
> performance for specialized applications.

### Defining and Initializing Built-in Arrays

```cpp
unsigned cnt = 42;          // not a constant expression
constexpr unsigned sz = 42; // constant expression
                            // constexpr see § 2.4.4 (p. 66)
int arr[10];             // array of ten ints
int *parr[sz];           // array of 42 pointers to int
string bad[cnt];         // error: cnt is not a constant expression
string strs[get_size()]; // ok if get_size is constexpr, error otherwise
```

#### Explicitly Initializing Array Elements

```cpp
const unsigned sz = 3;
int ia1[sz] = {0,1,2};        // array of three ints with values 0, 1, 2
int a2[] = {0, 1, 2};         // an array of dimension 3            
int a3[5] = {0, 1, 2};        // equivalent to a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"}; // same as a4[] =  {"hi", "bye", ""}
int a5[2] = {0,1,2};          // error: too many initializers
```

> If the dimension is greater than the number of initializers, the initializers
> are used for the first elements and any remaining elements are value
> initialized.

#### Character Arrays Are Special

Character arrays can be initialized from a string literal:

```cpp
char a1[] = {'C', '+', '+'};       // list initialization, no null
char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
char a3[] = "C++";                 // null terminator added automatically
const char a4[6] = "Daniel";       // error: no space for the null!
```

#### No Copy or Assignment

```cpp
int a[] = {0, 1, 2}; // array of three ints
int a2[] = a;        // error: cannot initialize one array with another
a2 = a;              // error: cannot assign one array to another
```

#### Understanding Complicated Array Declarations

```cpp
int *ptrs[10];            //  ptrs is an array of ten pointers to int
int &refs[10] = /* ? */;  //  error: no arrays of references
int (*Parray)[10] = &arr; //  Parray points to an array of ten ints
int (&arrRef)[10] = arr;  //  arrRef refers to an array of ten ints
```

### Acessing the Elements of an Array

```cpp
// count the number of grades by clusters of ten: 0--9, 10--19, ... 90--99, 100
unsigned scores[11] = {}; // 11 buckets, all value initialized to 0
unsigned grade;
while (cin >> grade) {
    if (grade <= 100)
        ++scores[grade/10]; // increment the counter for the current cluster
}
```

```cpp
for (auto i : scores)      // for each counter in scores
    cout << i << " ";      // print the value of that counter
cout << endl;
```

#### Checking Subscript Values

### Pointers and Arrays

> When we use an array, the compiler ordinarily converts the array to a
> pointer, —in most places when we use an array, the compiler automatically
> substitutes a pointer to the first element:

```cpp
string nums[] = {"one", "two", "three"};  // array of strings
string *p = &nums[0];   // p points to the first element in nums

string *p2 = nums;      // equivalent to p2 = &nums[0]
```

One such implication is that when we use an array as an initializer for a
variable defined using `auto`, the deduced type is a pointer, not an array:

```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
auto ia2(ia); // ia2 is an int* that points to the first element in ia
ia2 = 42;     // error: ia2 is a pointer, and we can't assign an int to a pointer
```

```cpp
auto ia2(&ia[0]);  // now it's clear that ia2 has type int*
```

Not for `decltype`

```cpp
// ia3 is an array of ten ints
decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};
ia3 = p;    // error: can't assign an int* to an array
ia3[4] = i; // ok: assigns the value of i to an element in ia3
```

#### Pointers Are Iterators

```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int *p = arr; // p points to the first element in arr
++p;          // p points to arr[1]

int *e = &arr[10]; // pointer just past the last element in arr
```

#### The Library `begin` and `end` Functions

```cpp
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
int *beg = begin(ia); // pointer to the first element in ia
int *last = end(ia);  // pointer one past the last element in ia
```

```cpp
// pbeg points to the first and pend points just past the last element in arr
int *pbeg = begin(arr),  *pend = end(arr);
// find the first negative element, stopping if we've seen all the elements
while (pbeg != pend && *pbeg >= 0)
    ++pbeg;
```

#### Pointer Arithmetic

```cpp
constexpr size_t sz = 5;
int arr[sz] = {1,2,3,4,5};
int *ip = arr;     // equivalent to int *ip = &arr[0]
int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr
```

```cpp
// ok: arr is converted to a pointer to its first element; p points one past the end of
arr
int *p = arr + sz; // use caution -- do not dereference!
int *p2 = arr + 10; // error: arr has only 5 elements; p2 has undefined value
```

```cpp
auto n = end(arr) - begin(arr); // n is 5, the number of elements in arr
```

> The result of subtracting two pointers is a library type named `ptrdiff_t`.

```cpp
int *b = arr, *e = arr + sz;
while (b < e) {
    // use *b
    ++b;
}
```

```cpp
int i = 0, sz = 42;
int *p = &i, *e = &sz;
// undefined: p and e are unrelated; comparison is meaningless!
while (p < e)
```

> Pointer arithmetic is also valid for null pointers and for pointers that
> point to an object that is not an array. In the latter case, the pointers
> must point to the same object, or one past that object. If p is a null
> pointer, we can add or subtract an integral constant expression whose value
> is 0 to p. We can also subtract two null pointers from one another, in which
> case the result is 0.

#### Interaction between Dereference and Pointer Arithmetic

```cpp
int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
int last = *(ia + 4); // ok: initializes last to 8, the value of ia[4]

last = *ia = 4;     // ok: last = 4, equivalent to ia[0] + 4
```

#### Subscripts and Pointers

When we subscript an array, we are really subscripting a pointer to an element
in that array:

```cpp
int ia[] = {0,2,4,6,8};  // array with 5 elements of type int

int i = ia[2];  // ia is converted to a pointer to the first element in ia
                // ia[2] fetches the element to which (ia + 2) points
int *p = ia;    // p points to the first element in ia
i = *(p + 2);   // equivalent to i = ia[2]
```

> Unlike subscripts for vector and string, the index of the built-in subscript
> operator is not an unsigned type.

### C-Style Character Strings

#### C Library String Function

| C-style Character String Functions |
| ---------------------------------- |
| `strlen(p)`                        |
| `strcmp(p1, p2)`                   |
| `strcat(p1, p2)`                   |
| `strcpy(p1, p2)`                   |

```cpp
char ca[] = {'C', '+', '+'};  // not null terminated
cout << strlen(ca) << endl;   // disaster: ca isn't null terminated
```

#### Comparing Strings

```cpp
string s1 = "A string example";
string s2 = "A different string";
if (s1 < s2)  // false: s2 is less than s1

const char ca1[] = "A string example";
const char ca2[] = "A different string";
if (ca1 < ca2)  // undefined: compares two unrelated addresses
```

```cpp
if (strcmp(ca1, ca2) < 0) // same effect as string comparison s1 < s2
```

#### Caller Is Responsible for Size of a Destination String

```cpp
// initialize largeStr as a concatenation of s1, a space, and s2
string largeStr = s1 + " " + s2;
```

```cpp
// disastrous if we miscalculated the size of largeStr
strcpy(largeStr, ca1);     // copies ca1 into largeStr
strcat(largeStr, " ");     // adds a space at the end of largeStr
strcat(largeStr, ca2);     // concatenates ca2 onto largeStr
```

### Interfacing to Older Code

#### Mixing Library `strings` and C-Style Strings

```cpp
string s("Hello World");  // s holds Hello World
```

> More generally, we can use a null-terminated character array anywhere that we
> can use a string literal, while the reverse functionality is not provided.

```cpp
char *str = s; // error: can't initialize a char* from a string
const char *str = s.c_str(); // ok
```

* The array returned by `c_str` is not guaranteed to be valid indefinitely. Any
  subsequent use of `s` that might change the value of `s` can invalidate this
  array.

> If a program needs continuing access to the contents of the array returned by
> `str()`, the program must copy the array returned by `c_str`.

#### Using an Array to Initialize a `Vector`

```cpp
int int_arr[] = {0, 1, 2, 3, 4, 5};
// ivec has six elements; each is a copy of the corresponding element in int_arr
vector<int> ivec(begin(int_arr), end(int_arr));
```

```cpp
// copies three elements: int_arr[1], int_arr[2], int_arr[3]
vector<int> subVec(int_arr + 1, int_arr + 4);
```

## Multidimensional Arrays

```cpp
int ia[3][4]; // array of size 3; each element is an array of ints of size 4
// array of size 10; each element is a 20-element array whose elements are arrays of 30 ints
int arr[10][20][30] = {0}; // initialize all elements to 0
```

#### Initializing the Elements of a Multidimensional Array

```cpp
int ia[3][4] = {    // three elements; each element is an array of size 4
    {0, 1, 2, 3},   // initializers for the row indexed by 0
    {4, 5, 6, 7},   // initializers for the row indexed by 1
    {8, 9, 10, 11}  // initializers for the row indexed by 2
};                     The nested braces are optional. The following initialization is equivalent, although
```

```cpp
// equivalent initialization without the optional nested braces for each row
int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
```

```cpp
// explicitly initialize only element 0 in each row
int ia[3][4] = {{ 0 }, { 4 }, { 8 }};
```

```cpp
// explicitly initialize row 0; the remaining elements are value initialized
int ix[3][4] = {0, 3, 6, 9};
```

#### Subscripting a Multidimensional Array

```cpp
// assigns the first element of arr to the last element in the last row of ia
ia[2][3] = arr[0][0][0];
int (&row)[4] = ia[1]; // binds row to the second four-element array in ia
```

```cpp
constexpr size_t rowCnt = 3, colCnt = 4;
int ia[rowCnt][colCnt];   // 12 uninitialized elements
// for each row
for (size_t i = 0; i != rowCnt; ++i) {
    // for each column within the row
    for (size_t j = 0; j != colCnt; ++j) {
        // assign the element's positional index as its value
        ia[i][j] = i * colCnt + j;
    }
}
```

#### Using a Range `for` with Multidimensional Arrays

```cpp
size_t cnt = 0;
for (auto &row : ia)        // for every element in the outer array
    for (auto &col : row) { // for every element in the inner array
        col = cnt;          // give this element the next value
        ++cnt;              // increment cnt
    }
```

To avoid the normal array to pointer conversion:

```cpp
for (const auto &row : ia)  // for every element in the outer array
    for (auto col : row)    // for every element in the inner array
        cout << col << endl;

for (auto row : ia)
    for (auto col : row)
```


> To use a multidimensional array in a range for, the loop control variable for
> all but the innermost array must be references.

#### Pointers and Multidimensional Arrays

```cpp
int ia[3][4];     // array of size 3; each element is an array of ints of size 4
int (*p)[4] = ia; // p points to an array of four ints
p = &ia[2];       // p now points to the last element in ia
```

```cpp
// print the value of each element in ia, with each inner array on its own line
// p points to an array of four ints
for (auto p = ia; p != ia + 3; ++p) {
    // q points to the first element of an array of four ints; that is, q points to an int
    for (auto q = *p; q != *p + 4; ++q)
         cout << *q << ' ';
    cout << endl;
}
```

```cpp
   // p points to the first array in ia
   for (auto p = begin(ia); p != end(ia); ++p) {
       // q points to the first element in an inner array
       for (auto q = begin(*p); q != end(*p); ++q)
           cout << *q << ' ';   // prints the int value to which q points
   cout << endl;
}
```

#### Type Aliases Simplify Pointers to Multidimensional Arrays

```cpp
using int_array = int[4]; // new style type alias declaration; see § 2.5.1 (p.
68)
typedef int int_array[4]; // equivalent typedef declaration; § 2.5.1 (p. 67)
// print the value of each element in ia, with each inner array on its own line
for (int_array *p = ia; p != ia + 3; ++p) {
    for (int *q = *p; q != *p + 4; ++q)
         cout << *q << ' ';
    cout << endl;
}
```
