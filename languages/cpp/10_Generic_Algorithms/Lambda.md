## Lambda Expressions

```cpp
void elimDups(vector<string>& words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s1.size();
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    // get an iterator to the first element whose size() is >= sz
    // compute the number of elements with size >= sz
    // print words of the given size or longer, each one followed by a space
}
```

------------------------------------------------------------------------------

### Introducint Lambda

A lambda expression has the form:

```
[capture list] (parameter list) -> return type { funcihtion body }
```

* where *capture list* is an (often empty) list of local variables defined in
  the enclosing function;
* *return type*, *parameter list*, and *function body* are the same as in any
  ordinary function.
* However, unlike ordinary functions, a lambda must use a trailing return to
  specify its return type.

```cpp
auto f = [] { return 42; };

cout << f() << endl;
```

* We can omit either or both of the parameter list and return type but must
  always include the capture list and function body:
* Omitting the parentheses and the parameter list in a lambda is equivalent to
  specifying an empty parameter list. Hence, when we call `f`, the argument list
  is empty.
* If we omit the return type, the lambda has an inferred `return` type that
  depends on the code in the function body.
* If the function body is just a `return` statement, the return type is inferred
  from the type of the expression that is returned. Otherwise, the return type
  is `void`.

> Lambdas with function bodies that contain anything other than a single
return statement that do not specify a return type return void.

### Passing Arguments to a Lambda

> Unlike ordinary functions, A lambda may not have default arguments.

A lambda that behaves like our isShorter function:

```cpp
[](const string& a, const string& b) { return a.size() < b.size() };
```

```cpp
// sort words by size, but maintain alphabetical order for words of the same size
stable_sort(words.begin(), words.end(),
            [](const string& a, const string& b) {return a.size() < b.size();})
```

* The empty capture list indicates that this lambda will not use any local
  variables from the surrounding function.

### Using the Capture List

```cpp
[sz](const string& a) { return a.size() > sz }

// error: sz not captured
[](const string& a) { return a.size() > sz }
```

### Calling `find_if`

```cpp
// get an iterator to the first element whose size() is >= sz
auto wc = find_if(words.begin(), words.end(),
                    [sz](const string& a) { return a.size() >= sz; })

// compute the number of elements with size >= sz
count = words.end() - wc;
cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
```

* Although a lambda may appear inside a function, it can use variables local to
  that function only if it specifies which variables it intends to use.
* The call to `find_if` returns an iterator to the first element that is at
  least as long as the given `sz`, or a copy of `words.end()` if no such
  element exists.

### The `for_each` Algorithm

```cpp
// print words of the given size or longer, each one followed by a space
for_each(wc, words.end(), [](const string& s) { cout << s << " "; });
cout << endl;
```

* The capture list is empty, because we use the capture list only for
  (non`static`) variables defined in the surrounding function. 
* So long as the `iostream` header is included in the scope in which `biggies`
  appears, our lambda can use `cout`.

> The capture list is used for local non`static` variables only; lambdas can use
local statics and variables declared outside the function directly.

### Put it All Together

```cpp
void biggies(vector<string>& words, vector<string>::size_type sz) {
    // put words in alphabetical order and remove duplicates
    elimDups(words);
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(),
                [](const string& a, const string& b) { return a.size() < b.size(); });
    // get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string& a) { return a.size() > sz; });
    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    // print words of the given size or longer, each one followed by a space
    for_each(wc, words.end(), [](const string& s) { cout << s << " "; });
    cout << endl;
}
```

## Lambda Captures and Returns

* When we define a lambda, the compiler generates a new (unnamed) class type
  that corresponds to that lambda.
* when we pass a lambda to a function, we are defining both a new type and an
  object of that type: The argument is an unnamed object of this
  compiler-generated class type.
* when we use `auto` to define a variable initialized by a lambda, we are
  defining an object of the type generated from that lambda.

### Capture by Value

Unlike parameters, the value of a captured variable is copied when the lambda
is created, not when it is called:


```cpp
void fcn1() {
    size_t v1 = 42;     // local variable
    // copies v1 into the callable object named f
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();       // j is 42; f stored a copy of v1 when we created it
}
```

### Capture by Reference

```cpp
void fcn2() {
    size_t v1 = 42;     // local variable
    // the object f2 contains a reference to v1
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f2();      // j is 0, f2 refers to v1; it doesn't store it
}
```

```cpp
void biggies(vector<string>& words, vector<string>::size_type sz,
              ostream& os = cout, char c = ' ') {
    // code to reorder words as before
    // statement to print count revised to print to os
    for_each(wc, words.end(), [&os, c](const string& s) { os << s << c; });
}
```

