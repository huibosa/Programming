[toc]

> If a class does not define all of the copy-control members, the compiler
> automatically defines the missing operations.

## Copy, Assign, and Destroy

### The Copy Constructor

A class controls these operations by defining five special member functions:

* Copy constructor,
* Copy-assignment operator,
* Move constructor,
* Move-assignment operator,
* Destructor.

```cpp
class Foo {
    public:
    Foo(); // default constructor
    Foo(const Foo&); // copy constructor
    // ...
};
```

* The first parameter must be a reference type. That parameter is almost always
  a reference to const, although we can define the copy constructor to take a
  reference to nonconst.
*  The copy constructor usually should not be explicit.

#### The Synthesized Copy Constructor

The synthesized copy constructor for our Sales_data class is equivalent to:

```cpp
class Sales_data {
public:
    // other members and constructors as before
    // declaration equivalent to the synthesized copy constructor
    Sales_data(const Sales_data&);
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};
// equivalent to the copy constructor that would be synthesized for Sales_data
Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),  // uses the string copy constructor
    units_sold(orig.units_sold), // copies orig.units_sold
    revenue(orig.revenue) // copies orig.revenue
    { }                   // empty body
```

* Members of class type are copied by the copy constructor for that class;
* Members of built-in type are copied directly.
* Although we cannot directly copy an array, the synthesized copy constructor
  copies members of array type by copying each element.
* Elements of class type are copied by using the elements’ copy constructor.

#### Copy Initialization

```cpp
string dots(10, '.');               // direct initialization
string s(dots);                     // direct initialization
string s2 = dots;                   // copy initialization
string null_book = "9-999-99999-9"; // copy initialization
string nines = string(100, '9');    // copy initialization
```

Copy initialization happens not only when we define variables using an =, but
also when we

* Pass an object as an argument to a parameter of nonreference type
* Return an object from a function that has a nonreference return type
* Brace initialize the elements in an array or the members of an aggregate class

#### Parameter and Return Values

The fact that the copy constructor is used to initialize nonreference
parameters of class type explains why the copy constructor’s own parameter must
be a reference. If that parameter were not a reference, then the call would
never succeed—to call the copy constructor, we’d need to use the copy
constructor to copy the argument, but to copy the argument, we’d need to call
the copy constructor, and so on indefinitely.

#### Constraints on Copy Initialization

```cpp
vector<int> v1(10);   // ok: direct initialization
vector<int> v2 = 10;  // error: constructor that takes a size is explicit

void f(vector<int>);  // f's parameter is copy initialized
f(10);    // error: can't use an explicit constructor to copy an argument
f(vector<int>(10));   // ok: directly construct a temporary vector from an int
```

* For the same reasons that we cannot copy initialize v2, we cannot implicitly
  use an explicit constructor when we pass an argument or return a value from a
  function.

#### The Compiler Can Bypass the Copy Constructor

```cpp
string null_book = "9-999-99999-9"; // copy initialization
```

is rewrite by compiler into:

```cpp
string null_book("9-999-99999-9"); // compiler omits the copy constructor
```

### The Copy-Assignment Operator

```cpp
Sales_data trans, accum;
trans = accum; // uses the Sales_data copy-assignment operator
```

#### Introducing Overloaded Assignment

```cpp
class Foo {
    public:
    Foo& operator=(const Foo&); // assignment operator
    // ...
};
```

#### The Synthesized Copy-Assignment Operator

* It assigns each nonstatic member of the right-hand object to the
  corresponding member of the left-hand object using the copy-assignment
  operator for the type of that member.
* Array members are assigned by assigning each element of the array.

```cpp
// equivalent to the synthesized copy-assignment operator
Sales_data&
Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo; // calls the string::operator=
    units_sold = rhs.units_sold; // uses the built-in int assignment
    revenue = rhs.revenue; // uses the built-in double assignment
    return *this; // return a reference to this object
}
```

### The Destructor

```cpp
class Foo {
public:
    ~Foo(); // destructor
    // ...
};
```

#### What a destructor does

In a destructor, the function body is executed first and then the members are
destroyed. Members are destroyed in reverse order from the order in which they
were initialized.

> The implicit destruction of a member of built-in pointer type does not delete
> the object to which that pointer points.

#### When a Destructor Is Called

* Variables are destroyed when they go out of scope.
* Members of an object are destroyed when the object of which they are a part
  is destroyed.
* Elements in a container—whether a library container or an array—are destroyed
  when the container is destroyed.
* Dynamically allocated objects are destroyed when the delete operator is
  applied to a pointer to the object.
* Temporary objects are destroyed at the end of the full expression in which
  the temporary was created.

