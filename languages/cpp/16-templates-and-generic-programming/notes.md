## Defining a Template

```cpp
// returns 0 if the values are equal, -1 if v1 is smaller, 1 if v2 is smaller
int compare(const string &v1, const string &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
int compare(const double &v1, const double &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

### Function Templates

```cpp
template<typename T>
int compare(const T& v1, const T& v2) {
    if (v1 < v2) { return -1; }
    if (v2 < v2) { return  1; }

    return 0;
}
```

#### Instantiating a Function Template

```cpp
cout << compare(1, 0) << endl; // T is int

// instantiates int compare(const int&, const int&)
cout << compare(1, 0) << endl; // T is int
// instantiates int compare(const vector<int>&, const vector<int>&)
vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
cout << compare(vec1, vec2) << endl; // T is vector<int>
```

```cpp
int compare(const int &v1, const int &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

#### Template Type Parameters


```
template<typename T> T foo(T* p) {
    T tmp = *p;
    // ...
    return tmp;
}
```

Each type parameter must be preceded by the keyword class or typename:

```cpp
// error: must precede U with either typename or class
template <typename T, U> T calc(const T&, const U&);
```

```
// ok: no distinction between typename and class in a template parameter list
template <typename T, class U> calc (const T&, const U&);
```

#### Nontype Template Parameters 

```cpp
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

compare("hi", "mom");
```

Remembering that the compiler inserts a null terminator at the end of a string
literal:

```cpp
int compare(const char (&p1)[3], const char (&p2)[4])
```

* A nontype parameter may be an **integral type, or a pointer or (lvalue)
  reference to an object or to a function type**.
* An argument bound to a nontype integral parameter must be a constant
  expression.
* Arguments bound to a pointer or reference nontype parameter must have static
  lifetime
* We may not use an ordinary (nonstatic) local object or a dynamic object as a
  template argument for reference or pointer nontype template parameters.
* A pointer parameter can also be instantiated by nullptr or a zero-valued
  constant expression.

#### `inline` and `constexpr` Function Templates

```cpp
// ok: inline specifier follows the template parameter list
template <typename T> inline T min(const T&, const T&);
// error: incorrect placement of the inline specifier
inline template <typename T> T min(const T&, const T&);
```

#### Writing Type-Independent Code

> By making the function parameters references to `const`, we ensure that our
> function can be used on types that cannot be copied.

```cpp
template<typename T>
int compare(const T& v1, const T& v2) {
    if (std::less<T>()(v1, v2)) { return -1; }
    if (std::less<T>()(v2, v1)) { return  1; }
    return 0;
}
```

* The problem with our original version is that if a user calls it with two
  pointers and those pointers do not point to the same array, then our code is
  undefined.

#### Template Compilation

To generate an instantiation, the compiler needs to have the code that defines
a function template or class template member function.

> Definitions of function templates and member functions of class templates are
> ordinarily put into header files.

> Headers for templates typically include definitions as well as declarations

#### Compilation Errors Are Mostly Reported during Instantiation

In general, there are three stages during which the compiler might flag an
error.

* The first stage is when we compile the template itself.
* The second error-detection time is when the compiler sees a use of the
  template.
* The third time when errors are detected is during instantiation.

```cpp
if (v1 < v2) return -1; // requires < on objects of type T
if (v2 < v1) return 1;  // requires < on objects of type T
return 0;               // returns int; not dependent on T
```
  
```cpp
Sales_data data1, data2;
cout << compare(data1, data2) << endl; // error: no < on Sales_data
```

### Class Templates

> Compiler cannot deduce the template parameter type(s) for a class template.

#### Defining a Class Template

```cpp
template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const T &t) {data->push_back(t);}
    // move version; see § 13.6.3 (p. 548)
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    T& back();
    T& operator[](size_type i); // defined in § 14.5 (p. 566)
private:
    std::shared_ptr<std::vector<T>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};
```

#### Instantiating a Class Template

```cpp
Blob<int> ia;                 // empty Blob<int>
Blob<int> ia2 = {0,1,2,3,4};  // Blob<int> with five elements
```

The compiler will instantiate a class that is equivalent to:

```cpp
template <> class Blob<int> {
    typedef typename std::vector<int>::size_type size_type;
    Blob();
    Blob(std::initializer_list<int> il);
    // ...
    int& operator[](size_type i);
private:
    std::shared_ptr<std::vector<int>> data;
    void check(size_type i, const std::string &msg) const;
};
```

```cpp
// these definitions instantiate two distinct Blob types
Blob<string> names; // Blob that holds strings
Blob<double> prices;// different element type
```

#### References to a Template Type in the Scope of the Template

Code in a class template generally doesn’t use the name of an actual type (or
value) as a template argument. Instead, we often use the template’s own
parameter(s) as the template argument(s).

```cpp
std::shared_ptr<std::vector<T>> data;

// Blob<string>
shared_ptr<vector<string>>

// Blob<int>
shared_ptr<vector<int>>
```

#### Member Functions of Class Templates

Therefore, a member function defined outside the class template body starts
with the keyword template followed by the class' template parameter list.

```
// a given member function of StrBlob that was defined as
ret-type StrBlob::member-name(parm-list)

// corresponding Blob member
template <typename T>
ret-type Blob<T>::member-name(parm-list)
```

#### The `check` and Element Access Members

```cpp
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}
```

```cpp
template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i) {
    // if i is too big, check will throw, preventing access to a nonexistent element
    check(i, "subscript out of range");
    return (*data)[i];
}
```

```cpp
template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();  
}
```

#### `Blob` Constructor

```cpp
template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }
```

```cpp
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
        data(std::make_shared<std::vector<T>>(il)) { }

Blob<string> articles = {"a", "an", "the"};
```

#### Instantiation of Class-Template Member Functions

```cpp
// instantiates Blob<int> and the initializer_list<int> constructor
Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
    // instantiates Blob<int>::size() const
    for (size_t i = 0; i != squares.size(); ++i)
        squares[i] = i*i; // instantiates Blob<int>::operator[](size_t)
```

> The fact that members are instantiated only if we use them lets us
> instantiate a class with a type that may not meet the requirements for some
> of the template’s operations 

#### Simplifying Use of a Template Class Name inside Class Code

Inside the scope of the class template itself, we may use the name of the
template without arguments:

```cpp
// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T> class BlobPtr
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; // (*p) is the vector to which this object points
    }
    // increment and decrement
    BlobPtr& operator++(); // prefix operators
    BlobPtr& operator--();
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string&) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr; // current position within the array
};
```

When we are inside the scope of a class template, the compiler treats
references to the template itself as if we had supplied template arguments
matching the template’s own parameters.

As if:

```cpp
BlobPtr<T>& operator++();
BlobPtr<T>& operator--();
```

#### Using a Class Template Name outside the Class Template Body

We are not in the scope of the class until the class name is seen.

```
// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret = *this; // save the current value
    ++*this; // advance one element; prefix ++ checks the increment
    return ret; // return the saved state
}
```

* Because the return type appears outside the scope of the class, we must
  specify that the return type returns a `BlobPtr` instantiated with the same
  type as the class.
* Inside the function body, we are in the scope of the class so do not need to
  repeat the template argument when we define ret.
* When we do not supply template arguments, the compiler assumes that we are
  using the same type as the member’s instantiation.

As if:

```cpp
BlobPtr<T> ret = *this;
```

#### Class Templates and Friends

* When a class contains a friend declaration, the class and the friend can
  independently be templates or not.
* A class template that has a nontemplate friend grants that friend access to
  all the instantiations of the template.
* When the friend is itself a template, the class granting friendship controls
  whether friendship includes all instantiations of the template or only
  specific instantiation(s).

#### One-to-One Friendship

In order to refer to a specific instantiation of a template (class or function)
we must first declare the template itself. A template declaration includes the
template’s template parameter list:

```cpp
// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;
template <typename> class Blob; // needed for parameters in operator==
template <typename T>
    bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> class Blob {
    // each instantiation of Blob grants access to the version of
    // BlobPtr and the equality operator instantiated with the same type
    friend class BlobPtr<T>;
    friend bool operator==<T>
           (const Blob<T>&, const Blob<T>&);
    // other members as in § 12.1.1 (p. 456)
};
```

```cpp
Blob<char> ca; // BlobPtr<char> and operator==<char> are friends
Blob<int> ia;  // BlobPtr<int> and operator==<int> are friends
```

#### General and Specific Template Friendship

```cpp
// forward declaration necessary to befriend a specific instantiation of a template
template <typename T> class Pal;
class C {  //  C is an ordinary, nontemplate class
    friend class Pal<C>;  // Pal instantiated with class C is a friend to C
    // all instances of Pal2 are friends to C;
    // no forward declaration required when we befriend all instantiations
    template <typename T> friend class Pal2;
};
template <typename T> class C2 { // C2 is itself a class template
    // each instantiation of C2 has the same instance of Pal as a friend
    friend class Pal<T>;  // a template declaration for Pal must be in scope
    // all instances of Pal2 are friends of each instance of C2, prior declaration needed
    template <typename X> friend class Pal2;
    // Pal3 is a nontemplate class that is a friend of every instance of C2
    friend class Pal3;    // prior declaration for Pal3 not needed
};
```

* To allow all instantiations as friends, the friend declaration must use
  template parameter(s) that differ from those used by the class itself.

#### Befriending the Template’s Own Type Parameter

```cpp
template <typename Type> class Bar {
friend Type; // grants access to the type used to instantiate Bar
    //  ...
};
```

* Whatever type is used to instantiate `Bar` is a friend.
* Thus, for some type named `Foo`, `Foo` would be a friend of `Bar<Foo>`,
  `Sales_data` a friend of `Bar<Sales_data>`, and so on.

#### Template Type Aliases

```cpp
typedef Blob<string> StrBlob;
```

```cpp
template<typename T> using twin = pair<T, T>;
twin<string> authors; // authors is a pair<string, string>

twin<int> win_loss;  // win_loss is a pair<int, int>
twin<double> area;   // area is a pair<double, double>
```

```cpp
template <typename T> using partNo = pair<T, unsigned>;
partNo<string> books;  // books is a pair<string, unsigned>
partNo<Vehicle> cars;  // cars is a pair<Vehicle, unsigned>
partNo<Student> kids;  // kids is a pair<Student, unsigned>
```

#### `static` Members of Class Templates

```cpp
template <typename T> class Foo {
public:
   static std::size_t count() { return ctr; }
   // other interface members
private:
   static std::size_t ctr;
   // other implementation members
};
```

```cp
// instantiates static members Foo<string>::ctr and Foo<string>::count
Foo<string> fs;
// all three objects share the same Foo<int>::ctr and Foo<int>::count members
Foo<int> fi, fi2, fi3;
```

As with any other static data member, there must be exactly one definition of
each static data member of a template class.

```cpp
template <typename T>
size_t Foo<T>::ctr = 0; // define and initialize ctr
```

```cpp
Foo<int> fi;                 // instantiates Foo<int> class
                             // and the static data member ctr
auto ct = Foo<int>::count;   // instantiates Foo<int>::count

ct = fi.count();             // uses Foo<int>::count
ct = Foo::count();           // error: which template instantiation?
```

### Template Parameters

```cpp
template <typename Foo> Foo calc(const Foo& a, const Foo& b)
{
    Foo tmp = a; // tmp has the same type as the parameters and return type
    // ...
    return tmp; // return type and parameters have the same type
}
```

#### Template Parameters and Scope 

* The name of a template parameter can be used after it has been declared and
  until the end of the template declaration or definition.
* As with any other name, a template parameter hides any declaration of that
  name in an outer scope.
* Unlike most other contexts, however, a name used as a template parameter may
  not be reused within the template:

```cpp
typedef double A;
template <typename A, typename B> void f(A a, B b)
{
    A tmp = a; // tmp has same type as the template parameter A, not double
    double B; // error: redeclares template parameter B
}
```

```cpp
// error: illegal reuse of template parameter name V
template <typename V, typename V> // ...
```

#### Template Declarations

```cpp
// declares but does not define compare and Blob
template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;
```

A template declaration must include the template parameters:

```cpp
// declares but does not define compare and Blob
template <typename T> int compare(const T&, const T&);
template <typename T> class Blob;
```

The names of a template parameter need not be the same across the
declaration(s) and the definition of the same template:

```cpp
// all three uses of calc refer to the same function template
template <typename T> T calc(const T&, const T&); // declaration
template <typename U> U calc(const U&, const U&); // declaration
// definition of the template
template <typename Type>
Type calc(const Type& a, const Type& b) { /* . . . */ }
```

> Declarations for all the templates needed by a given file usually should
> appear together at the beginning of a file before any code that uses those
> names.

#### Using Class Members That Are Types

Assuming `T` is a template type parameter, When the compiler sees code such as
`T::mem` it won’t know until instantiation time whether mem is a type or a
`static` data member.

By default, the language assumes that a name accessed through the scope
operator is not a type. As a result, **if we want to use a type member of a
template type parameter, we must explicitly tell the compiler that the name is
a type**. We do so by using the keyword typename:

```cpp
template <typename T>
typename T::value_type top(const T& c)
{
    if (!c.empty())
    return c.back();
    else
    return typename T::value_type();
}
```

#### Default Template Arguments

```cpp
// compare has a default template argument, less<T>
// and a default function argument, F()
template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}
```
