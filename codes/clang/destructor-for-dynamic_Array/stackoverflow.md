## How to define the destructor to safely free a dynamic array

So, for instance, I have the following code which I want a object's pointer
member to point to a memory which was pointed by another temporary object's
member.

```cpp
struct A {
    int * vals;
    A(): vals(new int[10]) { }
    ~A(){ delete[] vals; }
};

int main() {
    A a;
    {
        A temp;
        for (int i = 0; i < 10; ++i) {
          temp.vals[i] = 100;
        }
        a.vals = temp.vals;
        temp.vals = nullptr;  // avoid double free
    }
```

I set `temp.vals` to `nullptr` in case the destructor of `temp` will free that
memory. So far so good, I guess. However, if I change the `vals` to a dynamic
array, i.e. a pointer to pointers:

```cpp
struct A {
    int ** vals;
    
    A(): vals(new int*[10]) {
        for (int i = 0; i < 10; ++i) {
            vals[i] = new int;
        }
    }
  
    ~A(){
      for (int i = 0; i < 10; ++i) {
          delete vals[i]; // illegal to dereference nullptr
      }
      delete [] vals;
    }
};

int main() {
    A a;
    {
        A temp;
        for (int i = 0; i < 10; ++i) {
            temp.vals[i] = new int(1);
        }
        a.vals = temp.vals;
        temp.vals = nullptr; // avoid double free
    }
}
```

I have add a for loop in destructor to handle the nested allocated memory, and
to avoid the memory be freed by the destructor of `temp`, I set `temp.vals` to
`nullptr`, which, however will cause a segmentation fault since when destructor
of `temp` is called, it is illegal to dereference a `nullptr`.

So my question is, how to correct set the destructor to handle the dynamic array.

I'm not a native speaker, so please forgive my grammar mistakes.