```cpp
{ // new scope
    // p and p2 point to dynamically allocated objects
    Sales_data *p = new Sales_data;       // p is a built-in pointer
    auto p2 = make_shared<Sales_data>();  // p2 is a shared_ptr
    Sales_data item(*p);            // copy constructor copies *p into item
    vector<Sales_data> vec;         // local object
    vec.push_back(*p2);             // copies the object to which p2 points
    delete p;                       // destructor called on the object pointed to by p
} // exit local scope; destructor called on item, p2, and vec
  // destroying p2 decrements its use count; if the count goes to 0, the object is freed
  // destroying vec destroys the elements in vec
```

#### The Synthesized Destructor

```cpp
class Sales_data {
public:
    // no work to do other than destroying the members, which happens automatically
    ~Sales_data() { }
    // other members as before
};
```

### The Rule of Three/Five

> There is no requirement that we define all of these operations: We can define
> one or two of them without having to define all of them. However, ordinarily
> these operations should be thought of as a unit. In general, it is unusual to
> need one without needing to define them all.

#### Classes That Need Destructors Need Copy and Assignment

If the class needs a destructor, it almost surely needs a copy constructor and
copy-assignment operator as well.

Consider what would happen if we gave HasPtr a destructor but used the
synthesized versions of the copy constructor and copy-assignment operator:

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    ~HasPtr() { delete ps; }
    // WRONG: HasPtr needs a copy constructor and copy-assignment operator
    // other members as before
};
```

This version of the class uses the synthesized versions of copy and assignment.
Those functions copy the pointer member, meaning that multiple HasPtr objects
may be pointing to the same memory:

```cpp
HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
    HasPtr ret = hp; // copies the given HasPtr
    // process ret
    return ret; // ret and hp are destroyed
}
```

* When `f` returns, both `hp` and `ret` are destroyed and the `HasPtr`
  destructor is run on each of these objects.
* That destructor will delete the pointer member in `ret` and in `hp`. But
  these objects contain the same pointer value. This code will delete that
  pointer twice, which is an error. What happens is undefined.

In addition, the caller of f may still be using the object that was passed to
f:

```cpp
HasPtr p("some values");
f(p); // when f completes, the memory to which p.ps points is freed
HasPtr q(p); // now both p and q point to invalid memory!
```

#### Classes That Need Copy Need Assignment, and Vice Versa

> If a class needs a copy constructor, it almost surely needs a copy-assignment
> operator.

### Using = default

```cpp
class Sales_data {
public:
    // copy control; use defaults
    Sales_data() = default;
    Sales_data(const Sales_data&) = default;
    Sales_data& operator=(const Sales_data &);
    ~Sales_data() = default;
    // other members as before
};
Sales_data& Sales_data::operator=(const Sales_data&) = default;
```

* If we do not want the synthesized member to be an inline function, we can
  specify = default on the member’s definition, as we do in the definition of
  the copy-assignment operator.

### Preventing Copies

#### Defining a Function as Deleted

```cpp
struct NoCopy {
    NoCopy() = default; // use the synthesized default constructor
    NoCopy(const NoCopy&) = delete; // no copy
    NoCopy &operator=(const NoCopy&) = delete; // no assignment
    ~NoCopy() = default; // use the synthesized destructor
    // other members
};
```

* Unlike `= default`, `= delete` must appear on the first declaration of a deleted
  function. 
* We can specify `= delete` on any function.

> Although the primary use of deleted functions is to suppress the copy-control
> members, deleted functions are sometimes also useful when we want to guide
> the function-matching process.

#### The Destructor Should Not be a Deleted Member

Although we cannot define variables or members of such types, we can
dynamically allocate objects with a deleted destructor. However, we cannot free
them:

```cpp
struct NoDtor {
    NoDtor() = default; // use the synthesized default constructor
    ~NoDtor() = delete; // we can't destroy objects of type NoDtor
};
NoDtor nd; // error: NoDtor destructor is deleted
NoDtor *p = new NoDtor(); // ok: but we can't delete p
delete p; // error: NoDtor destructor is deleted
```

> It is not possible to define an object or delete a pointer to a dynamically
> allocated object of a type with a deleted destructor.

#### The Copy-Control Members May Be Synthesized as Deleted 

For some classes, the compiler defines these synthesized members as deleted
functions:

The synthesized destructor is defined as deleted

* If the class has a member whose own destructor is deleted or is inaccessible
  (e.g., private).

The synthesized copy constructor is defined as deleted

* If the class has a member whose own copy constructor is deleted or
  inaccessible.
* If the class has a member with a deleted or inaccessible
  destructor.

The synthesized copy-assignment operator is defined as deleted

* If a member has a deleted or inaccessible copy-assignment operator,
* If the class has a const or reference member.

The synthesized default constructor is defined as deleted

* if the class has a member with a deleted or inaccessible destructor;
* or has a reference member that does not have an in-class initializer;
* or has a const member whose type does not explicitly define a default
  constructor and that member does not have an in-class initializer.

> In essence, these rules mean that if a class has a data member that cannot be
> default constructed, copied, assigned, or destroyed, then the corresponding
> member will be a deleted function.

#### `private` Copy Control

Prior to the new standard, classes prevented copies by declaring their copy
constructor and copy-assignment operator as private:

```cpp
class PrivateCopy {
    // no access specifier; following members are private by default; see § 7.2 (p.  268)
    // copy control is private and so is inaccessible to ordinary user code
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator=(const PrivateCopy&);
    // other members
public:
    PrivateCopy() = default; // use the synthesized default constructor
    ~PrivateCopy(); // users can define objects of this type but not copy them
};
```

> Classes that want to prevent copying should define their copy constructor and
> copy-assignment operators using = delete rather than making those members
> private.

## Copy Control and Resourse Management

> Ordinarily, classes that manage resources that do not reside in the class
> must define the copy-control members. 

* Classes that behave like values have their own state
* Classes that act like pointers share state

### Classes That Act Like Values

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
    // each HasPtr has its own copy of the string to which ps points
    HasPtr(const HasPtr &p):
    ps(new std::string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};
```

