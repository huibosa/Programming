# Overloaded Operations and Conversions

```cpp
cout << item1 + item2; // print the sum of two Sales_items

print(cout, add(data1, data2)); // print the sum of two Sales_datas
```

## Basic Concepts

```cpp
// error: cannot redefine the built-in operator for ints
int operator+(int, int);
```

```cpp
x == y + z; // always equivalent to x == (y + z);
```

### Calling an Overloaded Operator Function Directly

```cpp
// equivalent calls to a nonmember operator function
data1 + data2; // normal expression
operator+(data1, data2); // equivalent function call
```

```cpp
data1 += data2; // expression-based ''call''
data1.operator+=(data2); // equivalent call to a member operator function
```

### Some Operators Shouldn’t Be Overloaded

* In particular, the operand-evaluation guarantees of the logical `AND`,
  logical `OR` , and `comma`  operators are not preserved.
* Moreover, overloaded versions of `&&` or `||` operators do not preserve
  short-circuit evaluation properties of the built-in operators. Both operands
  are always evaluated.

### Use Definitions That Are Consistent with the Built-in Meaning

The return type of an overloaded operator usually should be compatible with the
return from the built-in version of the operator:

* The logical and relational operators should return `bool`,
* The arithmetic operators should return a value of the class type,
* The assignment and compound assignment should return a reference to the
  left-hand operand.

### Assignment and Compound Assignment Operators

> After an assignment, the values in the left-hand and right-hand operands
> should have the same value, and the operator should return a reference to its
> left-hand operand.

### Choosing Member or Nonmember Implementation

* The assignment `=`, subscript `[]`, call `()`, and member access arrow `->`
  operators must be defined as members.
* The *compound-assignment* operators ordinarily ought to be members. However,
  unlike assignment, they are not required to be members.
* Operators that change the state of their object or that are closely tied to
  their given type-such as `++`, `--`, and `*`—usually should be members.
* Symmetric operators—those that might convert either operand, such as the
  arithmetic, equality, relational, and bitwise operators—usually should be
  defined as ordinary nonmember functions.

> When we define an operator as a member function, then the left-hand operand
> must be an object of the class of which that operator is a member. 

```cpp
string s = "world";
string t = s + "!";   // ok: we can add a const char* to a string
string u = "hi" + s;  // would be an error if + were a member of string
```

## Input and Output Operators

### Overloading the Output Operator

#### The `Sales_data` Output Operator

```cpp
ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}
```

#### Output Operators Usually Do Minimal Formatting

#### IO Operators Must Be Nonmember Functions

```cpp
Sales_data data;
data << cout; // if operator<< is a member of Sales_data
```

> IO operators usually must be declared as friends

### Overloading the Input Operator `>>`

```cpp
istream &operator>>(istream &is, Sales_data &item)
{
    double price; // no need to initialize; we'll read into price before we use it
    is >> item.bookNo >> item.units_sold >> price;
    if (is) // check that the inputs succeeded
        item.revenue = item.units_sold * price;
    else
        item = Sales_data(); // input failed: give the object the default state
    return is;
}
```

> Input operators must deal with the possibility that the input might fail;
> output operators generally don’t bother.

#### Errors during Input

* A read operation might fail because the stream contains data of an incorrect
  type.
* Any of the reads could hit end-of-file or some other error on the input stream.

> Input operators should decide what, if anything, to do about error recovery.

#### Indicating Errors

> Usually an input operator should set only the failbit. Setting eofbit would
> imply that the file was exhausted, and setting badbit would indicate that the
> stream was corrupted. These errors are best left to the IO library itself to
> indicate.

## Arithmetic and Relational Operators

* Ordinarily, we define the arithmetic and relational operators as *nonmember*
  functions in order to allow conversions for either the left- or right-hand
  operand.
* These operators shouldn’t need to change the state of either operand, so the
  parameters are ordinarily references to const.
* Classes that define an arithmetic operator generally define the corresponding
  compound assignment operator as well.

```cpp
// assumes that both objects refer to the same book
Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum += rhs; // add rhs into sum
    return sum;
}
```

> Classes that define both an arithmetic operator and the related compound
> assignment ordinarily ought to implement the arithmetic operator by using the
> compound assignment.

### Equality Operators

```cpp
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
    lhs.units_sold == rhs.units_sold &&
    lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}
```

