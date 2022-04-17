## Overview of the Sequential Containers

### Deciding Which Sequential Container to Use

## Container Library Overview

Operations provided by all containers types:

| Type Aliases      |
|-------------------|
| `iterator`        |
| `const_iterator`  |
| `size_type`       |
| `difference_type` |
| `value_type`      |
| `reference`       |
| `const_reference` |

| Construction      |
|-------------------|
| `C c;`            |
| `C c1(c2);`       |
| `C c(b, e);`      |
| `C c{a,b,c,...};` |

| Assignment and `swap` |
|-----------------------|
| `c1 = c2`             |
| `c1 = {a,b,c,...}`    |
| `a.swap(b)`           |
| `swap(a, b)`          |

| Size           |
|----------------|
| `c.size()`     |
| `c.max_size()` |
| `c.empty()`    |

| Add/Remove Elements (not valid for array) |
|-------------------------------------------|
| `c.insert(args)`                          |
| `c.emplace(inits)`                        |
| `c.erase()`                               |
| `c.clear()`                               |

| Equality and Relational Operators |                                                 |
|-----------------------------------|-------------------------------------------------|
| `==`, `!=`                        | Valid for all containers types                  |
| `<`, `<=`, `>`, `>=`              | Not valid for unordered associative containers) |

| Obtain Iterators         |
|--------------------------|
| `c.begin()`, `c.end()`   |
| `c.cbegin()`, `c.cend()` |

| Additional Members of Reversible Containers (not valid for `forward_list`) |
|----------------------------------------------------------------------------|
| `reverse_iterator`                                                         |
| `const_reverse_iterator`                                                   |
| `c.rbegin()`, `c.rend()`                                                   |
| `c.crbegin()`, `c.crend()`                                                 |

-------------------------------------------------------------------------------

Other operations are specific to the sequential, the associative, or the
unordered containers: 

| Defining and Initializing Containers |
|--------------------------------------|
| `C c;`                               |
| `C c1(c2);`                          |
| `C c1 = c2;`                         |
| `C c{a,b,c,...};`                    |
| `C c = {a,b,c,...};`                 |
| `C c(b, e);`                         |

Constructors that take a size are valid for sequential containers (not
including `array`) only:

| Defining and Initializing Containers |
|--------------------------------------|
| `C seq(n)`                           |
| `C seq(n, t)`                        |

```cpp
list<Sales_data>    // list that holds Sales_data objects
deque<double>       // deque that holds doubles
```

### Constraints on Types That a Container Can Hold

```cpp
vector<vector<string>> lines;   // vector of vectors
```

```cpp
// assume noDefault is a type without a default constructor
vector<noDefault> v1(10, init); // ok: element initializer supplied
vector<noDefault> v2(10);       // error: must supply an element initializer
```

## Iterators

### Iterators Ranges

```
[begin, end)
```

### Programming Implications of Using Left-Inclusive Ranges

```cpp
while (begin != end) {
    *begin = val;   // ok: range isn't empty so begin denotes an element
    ++begin;        // advance the iterator to get the next element
}
```

## Container Type Members

```cpp
// iter is the iterator type defined by list<string>
list<string>::iterator iter;
// count is the difference_type type defined by vector<int>
vector<int>::difference_type count;
```

## `begin` and `end` Members

```cpp
list<string> a = {"Milton", "Shakespeare", "Austen"};
auto it1 = a.begin();   // list<string>::iterator
auto it2 = a.rbegin();  // list<string>::reverse_iterator
auto it3 = a.cbegin();  // list<string>::const_iterator
auto it4 = a.crbegin(); // list<string>::const_reverse_iterator
```

```cpp
// type is explicitly specified
list<string>::iterator it5 = a.begin();
list<string>::const_iterator it6 = a.begin();
// iterator or const_iterator depending on a's type of a
auto it7 = a.begin(); // const_iterator only if a is const
auto it8 = a.cbegin(); // it8 is const_iterator
```

## Defining and Initializing a Container

### Initializing a Container as a Copy of Another Container

```cpp
// each container has three elements, initialized from the given initializers
list<string> authors = {"Milton", "Shakespeare", "Austen"};
vector<const char*> articles = {"a", "an", "the"};
list<string> list2(authors);        // ok: types match
deque<string> authList(authors);    // error: container types don't match
vector<string> words(articles);     // error: element types must match
// ok: converts const char* elements to string
forward_list<string> words(articles.begin(), articles.end());
```