#### Valuelike Copy-Assignment Operator 

Assignment operators typically combine the actions of the destructor and the
copy constructor. 

Handle self-assignment:

```cpp
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps); // copy the underlying string
    delete ps; // free the old memory
    ps = newp; // copy data from rhs into this object
    i = rhs.i;
    return *this; // return this object
}
```

There are two points to keep in mind when you write an assignment operator:

* Assignment operators must work correctly if an object is assigned to itself.
* Most assignment operators share work with the destructor and copy
  constructor.

> A good pattern to use when you write an assignment operator is to first copy
> the right-hand operand into a local temporary. After the copy is done, it is
> safe to destroy the existing members of the left-hand operand. Once the left-
> hand operand is destroyed, copy the data from the temporary into the members
> of the left-hand operand.

```cpp
// WRONG way to write an assignment operator!
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    delete ps; // frees the string to which this object points
    // if rhs and *this are the same object, we're copying from deleted memory!
    ps = new string(*(rhs.ps));
    i = rhs.i;
    return *this;
}
```

### Defining Classes that Act Like Pointers

#### Reference count

* In addition to initializing the object, each constructor (other than the copy
  constructor) creates a counter. This counter will keep track of how many
  objects share state with the object we are creating. When we create an
  object, there is only one such object, so we initialize the counter to 1.
* The copy constructor does not allocate a new counter; instead, it copies the
  data members of its given object, including the counter. The copy constructor
  increments this shared counter, indicating that there is another user of that
  object’s state.
* The destructor decrements the counter, indicating that there is one less user
  of the shared state. If the count goes to zero, the destructor deletes that
  state.
* The copy-assignment operator increments the right-hand operand’s counter and
  decrements the counter of the left-hand operand. If the counter for the
  left-hand operand goes to zero, there are no more users. In this case, the
  copy- assignment operator must destroy the state of the left-hand operand.

```cpp
HasPtr p1("Hiya!");
HasPtr p2(p1); // p1 and p2 point to the same string
HasPtr p3(p1); // p1, p2, and p3 all point to the same string
```

One way to solve this problem is to store the counter in dynamic memory. When we
create an object, we’ll also allocate a new counter. When we copy or assign an object,
we’ll copy the pointer to the counter. That way the copy and the original will point to
the same counter.

#### Defining a Reference-Counted Class

```cpp
class HasPtr {
public:
    // constructor allocates a new string and a new counter, which it sets to 1
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    // copy constructor copies all three data members and increments the counter
    HasPtr(const HasPtr &p):
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use; // member to keep track of how many objects share *ps
};
```

#### Pointerlike Copy Members "Fiddle" the Reference Count 

```cpp
HasPtr::~HasPtr()
{
        if (--*use == 0) {  // if the reference count goes to 0
        delete ps;          // delete the string
        delete use;         // and the counter
    }
}
```

Also, as usual, the operator must handle self-assignment. We do so by
incrementing the count in rhs before decrementing the count in the left-hand
object.

```cpp
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // increment the use count of the right-hand operand
    if (--*use == 0) { // then decrement this object's counter
        delete ps; // if no other users
        delete use; // free this object's allocated members
    }
    ps = rhs.ps; // copy data from rhs into this object
    i = rhs.i;
    use = rhs.use;
    return *this; // return this object
}
```

## Swap

> If a class defines its own swap, then the algorithm uses that class-specific
> version.  Otherwise, it uses the swap function defined by the library.

```cpp
HasPtr temp = v1; // make a temporary copy of the value of v1
v1 = v2;          // assign the value of v2 to v1
v2 = temp;        // assign the saved value of v1 to v2
```

```cpp
string *temp = v1.ps;   // make a temporary copy of the pointer in v1.ps
v1.ps = v2.ps;          // assign the pointer in v2.ps to v1.ps
v2.ps = temp;           // assign the saved pointer in v1.ps to v2.ps
```

