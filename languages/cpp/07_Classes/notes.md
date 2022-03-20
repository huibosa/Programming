## Defining Abstract Data Types

### Designing the Sales_data Class 

#### Using the Revised Sales_data Class 

```cpp
Sales_data total; // variable to hold the running sum
if (read(cin, total)) { // read the first transaction
    Sales_data trans; // variable to hold data for the next transaction
    while(read(cin, trans)) { // read the remaining transactions
        if (total.isbn() == trans.isbn()) // check the isbns
            total.combine(trans); // update the running total
        else {
            print(cout, total) << endl; // print the results
            total = trans; // process the next book
        }
    }
    print(cout, total) << endl; // print the last transaction
} else { // there was no input
    cerr << "No data?!" << endl; // notify the user
}
```

### Defining the Revised Sales_data Class 

```cpp
struct Sales_data {
    // new members: operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged from § 2.6.1 (p. 72)
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```

> Functions defined in the class are implicitly inline.

#### Defining Member Functions

```cpp
std::string isbn() const { return bookNo; }
```

#### Introducing `this`

```cpp
total.isbn()
```

* When we call a member function, this is initialized with the address of the
  object on which the function was invoked. 
* The compiler passes the address of total to the implicit this parameter in
  isbn. It is as if the compiler rewrites this call as:

```cpp
// pseudo-code illustration of how a call to a member function is translated
Sales_data::isbn(&total)
```

```cpp
std::string isbn() const { return this->bookNo; }
```

#### Introducing const Member Functions 

* By default, the type of `this` is a const pointer to the nonconst version of
  the class type.
* Although this is implicit, it follows the normal initialization rules, which
  means that (by default) we cannot bind this to a const object
* This fact, in turn, means that we cannot call an ordinary member function on
  a const object.

```cpp
// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
std::string Sales_data::isbn(const Sales_data *const this)
{ return this->isbn; }
```

> Objects that are const, and references or pointers to const objects, may call
> only const member functions.

#### Class Scope and Member Functions

> the compiler processes classes in two steps- the member declarations are
> compiled first, after which the member function bodies, if any, are
> processed. Thus, member function bodies may use other members of their class
> regardless of where in the class those members appear.

#### Defining a Member Function outside the Class

```cpp
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue; // the members of ''this'' object
    return *this; // return the object on which the function was called
}

total.combine(trans); // update the running total

units_sold += rhs.units_sold; // add the members of rhs into
```

### Defining Nonmember Class-Related Functions

> Functions that are conceptually part of a class, but not defined inside the
> class, are typically declared (but not defined) in the same header as the
> class itself.

### Defining the read and print Functions 

```cpp
// input transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}
```

#### Defining the add Function

```cpp
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs); // add data members from rhs into sum
    return sum;
}
```

> By default, copying a class object copies that object’s members.

### Constructors

#### The Synthesized Dedfault Constructor

```cpp
Sales_data total; // variable to hold the running sum
Sales_data trans; // variable to hold data for the next transaction
```

* We did not supply an initializer for these objects, so we know that they are
  default initialized.
* Classes control default initialization by defining a special constructor,
  known as the default constructor.
* The default constructor is one that takes no arguments.

The compiler-generated constructor is known as the synthesized default
constructor. For most classes, this synthesized constructor initializes each
data member of the class as follows:

* If there is an in-class initializer, use it to initialize the member.
* Otherwise, default-initialize the member.

#### Some Classes Cannot Rely on the Synthesized Default Constructor

Reasons that a class must define its own default constructor:

1. The compiler generates the default for us only if we do not define any other
   constructors for the class.
2. for some classes, the synthesized default constructor does the wrong thing.
   classes that have members of built-in or compound type should ordinarily
   either initialize those members inside the class or define their own version
   of the default constructor.
3. **if a class has a member that has a class type, and that class doesn’t have
   a default constructor, then the compiler can’t initialize that member**. For
   such classes, we must define our own version of the default constructor.
   Otherwise, the class will not have a usable default constructor.

#### Defining the `Sales_data` Constructors

```cpp
struct Sales_data {
    // constructors added
    Sales_data() = default;
    C++ Primer, Fifth Edition
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);
    // other members as before
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

#### What `= default` Means

> Under the new standard, if we want the default behavior, we can ask the
> compiler to generate the constructor for us by writing = default after the
> parameter list.

The = default can appear with the declaration inside the class body or on the
definition outside the class body. Like any other function.

* if the = default appears inside the class body, the default constructor will
  be inlined;
* if it appears on the definition outside the class, the member will not be
  inlined by default.

#### Constructor Initializer List

The constructor initializer is a list of member names, each of which is
followed by that member’s initial value in parentheses (or inside curly
braces). Multiple member initializations are separated by commas.

```cpp
Sales_data(const std::string &s): bookNo(s) { }
Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) { }
```

When a member is omitted from the constructor initializer list, it is
implicitly initialized using the same process as is used by the synthesized
default constructor.

```cpp
// has the same behavior as the original constructor defined above
Sales_data(const std::string &s):
    bookNo(s), units_sold(0), revenue(0){ }