```cpp
// copies up to but not including the element denoted by it
deque<string> authList(authors.begin(), it);
```

### List Initialization

```cpp
// each container has three elements, initialized from the given initializers
list<string> authors = {"Milton", "Shakespeare", "Austen"};
vector<const char*> articles = {"a", "an", "the"};
```

### Sequential Container Size-Related Constructors

```cpp
vector<int> ivec(10, -1);       // ten int elements, each initialized to -1
list<string> svec(10, "hi!");   // ten strings; each element is "hi!"
forward_list<int> ivec(10);     // ten elements, each initialized to 0
deque<string> svec(10);         // ten elements, each an empty string
```

> The constructors that take a size are valid only for sequential containers;
> they are not supported for the associative containers.

### Library `array`s Have Fixed Size

```cpp
array<int, 42>      // type is: array that holds 42 ints
array<string, 10>   // type is: array that holds 10 strings
```

```cpp
array<int, 10>::size_type i;    // array type includes element type and size
array<int>::size_type j;        // error: array<int> is not a type
```

```cpp
array<int, 10> ia1;     // ten default-initialized ints
array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9};     // list initialization
array<int, 10> ia3 = {42};  // ia3[0] is 42, remaining elements are 0
```

```cpp
int digs[10] = {0,1,2,3,4,5,6,7,8,9};
int cpy[10] = digs;     // error: no copy or assignment for built-in arrays

array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9};
array<int, 10> copy = digits;   // ok: so long as array types match
```

## Assignment and `swap`

```cpp
c1 = c2;        // replace the contents of c1 with a copy of the elements in c2
c1 = {a,b,c};   // after the assignment c1 has size 3
```

| Container Assignment Operations |
| ------------------------------- |
| `c1 = c2`                       |
| `c = {a, b, c}`                 |
| `swap(c1, c2)`                  |
| `c1.swap(c2)`                   |
| `seq.assign(b, e)`              |
| `seq.assign(il)`                |
| `seq.assign(n, t)`              |

> If the containers had been of unequal size, after the assignment both
> containers would have the size of the right-hand operand.

```cpp
array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
array<int, 10> a2 = {0};    // elements all have value 0

a1 = a2;    // replaces elements in a1
a2 = {0};   // error: cannot assign to an array from a braced list
```

### Using `assign` (Sequential Containers Only)

```cpp
list<string> names;
vector<const char*> oldstyle;

names = oldstyle;   // error: container types don't match

// ok: can convert from const char* to string
names.assign(oldstyle.cbegin(), oldstyle.cend());
```

```cpp
// equivalent to slist1.clear();
// followed by slist1.insert(slist1.begin(), 10, "Hiya!");
list<string> slist1(1);     // one element, which is the empty string
slist1.assign(10, "Hiya!"); // ten elements; each one is Hiya !
```

### Using `swap`

```cpp
vector<string> svec1(10); // vector with ten elements
vector<string> svec2(24); // vector with 24 elements
swap(svec1, svec2);
```

> Excepting `array`, swap does not copy, delete, or insert any elements and is
> guaranteed to run in constant time.

> Differently from the containers, a call to `swap` on a string may invalidate
> iterators, references and pointers.

## Container Size Operations

> `forward_list` provides `max_size` and `empty`, but not `size`.

## Relational Operators

```cpp
vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
vector<int> v2 = { 1, 3, 9 };
vector<int> v3 = { 1, 3, 5, 7 };
vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

v1 < v2     // true; v1 and v2 differ at element [2]: v1[2] is less than v2[2]
v1 < v3     // false; all elements are equal, but v3 has fewer of them;
v1 == v4    // true; each element is equal and v1 and v4 have the same size()
v1 == v2    // false; v2 has fewer elements than v1
```

### Relational Operators Use Their Element’s Relational Operator

```cpp
vector<Sales_data> storeA, storeB;
if (storeA < storeB) // error: Sales_data has no less-than operato
```

## Adding Elements to a Sequential Container