* If a class has an operation to determine whether two objects are equal, it
  should define that function as `operator==` rather than as a named function:
* If a class defines `operator==`, that operator ordinarily should determine
  whether the given objects contain equivalent data.
* The equality operator should be transitive.
* If a class defines `operator==`, it should also define `operator!=`. Users
  will expect that if they can use `==` then they can also use `!=,` and vice
  versa.
* One of the equality or inequality operators should delegate the work to the
  other. That is, one of these operators should do the real work to compare
  objects. The other should call the one that does the real work.

### Relational Operators

> If a single logical definition for `<` exists, classes usually should define
> the `<` operator. However, if the class also has `==,` define `<` only if the
> definitions of `<` and `==` yield consistent results.

## Assignment Operators

> Assignment operators can be overloaded. Assignment operators, regardless of
> parameter type, must be defined as member functions.

```cpp
vector<string> v;
v = {"a", "an", "the"};
```

```cpp
class StrVec {
public:
    StrVec &operator=(std::initializer_list<std::string>);
    // other members as in § 13.5 (p. 526)
};
```

To be consistent with assignment for the built-in types, our new assignment
operator will return a reference to its left-hand operand:

```cpp
StrVec &StrVec::operator=(initializer_list<string> il)
{
    // alloc_n_copy allocates space and copies elements from the given range
    auto data = alloc_n_copy(il.begin(), il.end());
    free(); // destroy the elements in this object and free the space
    elements = data.first; // update data members to point to the new space
    first_free = cap = data.second;
    return *this;
}
```

Unlike the copy-and move-assignment operators, this operator does not need to
check for self-assignment.

### Compound-Assignment Operators

> Assignment operators must, and ordinarily compound-assignment operators
> should, be defined as members. These operators should return a reference to
> the left-hand operand.

```cpp
// member binary operator: left-hand operand is bound to the implicit this pointer
// assumes that both objects refer to the same book
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

## Subscript Operator

> The subscript operator must be a member function.

> If a class has a subscript operator, it usually should define two versions:
> one that returns a plain reference and the other that is a `const` member and
> returns a reference to `const`.

```cpp
class StrVec {
public:
    std::string& operator[](std::size_t n)
        { return elements[n]; }
    const std::string& operator[](std::size_t n) const
        { return elements[n]; }
    // other members as in § 13.5 (p. 526)
private:
    std::string *elements; // pointer to the first element in the array
};
```

```cpp
// assume svec is a StrVec
const StrVec cvec = svec; // copy elements from svec into cvec
// if svec has any elements, run the string empty function on the first one
if (svec.size() && svec[0].empty()) {
    svec[0] = "zero"; // ok: subscript returns a reference to a string
    cvec[0] = "Zip"; // error: subscripting cvec returns a reference to const
}
```

## Increment and Decrement Operators

> Classes that define increment or decrement operators should define both the
> prefix and postfix versions. These operators usually should be defined as
> members.

### Defining Prefix Increment/Decrement Operators

```cpp
class StrBlobPtr {
public:
    // increment and decrement
    StrBlobPtr& operator++(); // prefix operators
    StrBlobPtr& operator--();
    // other members as before
};
```

> To be consistent with the built-in operators, the prefix operators should
> return a reference to the incremented or decremented object.

```cpp
// prefix: return a reference to the incremented/decremented object
StrBlobPtr& StrBlobPtr::operator++()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr; // move the current state back one element
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}
```

### Differentiating Prefix and Postfix Operators

> To be consistent with the built-in operators, the postfix operators should
> return the old (unincremented or undecremented) value. That value is returned
> as a value, not a reference.

```cpp
class StrBlobPtr {
    public:
    // increment and decrement
    StrBlobPtr operator++(int); // postfix operators
    StrBlobPtr operator--(int);
    // other members as before
};
```

```cpp
// postfix: increment/decrement the object but return the unchanged value
StrBlobPtr StrBlobPtr::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    StrBlobPtr ret = *this; // save the current value
    ++*this; // advance one element; prefix ++ checks the increment
    return ret; // return the saved state
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    // no check needed here; the call to prefix decrement will do the check
    StrBlobPtr ret = *this; // save the current value
    --*this; // move backward one element; prefix -- checks the decrement
    return ret; // return the saved state
}
```

* Each of our operators calls its own prefix version to do the actual work.

### Calling the Postfix Operators Explicitly

If we want to call the postfix version using a function call, then we must pass
a value for the integer argument:

```cpp
StrBlobPtr p(a1); // p points to the vector inside a1
p.operator++(0); // call postfix operator++
p.operator++(); // call prefix operator++
```

## Member Access Operators

* Operator arrow must be a member. The dereference operator is not required
  to be a member but usually should be a member as well.

```cpp
class StrBlobPtr {
public:
    std::string& operator*() const { 
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; // (*p) is the vector to which this object points
    }
    