#### Writing Our Own `swap` Function

```cpp
class HasPtr {
friend void swap(HasPtr&, HasPtr&);
// other members as in § 13.2.1 (p. 511)
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i); // swap the int members
}
```

* Because swap exists to optimize our code, we’ve defined swap as an inline
  function

#### `swap` Functions Should Call `swap`, Not `std::swap`

If a class has a member that has its own type-specific swap function, calling
`std::swap` would be a mistake.

```cpp
void swap(Foo &lhs, Foo &rhs)
{
    // WRONG: this function uses the library version of swap, not the HasPtr version
    std::swap(lhs.h, rhs.h);
    // swap other members of type Foo
}
```

```cpp
void swap(Foo &lhs, Foo &rhs)
{
    using std::swap;
    swap(lhs.h, rhs.h); // uses the HasPtr version of swap
    // swap other members of type Foo
}
```

If there is a type-specific version of `swap`, that version will be a better
match than the one defined in `std`. As a result:

* If there is a type-specific version of `swap`, calls to `swap` will match
  that type-specific version.
* If there is no type-specific version, then—assuming there is a using
  declaration for `swap` in scope—calls to `swap` will use the version in
  `std`.

#### Using `swap` in Assignment Operators

```cpp
// note rhs is passed by value, which means the HasPtr copy constructor
// copies the string in the right-hand operand into rhs
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // swap the contents of the left-hand operand with the local variable rhs
    swap(*this, rhs); // rhs now points to the memory this object had used
    return *this; // rhs is destroyed, which deletes the pointer in rhs
}
```

* The interesting thing about this technique is that it automatically handles
  self assignment and is automatically exception safe.

## A Copy-Control Example

These classes, `Message` and `Folder`, represent, respectively, email (or other
kinds of) messages, and directories in which a message might appear.

* Each `Message` can appear in multiple `Folders`. However, there will be only
  one copy of the contents of any given `Message`.
* Each `Message` will store a `set` of pointers to the `Folders` in which it
  appears, and each `Folder` will contain a `set` of pointers to its
  `Messages`.
* Our `Message` class will provide `save` and `remove` operations to add or
  remove a `Message` from a specified `Folder`. To create a new `Message`, we
  will specify the contents of the message but no `Folder`. To put a Message in
  a particular `Folder`, we must call `save`.
* When we copy a `Message`, the copy and the original will be distinct
  `Messages`, but both `Messages` should appear in the same `set` of `Folders`.
* Destroying a `Message` must remove pointers to that `Message` from the
  `Folders` that had contained that `Message`.
* When we assign one `Message` to another, we’ll replace the contents of the
  left-hand `Message` with those in the right-hand side. We must also update
  the `set` of `Folders`, removing the left-hand `Message` from its previous
  `Folders` and adding that `Message` to the `Folders` in which the right-hand
  `Message` appears.
* Both the destructor and the copy-assignment operator have to remove this
  `Message` from the `Folders` that point to it. Similarly, both the copy
  constructor and the copy-assignment operator add a `Message` to a given list
  of `Folders`. We’ll define a pair of `private` utility functions to do these
  tasks.
* The Folder class will need analogous copy control members to add or remove
  itself from the Messages it stores.

#### The Message Class

```cpp
class Message {
friend class Folder;
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = ""):
    contents(str) { }
    // copy control to manage pointers to this Message
    Message(const Message&); // copy constructor
    Message& operator=(const Message&); // copy assignment
    ~Message(); // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents; // actual message text
    std::set<Folder*> folders; // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};
```

* The constructor that takes a string copies the given string into contents and
  (implicitly) initializes folders to the empty set.
* Because this constructor has a default argument, it is also the Message
  default constructor.

#### The `save` and `remove` Members

```cpp
void Message::save(Folder &f)
{
    folders.insert(&f); // add the given Folder to our list of Folders
    f.addMsg(this); // add this Message to f's set of Messages
}
void Message::remove(Folder &f)
{
    folders.erase(&f); // take the given Folder out of our list of Folders
    f.remMsg(this); // remove this Message to f's set of Messages
}
```

#### Copy Control for the `Message` Class

```cpp
// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) // for each Folder that holds m
    f->addMsg(this); // add a pointer to this Message to that Folder
}
```

```cpp
Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); // add this Message to the Folders that point to m
}
```

#### The `Message` Destructor

```cpp
// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
    for (auto f : folders) // for each pointer in folders
    f->remMsg(this); // remove this Message from that Folder
}
```

```cpp
Message::~Message()
{
    remove_from_Folders();
}
```

#### Message Copy-Assignment Operator

In this case, we protect against self-assignment by removing pointers to this
Message from the folders of the left-hand operand before inserting pointers in
the folders in the right-hand operand:

```cpp
Message& Message::operator=(const Message &rhs)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();    // update existing Folders
    contents = rhs.contents;  // copy message contents from rhs
    folders = rhs.folders;    // copy Folder pointers from rhs
    add_to_Folders(rhs);      // add this Message to those Folders
    return *this;
}
```

