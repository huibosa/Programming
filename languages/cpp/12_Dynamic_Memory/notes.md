[toc]

## Dynamic Memory and Smart Pointers

### The `shared_ptr` Class

```cpp
shared_ptr<string> p1;      // shared_ptr that can point at a string
shared_ptr<list<int>> p2;   // shared_ptr that can point at a list of ints
```

> A default initialized samrt pointer holds a null pointer

```cpp
// if p1 is not null, check whether it's the empty string
if (p1 && p1->empty())
    *p1 = "hi";     // if so, dereference p1 to assign a new value to that string
```

| Operations Common to `shared_ptr` and `unique_ptr` |
| :------------------------------------------------: |
| `shared_ptr<T> sp`                                 |
| `unique_ptr<T> up`                                 |
| `p`                                                |
| `*p`                                               |
| `p->mem`                                           |
| `p.get()`                                          |
| `swap(p, q)`                                       |
| `p.swap(q)`                                        |

| Operations Specific to `shared_ptr` |
| ----------------------------------- |
| `make_shared<T> args`               |
| `shared_ptr<T> p(q)`                |
| `p = q`                             |
| `p.unique()`                        |
| `p.use_count()`                     |

#### The `make_shared` Function

```cpp
// shared_ptr that points to an int with value 42
shared_ptr<int> p3 = make_shared<int>(42);
// p4 points to a string with value 9999999999
shared_ptr<string> p4 = make_shared<string>(10, '9');
// p5 points to an int that is value initialized (§ 3.3.1 (p. 98)) to 0
shared_ptr<int> p5 = make_shared<int>();
// p6 points to a dynamically allocated, empty vector<string>
auto p6 = make_shared<vector<string>>();
```

#### Copying and Assigning `shared_ptr`s

```cpp
auto p = make_shared<int>(42); // object to which p points has one user
auto q(p);      // p and q point to the same object
                // object to which p and q point has two users
```

```cpp
auto r = make_shared<int>(42); // int to which r points has one user
r = q;  // assign to r, making it point to a different address
        // increase the use count for the object to which q points
        // reduce the use count of the object to which r had pointed
        // the object r had pointed to has no users; that object is automatically freed
```

#### `shared_ptr`s Automatically Destroy Their Objects ...

#### ...and Automatically Free the Associated Memory

```cpp
// factory returns a shared_ptr pointing to a dynamically allocated object
shared_ptr<Foo> factory(T arg)
{
    // process arg as appropriate
    // shared_ptr will take care of deleting this memory
    return make_shared<Foo>(arg);
}
```

```cpp
void use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);
    // use p
} // p goes out of scope; the memory to which p points is automatically freed
```

```cpp
shared_ptr<Foo> use_factory(T arg)
{
    shared_ptr<Foo> p = factory(arg);
    // use p
    return p; // reference count is incremented when we return p
} // p goes out of scope; the memory to which p points is not freed
```

> If you put `shared_ptr`s in a container, and you subsequently need to use some,
> but not all, of the elements, remember to erase the elements you no longer
> need.

#### Classes with Resources That Have Dynamic Lifetime

Programs tend to use dynamic memory for one of three purposes:

1. They don’t know how many objects they’ll need
2. They don’t know the precise type of the objects they need
3. They want to share data between several objects

```cpp
vector<string> v1; // empty vector

{   // new scope
    vector<string> v2 = {"a", "an", "the"};
    v1 = v2; // copies the elements from v2 into v1
} // v2 is destroyed, which destroys the elements in v2
 // v1 has three elements, which are copies of the ones originally in v2
```

```cpp
Blob<string> b1; // empty Blob

{ // new scope
    Blob<string> b2 = {"a", "an", "the"};
    b1 = b2; // b1 and b2 share the same elements
} // b2 is destroyed, but the elements in b2 must not be destroyed
  // b1 points to the elements originally created in b2
```

#### Defining the `StrBlob` Class

```cpp
class StrBlob {
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
public:
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const std::string& t) { data->push_back(t); }
    void pop_back();
    // element access
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string& msg) const;
};
```

#### `StrBlob` Constructors

```cpp
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il):
                data(std::make_shared<std::vector<std::string>>(il)) {}
```

#### Element Access Members

```cpp
void StrBlob::check(size_type i, const std::string & msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
```

```cpp
std::string& StrBlob::front() {
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
```

#### Copying, Assigning, and Destroying `StrBlobs`

### Managing Memory Directly