    std::string* operator->() const {
        // delegate the real work to the dereference operator
        return & this->operator*();
    }
    // other members as before
};
```

* The dereference operator checks that curr is still in range and, if so,
  returns a reference to the element denoted by curr.
* The arrow operator avoids doing any work of its own by calling the
  dereference operator and returning the address of the element returned by
  that operator.

```cpp
StrBlob a1 = {"hi", "bye", "now"};
StrBlobPtr p(a1); // p points to the vector inside a1
*p = "okay"; // assigns to the first element in a1
cout << p->size() << endl; // prints 4, the size of the first element in a1
cout << (*p).size() << endl; // equivalent to p->size()
```

### Constraints on the Return from Operator Arrow

Depending on the type of point, writing `point->mem` is equivalent to:

```cpp
(*point).mem; // point is a built-in pointer type
point.operator()->mem; // point is an object of class type
```

> The overloaded arrow operator must return either a pointer to a class type or
> an object of a class type that defines its own operator arrow.

## Function-Call Operator

> The function-call operator must be a member function. A class may define
> multiple versions of the call operator, each of which must differ as to the
> number or types of their parameters.

```cpp
struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int i = -42;
absInt absObj; // object that has a function-call operator
int ui = absObj(i); // passes i to absObj.operator()
```

### Function-Object Classes with State

```cpp
class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '):
    os(o), sep(c) { }
    void operator()(const string &s) const { os << s << sep;
}
private:
    ostream &os; // stream on which to write
    char sep; // character to print after each output
};

PrintString printer; // uses the defaults; prints to cout
printer(s); // prints s followed by a space on cout
PrintString errors(cerr, '\n');
errors(s); // prints s followed by a newline on cerr
```

Function objects are most often used as arguments to the generic algorithms:

```cpp
for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
```

### Lambdas Are Function Objects

> When we write a lambda, the compiler translates that expression into an
> unnamed object of an unnamed class, which contains an overloaded
> function-call operator.

```cpp
// sort words by size, but maintain alphabetical order for words of the same size
stable_sort(words.begin(), words.end(),
      [](const string &a, const string &b) { return a.size() < b.size();});
```

```cpp
class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const
        { return s1.size() < s2.size(); }
};