| Add Operations          |
| ----------------------- |
| `c.push_back(t)`        |
| `c.emplace_back(args)`  |
| `c.push_front(t)`       |
| `c.emplace_front(args)` |
| `c.insert(p, t)`        |
| `c.emplace(p, args)`    |
| `c.insert(p, n, t)`     |
| `c.insert(p, b, e)`     |
| `c.insert(p, il)`       |

> Adding elements to a `vector`, `string`, or `deque` potentially invalid all
> existing iterators, reference, and pointers in to the container.

### Using `push_back`

```cpp
// read from standard input, putting each word onto the end of container
string word;

while (cin >> word)
    container.push_back(word);
```

```cpp
void pluralize(size_t cnt, string &word)
{
    if (cnt > 1)
        word.push_back('s');    // same as word += 's'
}
```

> Key Concept: Container Elements Are Copies.

### Using `push_front`

```cpp
list<int> ilist;
// add elements to the start of ilist
for (size_t ix = 0; ix != 4; ++ix)
    ilist.push_front(ix);
```

### Adding Elements at a Specified Point in the Container

```cpp
slist.insert(iter, "Hello!"); // insert "Hello!" just before iter
```

```cpp
vector<string> svec;
list<string> slist;

// equivalent to calling slist.push_front("Hello!");
slist.insert(slist.begin(), "Hello!");
// no push_front on vector but we can insert before begin()
// warning: inserting anywhere but at the end of a vector might be slow
svec.insert(svec.begin(), "Hello!");
```

> It is legal to insert anywhere in a `vector`, `deque`, or `string`. However,
> doing so can be an expensive operation.

### Inserting a Range of Elements

```cpp
svec.insert(svec.end(), 10, "Anna");
```

```cpp
vector<string> v = {"quasi", "simba", "frollo", "scar"};

// insert the last two elements of v at the beginning of slist
slist.insert(slist.begin(), v.end() - 2, v.end());
slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
// run-time error: iterators denoting the range to copy from
// must not refer to the same container as the one we are changing
slist.insert(slist.begin(), slist.begin(), slist.end());
```

* The versions of insert that take a count or a range return an iterator to the
  *first element* that was inserted. If the range is empty, no elements are
  inserted, and the operation returns its *first parameter*.

### Using the Return from `insert`

```cpp
list<string> 1st;
auto iter = 1st.begin();
while (cin >> word)
    iter = 1st.insert(iter, word); // same as calling push_front
```

### Using the Emplace Operations

```cpp
// construct a Sales_data object at the end of c
// uses the three-argument Sales_data constructor
c.emplace_back("978-0590353403", 25, 15.99);
// error: there is no version of push_back that takes three arguments
c.push_back("978-0590353403", 25, 15.99);
// ok: we create a temporary Sales_data object to pass to push_back
c.push_back(Sales_data("978-0590353403", 25, 15.99));
```

```cpp
// iter refers to an element in c, which holds Sales_data elements
c.emplace_back(); // uses the Sales_data default constructor
c.emplace(iter, "999-999999999"); // uses Sales_data(string)
// uses the Sales_data constructor that takes an ISBN, a count, and a price
c.emplace_front("978-0590353403", 25, 15.99);
```

## Accessing Elements

| Accessing Elements Operations |
| ----------------------------- |
| `c.back()`                    |
| `c.front()`                   |
| `c[n]`                        |
| `c.at(n)`                     |

```cpp
// check that there are elements before dereferencing an iterator or calling front or back
if (!c.empty()) {
    // val and val2 are copies of the value of the first element in c
    auto val = *c.begin(), val2 = c.front();
    // val3 and val4 are copies of the of the last element in c
    auto last = c.end();
    auto val3 = *(--last);  // can't decrement forward_list iterators
    auto val4 = c.back();   // not supported by forward_list
}
```

### The Access Members Return References

```cpp
if (!c.empty()) {
    c.front() = 42;         // assigns 42 to the first element in c
    auto &v = c.back();     // get a reference to the last element
    v = 1024;               // changes the element in c
    auto v2 = c.back();     // v2 is not a reference; it's a copy of c.back()
    v2 = 0;                 // no change to the element in c
}
```

### Subscripting and Safe Random Access

```cpp
vector<string> svec;    // empty vector
cout << svec[0];        // run-time error: there are no elements in svec!
cout << svec.at(0);     // throws an out_of_range exception
```

## Erasing Elements