#### Using `new` to Dynamically Allocate and Initialize Objects

```cpp
int *pi = new int;  // pi points to a dynamically allocated,
                    // unnamed, uninitialized int
```

> By default, dynamically allocated objects are default initialized.

```cpp
string *ps = new string; // initialized to empty string
int *pi = new int; // pi points to an uninitialized int
```

```cpp
int *pi = new int(1024);    // object to which pi points has value 1024
string *ps = new string(10, '9');   // *ps is "9999999999"
// vector with ten elements with values from 0 to 9
vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
```

```cpp
string *ps1 = new string;   // default initialized to the empty string
string *ps = new string();  // value initialized to the empty string
int *pi1 = new int;         // default initialized; *pi1 is undefined
int *pi2 = new int();       // value initialized to 0; *pi2 is 0
```

```cpp
auto p1 = new auto(obj);    // p points to an object of the type of obj
                            // that object is initialized from obj
auto p2 = new auto{a,b,c};  // error: must use parentheses for the initializer
```

#### Dynamically Allocated const Objects

```cpp
// allocate and initialize a const int
const int *pci = new const int(1024);
// allocate a default-initialized const empty string
const string *pcs = new const string;
```

#### Memory Exhaustion

```cpp
// if allocation fails, new returns a null pointer
int *p1 = new int; // if allocation fails, new throws std::bad_alloc
int *p2 = new (nothrow) int; // if allocation fails, new returns a null pointer
```

#### Freeing Dynamic Memory

```cpp
delete p;   // p must point to a dynamically allocated object or be null
```

#### Pointer Values and `delete`

```cpp
int i, *pi1 = &i, *pi2 = nullptr;
double *pd = new double(33), *pd2 = pd;
delete i;   // error: i is not a pointer
delete pi1; // undefined: pi1 refers to a local
delete pd;  // ok
delete pd2; // undefined: the memory pointed to by pd2 was already freed
delete pi2; // ok: it is always ok to delete a null pointer
```

```cpp
const int* pci = new const int(1024);
delete pci;     // ok, deletes a const object
```

#### Dynamically Allocated Objects Exist until Are Freed

```cpp
// factory returns a pointer to a dynamically allocated object
Foo* factory(T arg) {
    // process arg as appropriate
    return new Foo(arg); // caller is responsible for deleting this memory
}
```

```cpp
void use_factory(T arg) {
    Foo *p = factory(arg);
    // use p but do not delete it
} // p goes out of scope, but the memory to which p points is not freed!
```

> Dynamic memory managed through built-in pointers (rather than smart pointers)
> exists until it is explicitly freed.

```cpp
void use_factory(T arg) {
    Foo *p = factory(arg);
    // use p
    delete p; // remember to free the memory now that we no longer need it
}
```

```cpp
Foo* use_factory(T arg) {
    Foo *p = factory(arg);
    // use p
    return p; // caller must delete the memory
}
```

#### Resetting the Value of a Pointer after a `delete` ...

#### ...Provides Only Limited Protection

```cpp
int *p(new int(42));    // p points to dynamic memory
auto q = p;             // p and q point to the same memory
delete p;       // invalidates both p and q
p = nullptr;    // indicates that p is no longer bound to an object
```

### Using `shared_ptr`s with `new`

```cpp
shared_ptr<double> p1; // shared_ptr that can point at a double
shared_ptr<int> p2(new int(42)); // p2 points to an int with value 42
```

| Other Ways to Define and Change `shared_ptr`s |
| --------------------------------------------- |
| `shared_ptr<T> p(q)`                          |
| `shared_ptr<T> p(u)`                          |
| `shared_ptr<T> p(q, d)`                       |
| `shared_ptr<T> p(p2, d)`                      |
| `p.reset()`                                   |
| `p.reset(q)`                                  |
| `p.reset(q, d)`                               |

```cpp
shared_ptr<int> clone(int p) {
    return new int(p); // error: implicit conversion to shared_ptr<int>
}

shared_ptr<int> clone(int p) {
    // ok: explicitly create a shared_ptr<int> from int*
    return shared_ptr<int>(new int(p));
}
```

#### Don't Mix Ordinary Pointers and Smart Pointers

```cpp
// ptr is created and initialized when process is called
void process(shared_ptr<int> ptr)
{
    // use ptr
} // ptr goes out of scope and is destroyed

shared_ptr<int> p(new int(42)); // reference count is 1
process(p); // copying p increments its count; in process the reference count is 2
int i = *p; // ok: reference count is 1
```

