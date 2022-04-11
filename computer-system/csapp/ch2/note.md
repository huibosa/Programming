```go
const (
	intSize = 32 << (^uint(0) >> 63) // 32 or 64

	MaxInt    = 1<<(intSize-1) - 1
	MinInt    = -1 << (intSize - 1)
	MaxInt8   = 1<<7 - 1
	MinInt8   = -1 << 7
	MaxInt16  = 1<<15 - 1
	MinInt16  = -1 << 15
	MaxInt32  = 1<<31 - 1
	MinInt32  = -1 << 31
	MaxInt64  = 1<<63 - 1
	MinInt64  = -1 << 63
	MaxUint   = 1<<intSize - 1
	MaxUint8  = 1<<8 - 1
	MaxUint16 = 1<<16 - 1
	MaxUint32 = 1<<32 - 1
	MaxUint64 = 1<<64 - 1
)
```

> Floating-point arithmetic has altogether different mathematical properties.
> The product of a set of positive numbers will always be positive, although
> over flow will yield the special value `+inf`.

the C expression `(3.14+1e20)-1e20` will evaluate to `0.0` on most machines,
while `3.14+(1e20- 1e20)` will evaluate to `3.14`.

## 2.1 Information Storage

### 2.1.1 Hexadecimal Notation

### 2.1.2 Data Sizes

### 2.1.3 Addressing and Byte Ordering

Some machines choose to store the object in memory ordered from least
significant byte to most, while other machines store them from most to least.

* The former convention—where the least significant byte comes first—is
  referred to as little endian.
* The latter convention—where the most significant byte comes first—is referred
  to as big endian.

```
Big endian:

  0x100  0x101  0x102  0x103
+------+------+------+------+
|  01  |  23  |  45  |  67  |
+------+------+------+------+
```

```
Little endian:

  0x100  0x101  0x102  0x103
+------+------+------+------+
|  67  |  45  |  23  |  01  |
+------+------+------+------+
```

---------------------------------------------------------------------------

```
4004d3:   01 05 43 0b 20 00       add %eax,0x200b43(%rip)
```

> Having bytes appear in reverse order is a common occurrence when reading
> machine-level program representations generated for little-endian machines such
> as this one. The natural way to write a byte sequence is to have the
> lowest-numbered byte on the left and the highest on the right, but this is
> contrary to the normal way of writing numbers with the most significant digit
> on the left and the least on the right.

### 2.1.4 Representing Strings

### 2.1.4 Representing Strings

### 2.1.5 Representing Code

### 2.1.6 Introduction to Boolean Algebra

Boolean operation `&` distributes over `|`, written `a & (b | c) = (a & b) | (a
& c)`. In addition, however. Boolean operation `|` distributes over `&`, and so
we can write `a | (b & c) = (a | b) & (a | c)`,

* `^` is the *addition* operation, but in this case each element is its own
  additive inverse.
* That is, `a ^ a = 0` for any value `a`, where we use 0 here to represent a
  bit vector of all zeros. We can see this holds for single bits, since `0 ^ 0
  = 1 ^ 1 = 0`, and it extends to bit vectors as well.
* This property holds even when we rearrange terms and combine them in a
  different order, and so `(a ^ b) ^ a = b`.

### 2.1.7 Bit-Level Operations in C

`x ^ 0xff` is equivalent to `~x`

### 2.1.8 Logical Operations in C

the logical operators do not evaluate their second argument if the result of
the expression can be determined by evaluating the first argument. Thus, for
example, the expression `a && 5/a` will never cause a division by zero, and
the expression `p && *p++` will never cause the dereferencing of a null
pointer.

### 2.1.9 Shift Operations in C

## 2.2 Integer Representations

### 2.2.1 Integral Data Types

### 2.2.2 Unsigned Encodings

### 2.2.3 Two’s-Complement Encodings

* |TMin| = |TMax| + 1
* Umax = 2 * TMax + 1

### 2.2.4 Conversions between Signed and Unsigned

#### Conversion from two's complement to unsigned

```python
# For x such that TMin_w <= x <= TMax_w:
if t < 0:
    ret = T2U_w(t + 2**w)
else:
    ret = t
```

#### Unsigned to two's-complement conversion

```python
# For u such that 0 <= u <= UMax_w:
if u <= TMax_w:
    ret = U2T_w(u)
else:
    ret = U2T_w(u - 2**w)
```

### 2.2.5 Signed versus Unsigned in C

### 2.2.6 Expanding the Bit Representation of a Number

* To convert an unsigned number to a larger data type, we can simply add
  leading zeros to the representation; this operation is known as zero
  extension