```

> Constructors should not override in-class initializers except to use a
> different initial value.

#### Defining a Constructor outside the Class Body 

```cpp
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this); // read will read a transaction from is into this object
}
```

> In this constructor there is no constructor initializer list, although
> technically speaking, it would be more correct to say that the constructor
> initializer list is empty.  Even though the constructor initializer list is
> empty, the members of this object are still initialized before the
> constructor body is executed.

### Copy, Assignment, and Destruction 

```cpp
total = trans; // process the next book

// default assignment for Sales_data is equivalent to:
total.bookNo = trans.bookNo;
total.units_sold = trans.units_sold;
total.revenue = trans.revenue;
```

## Access Control and Encapsulations

```cpp
class Sales_data {
public: // access specifier added
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(std::istream&);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);
private: // access specifier added
    double avg_price() const
    { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

#### Using the class or struct Keyword

If we use the struct keyword, the members defined before the first
access specifier are public; if we use class, then the members are
private.

### Friends

```cpp
class Sales_data {
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    // other members and access specifiers as before
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// declarations for nonmember parts of the Sales_data interface
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
```

> Friend declarations may appear only inside a class definition; they may
> appear anywhere in the class. Friends are not members of the class and are
> not affected by the access control of the section in which they are declared.

#### Declaration for Friends

> A friend declaration only specifies access. It is not a general declaration
> of the function. If we want users of the class to be able to call a friend
> function, then we must also declare the function separately from the friend
> declaration.

## Additional Class Features

#### Defining a Type Member

```cpp
class Screen {
public:
    typedef std::string::size_type pos;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
```

```cpp
class Screen {
public:
    // alternative way to declare a type member using a type alias
    using pos = std::string::size_type;
    // other members as before
};
```

#### Member Functions of class `Screen`

```cpp
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) { }
    char get() const // get the character at the cursor
    { return contents[cursor]; } // implicitly inline
    inline char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c); // can be made inline later
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
```

#### Making Members inline 

```cpp
inline // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c ; // move cursor to the column within that row
    return *this; // return this object as an lvalue
}
char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width; // compute row location
    return contents[row + c]; // return character at the given column
}
```

#### Overloading Member Functions 

```cpp
Screen myscreen;
char ch = myscreen.get();// calls Screen::get()
ch = myscreen.get(0,0); // calls Screen::get(pos, pos)
```

#### `mutable` Data Members 

```cpp
class Screen {
public:
    void some_member() const;
private:
    mutable size_t access_ctr; // may change even in a const object
    // other members as before
};

void Screen::some_member() const
{
    ++access_ctr;   // keep a count of the calls to any member function
    // whatever other work this member needs to do
}
```

#### Initializers for Data Members of Class Type 

```cpp
class Window_mgr {
private:
    // Screens this Window_mgr is tracking
    // by default, a Window_mgr has one standard sized blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ') };
};
```

* In-class initializers must use either the = form of initialization (which we
  used when we initialized the the data members of Screen) or the direct form
  of initialization using curly braces (as we do for screens).

#### 7.3.2. Functions That Return `*this`

```cpp
class Screen {
public:
    Screen &set(char);
    Screen &set(pos, pos, char);
    // other members as before
};
inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this; // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch; // set specified location to given value
    return *this; // return this object as an lvalue
}
```

```cpp
// move the cursor to a given position, and set that character
myScreen.move(4,0).set('#');

// equivalent to 
myScreen.move(4,0);
myScreen.set('#');
```

```cpp
// if move returns Screen not Screen&
Screen temp = myScreen.move(4,0); // the return value would be copied
temp.set('#'); // the contents inside myScreen would be unchanged
```

* If move had a nonreference return type, then the return value of move would
  be a copy of `*this`. The call to set would change the temporary copy, not
  myScreen.

#### Returning `*this` from a `const` Member Function

```cpp
Screen myScreen;
// if display returns a const reference, the call to set is an error
myScreen.display(cout).set('*');
```

* Even though myScreen is a nonconst object, the call to set won’t compile. The
  problem is that the const version of display returns a reference to const and
  we cannot call set on a const object.

#### Overloading Based on const

* The nonconst version will not be viable for const objects;
* we can only call const member functions on a const object.
* We can call either version on a nonconst object, but the nonconst version
  will be a better match.

```cpp
class Screen {
public:
    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os)
    { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
    { do_display(os); return *this; }
private:
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const {os << contents;}
    // other members as before
};
```

```cpp
Screen myScreen(5,3);
const Screen blank(5, 3);
myScreen.set('#').display(cout); // calls non const version
blank.display(cout); // calls const version
```

* We defined do_display inside the class body, so it is implicitly inline.
  Thus, there likely be no run-time overhead associating with calling
  do_display.

### 7.3.3 Class Types

```cpp
struct First {
    int memi;
    int getMem();
};
struct Second {
    int memi;
    int getMem();
};
First obj1;
Second obj2 = obj1; // error: obj1 and obj2 have different types
```

> Even if two classes have exactly the same member list, they are different
> types. The members of each class are distinct from the members of any other
> class (or any other scope).

```cpp
Sales_data item1; // default-initialized object of type Sales_data
class Sales_data item1; // equivalent declaration
```

#### Class Declarations

```cpp
class Screen; // declaration of the Screen class
```

We can use an incomplete type in only limited ways:

* We can define pointers or references to such types, and we can declare (but
  not define) functions that use an incomplete type as a parameter or return
  type.
* A class must be defined—not just declared—before we can write code that
  creates objects of that type.
* The class must be defined before a reference or pointer is used to access a
  member of the type.
* With one exception that we’ll describe in § 7.6 (p. 300), data members can be
  specified to be of a class type only if the class has been defined.
* Because a class is not defined until its class body is complete, a class
  cannot have data members of its own type, but a class can have data members
  that are pointers or references to its own type:

```cpp
class Link_screen {
    Screen window;
    Link_screen *next;
    Link_screen *prev;
};
```

### 7.3.4 Friendship Revisited

A friend function can be defined inside the class body. Such functions are
implicitly inline.

#### Friendship between Classes

```cpp
class Screen {
    // Window_mgr members can access the private parts of class Screen
    friend class Window_mgr;
    // ... rest of the Screen class
};
```

```cpp
class Window_mgr {
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = string(s.height * s.width, ' ');
}
```

#### Making A Member Function a Friend 

```cpp
class Screen {
    // Window_mgr::clear must have been declared before class Screen
    friend void Window_mgr::clear(ScreenIndex);
    // ... rest of the Screen class
};
```

Making a member function a friend requires careful structuring of our programs to
accommodate interdependencies among the declarations and definitions. In this
example, we must order our program as follows:

* First, define the Window_mgr class, which declares, but cannot define, clear.
  Screen must be declared before clear can use the members of Screen.
* Next, define class Screen, including a friend declaration for clear.
* Finally, define clear, which can now refer to the members in Screen.

#### Overloaded Functions and Friendship 

// overloaded storeOn functions
extern std::ostream& storeOn(std::ostream &, Screen &);
extern BitMap& storeOn(BitMap &, Screen &);
class Screen {
    // ostream version of storeOn may access the private parts of
    Screen objects
    friend std::ostream& storeOn(std::ostream &, Screen &);
    // . . .
};

#### Friend Declarations and Scope

Classes and nonmember functions need not have been declared before they are
used in a friend declaration.

When a name first appears in a friend declaration, that name is implicitly
assumed to be part of the surrounding scope. However, the friend itself is not
actually declared in that scope

```cpp
struct X {
    friend void f() { /* friend function can be defined in the class body */ }
    X() { f(); } // error: no declaration for f
    void g();
    void h();
};
void X::g() { return f(); } // error: f hasn't been declared
void f(); // declares the function defined inside X
void X::h() { return f(); } // ok: declaration for f is now in scope
```

## 7.4 Class Scope

### 7.5.4 Implicit Class-Type Conversions

> A constructor that can be called with a single argument defines an implicit
> conversion from the constructor’s parameter type to the class type.

```cpp
string null_book = "9-999-99999-9";
// constructs a temporary Sales_data object
// with units_sold and revenue equal to 0 and bookNo equal to null_book
item.combine(null_book);
```

* That newly generated (temporary) `Sales_data` is passed to `combine`. Because
  combine's parameter is a reference to const, we can pass a temporary to that
  parameter.

#### Only One Class-Type Conversion Is Allowed

The following code is in error because it implicitly uses two conversions:

```cpp
// error: requires two user-defined conversions:
//      (1) convert "9-999-99999-9" to string
//      (2) convert that (temporary) string to Sales_data
item.combine("9-999-99999-9");
```

```cpp
// ok: explicit conversion to string, implicit conversion to Sales_data
item.combine(string("9-999-99999-9"));
// ok: implicit conversion to string, explicit conversion to Sales_data
item.combine(Sales_data("9-999-99999-9"));
```

#### Class-Type Conversions Are Not Always Useful

```cpp
// uses the istream constructor to build an object to pass to combine
item.combine(cin);
```

#### Suppressing Implicit Conversions Defined by Constructors

```cpp
class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) { }
    explicit Sales_data(const std::string &s): bookNo(s) { }
    explicit Sales_data(std::istream&);
    // remaining members as before
};

item.combine(null_book);    // error: string constructor is explicit
item.combine(cin);          // error: istream constructor is explicit
```

> The explicit keyword is meaningful only on constructors that can be called
> with a single argument.

The explicit keyword is used only on the constructor declaration inside the
class. It is not repeated on a definition made outside the class body:

```cpp
// error: explicit allowed only on a constructor declaration in a class header
explicit Sales_data::Sales_data(istream& is) {
    read(is, *this);
}
```

#### `explicit` Constructors Can Be Used Only for Direct Initialization

> When a constructor is declared `explicit`, it can be used only with the direct
> form of initialization. Moroever, the compiler will not use this constructor
> in an automatic conversion.

```cpp
Sales_data item1(null_book); // ok: direct initialization
// error: cannot use the copy form of initialization with an explicit constructor
Sales_data item2 = null_book;
```

#### Explicitly Using Constructors for Conversions

```cpp
// ok: the argument is an explicitly constructed Sales_data object
item.combine(Sales_data(null_book));
// ok: static_cast can use an explicit constructor
item.combine(static_cast<Sales_data>(cin));
```

#### Library Classes with explicit Constructors

Some of the library classes that we’ve used have single-parameter constructors:

* The `string` constructor that takes a single parameter of type const `char*`
  is not `explicit`.
* The `vector` constructor that takes a size is `explicit`.

## `static` Class Members

#### Declaring static Members 

```cpp
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};
```

* Objects do not contain data associated with static data members. Thus, each
  Account object will contain two data members—owner and amount.  There is only
  one interestRate object that will be shared by all the Account objects.
* Similarly, static member functions are not bound to any object; they do not
  have a `this` pointer. This restriction applies both to explicit uses of this
  and **to implicit uses of this by calling a nonstatic member**.

#### Using a Class `static` Member

```cpp
double r;
r = Account::rate(); // access a static member using the scope operator
```

Even though `static` members are not part of the objects of its class, we can
use an object, reference, or pointer of the class type to access a `static`
member:

```cpp
Account ac1;
Account *ac2 = &ac1;
// equivalent ways to call the static member rate function
r = ac1.rate(); // through an Account object or reference
r = ac2->rate(); // through a pointer to an Account object
```

Member functions can use `static` members directly, without the scope operator:

```cpp
class Account {
public:
    void calculate() { amount += amount * interestRate; }
private:
    static double interestRate;
    // remaining members as before
};
```

When we define a `static` member outside the class, we do not repeat the `static`
keyword.

```cpp
void Account::rate(double newRate)
{
    interestRate = newRate;
}
```

Instead, we must define and initialize each `static` data member outside the
class body. Once they are defined, they continue to exist until the program
completes.

```cpp
// define and initialize a static class member
double Account::interestRate = initRate();
This statement defines the object named interestRate that
```

* Once the class name is seen, the remainder of the definition is in the scope
  of the class.
* Note also that even though `initRate` is private, we can use this function to
  initialize `interestRate`. The definition of `interestRate`, like any other
  member definition, has access to the private members of the class.

> The best way to ensure that the object is defined exactly once is to put the
> definition of static data members in the same file that contains the
> definitions of the class noninline member functions.

#### In-Class Initialization of `static` Data Members

* We can provide in-class initializers for static members that have const
  integral type
* and must do so for static members that are constexprs of literal type
* The initializers must be constant expressions.
* Such members are themselves constant expressions; they can be used where a
  constant expression is required.

```cpp
class Account {
public:
    static double rate() { return interestRate; }
    static void rate(double);
private:
    static constexpr int period = 30;// period is a constant expression
    double daily_tbl[period];
};
```

If an initializer is provided inside the class, the member’s definition must
not specify an initial value:

```cpp
// definition of a static member with no initializer
constexpr int Account::period; // initializer provided in the class definition
```

> Even if a const static data member is initialized in the class body, that
> member ordinarily should be defined outside the class definition.

#### static Members Can Be Used in Ways Ordinary Members Can’t 

```cpp
class Bar {
public:
    // ...
private:
    static Bar mem1; // ok: static member can have incomplete type
    Bar *mem2; // ok: pointer member can have incomplete type
    Bar mem3; // error: data members must have complete type
};
```

* A static data member can have incomplete type.
* A static data member can have the same type as the class type of which it is
  a member.
* A nonstatic data member is restricted to being declared as a pointer or a
  reference to an object of its class:

We can use a static member as a default argument:

```cpp
class Screen {
public:
    // bkground refers to the static member
    // declared later in the class definition
    Screen& clear(char = bkground);
private:
    static const char bkground;
};
```