```cpp
int *x(new int(1024)); // dangerous: x is a plain pointer, not a smart pointer
process(x); // error: cannot convert int* to shared_ptr<int>
process(shared_ptr<int>(x)); // legal, but the memory will be deleted!
int j = *x; // undefined: x is a dangling pointer!
```

#### ...and Don’t Use `get` to Initialize or Assign Another Smart Pointer

```cpp
shared_ptr<int> p(new int(42)); // reference count is 1
int *q = p.get(); // ok: but don't use q in any way that might delete its pointer

{ // new block
// undefined: two independent shared_ptrs point to the same memory
shared_ptr<int>(q);
} // block ends, q is destroyed, and the memory to which q points is freed

int foo = *p; // undefined; the memory to which p points was freed
```

> Use `get` only to pass access to the pointer to code that you know will not
> `delete` the pointer. In particular, never use `get` to initialize or assign
> to another smart pointer.

#### Other `shared_ptr` Operations

```cpp
p = new int(1024); // error: cannot assign a pointer to a shared_ptr
p.reset(new int(1024)); // ok: p points to a new object
```

> The `reset` member is often used together with `unique` to control changes to
> the object shared among several `shared_ptr`s.

```cpp
if (!p.unique())
    p.reset(new string(*p)); // we aren't alone; allocate a new copy
*p += newVal; // now that we know we're the only pointer, okay to change this object
```

### Smart Pointers and Exceptions

```cpp
void f() {
    shared_ptr<int> sp(new int(42)); // allocate a new object
    // code that throws an exception that is not caught inside f
}  // shared_ptr freed automatically when the function ends
```

```cpp
void f()
{
    int *ip = new int(42); // dynamically allocate a new object
    // code that throws an exception that is not caught inside f
    delete ip; // free the memory before exiting
}
```

#### Smart Pointers and Dumb Classes

```cpp
struct destination; // represents what we are connecting to
struct connection; // information needed to use the connection

connection connect(destination*); // open the connection
void disconnect(connection); // close the given connection

void f(destination &d /* other parameters */)
{
    // get a connection; must remember to close it when done
    connection c = connect(&d);
    // use the connection
    // if we forget to call disconnect before exiting f, there will be no way to close c
}
```

#### Using Your Own Deletion Code

```cpp
void end_connection(connection* p) { disconnect(*p); }
```

```cpp
void f(destination& d /* other parameters */) {
    connection c = connect(&d);
    shared_ptrs<connection> p(&c, end_connection);
    // use the connection
    // when f exits, even if by an exception, the connection will be properly closed
}
```

> Cautions: Smart Pointer Pitfalls
> 
> * Don't use the same built-in pointer value to initialize (or `reset`) more
>   than one smart pointer.
> * Don't `delete` the pointer returned from `get()`.
> * Don't use `get()` to initialize or `reset` another smart pointer.
> * If you use a smart pointer to manage a resourse other than memory allocated
>   by `new`, remember to pass a deleter.

### `unique_ptr`

| `unique_ptr` Operations |
| ----------------------- |
| `unique_ptr<T> u1`      |
| `unique_ptr<T, D> u2`   |
| `unique_ptr<T, D> u(d)` |
| `u = nullptr`           |
| `u.release()`           |
| `u.reset()`             |
| `u.reset(q)`            |
| `u.reset(nullptr)`      |

```cpp
unique_ptr<double> p1; // unique_ptr that can point at a double
unique_ptr<int> p2(new int(42)); // p2 points to int with value 42
```

