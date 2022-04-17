# Associative Containers

| Associative Container Types |
| --------------------------- |
| `map`                       |
| `set`                       |
| `multimap`                  |
| `multiset`                  |
| `unordered_map`             |
| `unordered_set`             |
| `unordered_multimap`        |
| `unordered_multiset`        |

## Using an Associative Container

### Using a `map`

```cpp
// count the number of times each word occurs in the input
map<string, size_t> word_count; // empty map from string to size_t
string word;
while (cin >> word)
    ++word_count[word]; // fetch and increment the counter for word
for (const auto &w : word_count) // for each element in the map
    // print the results
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
```

### Using a `set`

```cpp
// count the number of times each word occurs in the input
map<string, size_t> word_count; // empty map from string to size_t
set<string> exclude = {
    "The", "But", "And", "Or", "An", "A",
    "the", "but", "and", "or", "an", "a"};
string word;
while (cin >> word)
    // count only words that are not in exclude
    if (exclude.find(word) == exclude.end())
        ++word_count[word]; // fetch and increment the counter for word
```

## Overview of the Associative Containers

### Defining an Associative Container

```cpp
map<string, size_t> word_count; // empty
// list initialization
set<string> exclude = {
    "the", "but", "and", "or", "an", "a",
    "The", "But", "And", "Or", "An", "A"
};
// three elements; authors maps last name to first
map<string, string> authors = {
    {"Joyce", "James"},
    {"Austen", "Jane"},
    {"Dickens", "Charles"}
};
```

### Initializing a `multimap` or `multiset`

```cpp
// define a vector with 20 elements, holding two copies of each number from 0 to 9
vector<int> ivec;
for (vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i); // duplicate copies of each number
}
// iset holds unique elements from ivec; miset holds all 20 elements
set<int> iset(ivec.cbegin(), ivec.cend());
multiset<int> miset(ivec.cbegin(), ivec.cend());
cout << ivec.size() << endl; // prints 20
cout << iset.size() << endl; // prints 10
cout << miset.size() << endl; // prints 20
```

## Requirements on Key Type

### Key Types for Ordered Containers

> If two keys are equivalent (i.e., if neither is “less than” the other), the
> container treats them as equal. When used as a key to a map, there will be
> only one element associated with those keys, and either key can be used to
> access the corresponding value.

### Using a Comparison Function for the Key Typ

```cpp
bool compareIspn(const Sales_data& lhs, const Sales_data& rhs) {
    return lhs.isbn() < rhs.isbn();
}


// bookstore can have several transactions with the same ISBN
// elements in bookstore will be in ISBN order
multiset<Sales_data, decltype(compareIspn)*> bookstore(compareIspn);
```

## The `pair` Type

```cpp
pair<string, string> anon;          // holds two strings
pair<string, size_t> word_count;    // holds a string and an size_t
pair<string, vector<int>> line;     // holds string and vector<int>

pair<string, string> author{"James", "Joyce"};
```

```cpp
// print the results
cout << w.first << " occurs " << w.second
     << ((w.second > 1) ? " times" : " time") << endl;
```

| Operations on `pair`s        |
| ---------------------------- |
| `pair<T1, T2> p;`            |
| `pair<T1, T2> p(v1, v2);`    |
| `pair<T1, T2> p = {v1, v2};` |
| `make_pair(v1, v2);`         |
| `p.first`                    |
| `p.second`                   |
| p1 *relop* p2                |
| `p1 == p2`                   |
| `p1 != p2`                   |

### A Function to Create `pair` Objects

```cpp
pair<string, int> process(vector<string>& v) {
    // process v
    if (!v.empty())
        return {v.back(), v.back().size()};     // list initialize
    else
        return pair<string, int>();   // explicitly constructed return value
}
```

Earlier versions of C++:

```cpp
if (!v.empty()) {
    return pair<string, int>(v.back(), v.back().size());
}

if (!v.empty()) {
    return make_pair(v.back(), v.back().size());
}
```

## Operations on Associative Containers

| Associative Container Additional Type Aliases |
| --------------------------------------------- |
| `key_type`                                    |
| `value_type`                                  |

```cpp
set<string>::value_type v1;         // v1 is a string
set<string>::key_type v2;           // v2 is a string
map<string, int>::value_type v3;    // v3 is a pair<const string, int>
map<string, int>::key_type v4;      // v4 string
map<string, int>::mapped_type v5;   // v5 is an int
```