| Erase Operations |
| ---------------- |
| `c.pop_back()`   |
| `c.pop_front()`  |
| `c.erase(p)`     |
| `c.erase(b, e)`  |
| `c.clear()`      |

### The `pop_front` and `pop_back` Members

```cpp
while (!ilist.empty()) {
    process(ilist.front()); // do something with the current top of ilist
    ilist.pop_front();      // done; remove the first element
}
```

### Removing an Element from within the Container

```cpp
list<int> lst = {0,1,2,3,4,5,6,7,8,9};
auto it = lst.begin();
while (it != lst.end())
    if (*it % 2)            // if the element is odd
        it = lst.erase(it);     // erase this element
    else
        ++it;
```

> Both forms of `erase` return an iterator referring to the location after the
> (last) element that was removed.

### Removing Multiple Elements

```cpp
// delete the range of elements between two iterators
// returns an iterator to the element just after the last removed element
elem1 = slist.erase(elem1, elem2);      // after the call elem1 == elem2
```

```cpp
slist.clear();  // delete all the elements within the container
slist.erase(slist.begin(), slist.end()); // equivalent
```

## Specialized `forward_list` Operations

| Insert or Remove Operations  |
| ---------------------------- |
| `lst.before_begin()`         |
| `lst.cbefore_begin()`        |
| `lst.insert_after(p, t)`     |
| `lst.insert_after(p, n, t)`  |
| `lst.insert_after(p, b, e)`  |
| `lst.insert_after(p, il)`    |
| `lst.emplace_after(p, args)` |
| `lst.erase_after(p)`         |
| `lst.erase_after(b, e)`      |

```cpp
forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
auto prev = flst.before_begin();    // denotes element "off the start" of flst
auto curr = flst.begin();           // denotes the first element in flst

while (curr != flst.end()) { // while there are still elements to process
    if (*curr % 2)      // if the element is odd
        curr = flst.erase_after(prev);  // erase it and move curr
    else {
        prev = curr;    // move the iterators to denote the next
        ++curr;         // element and one before the next element
    }
}
```

## Resizing a Container

| Size Operations  |
| ---------------- |
| `c.resize(n)`    |
| `c.resize(n, t)` |

> If `resize` shrinks the container, then iterators, references, and pointers
> to the deleted element are invalidated; `resize` on a `vector`, `string`, or
> `deque` potentially invalidates all iterators, pointers, and references.

```cpp
list<int> ilist(10, 42);    // ten ints: each has value 42
ilist.resize(15);           // adds five elements of value 0 to the back of ilist
ilist.resize(25, -1);       // adds ten elements of value -1 to the back of ilist
ilist.resize(5);            // erases 20 elements from the back of ilist
```

## Container Operations May Invalidate Iterators

### Writing Loops That Changea Container

```cpp
// silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
while (iter != vi.end()) {
    if (*iter % 2) {
        iter = vi.insert(iter, *iter); // duplicate the current element
        iter += 2; // advance past this element and the one inserted before it
    } else
        iter = vi.erase(iter); // remove even elements
        // don't advance the iterator; iter denotes the element after the one we erased
}
```

### Avoid Storing the Iterator Returned from end

```cpp
// disaster: the behavior of this loop is undefined
auto begin = v.begin(),
     end = v.end(); // bad idea, saving the value of the end iterator
while (begin != end) {
    // do some processing
    // insert the new value and reassign begin, which otherwise would be invalid
    ++begin; // advance begin because we want to insert after this element
    begin = v.insert(begin, 42); // insert the new value
    ++begin; // advance begin past the element we just added
}
```

```cpp
// safer: recalculate end on each trip whenever the loop adds/erases elements
while (begin != v.end()) {
    // do some processing
    ++begin; // advance begin because we want to insert after this element
    begin = v.insert(begin, 42); // insert the new value
    ++begin; // advance begin past the element we just added
}
```

### Members to Change Capacity

| Container Size Management |
| ------------------------- |
| `c.shrink_to_fit()`       |
| `c.capacity()`            |
| `c.reserve()`             |

### `capacity` and `size`