```cpp
unique_ptr<string> p1(new string("Stegosaurus"));
unique_ptr<string> p2(p1);  // error: no copy for unique_ptr
unique_ptr<string> p3;
p3 = p2;                    // error: no assign for unique_ptr
````

```cpp
// transfers ownership from p1 (which points to the string Stegosaurus) to p2
unique_ptr<string> p2(p1.release()); // release makes p1 null
unique_ptr<string> p3(new string("Trex"));
// transfers ownership from p3 to p2
p2.reset(p3.release()); // reset deletes the memory to which p2 had pointed
```

* The release member returns the pointer currently stored in the `unique_ptr`
  and makes that `unique_ptr` null.
* The reset member takes an optional pointer and repositions the `unique_ptr`
  to point to the given pointer.

```cpp
p2.release(); // WRONG: p2 won't free the memory and we've lost the pointer
auto p = p2.release(); // ok, but we must remember to delete(p)
```

#### Passing and Returning `unique_ptr`s

```cpp
unique_ptr<int> clone(int p) {
    // ok: explicitly create a unique_ptr<int> from int*
    return unique_ptr<int>(new int(p));
}
```

```cpp
unique_ptr<int> clone(int p) {
    unique_ptr<int> ret(new int(p));
    // ...
    return ret;
}
```

#### Passing a Deleter to `unique_ptr`

```cpp
// p points to an object of type objT and uses an object of type delT to free that object
// it will call an object named fcn of type delT
unique_ptr<objT, delT> p (new objT, fcn);
```

```cpp
void f(destination& d /* other needed parameters */) {
    connection c = connect(&d);
    unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
}
```

```cpp
void f(destination &d /* other needed parameters */)
{
    connection c = connect(&d); // open the connection
    // when p is destroyed, the connection will be closed
    unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
    // use the connection
    // when f exits, even if by an exception, the connection will be properly closed
}
```

#### `weak_ptr`

| `weak_ptr` Operations |
| --------------------- |
| `weak_ptr<T> w`       |
| `weak_ptr<T> w(sp)`   |
| `w = p`               |
| `w.reset()`           |
| `w.use_count()`       |
| `w.expired()`         |
| `w.lock()`            |

```cpp
auto p = make_shared<int>(42);
weak_ptr<int> wp(p); // wp weakly shares with p; use count in p is unchanged
```

```cpp
if (shared_ptr<int> np = wp.lock()) { // true if np is not null
    // inside the if, np shares its object with p
}
```

#### Checked Pointer Class

```cpp
// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
                wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr(); // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // current position within the array
};
```

```cpp
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock(); // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}
```

```cpp
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p) is the vector to which this object points
}
```

```cpp
// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return *this;
}
```

```cpp
// forward declaration needed for friend declaration in StrBlob
class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    // other members as in § 12.1.1 (p. 456)
    // return StrBlobPtr to the first and one past the last elements
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
};
```

## Dynamic Arrays

> Most applications should use a library container rather than dynamically
> allocated arrays. Using a container is easier, less likely to contain
> memorymanagement bugs, and is likely to give better performance.

### `new` and Arrays

```cpp
// call get_size to determine how many ints to allocate
int *pia = new int[get_size()]; // pia points to the first of these ints
```

```cpp
typedef int arrT[42]; // arrT names the type array of 42 ints
int *p = new arrT;    // allocates an array of 42 ints; p points to the first one

// The compiler executes this expression as
int* p = new int[42];
```

#### Allocating an Array Yields a Pointer to the Element Type

#### Initializing an Array of Dynamically Allocated Objects

```cpp
int *pia = new int[10]; // block of ten uninitialized ints
int *pia2 = new int[10](); // block of ten ints value initialized to 0
string *psa = new string[10]; // block of ten empty strings
string *psa2 = new string[10](); // block of ten empty strings
```

```cpp
// block of ten ints each initialized from the corresponding initializer
int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
// block of ten strings; the first four are initialized from the given initializers
// remaining elements are value initialized
string *psa3 = new string[10]{"a", "an", "the", string(3,'x')};
```

#### It Is Legal to Dynamically Allocate an Empty Array

```cpp
size_t n = get_size(); // get_size returns the number of elements needed
int* p = new int[n]; // allocate an array to hold the elements
for (int* q = p; q != p + n; ++q)
    /* process the array */ ;
```

```cpp
char arr[0];            // error: cannot define a zero-length array
char *cp = new char[0]; // ok: but cp can't be dereferenced
```

#### Freeing Dynamic Arrays

```cpp
delete p;       // p must point to a dynamically allocated object or be null
delete [] pa;   // pa must point to a dynamically allocated array or be null
```

> Elements in an array are destroyed in reverse order.

```cpp
typedef int arrT[42]; // arrT names the type array of 42 ints
int *p = new arrT; // allocates an array of 42 ints; p points to the first one
delete [] p; // brackets are necessary because we allocated an array
```

#### Smart Pointers and Dynamic Arrays

```cpp
// up points to an array of ten uninitialized ints
unique_ptr<int[]> up(new int[10]);
up.release(); // automatically uses delete[] to destroy its pointer
```

| `unique_ptr`s to Arrays |
| ----------------------- |
| `unique_ptr<T[]> u`     |
| `unique_ptr<T[]> u(p)`  |
| `u[i]`                  |

```cpp
for (size_t i = 0; i != 10; ++i) {
    up[i] = i;  // assign a new value to each of the elements
}
```

```cpp
// to use a shared_ptr we must supply a deleter
shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
sp.reset(); // uses the lambda we supplied that uses delete[] to free the array
```

```cpp
// shared_ptrs don't have subscript operator and don't support pointer arithmetic
for (size_t i = 0; i != 10; ++i)
    *(sp.get() + i) = i; // use get to get a built-in pointer
