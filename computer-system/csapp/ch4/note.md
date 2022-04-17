## 4.1 The Y86-64 Instruction Set Architecture

### 4.1.1 Programmer-Visible State

### 4.1.2 Y86-64 Instructions

### 4.1.3 Instruction Encoding

### 4.1.4 Y86-64 Exceptions

### 4.1.5 Y86-64 Programmers

### 4.1.6 Some Y86-64 Instruction Details

## 4.2 Logic Design and the Hardware Control Language HCL

### Logic Gates

### 4.2.2 Combinational Circuits and HCL Boolean Expressions

Several restrictions are placed on how the combinational circuits are
constructed:

* Every logic gate input must be connected to exactly one of the following:
  1. One of the system inputs (known as a *primary input*)
  2. The output connection of some memory element
  3. The output of some logic gate.
* The outputs of two or more logic gates cannot be connected together.
* The network must be `acyclic`. 

#### Xor

```hcl
bool eq = (a && b) || (!a && !b)
```

#### Multiplexor

```hcl
bool out = (s && a) | (!s && b)
```

### 4.2.3 Word-Level Combinational Circuits and HCL Integer Expressions

HCL allows words to be compared for equality, and so the functionality of the
circuit shown in Figure 4.12 can be expressed at the word level as

```hcl
bool Eq = (A == B)
```

```hcl
int Out = [
  s: A;
  1: B;
]
```

```hcl
word Out4 = [
  !s1 && !s0 : A; # 00
  !s1        : B; # 01
  !s0        : C; # 10
  1          : D; # 11
]
```

For example, the second expression can be written `!s1`, rather than the more
complete `!s1 && s0`, since the only other possibility having `s1` equal to `0` was
given as the first selection expression. Similarly, the third expression can be
written as `!s0`, while the fourth can simply be written as `1`.

```hcl
word Min3 = [
  A <= B && A <= C : A;
  B <= A && B <= C : B;
  1                : C;
]
```

### 4.2.4 Set Membership