```cpp
vector<int> ivec;
// size should be zero; capacity is implementation defined
cout << "ivec: size: " << ivec.size()
     << " capacity: "  << ivec.capacity() << endl;
// give ivec 24 elements
for (vector<int>::size_type ix = 0; ix != 24; ++ix)
    ivec.push_back(ix);
// size should be 24; capacity will be >= 24 and is implementation defined
cout << "ivec: size: " << ivec.size()
     << " capacity: "  << ivec.capacity() << endl;
ivec.reserve(50); // sets capacity to at least 50; might be more
// size should be 24; capacity will be >= 50 and is implementation defined
cout << "ivec: size: " << ivec.size()
     << " capacity: "  << ivec.capacity() << endl;
// add elements to use up the excess capacity
while (ivec.size() != ivec.capacity())
    ivec.push_back(0);
// capacity should be unchanged and size and capacity are now equal
cout << "ivec: size: " << ivec.size()
     << " capacity: "  << ivec.capacity() << endl;
ivec.push_back(42); // add one more element
// size should be 51; capacity will be >= 51 and is implementation defined
cout << "ivec: size: " << ivec.size()
     << " capacity: "  << ivec.capacity() << endl;
ivec.shrink_to_fit(); // ask for the memory to be returned
// size should be unchanged; capacity is implementation defined
cout << "ivec: size: " << ivec.size()
     << " capacity: "  << ivec.capacity() << endl;
```

> Calling `shrink_to_fit` is only a request; there is no guarantee that the
> library will return the memory.

> Each `vector` implementation can choose its own allocation strategy. However,
> it must not allocate new memory until it is forced to do so.

## Other Ways to Construct `string`s

| Additional Ways to Construct `string`s |
| -------------------------------------- |
| `string s(cp, n)`                      |
| `string s(s2, pos2)`                   |
| `string s(s2, pos2, len2)`             |

```
const char *cp = "Hello World!!!"; // null-terminated array
char noNull[] = {'H', 'i'};         // not null terminated
string s1(cp);          // copy up to the null in cp; s1 == "Hello World!!!"
string s2(noNull,2);    // copy two characters from no_null; s2 == "Hi"
string s3(noNull);      // undefined: noNull not null terminated
string s4(cp + 6, 5);   // copy 5 characters starting at cp[6]; s4 == "World"
string s5(s1, 6, 5);    // copy 5 characters starting at s1[6]; s5 == "World"
string s6(s1, 6);       // copy from s1 [6] to end of s1; s6 == "World!!!"
string s7(s1,6,20);     // ok, copies only to end of s1; s7 == "World!!!"
string s8(s1, 16);      // throws an out_of_range exception
```

### `substr` Operation

| Substring Operation |
| ------------------- |
| s.substr(pos, n)    |

```cpp
string s("hello world");
string s2 = s.substr(0, 5);     // s2 = hello
string s3 = s.substr(6);        // s3 = world
string s4 = s.substr(6, 11);    // s3 = world
string s5 = s.substr(12);       // throws an out_of_range exception
```

## Other Ways to Change a `string`

```cpp
s.insert(s.size(), 5, '!');     // insert five exclamation points at the end of s
s.erase(s.size() - 5, 5);       // erase the last five characters from s
```

```cpp
const char *cp = "Stately, plump Buck";
s.assign(cp, 7);                // s == "Stately"
s.insert(s.size(), cp + 7);     // s == "Stately, plump Buck"
```

```cpp
string s = "some string", s2 = "some other string";
s.insert(0, s2);    // insert a copy of s2 before position 0 in s
// insert s.size() characters from s2 starting at s2[0] before s[0]
s.insert(0, s2, 0, s2.size());
```

### The `append` and `replace` Functions


| Operations to Modify `strings` |
| ------------------------------ |
| `s.insert(pos, args);`         |
| `s.erase(pos, len);`           |
| `s.assign(args);`              |
| `s.append(args);`              |
| `s.replace(range, args);`      |

| `args`              |
| ------------------- |
| `str`               |
| `str`, `pos`, `len` |
| `cp`, `len`         |
| `n`, `c`            |
| `b`, `e`            |

> `args` for `replace` and `insert` depend on how `range` or pos is specified.

```cpp
string s("C++ Primer"), s2 = s; // initialize s and s2 to "C++ Primer"

s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
s2.append(" 4th Ed."); // equivalent: appends " 4th Ed." to s2; s == s2

// equivalent way to replace "4th" by "5th"
s.erase(11, 3); // s == "C++ Primer Ed."
s.insert(11, "5th"); // s == "C++ Primer 5th Ed."
// starting at position 11, erase three characters and then insert "5th"
s2.replace(11, 3, "5th"); // equivalent: s == s2

s.replace(11, 3, "Fifth"); // s == "C++ Primer Fifth Ed."
```