* Had we called `remove_from_folders` after calling `add_to_folders`, we would
  have removed this `Message` from all of its corresponding `Folders`.

#### A `swap` Function for `Message`

```cpp
void swap(Message &lhs, Message &rhs)
{
    using std::swap; // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders); // uses swap(set&, set&)
    swap(lhs.contents, rhs.contents); // swap(string&, string&)
    // add pointers to each Message to their (new) respective Folders
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}
```

## Classes That Manage Dynamic Memory

#### StrVec Class Design

Each `StrVec` will have three pointers into the space it uses for its elements:

* `elements`, which points to the first element in the allocated memory
* `first_free`, which points just after the last actual element
* `cap`, which points just past the end of the allocated memory

Our class will also have four utility functions:

* `alloc_n_copy` will allocate space and copy a given range of elements.
* `free` will destroy the constructed elements and deallocate the space.
* `chk_n_alloc` will ensure that there is room to add at least one more element
  to the `StrVec`. If there isn’t room for another element, `chk_n_alloc` will
  call `reallocate` to get more space.
* `reallocate` will reallocate the `StrVec` when it runs out of space.

#### `StrVec` Class Definition

```cpp
// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec {
public:
    StrVec(): // the allocator member is default initialized
    elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&); // copy constructor
    StrVec &operator=(const StrVec&); // copy assignment
    ~StrVec(); // destructor
    void push_back(const std::string&); // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    // ...
private:
    std::allocator<std::string> alloc; // allocates the elements
    // used by the functions that add elements to the StrVec
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free(); // destroy the elements and free the space
    void reallocate(); // get more space and copy the existing elements
    std::string *elements; // pointer to the first element in the array
    std::string *first_free; // pointer to the first free element in the array
    std::string *cap; // pointer to one past the end of the array
};
```

#### Using `construct`

```cpp
void StrVec::push_back(const string& s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}
```

#### The `alloc_n_copy` Member

This function returns a `pair` of pointers, pointing to the beginning of the
new space and just past the last element it copied:

```cpp
pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    // initialize and return a pair constructed from data and
    // the value returned by uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}
```

#### The `free` Member

The free member has two responsibilities:

* It must destroy the elements
* Deallocate the space that this StrVec itself allocated.

```cpp
void StrVec::free()
{
    // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
    if (elements) {
        // destroy the old elements in reverse order
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
```

#### Copy-Control Member

```cpp
StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
```

#### Moving, Not Copying, Elements during Reallocation

#### Move Constructors and std::move

> However, we do know that move constructors typically operate by "moving"
> resources from the given object to the object being constructed. We also know
> that the library guarantees that the "moved-from" string remains in a valid,
> destructible state.

#### The `reallocate` Member

```cpp
void StrVec::reallocate()
{
    // we'll allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;
    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    // move the data from the old memory to the new
    auto dest = newdata; // points to the next free position in the new array
    auto elem = elements; // points to the next element in the old array
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free(); // free the old space once we've moved the elements
    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
```

* Calling `move` returns a result that causes `construct` to use the `string`
  move constructor.
* Each string we construct will take over ownership of the memory from the
  string to which elem points.

## Moving Objects

The library containers, `string`, and `shared_ptr` classes support move as well
as copy. The IO and `unique_ptr` classes can be moved but not copied.

### Rvalue Reference

> We cannot bind an lvalue reference to expressions that require a conversion,
> to literals, or to expressions that return an rvalue, but we can bind either
> an *lvalue reference to const* or an *rvalue reference* to such expressions.

```cpp
int i = 42;
int &r = i; // ok: r refers to i
int &&rr = i; // error: cannot bind an rvalue reference to an lvalue
int &r2 = i * 42; // error: i * 42 is an rvalue
const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
int &&rr2 = i * 42; // ok: bind rr2 to the result of the multiplicatio
```

* Functions that return lvalue references, along with the assignment,
  subscript, dereference, and prefix increment/decrement operators, are all
  examples of expressions that return lvalues. We can bind an lvalue reference
  to the result of any of these expressions.
* Functions that return a nonreference type, along with the arithmetic,
  relational, bitwise, and postfix increment/decrement operators, all yield
  rvalues.

#### Lvalues Persist; Rvalues Are Ephemeral

Because rvalue references can only be bound to temporaries, we know that:

* The referred-to object is about to be destroyed
* There can be no other users of that object

#### Variables are Lvalues

```cpp
int &&rr1 = 42; // ok: literals are rvalues
int &&rr2 = rr1; // error: the expression rr1 is an lvalue!
```

* A variable is an lvalue;
* We cannot directly bind an rvalue reference to a variable even if that
  variable was defined as an rvalue reference type.

#### The Library `move` Function

```cpp
int &&rr3 = std::move(rr1); // ok
```