* For converting a two’s-complement number to a larger data type, the rule is
  to perform a sign extension, adding copies of the most significant bit to the
  representation

This shows that, when converting from short to unsigned, the program first
changes the size and then the type. That is, `(unsigned) sx` is equivalent to
`(unsigned) (int) sx`, evaluating to 4,294,954,951, not `(unsigned) (unsigned
short) sx`, which evaluates to 53,191. Indeed, this convention is required by
the C standards.

### 2.2.7 Truncating Numbers

#### Truncation of an unsigned number

```python
u_trancate = u % 2**k
```

#### Truncating of a two's complement number

```python
t_truncate = U2T_w(t % (2**k))
```

### 2.2.8 Advice on Signed versus Unsigned

## 2.3 Integer Arithmetic

### 2.3.1 Unsigned Addition

#### Unsigned addition

```python
# For x and y such that 0 <= x, y < 2w:
if x + y < 2**w:              # normal
    sum = x + y
elif 2**w <= x+y < 2**(w+1): # overflow
    sum = x + y - 2^w
```

#### Detecting overflow of unsigned addition

```python
# For x and y in the range 0 <= x, y <= UMax_w
def uadd_ok(x, y):
    sum = x + y;
    return sum >= x
```

#### Unsigned negation

```python
# For any number x such that 0 <= x < 2w
if x == 0:
    neg = x
elif x > 0:
    neg = 2**w - x
```

### 2.3.2 Two’s-Complement Addition

#### Two's-complement addition

```python
# For integer values x and y in the range −2^w−1 <= x, y <= 2^{w−1} − 1:
if 2**(w-1) <= x+y:                   # positive overflow
    sum = x + y - 2**w
elif -2**(w-1) <= x+y < 2**(w-1):     # normal
    sum = x + y
elif x + y < -2**(w-1)                # negative overflow
    sum = x + y + 2**w
```

#### Detecting overflow in two's-complement addition

```python
# For x and y in the range TMin_w <= x, y <= TMax_w
def tadd_ok(x, y):
    sum = x + y;

    pos_over = x >= 0 and y >= 0 and sum <  0
    neg_over = x <  0 and y <  0 and sum >= 0:

    return not pos_over and not neg_over
```

### 2.3.3 Two's-Complement Negation

#### Two's-Complement Negation

```python
# For x in the range TMinw ≤ x ≤ TMaxw
if x == Tmin_w
    neg = Tmin_w
elif x > Tmin_w
    neg = -x
```

### 2.3.4 Unsigned Multiplication

#### Unsigned multiplication

```python
ret = (x * y) % 2**w
```

### 2.3.5 Two's-Complement Multiplication

#### Two's-complement multiplication

```python
ret = U2T_w((x * y) % 2**w)
```

### 2.3.6 Multiplying by Constants

#### Unsigned multiplication by a power of 2

```python
# For variables x and k with unsigned values x and k, such that 0 <= k < w,
mult = x << k
```

#### Two’s-complement multiplication by a power of 2

```python
# For variables x and k with unsigned values x and k, such that 0 <= k < w,
mult = x << k
```

Note that multiplying by a power of 2 can cause overflow with either unsigned
or two’s-complement arithmetic.

Generalizing from our example, consider the task of generating code for
the expression `x * K`, for some constant `K`. The compiler can express the binary
representation of `K` as an alternating sequence of zeros and ones:

```
[(0...0)(1...1)(0...0)... (1...1)]
```

For example, 14 can be written as `[(0...0)(111)(0)]`. Consider a run of ones from
bit position n down to bit position m (n ≥ m). (For the case of 14, we have n = 3
and m = 1.) We can compute the effect of these bits on the product using either of
two different forms:

```
Form A: (x<<n) + (x<<(n − 1)) + . . . + (x<<m)
Form B: (x<<(n + 1)) - (x<<m)
```

> The two computations will yield the same result, regardless of whether x is
> unsigned or two’s comple- ment, and even if the multiplication would cause an
> overflow.

### 2.3.7 Dividing by Powers of 2

> Integer division always round toward zero.

#### Unsigned division by a power of 2

```python
quotient = floor(x >> k)
```

#### Two’s-complement division by a power of 2, rounding down

As an example of a For the case when no rounding is required (k = 1), the
result will be x/2k. When rounding is required, shifting causes the result to
be rounded downward.

#### Two’s-complement division by a power of 2, rounding up

```
x/2^k = (x < 0 ? x + (1<<k)-1 : x) >> k
```

| k | Bias |
| - | ---- |
| 0 | 0    |
| 1 | 1    |
| 4 | 15   |
| 8 | 255  |

## 2.4 Floating Point

### 2.4.1 Fractional Binary Numbers
