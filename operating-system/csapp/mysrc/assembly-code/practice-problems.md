## Practice Problem

### Practice Problem 3.1

|Address|Value|Register|Value|
|-|-|-|-|
|0x100|0xFF|%rax|0x100|
|0x104|0xAB|%rcx|0x1|
|0x108|0x13|%rdx|0x3|
|0x10C|0x11|||

```
%rax              ; 0x100
0x104             ; 0xAB
$0x108            ; 0x108
(%rax)            ; 0xFF
4(%rax)           ; 0xAB
9(%rax,%rdx)      ; 0x11
260(%rcx,%rdx)    ; 0x13
0xFC(,%rcx,4)     ; 0xFF
(%rax,%rdx,4)     ; 0x11
```

### Practice Problem 3.2

```
movl  %eax, (%rsp)
movw  (%rax), %dx
movb  $0xFF, %bl
movb  (%rsp,%rdx,4), %dl
movq  (%rdx), %rax
movw  %dx, (%rax)
```

> Memory references in x86-64 are always given with quad word registers, such
> as %rax, even if the operand is a byte, single word, or double word.

### Practice Problem 3.3

```
movb $0xF, (%ebx)      ; Cannot use %ebx as address register
movl %rax, (%rsp)      ; Mismatch between instruction suffix and register ID
movw (%rax), 4(%rsp)   ; Cannot have both source and destination be memory references
movb %al, %sl          ; No register named %sl
movq %rax, $0x123      ; Cannot have immediate as destination
movl %eax, %rdx        ; Destination operand incorrect size
movb %si, 8(%rbp)      ; Mismatch between instruction suffix and register ID
```

### Practice Problem 3.4

```
src_t * sp;
dest_t * dp;
*dp = (dest_t) * sp;

+===============+===============+=======================+
| src_t         | dest_t        |      Instructions     |
+===============+===============+=======================+
| long          | long          |  movq (%rdi), %rax    |
|               |               |  movq %rax, (%rsi)    |
+---------------+---------------+-----------------------+
| char          | int           |  movsbl (%rdi), %eax  |
|               |               |  movl %eax, (%rsi)    |
+---------------+---------------+-----------------------+
| char          | unsigned      |  movsbl (%rdi), %eax  |
|               |               |  movl %eax, (%rsi)    |
+---------------+---------------+-----------------------+
| unsigned char | long          |  movzbl (%rdi), %eax  |***********
|               |               |  movq %rax, (%rsi)    |***********
+---------------+---------------+-----------------------+
| int           | char          |  movl (%rdi), %eax    |
|               |               |  movb %al, (%rsi)     |
+---------------+---------------+-----------------------+
| unsigned      | unsigned char |  movl (%rdi), %eax    |
|               |               |  movb %al, (%rsi)     |
+---------------+---------------+-----------------------+
| char          | short         |  movsbw (%rdi), %ax   |
|               |               |  movw %ax, (%rsi)     |
+---------------+---------------+-----------------------+
```

### Practice Problem 3.5

```c
void decode1(long *xp, long *yp, long *zp);
// xp in %rdi, yp in %rsi, zp in %rdx

decode1:
movq (%rdi), %r8
movq (%rsi), %rcx
movq (%rdx), %rax
movq %r8, (%rsi)
movq %rcx, (%rdx)
movq %rax, (%rdi)
ret

void decode1(long * xp, long * yp, long * zp) {
  long x = *xp;
  long y = *yp;
  long z = *zp;

  *xp = z;
  *yp = x;
  *zp = y;

  return;
}
```

### Practice Problem 3.6

> Suppose register `%rbx` holds value `p` and `%rdx` holds value `q`.

```
leaq 9(%rdx), %rax            ; 9 + q
leaq (%rdx, %rbx), %rax       ; p + q
leaq (%rdx, %rbx, 3), %rax    ; 3p + q
leaq 2(%rbx, %rbx, 7), %rax   ; 8p + 2
leaq 0xE(, %rdx, 3), %rax     ; 3q + 14
leaq 6(%rbx, %rdx, 7), %rax   ; 7q + p + 6
```

### Practice Problem 3.7

```c
short scale3(short x, short y, short z) {
    short t = x * y + 10 * y + z;
    return t;
}
```

```
leaq (%rsi, %rsi, 9), %rbx    ; 10 * y
leaq (%rbx, %rdx), %rbx       ; 10 * y + z 
leaq (%rbx, %rdi, %rsi), %rbx ; x * y + 10 * y + z
ret
```

### Practice Problem 3.8

|Address|Value|Register|Value|
|-|-|-|-|
|0x100|0xFF|%rax|0x100|
|0x108|0xAB|%rcx|0x1|
|0x110|0x13|%rdx|0x3|
|0x118|0x11|||

|Instruction|Destination|Value|
|-|-|-|
|`addq %rcx,(%rax)`|0x100|0x100|
|`subq %rdx,8(%rax)`|0x108|0xA8|
|`imulq $16,(%rax,%rdx,8)`|0x118|0x110|
|`incq 16(%rax)`|0x110|0x14|
|`decq %rcx`|%rcx|0x0|
|`subq %rdx,%rax`|%rax|0xFD|

### Practice Problem 3.9

```c
long shift_left4_rightn(long x, long n) {
    x <<= 4;
    x >>= n;
    return x;
}
```

```
shift_left4_rightn:
movq %rdi, %rax
salq $4, %rax
movl %esi, %ecx
sarq %cl, %rax
```