* Calling `move` tells the compiler that we have an lvalue that we want to
  treat as if it were an rvalue.
* It is essential to realize that the call to `move` promises that we do not
  intend to use `rr1` again except to assign to it or to destroy it.
* After a call to `move`, we cannot make any assumptions about the value of the
  moved-from object.

> We can destroy a moved-from object and can assign a new value to it, but we
> cannot use the value of a moved-from object.

### Move Constructor and Move Assignment

```cpp
StrVec::StrVec(StrVec &&s) noexcept // move won't throw any exceptions
// member initializers take over the resources in s
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}
```

* The move constructor does not allocate any new memory;
* It takes over the memory in the given `StrVec`.
* Having taken over the memory from its argument, the constructor body sets the
  pointers in the given object to nullptr.
* After an object is moved from, that object continues to exist.
* Eventually, the moved-from object will be destroyed, meaning that the
  destructor will be run on that object. The `StrVec` destructor calls
  deallocate on `first_free`. If we neglected to change `s.first_free`, then
  destroying the moved-from object would delete the memory we just moved.

#### Move Operations, Library Containers, and Exceptions 

> Unless the library knows that our move constructor won’t throw, it will do
> extra work to cater to the possibliity that moving an object of our class
> type might throw.

```cpp
class StrVec {
public:
    StrVec(StrVec&&) noexcept; // move constructor
    // other members as before
};
StrVec::StrVec(StrVec &&s) noexcept : /* member initializers */
{ /* constructor body */ }
```

We need to indicate that a move operation doesn’t throw because of two
interrelated facts:

1. Although move operations usually don’t throw exceptions, they are
   permitted to do so.  
2. The library containers provide guarantees as to what they do if an
   exception happens.

> As one example, `vector` guarantees that if an exception happens when we call
> `push_back`, the vector itself will be left unchanged.
> 
> To avoid this potential problem, `vector` must use a copy constructor instead
> of a move constructor during reallocation unless it knows that the element
> type’s move constructor cannot throw an exception.
> 
> If we want objects of our type to be moved rather than copied in
> circumstances such as vector reallocation, we must explicity tell the library
> that our move constructor is safe to use. We do so by marking the move
> constructor (and move-assignment operator) `noexcept`.

#### Move-Assignment Operator

```cpp
StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    // direct test for self-assignment
    if (this != &rhs) {
        free();                  // free existing elements
        elements = rhs.elements; // take over resources from rhs
        first_free = rhs.first_free;
        cap = rhs.cap;
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
```

#### A Moved-from Object Must Be Destructible

Sometime after the move operation completes, the moved-from object will be
destroyed.

In addition to leaving the moved-from object in a state that is safe to
destroy, move operations must guarantee that the object remains **valid**.

In general, a valid object is one that can safely be given a new value or used
in other ways that do not depend on its current value. On the other hand, move
operations have no requirements as to the value that remains in the moved-from
object.

> For example, when we move from a library `string` or container object, we
> know that the moved-from object remains valid. As a result, we can run
> operations such as as `empty` or `size` on moved-from objects. However, we
> don’t know what result we’ll get. We might expect a moved-from object to be
> empty, but that is not guaranteed.

#### The Synthesized Move Operations

In particular, if a class defines its own copy constructor, copy-assignment
operator, or destructor, the move constructor and move-assignment operator are
not synthesized. 

------------------------------------------------------------------------------

The compiler will synthesize a move constructor or a move-assignment operator
only:

* If the class doesn't define any of its own copy-control members
* And if every nonstatic data member of the class can be moved.

> The compiler synthesizes the move constructor and move assignment only if a
> class does not define any of its own copy-control members and only if all the
> data members can be moved constructed and move assigned, respectively.

------------------------------------------------------------------------------

The compiler can move members of built-in type. It can also move members of a
class type if the member’s class has the corresponding move operation:
 
```cpp
// the compiler will synthesize the move operations for X and hasX
struct X {
    int i;         // built-in types can be moved
    std::string s; // string defines its own move operations
};
struct hasX {
    X mem;  // X has synthesized move operations
};
X x, x2 = std::move(x);       // uses the synthesized move constructor
hasX hx, hx2 = std::move(hx); // uses the synthesized move constructor
```
 
Unlike the copy operations, a move operation is never implicitly defined as a
deleted function. However, if we explicitly ask the compiler to generate a
move operation by using `= default`, and the compiler is unable to move all the
members, then the move operation will be defined as deleted.

With one important exception, the rules for when a synthesized move operation
is defined as deleted are analogous to those for the copy operations:

* Unlike the copy constructor, the move constructor is defined as deleted if
  the class has a member that defines its own copy constructor but does not
  also define a move constructor, or if the class has a member that doesn’t
  define its own copy operations and for which the compiler is unable to
  synthesize a move constructor. Similarly for move-assignment.
