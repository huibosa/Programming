## Fractional Binary Numbers

$$
\sum^m_{i=-n}2^i \times b_i
$$

Fractional binary notation can only represent numbers that can be written $x \times
2y$.

## IEEE Floating-Point Representation

For 32 bit:

$$
F1 = (-1)^S \times 1.M \times 2^{E-127} \\
F2 = (-1)^S \times 0.M \times 2^{-126}
$$

For 64 bit:

$$
D1 = (-1)^S \times 1.M \times 2^{E-1023} \\ 
D2 = (-1)^S \times 0.M \times 2^{-1022}
$$

$$
V = (-1)^s \times M \times 2^E
$$

Normalized values:

$$
E = e - Bias \\
$$

Where $e = [1, 2^k - 1]$ and $bias = 2^{k-1} - 1$

$$
M = 1 + f
$$

Denormalized values:

$$
E = 1 - Bias
$$

$$
M = f
$$
