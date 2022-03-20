## Boolean

* for any value `a`, `a ^ a = 0`
* (a ^ b) ^ a = b

## Integer Representation

### Convertion between Signed and Unsigned

### Truncating Numbers

Truncating of an Unsigned number:

$$
x' = x mod 2^k
$$

Truncating of a two's complement number:

$$
x' = U2T_w(x mod 2^k)
$$

## Integer Arithmetic

### Integer Addition

Unsigned Addition:

$$
x +_w^u y =
    \begin{cases}
        x+y & x+y < 2^w & \quad \text{Normal} \\
        x+y-2^w & 2^w \leq x+y < 2^{w+1} & \quad \text{Overflow} \\
    \end{cases}
$$

Two's-Complement Addition:

$$
x +_w^t y =
    \begin{cases}
        x+y-2^w & 2^{w-1} \leq x+y & \quad \text{Positive overflow} \\
        x+y & -2^{w-1} \leq x+x < 2^{w-1} & \quad \text{Normal} \\
        x+y+2^w & x+y < -2^w & \quad \text{Negative overflow} \\
    \end{cases}
$$

### Integer Negation

Unsigned Negation:

$$
-_w^u x =
    \begin{cases}
        x & x = 0 \\
        2^w - x & x > 0 \\
    \end{cases}
$$

Two's-Complement Negation:

$$
-_w^t x =
    \begin{cases}
        TMin_w & x = TMin_w \\
        -x & TMin_w < x \leq Tmax_w \\
    \end{cases}
$$

### Integer Multiplication

Unsigned Multiplication:

$$
x *_u^wy = (x \cdot y) \ mod \ 2^w
$$

Two's Complement Multiplication:

$$
x *_u^ty = U2T_w((x \cdot y) \ mod \ 2^w)
$$

Bit level equivalence of unsigned and two's complement multiplication:

$$
T2B_w(x *_w^t y) = U2B(x' *_w^u y')
$$

### Multiplication by Constant

Unsigned multiplication by a power of 2:

$x \ll k$ yields $x *^u_w 2^k$

Two's complement multiplication by a power of 2:

$x \ll k$ yields $x *^t_w 2^k$

### Dividing by Powers of 2

* Arithmetic right shift always rounds down.
* *Integer division always round toward zero*:

$x \ll k$ yields $\lfloor \frac{x}{2^k} \rfloor$