```

### The `allocator` Class

> An aspect of `new` that limits its flexibility is that `new` combines
  allocating memory with constructing object(s) in that memory. Similarly,
  delete combines destruction with deallocation.

In general, coupling allocation and construction can be wasteful. For example:

```cpp
string *const p = new string[n]; // construct n empty strings
string s;
string *q = p; // q points to the first string
while (cin >> s && q != p + n)
    *q++ = s; // assign a new value to *q
const size_t size = q - p; // remember how many strings we read
// use the array
delete[] p; // p points to an array; must remember to use delete[]
```

* The elements that are used are written twice: first when the elements are
  default initialized, and subsequently when we assign to them.
* More importantly, classes that do not have default constructors cannot be
  dynamically allocated as an array.

#### The `allocator` Class

| Standard `allocator` Class and Customized Algorithms |
| ---------------------------------------------------- |
| `allocator<T> a`                                     |
| `a.allocate(n)`                                      |
| `a.deallocate(p, n)`                                 |
| `a.construct(p, args)`                               |
| `a.destroy(p)`                                       |

```cpp
allocator<string> alloc;          // object that can allocate strings
auto const p = alloc.allocate(n); // allocate n unconstructed strings
```

#### `allocator`s Allocate Unconstructed Memory

```cpp
auto q = p; // q will point to one past the last constructed element
alloc.construct(q++);           // *q is the empty string
alloc.construct(q++, 10, 'c');  // *q is cccccccccc
alloc.construct(q++, "hi");     // *q is hi!
```

```cpp
cout << *p << endl; // ok: uses the string output operator
cout << *q << endl; // disaster: q points to unconstructed memory!
```

```cpp
while (q != p)
    alloc.destroy(--q); // free the strings we actually allocated
```

```cpp
alloc.deallocate(p, n);
```

* The pointer we pass to deallocate cannot be null; it must point to memory
  allocated by allocate.
* Moreover, the size argument passed to deallocate must be the same size as
  used in the call to allocate that obtained the memory to which the pointer
  points.

#### Algorithms to Copy and Fill Uninitialized Memory

| `allocator` Algorithms           |
| -------------------------------- |
| `uninitialized_copy(b, e, b2)`   |
| `uninitialized_copy_n(b, n, b2)` |
| `uninitialized_fill(b, e, t)`    |
| `uninitialized_fill_n(b, n, t)`  |

```cpp
// allocate twice as many elements as vi holds
auto p = alloc.allocate(vi.size() * 2);
// construct elements starting at p as copies of elements in vi
auto q = uninitialized_copy(vi.begin(), vi.end(), p);
// initialize the remaining elements to 42
uninitialized_fill_n(q, vi.size(), 42);
```

## Using the Library: A Text-Query Program

### Design of the Query Program

#### Data Structures

#### Sharing Data between Classes

#### Using the `TextQuery` Class

```cpp
void runQueries(ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile);  //  store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q") break;
        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}
```

### Defining the Query Program Classes

```cpp
class QueryResult; // declaration needed for return type in the query function
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;  // input file
    // map of each word to the set of the lines in which that word appears
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
```

#### The `TextQuery` Constructor

```cpp
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {       // for each line in the file
        file->push_back(text);        // remember this line of text
        int n = file->size() - 1;     // the current line number
        istringstream line(text);     // separate the line into words
        string word;
        while (line >> word) {        // for each word in that line
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>); // allocate a new set
            lines->insert(n);      // insert this line number
        }
    }
}
```

#### The `QueryResult` Class

```cpp
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
private:
    std::string sought;  // word this query represents
    std::shared_ptr<std::set<line_no>> lines;       // line it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
}
```

#### The `query` Function


```cpp
QueryResult TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // not found
    else
        return QueryResult(sought, loc->second, file);
}
```

> Use `static` just allocate once.

#### Printing the Results

```cpp
ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines) // for every element in the set
        // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}
```