### Practice Problem 3.10

```c
short arith3(short x, short y, short z) {
  short p1 = z | y;
  short p2 = p1 >> p1;
  short p3 = ~p2;
  short p4 = y - p3;
}
```

### Practice Problem 3.11

```
xorq %rcx, %rcx
```

1. This instruction is used to set register %rcx to zero, exploiting the
   property that x ^ x = 0 for any x. It corresponds to the C statement x = 0.
2. A more direct way of setting register %rcx to zero is with the instruction
   movq $0,%rcx.
3. Assembling and disassembling this code, however, we find that the version
   with xorq requires only 3 bytes, while the version with movq requires 7.
   Other ways to set %rcx to zero rely on the property that any instruction
   that updates the lower 4 bytes will cause the high-order bytes to be set to
   zero. Thus, we could use either xorl %ecx,%ecx (2 bytes) or movl $0,%ecx (5
   bytes).

```
0:   48 31 c9                xor    %rcx,%rcx
3:   48 c7 c1 00 00 00 00    mov    $0x0,%rcx
a:   89 c9                   mov    %ecx,%ecx
c:   b9 00 00 00 00          mov    $0x0,%ecx
```

### Practice Problem 3.12

```c
void uremdiv(unsigned long x, unsigned long y, unsigned long *qp,
             unsigned long *rp) {
    unsigned long q = x / y;
    unsigned long r = x % y;
    *qp = q;
    *rp = r;
}
```

```
movq %rdx, %r8
movq %rdi, %rax
xorl %edx, %edx
div %rsi
movq %rdx, (%r8)
movq %rax, (%rcx)
ret
```

### Practice Problem 3.13

```c
int comp(data_t a, data_t b) {
    return a COMP b;
}
```

```
cmpl %esi, %edi
setl %al

typedef int data_t
#define CMP <
```

```
cmpw %si, %di
setge %al

typedef short data_t
#define CMP >=
```

```
cmpl %sil, %dil
setbe %al

typedef unsigned char data_t
#define CMP <=
```

```
cmpq %rsi, %rdi
setne %al

typedef long data_t ||
typedef unsigned long data_t ||
typedef char * data_t ||
#define CMP !=
```

### Practice Problem 3.14

```c
int test(data_t a) {
    return a TEST 0;
}
```

```
testq %rdi, %rdi
setge %al

typedef long data_t
#define TEST >=
```

```
testw %di, %di
sete %al

typedef unsigned short data_t
typedef short data_t
#define TEST ==
```

```
testb %dil, %dil
seta %al

typedef unsigned char data_t
#define TEST >
```

```
testl %edi, %edi
setle %al

typedef int data_t
#define TEST <=
```

### Practice Problem 3.15

```
4003fa:     74 02       je 4003fe
4003fc:     ff d0       callq *%rax
```

```
40042f:     74 f4       je 400525
400431:     5d          pop %rbp
```

```
400543:     77 02       ja 400547
400545:     5d          pop %rbp
```

```
4005e8:     e9 73 ff ff ff jmpq 400560
4005ed:     90 nop
```

### Practice Problem 3.16

```c
void cond(short a, short * p) {
    if (a && *p < a)
        *p = a;
}
```

```
cond:
  testq %rdi, %rdi
  je .L1
  cmpq %rsi, (%rsi)
  jge .L1
  movq %rdi, (%rsi)
.L1:
  rep; ret
```

```c
void cond(short a, short * p) {
  if (a == 0)
    goto done;
  if (*p <= a)
    goto done;
  *p = a;
done:
  return;
}
```

### Practice Problem 3.17

```
long gotdiff_se2(long x, long y) {
    long result;
    if (x < y) {
        goto x_l_y;
    }
    ge_cnt++;
    result = x - y;
x_l_y:
    lt_cnt++;
    result = y - x;
    return result;
}
```

### Practice Problem 3.18

```
test:
  leaq  (%rdi + %rsi), %rax     ; ret = x + y
  subq  %rdi, %rax              ; ret -= x
  cmpq  $5, %rdx                ; cmp = compare(z - 5)
  jle   .L2                     ; if z <= 5, goto .L2
  cmpq  $2, %rsi                ; cmp = compare(y - 2)
  jle   .L3                     ; if y <= 2 goto .L3
  movq  %rdi, %rax              ; ret = x
  idivq %rdx, %rax              ; rax /= z
  ret
.L3:
  movq  %rdi, %rax              ; ret = x
  idivq %rsi, %rax              ; ret /= y
.L2:
  cmpq  $3, %rdx                ; cmp = compare(z - 3)
  jge   .L4                     ; if z >= 3, goto .L4
  movq %rdx, %rax               ; ret = z
  idivq %rsi, %rax              ; ret /= y
.L4:
  rep; ret
```

```c
short test(short x, short y, short z) {
  short val = y + z - x;
  if (z > 5) {
    if (y > 2) {
      val = x / z;
    } else {
      val = x / y;
    }
  } else if (z < 3) {
    val = z / y;
  }
  return val;
}
```

### Practice Problem 3.19

> Running on a new processor model, our code required around 45 cycles when the
> branching pattern was random, and around 25 cycles when the pattern was
> highly predictable.
>
> 1. What is the approximate miss penalty?
> 2. How many cycles would the function require when the branch is mispre-
>    dicted?

1. $T_{MP} = 2 (45 - 25) = 40$