* The move constructor or move-assignment operator is defined as deleted if the
  class has a member whose own move constructor or move-assignment operator is
  deleted or inaccessible.
* Like the copy constructor, the move constructor is defined as deleted **if
  the destructor is deleted or inaccessible**.
* Like the copy-assignment operator, the move-assignment operator is defined as
  deleted if the class **has a const or reference member**.
 
```cpp
// assume Y is a class that defines its own copy constructor
// but not a move constructor

struct hasY {
    hasY() = default;
    hasY(hasY&&) = default;
    Y mem; // hasY will have a deleted move constructor
};
hasY hy, hy2 = std::move(hy); // error: move constructor is deleted
```

* The compiler can copy objects of type `Y` but cannot move them.
* Class `hasY` explicitly requested a move constructor, which the compiler is
  unable to generate. Hence, `hasY` will get a deleted move constructor.
* Had `hasY` omitted the declaration of its move constructor, then the compiler
  would not synthesize the hasY move constructor at all. The move operations
  are not synthesized if they would otherwise be defined as deleted.

> Classes that define a move constructor or move-assignment operator must also
> define their own copy operations. Otherwise, those members are deleted by
> default.

#### Rvalues Are Moved, Lvalues Are Copyied

```cpp
StrVec v1, v2;
v1 = v2;                  // v2 is an lvalue; copy assignment
StrVec getVec(istream &); // getVec returns an rvalue
v2 = getVec(cin);         // getVec(cin) is an rvalue; move assignment
```

In the second assignment, we assign from the result of a call to `getVec`. That
expression is an rvalue. In this case, both assignment operators are viable—we
can bind the result of getVec to either operator's parameter. Calling the
copy-assignment operator requires a conversion to const, whereas `StrVec&&` is
an exact match. Hence, the second assignment uses the move-assignment operator.

#### ...But Rvalues Are Copied If There Is No Move Constructor

```cpp
class Foo {
public:
    Foo() = default;
    Foo(const Foo&);  // copy constructor
    // other members, but Foo does not define a move constructor
};
Foo x;
Foo y(x);            // copy constructor; x is an lvalue
Foo z(std::move(x)); // copy constructor, because there is no move constructor
```

* The call to move(x) in the initialization of z returns a Foo&& bound to x.
* The copy constructor for Foo is viable because we can convert a Foo&& to a
  const Foo&. Thus, the initialization of z uses the copy constructor for Foo.

#### Copy-and-Swap Assignment Operators and Move 

```cpp
class HasPtr {
public:
    // added move constructor
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
    // assignment operator is both the move-and copy-assignment operator
    HasPtr& operator=(HasPtr rhs)
                   { swap(*this, rhs); return *this; }
    // other members as in § 13.2.1 (p. 511)
};
```

* Depending on the type of the argument, copy initialization uses either the
  copy constructor or the move constructor.
* Lvalues are copied and rvalues are moved.
* As a result, this single assignment operator acts as both the copy-assignment
  and move- assignment operator.

```cpp
hp = hp2; //  hp2 is an lvalue; copy constructor used to copy hp2
hp = std::move(hp2); // move constructor moves hp2
```

In the first assignment, the right-hand operand is an lvalue, so the move
constructor is not viable. The copy constructor will be used to initialize rhs.
The copy constructor.
 
In the second assignment, we invoke std::move to bind an rvalue reference to
hp2. In this case, both the copy constructor and the move constructor are viable.
However, because the argument is an rvalue reference, it is an exact match for the
move constructor. The move constructor copies the pointer from hp2. It does not
allocate any memory.

> All five copy-control members should be thought of as a unit: Ordinarily, if
> a class defines any of these operations, it usually should define them all.

#### Move Operations for the Message Class 

However, in addition to moving the folders member, we must also update each
Folder that points to the original Message. We must remove pointers to the old
Message and add a pointer to the new one.

```cpp
// move the Folder pointers from m to this Message
void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders); // uses set move assignment
    for (auto f : folders) {  // for each Folder
        f->remMsg(m);    // remove the old Message from the Folder
        f->addMsg(this); // add this Message to that Folder
    }
    m->folders.clear();  // ensure that destroying m is harmless
}
```

* The function ends by calling clear on m.folders. After the move, we know that
  m.folders is valid but have no idea what its contents are. Because the
  Message destructor iterates through folders, we want to be certain that the
  set is empty.

```cpp
Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_Folders(&m); // moves folders and updates the Folder pointers
}
```

```cpp
Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs) {       // direct check for self-assignment
        remove_from_Folders();
        contents = std::move(rhs.contents); // move assignment
        move_Folders(&rhs); // reset the Folders to point to this Message
    }
    return *this;
}
```

#### Move Iterators

A move iterator adapts its given iterator by changing the behavior of the
iterator’s dereference operator. Ordinarily, an iterator dereference operator
returns an lvalue reference to the element. Unlike other iterators, **the
dereference operator of a move iterator yields an rvalue reference**.