## Associative Container Iterators

```cpp
// get an iterator to an element in word_count
auto map_it = word_count.begin();
// *map_it is a reference to a pair<const string, size_t> object
cout << map_it->first;          // prints the key for this element
cout << " " << map_it->second;  // prints the value of the element
map_it->first = "new key";      // error: key is const
++map_it->second;   // ok: we can change the value through an iterator
```

### Iterators for `set`s are `const`

```cpp
set<int> iset = {0,1,2,3,4,5,6,7,8,9};
set<int>::iterator set_it = iset.begin();
if (set_it != iset.end()) {
    *set_it = 42;               // error: keys in a set are read-only
    cout << *set_it << endl;    // ok: can read the key
}
```

### Iterators across Associative Container

```cpp
// get an iterator positioned on the first element
auto map_it = word_count.cbegin();
// compare the current iterator to the off-the-end iterator
while (map_it != word_count.cend()) {
    // dereference the iterator to print the element key--value pairs
    cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it;   // increment the iterator to denote the next element
}
```

>  When we use an iterator to traverse a `map`, `multimap`, `set`, or
>  `multiset`, the iterators yield elements in ascending key order.

### Associative Container and Algorithms

## Adding Elements

| Associative Container `insert` Operations |
| ----------------------------------------- |
| `c.insert(v)`                             |
| `c.emplace(args)`                         |
| `c.insert(b, e)`                          |
| `c.insert(il)`                            |
| `c.insert(p, v)`                          |
| `c.emplace(args)`                         |

```cpp
vector<int> ivec = {2,4,6,8,2,4,6,8};       // ivec has eight elements
set<int> set2;                              // empty set
set2.insert(ivec.cbegin(), ivec.cend());    // set2 has four elements
set2.insert({1,3,5,7,1,3,5,7});             // set2 now has eight elements
```

### Adding Elements to a `map`

```cpp
// four ways to add word to word_count
word_count.insert({word, 1});       // C++11
word_count.insert(make_pair(word, 1));
word_count.insert(pair<string, size_t>(word, 1));
word_count.insert(map<string, size_t>::value_type(word, 1));
```

### Testing the Return from `insert`

```cpp
// more verbose way to count number of times each word occurs in the input
map<string, size_t> word_count; // empty map from string to size_t
string word;
while (cin >> word) {
    // inserts an element with key equal to word and value 1;
    // if word is already in word_count, insert does nothing
    auto ret = word_count.insert({word, 1});
    if (!ret.second)            // word was already in word_count
        ++ret.first->second;    // increment the counter
}
```

### Unwinding the Syntax

```cpp
++(ret.first->second);  // equivalent expression
```

Older compiler:

```cpp
pair<map<string, size_t>::iterator, bool> ret = word_count.insert(make_pair(word, 1));
```

### Adding Elements to `multiset` or `multimap`

```cpp
multimap<string, string> authors;
// adds the first element with the key Barth, John
authors.insert({"Barth, John", "Sot-Weed Factor"});
// ok: adds the second element with the key Barth, John
authors.insert({"Barth, John", "Lost in the Funhouse"});
```

## Erasing Elements

| Removing Elements       | Return Value               |
| :---------------------: | :------------------------: |
| `c.erase(k)`            | number of elements removed |
| `c.erase(p)`            | `void`                     |
| `c.erase(b, e)`         | `void`                     |

```cpp
// erase on a key returns the number of elements removed
if (word_count.erase(removal_word))
     cout << "ok: " << removal_word << " removed\n";
else cout << "oops: " << removal_word << " not found!\n";
```

```cpp
auto cnt = authors.erase("Barth, John");
```

## Subscripting a `map`

| For `map` and `unordered_map` |                                                             |
| ----------------------------- | ----------------------------------------------------------- |
| `c[k]`                        | if `k` is not in `c`, adds a new, value-initialized element |
| `c.at(k)`                     | throws `out-of-range` exception if `k` is not in `c`        |

```cpp
map<string, size_t> word_count;     // empty map
// insert a value-initialized element with key Anna; then assign 1 to its value
word_count["Anna"] = 1;
```

> Because the subscript operator might insert an element, we may use subscript
> only on a map that is not const

### Using the Value Returned from a Subscript Operation

> When we subscript a `map`, we get a `mapped_type` object; when we dereference a
> `map` iterator, we get a `value_type` object.