### The Many Overloaded Ways to Change a string

## `string` Search Operations

| `string` Search Operations  |
| --------------------------- |
| `s.find(args)`              |
| `s.rfind(args)`             |
| `s.find_first_of(args)`     |
| `s.find_last_of(args)`      |
| `s.find_first_not_of(args)` |
| `s.find_last_not_of(args)`  |

| `args` must be one of |
| --------------------- |
| `c`, `pos`            |
| `s2`, `pos`           |
| `cp`, `pos`           |
| `cp`, `pos`, `n`      |

```cpp
string name("AnnaBelle");
auto pos1 = name.find("Anna"); // pos1 == 0
```

```cpp
string lowercase("annabelle");
pos1 = lowercase.find("Anna"); // pos1 == npos
```

```cpp
string numbers("0123456789"), name("r2d2");
// returns 1, i.e., the index of the first digit in name
auto pos = name.find_first_of(numbers);

string dept("03714p3");
// returns 5, which is the index to the character 'p'
auto pos = dept.find_first_not_of(numbers);
```

### Specifiying Where to Start the Search

```cpp
string::size_type pos = 0;
// each iteration finds the next number in name
while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
    cout << "found number at index: " << pos
         << " element is " << name[pos] << endl;
    ++pos; // move to the next character
}
```

### Searching Backward

```cpp
string river("Mississippi");
auto first_pos = river.find("is"); // returns 1
auto last_pos = river.rfind("is"); // returns 4
```

## The `compare` Functions

| Possible Arguments to `s.compare` |
| --------------------------------- |
| `s2`                              |
| `pos1, n1, s2`                    |
| `pos1, n1, s2, pos2, n2`          |
| `cp`                              |
| `pos1, n1, cp`                    |
| `pos1, n1, cp, n2`                |

## Numeric Conversions

| Conversions between `string`s and numbers |
| ----------------------------------------- |
| `stoi(s, p, b)`                           |
| `stol(s, p, b)`                           |
| `stoul(s, p, b)`                          |
| `stoll(s, p, b)`                          |
| `stoull(s, p, b)`                         |
| `stof(s, p, b)`                           |
| `stod(s, p, b)`                           |
| `stold(s, p, b)`                          |

```cpp
int i = 42;
string s = to_string(i);    // converts the int i to its character representation
double d = stod(s);         // converts the string s to floating-point
```

```cpp
string s2 = "pi = 3.14";
// convert the first substring in s that starts with a digit, d = 3.14
d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
```

## Container Adapters

| Operations and Types Common to the Container Adapters |
| ----------------------------------------------------- |
| `size_type`                                           |
| `value_type`                                          |
| `container_type`                                      |
| `A a;`                                                |
| `A a(c);`                                             |
| *relational operators*                                |
| `a.empty()`                                           |
| `a.size()`                                            |
| `swap(a, b)`                                          |
| `a.swap(b)`                                           |

### Define an Adapter

```cpp
stack<int> stk(deq);    // copies elements from deq into stk
```

```cpp
// empty stack implemented on top of vector
stack<string, vector<string>> str_stk;
// str_stk2 is implemented on top of vector and initially holds a copy of svec
stack<string, vector<string>> str_stk2(svec);
```

### Stack Adapter

| Stack Operations  |
| ----------------- |
| `s.pop()`         |
| `s.push()`        |
| `s.emplace(args)` |
| `s.top()`         |

```cpp
stack<int> intStack;    // empty stack
// fill up the stack
for (size_t ix = 0; ix != 10; ++ix)
    intStack.push(ix);  // intStackholds 0 ... 9 inclusive
while (!intStack.empty()) {     // while there are still values in intStack
    int value = intStack.top();
    // code that uses value
    intStack.pop();     // pop the top item, and repeat
}
```

### The Queue Adapters

| `queue`, `priority_queue` Operations |
| ------------------------------------ |
| `q.pop()`                            |
| `q.front()`                          |
| `q.back()`                           |
| `q.top()`                            |
| `q.push(item)`                       |
| `q.emplace(args)`                    |
