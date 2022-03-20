## Forward_list

```c
list.insert_after(p, t);
list.insert_after(p, n, t);
list.insert_after(p, b, e);
list.insert_after(p, il);
```

* Returns iterator to last inserted element.

```c
list.erase_after(p);
list.erase_after(b, e);
```

* Returns iterator to the element after the last one deleted.

## Others

```c
c.erase(p);
c.erase(b, e);
```

* Returns iterator to the element after the last one deleted.

```c
c.insert(p, t);
c.insert(p, n, t);
c.insert(p, b, n);
c.insert(p, il);
```

* Returns iterator to first inserted element.
