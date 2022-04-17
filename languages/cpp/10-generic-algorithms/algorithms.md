## Overview

```cpp
int val = 42;   // value we'll looking for
// result will denote the element we want if it's in vec, or vec.cend() if not
auto result = find(vec.cbegin(), vec.cend(), val);
// report the result
cout << "The value " << val
        << (result == vec.cend() ? " is not present" : " is present")
        << endl;
```

```cpp
string val = "a value";     // value we'll looking for
// this call to find looks through string elements in a list
auto result = find(lst.cbegin(), lst.cend(), val);
```

```cpp
int ia[] = {27, 210, 12, 47, 109, 83};
int val = 83;
int* result = find(begin(ia), end(ia), val);
// search the elements starting from ia[1] up to but not including ia[4]
auto result = find(ia + 1, ia + 4, val);
```

## Read Only Algorithms

```cpp
int sum = accumulate(vec.cbegin(), vec.cend(), 0);
```

### Algorithms and Element Types

```cpp
string sum = accumulate(v.cbegin(), v.cend(), string(""));
// error: no + on const char*
string sum = accumulate(v.cbegin(), v.cend(), "");
```

### Algorithms That Operate on Two Sequences

```cpp
// roster2 should have at least as many elements as roster1
vector<string> roster1;
list<char*> roster2;
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
```

## Algorithms That Write Container Elements

```cpp
fill(vec.begin(), vec.end(), 0);    // reset each element to 0
// set a subsequence of the container to 10
fill(vec.begin(), vec.begin() + vec.max_size() / 2, 10);
```

### Algorithms Do Not Check Write Operations

```cpp
vector<int> vec;    // empty vector
// use vec giving it various values
fill_n(vec.begin(), vec.size(), 0); // reset all the element of vec to 0

fill_n(dest, n, val);

// disaster: attempts to write to ten (nonexistent) elements in vec
fill_n(vec.begin(), 10, 0);
```

### Introducing `back_inserter`

```cpp
vector<int> vec;    // empty vector
auto it = back_inserter(vec);   // assigning through it adds elements to vec
*it = 42;   // vec now has one element with value 42
```

```cpp
vector<int> vec;    // empty vector
// ok: back_inserter creates an insert iterator that adds elements to vec
fill_n(back_inserter(vec), 10, 0);
```

### Copy Algorithms

```cpp
int a1[] = {0,1,2,3,4,5,6,7,8,9};
int a2[sizeof(a1) / sizeof(*a1)];   // a2 has the same size as a1
// ret points just after the last element copied into a2
auto ret = copy(begin(a1), end(a1), a2);
```

```cpp
// replace any element with the value 0 with 42
replace(ilst.begin(), ilst.end(), 0, 42);
// use back_inserter to grow destination as needed
replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(ivec), 0, 42);
```

## Algorithms That Reorder Container Elements

### Eliminating Duplicates

```cpp
void elimDups(vector<string>& words) {
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    // unique reorders the input range so that each word appears once in the
    // front portion of the range and returns an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}
```

### Using `unique`

### Using Container Operation to Remove Elements

## Passing a Function to an Algorithm

### Predicates

```cpp
// comparison function to be used to sort by word length
bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}
// sort on word length, shortest to longest
sort(words.begin(), words.end(), isShorter);
```

### Sorting Algorithms

```cpp
elimDups(words);    // put words in alphabetical order and remove duplicates
// resort by length, maintaining alphabetical order among words of the same length
stable_sort(words.begin(), words.end(), isShorter);
for (const auto &s : words) {     // no need to copy the strings
    cout << s << " ";  
}        // print each element separated by a space
cout << endl;
```

## The Five Iterator Categories

* Input iterator: Read, but not write; single-pass, increment only
* Output iterator: Write, but not read; single-pass, increment only
* Forward iterator: Read and write; multi-pass, increment only
* Bidirectional iterator: Read and write; multi-pass, increment and decrement
* Random-access iterator: Read and write; multi-pass, full iterator arithmetic

## Algorithm Parameter Patterns

```
alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg2, end2, other args);
```

### Algorithm with a Single Destination Iterator

### Algorithm with a Second Input Sequence

## Algorithm Naming Conventions

### Some Algorithms Use Overloading to pass a Predicate

```cpp
unique(beg, end);       // uses the == operator to compare the elements
unique(beg, end, comp); // uses comp to compare the elements
```

### Algorithms with `_if` Versions

```cpp
find(beg, end, val);        // find the first instance of val in the input range
find_if(beg, end, pred);    // find the first instance for which pred is true
```

### Distinguishing Versions That Copy from Those That Do Not

```cpp
reverse(beg, end); // reverse the elements in the input range
reverse_copy(beg, end, dest);// copy elements in reverse order into dest
```

```cpp
// remove odd element from v1
remove_if(v1.begin(), v1.end(), [](int i) { return i & 0x01; });
// copies only the even elements from v1 into v2; v1 is unchanged
remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
                [](int i) { return i & 0x01; });
```

## Container-Specific Algorithm

```cpp
lst.merge(lst2);
lst.merge(lst2, comp);
lst.remove(val);
lst.remove_if(pred);
lst.reverse();
lst.sort();
lst.sort(comp);
lst.unique();
lst.unique(pred);
```

### The `splice` Members

```cpp
lst.splice(p, lst2);
lst.splice(p, lst2, p2);
lst.splice(p, lst2, b, e);

lst.splice_after(p, lst2);
lst.splice_after(p, lst2, p2);
lst.splice_after(p, lst2, b, e);
```

### The List-Specific Operations Do Change the Containers