```cpp
void StrVec::reallocate()
{
    // allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    // move the elements
    auto last = uninitialized_copy(make_move_iterator(begin()),
                                   make_move_iterator(end()),
                                   first);
    free();             // free the old space
    elements = first;   // update the pointers
    first_free = last;
    cap = elements + newcapacity;
}
```

> It is worth noting that standard library makes no guarantees about which
> algorithms can be used with move iterators and which cannot. Because moving
> an object can obliterate the source, you should pass move iterators to
> algorithms only when you are confident that the algorithm does not access an
> element after it has assigned to that element or passed that element to a
> user-defined function.

### 13.6.3. Rvalue References and Member Functions
  
```cpp
void push_back(const X&); // copy: binds to any kind of X
void push_back(X&&);      // move: binds only to modifiable rvalues of type X
```

* We can pass only an rvalue that is not const to the second version.
* This version is an exact match (and a better match) for nonconst rvalues and
  will be run when we pass a modifiable rvalue.
* This version is free to steal resources from its parameter.

Ordinarily, there is no need to define versions of the operation that take a
`const X&&` or a (plain) `X&`.

* Usually, we pass an rvalue reference when we want to “steal” from the
  argument. In order to do so, the argument must not be const.
* Similarly, copying from an object should not change the object being copied.
  As a result, there

Overloaded functions that distinguish between moving and copying a parameter
typically have one version that takes a `const T&` and one that takes a `T&&`.

```cpp
class StrVec {
public:
    void push_back(const std::string&);  // copy the element
    void push_back(std::string&&);       // move the element
    // other members as before
};
// unchanged from the original version in § 13.5 (p. 527)
void StrVec::push_back(const string& s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s)
{
    chk_n_alloc(); // reallocates the StrVec if necessary
    alloc.construct(first_free++, std::move(s));
}
```

```cpp
StrVec vec;  // empty StrVec
string s = "some string or another";
vec.push_back(s);      // calls push_back(const string&)
vec.push_back("done"); // calls push_back(string&&)
```

#### Rvalue and Lvalue Reference Member Functions

```cpp
string s1 = "a value", s2 = "another";
auto n = (s1 + s2).find('a');
```

```cpp
s1 + s2 = "wow";
```

```cpp
class Foo {
public:
    Foo &operator=(const Foo&) &; // may assign only to modifiable lvalues
    // other members of Foo
};

Foo &Foo::operator=(const Foo &rhs) &
{
    // do whatever is needed to assign rhs to this object
    return *this;
}
```

* The reference qualifier can be either & or &&, indicating that this may point
  to an rvalue or lvalue, respectively.
* Like the const qualifier, a reference qualifier may appear only on a
  (nonstatic) member function and must appear in both the declaration and
  definition of the function.

We may run a function qualified by `&` only on an lvalue and may run a function qualified by `&&` only on an rvalue.
 
```cpp
Foo &retFoo();  // returns a reference; a call to retFoo is an lvalue
Foo retVal();   // returns by value; a call to retVal is an rvalue
Foo i, j;       // i and j are lvalues
i = j;          // ok: i is an lvalue
retFoo() = j;   // ok: retFoo() returns an lvalue
retVal() = j;   // error: retVal() returns an rvalue
i = retVal();   // ok: we can pass an rvalue as the right-hand operand to assignment
```

A function can be both const and reference qualified. In such cases, the
reference qualifier must follow the `const` qualifier:

```cpp
class Foo{
public:
    Foo someMem() & const;    // error: const qualifier must come first
    Foo anotherMem() const &; // ok: const qualifier comes first
};
```

#### Overloading and Reference Functions

```cpp
class Foo {
public:
    Foo sorted() &&;         // may run on modifiable rvalues
    Foo sorted() const &;    // may run on any kind of Foo
    // other members of Foo
private:
    vector<int> data;
};
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}
// this object is either const or it is an lvalue; either way we can't sort in place
Foo Foo::sorted() const & {
    Foo ret(*this);                         // make a copy
    sort(ret.data.begin(), ret.data.end()); // sort the copy
    return ret;                             // return the copy
}
```

```cpp
retVal().sorted(); // retVal() is an rvalue, calls Foo::sorted() &&
retFoo().sorted(); // retFoo() is an lvalue, calls Foo::sorted() const &
```

When we define two or more members that have the same name and the same
parameter list, we must provide a reference qualifier on **all or none of those
functions**:

```cpp
class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const; // error: must have reference qualifier
    // Comp is type alias for the function type (see § 6.7 (p. 249))
    // that can be used to compare int values
    using Comp = bool(const int&, const int&);
    Foo sorted(Comp*);        // ok: different parameter list
    Foo sorted(Comp*) const;  // ok: neither version is reference qualified
};
```

If a member function has a reference qualifier, all the versions of that member
with the same parameter list must have reference qualifiers.