### Implicit Captures

```cpp
auto wc = find_if(words.begin(), words.end(),
                  [=](const string& s) { return s.size() > sz; });
```

```cpp
void biggies(vector<string>& words, vector<string>::size_type sz,
              ostream& os = cout, char c = ' ') {
    // other processing as before
    // os implicitly captured by reference; c explicitly captured by value
    for_each(wc, words.end(), [&, c](const string& s) {return s.size() > sz;});
}
```

### Mutable Lambdas

```cpp
void fcn3() {
    size_t v1 = 42;     // local varialble
    // f can change the value of the varialble it captures
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();   // j is 42
}
```

```cpp
void fcn4() {
    size_t v1 = 42;     // local varialble
    // v1 is a reference to a non const variable
    // we can change that variable through the reference inside f2
    auto f = [&v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();   // j is 1
}
```

### Specifying the Lambda Return Types

```cpp
transform(vi.begin(), vi.end(), vi.begin(),
            [](int i) { return i < 0 ? -i : i; });

// error: cannot deduce the return type for the lambda
transform(vi.begin(), vi.end(), vi.begin(),
            [](int i) {if (i < 0) return -i; else return i;});

transform(v1.begin(), vi.end(), vi.begein(),
            [](int i) -> int { if (i < 0) return -i; else return i });
```

## Binding Arguments

We can’t use this function as an argument to `find_if`. As we’ve seen,
`find_if` takes a unary predicate, so the callable passed to `find_if` must
take a single argument.

```cpp
bool check_size(const string& s, string::size_type sz) {
    return s.size() >= sz;
}
```

------------------------------------------------------------------------------

```cpp
auto newCallable = bind(callable, arg_list);
```

* Where `newCallable` is itself a callable object and `arg_list` is a
  comma-separated list of arguments that correspond to the parameters of the
  given `callable`.
* That is, when we call `newCallable`, `newCallable` calls `callable`, passing
  the arguments in `arg_list`.
* The arguments in `arg_list` may include names of the form `_n`, where `n` is
  an integer. These arguments are "placeholders" representing the parameters
  of `newCallable`. They stand "in place of" the arguments that will be passed
  to `newCallable`. The number `n` is the position of the parameter in the
  generated callable: `_1` is the first parameter in `newCallable`, `_2` is the
  second, and so forth. 

### Binding the `sz` Parameter of `check_size`

```cpp
// check6 is a callable object that takes one argument of type string
// and calls check_size on its given string and the value 6
auto check6 = bind(check_size, placeholders::_1, 6);

string s = "hello";
bool b1 = check6(s);    // check6 calls check_size(s, 6)
```

* This call to bind has only one placeholder, which means that `check6` takes a
  single argument.
* The placeholder appears first in `arg_list`, which means that the parameter in
  check6 corresponds to the first parameter of `check_size`. That parameter is a
  `const strin&`, which means that the parameter in `check6` is also a `const
  string&`.
* Thus, a call to `check6` must pass an argument of type `string`, which `check6`
  will pass as the first argument to `check_size`.

Using `bind`, we can replace our original lambda-based call to `find_if`:

```cpp
auto wc = find_if(words.begin(), words.end(),
                    [sz](const string& a) { return a.size() > sz; });

auto wc = find_if(words.begin(), words.end(), bind(check_size, placeholders::_1, sz))
```

### Using `placeholders` Names

```cpp
using std::placeholder::_1
```

```cpp
// using namespace namspace_name;
using namespace std::palceholders;
```

### Arguments to `bind`

We can use `bind` to bind or rearrange the parameter in the given callable:

```cpp
// g is a callable object that takes two arguments
auto g = bind(f, a, b, placeholders::_2, c, placeholders::_1);

g(placeholders::_1, placeholders::_2);
// maps to
f(a, b, placeholders::_2, c, placeholders::_1);
```

### Using to bind to Reorder Parameters

```cpp
// sort on word length, shortest to longest
sort(words.begin(), words.end(), isShorter);
// sort on word length, longest to shortest
sort(words.begin(), words.end(), bind(isShorter, _2, _1));
```

### Binding Reference Parameters

```cpp
// os is a local variable referring to an output stream
// c is a local variable of type char
for_each(words.begin(), words.end(),
         [&os, c](const string& s) { os << s << endl; });
```

```cpp
ostream& print(ostream& os, const string& s, char c) {
    return os << s << c;
}

// error: cannot copy os
for_each(words.begin(), words.end(), bind(print, os, placeholders::_1, ' '));

for_each(words.begin(), words.end(), bind(print, ref(os), placeholders::_1, ' '));
```
