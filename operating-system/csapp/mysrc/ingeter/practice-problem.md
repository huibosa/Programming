## 2.8

```
a   01001110
b   11100001
~a  10110001
~b  00011110
a&b 01000000
a|b 11101111
a^b 10101111
```

## 2.9

complement

```
0 0 0 Black     1 1 1 White
0 0 1 Blue      1 1 0 Yellow
0 1 0 Green     1 0 1 Magenta
0 1 1 Cyan      1 0 0 Red
1 0 0 Red       0 1 1 Cyan
1 0 1 Magenta   0 1 0 Green
1 1 0 Yellow    0 0 1 Blue
1 1 1 White     0 0 0 Black
```

```
Blue   | Green   = 0 1 1  Cyan
Yellow & Cyan    = 0 1 0  Green
Red    ^ Magenta = 0 0 1  Blue
```

## 2.10

```
Step      *x      *y
Init      a       b
Step 1    a       b^a
Step 2    a^b^a   b^a
Step 3    a^b^a   a^b^a^b^a
```