stable_sort(words.begin(), words.end(), ShorterString());
```

* By default, lambdas may not change their captured variables. As a result, by
  default, the function-call operator in a class generated from a lambda is a
  const member function.
* If the lambda is declared as mutable, then the call operator is not const.

#### Classes Representing Lambdas with Captures

```cpp
// get an iterator to the first element whose size() is >= sz
auto wc = find_if(words.begin(), words.end(),
          [sz](const string &a) { return a.size >= sz; }
```

```cpp
class SizeComp {
    SizeComp(size_t n): sz(n) { } // parameter for each captured variable
    // call operator with the same return type, parameters, and body as the lambda
    bool operator()(const string &s) const { return s.size() >= sz; }
private:
    size_t sz; // a data member for each variable captured by value
};

// get an iterator to the first element whose size() is >= sz
auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
```

### Library-Defined Function Objects

```cpp
plus<int> intAdd; // function object that can add two int values
negate<int> intNegate; // function object that can negate an int value
// uses intAdd::operator(int, int) to add 10 and 20
int sum = intAdd(10, 20); // equivalent to sum = 30
sum = intNegate(intAdd(10, 20)); // equivalent to sum = 30
// uses intNegate::operator(int) to generate -10 as the second parameter
// to intAdd::operator(int, int)
sum = intAdd(10, intNegate(10)); // sum = 0
```
  
```cpp
// Arithmetic
std::plus<Type>
std::minus<Type>
std::multiplies<Type>
std::divides<Type>
std::modulus<Type>
std::negate<Type>

// Relational
std::equal_to<Type>
std::not_equal_to<Type>
std::greater<Type>
std::greater_equal<Type>
std::less<Type>
std::less_equal<Type>

// Logical
std::logical_and<Type>
std::logical_or<Type>
std::logical_not<Type>
```

#### Using a Library Function Object with the Algorithms

```cpp
// passes a temporary function object that applies the < operator to two strings
sort(svec.begin(), svec.end(), greater<string>());
```

However, we might want to sort a vector of pointers based on their addresses in
memory. Although it would be undefined for us to do so directly, we can do so
through one of the library function objects:

```cpp
vector<string *> nameTable; // vector of pointers
// error: the pointers in nameTable are unrelated, so < is undefined
sort(nameTable.begin(), nameTable.end(),
    [](string *a, string *b) { return a < b; });
// ok: library guarantees that less on pointer types is well defined
sort(nameTable.begin(), nameTable.end(), less<string*>());
```

### Callable Objects and function

C++ has several kinds of callable objects:

* Functions
* Pointers to functions
* Lambdas
* Objects created by `bind`
* Classes that overload the function-call operator.

* The call signature specifies the type returned by a call to the object and
  the argument type(s) that must be passed in the call.
* A call signature corresponds to a function type. For example:

```cpp
int(int, int)
```

* A function type that takes two `int`s and returns an `int`.

#### Different Types Can Have the Same Call Signature

```cpp
// ordinary function
int add(int i, int j) { return i + j; }

// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j) { return i % j; };

// function-object class
struct div {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};
```

Define a *function table* to store "pointers" to these callables:

```cpp
// maps an operator to a pointer to a function taking two ints and returning an int
map<string, int(*)(int,int)> binops;

// ok: add is a pointer to function of the appropriate type
binops.insert({"+", add}); // {"+", add} is a pair § 11.2.3 (p. 426)

// However, we can't store `mod` or `div` in binops:
binops.insert({"%", mod}); // error: mod is not a pointer to function
```

* The problem is that `mod` is a lambda, and each lambda has its own class type.
  That type does not match the type of the values stored in `binops`.

#### The Library Function Type

```cpp
function<T> f;
function<T> f(nullptr);
function<T> f(obj);
f
f(args)
```

```cpp
result_type
argument_type
first_argument_type
second_argument_type
```

```cpp
function<int(int, int)>

function<int(int, int)> f1 = add; // function pointer
function<int(int, int)> f2 = div(); // object of a function-object class
function<int(int, int)> f3 = [](int i, int j) { return i * j; };  // lambda
cout << f1(4,2) << endl; // prints 6
cout << f2(4,2) << endl; // prints 2
cout << f3(4,2) << endl; // prints 8
```

```cpp
// table of callable objects corresponding to each binary operator
// all the callables must take two ints and return an int
// an element can be a function pointer, function object, or lambda
map<string, function<int(int, int)>> binops;

map<string, function<int(int, int)>> binops = {
    {"+", add},               // function pointer
    {"-", std::minus<int>()}, // library function object
    {"/", div()},             // user-defined function object
    {"*", [](int i, int j) { return i * j; }}, // unnamed lambda
    {"%", mod} };             // named lambda object
}
```

```cpp
binops["+"](10, 5); // calls add(10, 5)
binops["-"](10, 5); // uses the call operator of the minus<int> object
binops["/"](10, 5); // uses the call operator of the div object
binops["*"](10, 5); // calls the lambda function object
binops["%"](10, 5); // calls the lambda function object
```

#### Overloaded Functions and function

We cannot (directly) store the name of an overloaded function in an object of
type function:

```cpp
int add(int i, int j) { return i + j; }
Sales_data add(const Sales_data&, const Sales_data&);
map<string, function<int(int, int)>> binops;
binops.insert( {"+", add} ); // error: which add?
```

```cpp
int (*fp)(int,int) = add; // pointer to the version of add that takes two ints
binops.insert( {"+", fp} ); // ok: fp points to the right version of add
```

```cpp
// ok: use a lambda to disambiguate which version of add we want to use
binops.insert( {"+", [](int a, int b) {return add(a, b);} });
```

## Overloading, Conversions, and Operators