```cpp
cout << word_count["Anna"];     // fetches the element indexed by Anna; prints 1
++word_count["Anna"];           // fetches the element and add 1 to it
cout << word_count["Anna"];     // fetches the element and print it; prints 2
```

## Accessing Elements

| Find Elements in  Associative Container |
| --------------------------------------- |
| `c.find(k)`                             |
| `c.count(k)`                            |
| `c.lower_bound(k)`                      |
| `c.upper_bound(k)`                      |
| `c.equal_range(k)`                      |

```cpp
set<int> iset = {0,1,2,3,4,5,6,7,8,9};
iset.find(1);   // returns an iterator that refers to the element with key == 1
iset.find(11);  // returns the iterator == iset.end()
iset.count(1);  // returns 1
iset.count(11); // returns 0
```

### Using `find` instead of Subscript for `map`s

```cpp
if (word_count.find("foobar") == word_count.end())
    cout << "foobar is not in the map" << endl;
```

### Finding Elements in a `multimap` or `multiset`

```cpp
string search_item("Alain de Botton"); // author we'll look for
auto entries = authors.count(search_item); // number of elements
auto iter = authors.find(search_item); // first entry for this author
// loop through the number of entries there are for this author
while(entries) {
    cout << iter->second << endl; // print each title
    ++iter;     // advance to the next title
    --entries;  // keep track of how many we've printed
}
```

### A Different, Iterator-Oriented Solution

```cpp
// definitions of authors and search_item as above
// beg and end denote the range of elements for this author
for (auto beg = authors.lower_bound(search_item),
    end = authors.upper_bound(search_item); beg != end; ++beg)
    cout << beg->second << endl; // print each title
```

### The `equal_range` Function

```cpp
// definitions of authors and search_item as above
// pos holds iterators that denote the range of elements for this key
for (auto pos = authors.equal_range(search_item);
    pos.first != pos.second; ++pos.first)
    cout << pos.first->second << endl; // print each title
```

## A Word Transformation Map

```cpp
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file); // store the transformations
    string text; // hold each line from the input
    while (getline(input, text)) { // read a line of input
        istringstream stream(text); // read each word
        string word;
        bool firstword = true; // controls whether a space is printed
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " "; // print a space between words
            // transform returns its first argument or its transformation
            cout << transform(word, trans_map); // print the output
        }
        cout << endl; // done with this line of input
    }
}
```

```cpp
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map; // holds the transformations
    string key; // a word to transform
    string value; // phrase to use instead
    // read the first word into key and the rest of the line into value
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1) // check that there is a transformation
            trans_map[key] = value.substr(1); // skip leading space
    else
        throw runtime_error("no rule for " + key);
    return trans_map;
}
```

```cpp
const string &
transform(const string &s, const map<string, string> &m)
{
    // the actual map work; this part is the heart of the program
    auto map_it = m.find(s);
    // if this word is in the transformation map
    if (map_it != m.cend())
        return map_it->second; // use the replacement word
    else
        return s; // otherwise return the original unchanged
}
```

## The Unordered Containers

> Use an unordered container if the key type is inherently unordered or if
> performance testing reveals problems that hashing might solve.

### Using an Unordered Container

```cpp
// count occurrences, but the words won't be in alphabetical order
unordered_map<string, size_t> word_count;
string word;
while (cin >> word)
    ++word_count[word]; // fetch and increment the counter for word
for (const auto &w : word_count) // for each element in the map
    // print the results
    cout << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
```

### Managing the Buckets

| Buckets Interface       |
| ----------------------- |
| `c.bucket_count();`     |
| `c.max_bucket_count();` |
| `c.bucket_size(n);`     |
| `c.bucket(k);`          |

| Buckets Iteration          |
| -------------------------- |
| `local_iterator`           |
| `const_local_iterator`     |
| `c.begin(n)`, `c.end(n)`   |
| `c.cbegin(n)`, `c.cend(n)` |

| Hash Policy            |
| ---------------------- |
| `c.load_factor();`     |
| `c.max_load_factor();` |
| `c.rehash(n);`         |
| `c.reserve(n);`        |

### Requirements on Key Type for Unordered Containers

```cpp
size_t hasher(const Sales_data &sd) {
    return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
// arguments are the bucket size and pointers to the hash function and equality operator
SD_multiset bookstore(42, hasher, eqOp);
```

If our class has its own `==` operator we can just overide the hash function
```cpp
// use FooHash to generate the hash code; Foo must have an == operator
unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);
```
