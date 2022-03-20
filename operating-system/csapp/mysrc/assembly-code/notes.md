## 3.3 Data Formats

|C declaration|Intel data type|Assembly-code suffix|Size(bytes)|
|-|-|-|-|
|`char`|Byte|b|1|
|`short`|Word|w|2|
|`int`|Double word|l|4|
|`long`|Quad word|q|8|
|`char *`|Quad word|q|8|
|`float`|Single precision|s|4|
|`double`|Double precision|l|8|

> The assembly code uses the suffix ‘l’ to denote a 4-byte integer as well as
> an 8-byte double-precision floating-point number. This causes no ambigu- ity,
> since floating-point code involves an entirely different set of instructions
> and registers.

## 3.4 Accessing Information

```
rax eax ax al         ; return value
rbx ebx bx bl         ; callee saved
rcx ecx cx cl         ; 4th argument
rdx edx dx dl         ; 3rd argument

rsi esi si sil        ; 2st argument
rdi edi di dil        ; 1st argument

rbp ebp bp bpl        ; callee saved
rsp esp sp spl        ; stack pointer

r8  r8d r8w r8b       ; 5th argument
r9  r9d r9w r9b       ; 6th argument
r10 r10d r10w r10b    ; caller saved
r11 r11d r11w r11b    ; caller saved
r12 r12d r12w r12b    ; callee saved
r13 r13d r13w r13b    ; callee saved
r14 r14d r14w r14b    ; callee saved
r15 r15d r15w r15b    ; callee saved
```

> Those that generate 1- or 2-byte quantities leave the remaining bytes
> unchanged. Those that generate 4- byte quantities set the upper 4 bytes of
> the register to zero.

### 3.4.1 Operand Specifier

Three different operand types:

* immediate
* register
* memory

> $Imm(r_b, r_i, s)$, where $s$ must be 64-bit registers.

### 3.4.2 Data Movement Instructions

```
movl $0x4050, %eax        immediate--register   4 bytes
movw %bp, %sp             register--register    2 bytes
movb (%rdi, %rcx), %al    memory--register      1 bytes
movb $-17, (%esp)         immediate--memory     1 bytes
movq %rax -12(%rbp)       register--memory      8 bytes
```

> x86-64 imposes the restriction that a move instruction cannot have both
> operands refer to memory locations. Copying a value from one memory location
> to another requires two instructions—the first to load the source value into
> a register, and the second to write this register value to the des- tination.

```
movabsq $0x0011223344556677, %rax      ; %rax = 0011223344556677
movb $-1, %al                          ; %rax = 00112233445566FF
movw $-1, %ax                          ; %rax = 001122334455FFFF
movl $-1, %eax                         ; %rax = 00000000FFFFFFFF
movq $-1, %rax                         ; %rax = FFFFFFFFFFFFFFFF
```

* When `movl` has a register as the destination, it will also set the
  high-order 4 bytes of the register to 0.
* The regular `movq` instruction can only have immediate source operands that can
  be represented as 32-bit two’s-complement numbers. This value is then sign
  extended to produce the 64-bit value for the destination.
* The `movabsq` instruction can have an arbitrary 64-bit immediate value as its
  source operand and can only have a register as a destination.

---------------------------------------------------------------------------------

```
movzbw
movzbl
movzbq
movzwl
movzwq
; movzlq can be implemented with movl

movsbw
movsbl
movsbq
movswl
movswq
movslq
cltq      ; sign-extend %eax to %rax
```

* Instructions in the `MOVZ` class fill out the remaining bytes of the
  destination with zeros.
* While those in the `MOVS` class fill them out by sign extension, replicating
  copies of the most significant bit of the source operand.
* for 64-bit destinations, moving with sign extension is supported for all
  three source types, and moving with zero extension is supported for the two
  smaller source types.

### 3.4.3 Pushing and Popping Stack Data

The stack pointer %rsp holds the address of the top stack element.

Pushing a quad word value onto the stack involves first decrementing the stack
pointer by 8 and then writing the value at the new top-of-stack address.

`pushq %rbp`:

```
subq $8, %rsp       ; decrement stack pointer
movq %rbp, (%rsp)   ; store %rbp on stack
```

Popping a quad word involves reading from the top-of-stack location and then
incrementing the stack pointer by 8. 

`popq %rax`:

```
movq (%rsp), %rax
addq $8, %rsp
```

Since the stack is contained in the same memory as the program code and other
forms of program data, programs can access arbitrary positions within the stack
using the standard memory addressing methods.

> Local variables such as x are often kept in registers rather than stored in
> memory locations. 

## 3.5 Arithmetic and Logical Operations

### 3.5.1 Load Effective Address

> Compilers often find clever uses of leaq that have nothing to do with
> effective address computations. The destination operand must be a register.

```c
long scale(long x, long y, long z) {
    long t = x + 4 * y + 12 * z;
    return t;
}
```

```
leaq (%rdi, %rsi, 4), %rax
leaq (%rdx, %rdx, 2), %rdx
leaq (%rax, %rdx, 4), %rax
```

### 3.5.2 Unary and Binary Operations

### Shift Operations

The different shift instructions can specify the shift amount either as an
immediate value or with the single-byte register %cl.

With x86-64, a shift instruction operating on data values that are w bits long
determines the shift amount from the low-order m bits of register %cl, where
$2^m = w$. The higher-order bits are ignored.

So, for example, when register %cl has hexadecimal value 0xFF, then instruction
`salb` would shift by 7, while `salw` would shift by 15, `sall` would shift by
31, and `salq` would shift by 63.

### 3.5.5 Special Arithmetic Operations

* One for unsigned `mulq` and one for two’s-complement `imulq` multiplication.
* For both of these instructions, one argument must be in register `%rax`, and
  the other is given as the instruction source operand.
* The product is then stored in registers `%rdx` (high-order 64 bits) and `%rax`
  (low-order 64 bits).

```c
void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
    *dest = x * (uint128_t) y;
}
```

```
movq %rsi, %rax
mulq %rdx
movq %rax, (%rdi)
movq %rdx, 8(%rdi)
ret
```

* Since the code is generated for a little-endian machine, the high-order bytes
  are stored at higher addresses, as indicated by the address specification
  8(%rdi).

---

* The signed division instruction `idivl` takes as its dividend the 128-bit
  quantity in registers `%rdx` (high-order 64 bits) and `%rax` (low-order 64
  bits).
* The divisor is given as the instruction operand.
* The instruction stores the quotient in register `%rax` and the remainder in
  register `%rdx`.
  
For most applications of 64-bit addition, the dividend is given as a 64-bit
value. This value should be stored in register `%rax`. The bits of `%rdx`
should then be set to either all zeros (unsigned arithmetic) or the sign bit of
`%rax` (signed arithmetic).

```c
void remdiv(long x, long y, long * qp, long * rp) {
    long q = x / y;
    long r = x % y;
    *qp = q;
    *rp = r;
}
```

```
movq %rdx, %r8
movq %rdi, %rax
cqto              ; sign-extend to upper 8 bytes of dividend
idivl %r8
movq %rax, (%r8)
movq %rdx, (%rcx)
ret
```

* `cqto` This instruction takes no operands—it implicitly reads the sign bit
  from %rax and copies it across all of %rdx.

## 3.6 Control

### 3.6.1 Condition Codes

```
CF    (unsigned) t < (unsigned) a           ; unsigned overflow
ZERO  (t == 0)                              ; zero
SF    (t < 0)                               ; negative
OF    (a < 0 == b < 0) && (t < 0 != a < 0)  ; signed overflow
```

* The `leaq` instruction does not alter any condition codes, since it is
  intended to be used in address computations.
* For the logical operations, such as `xor`, the carry and overflow flags are
  set to zero.
* For the shift operations, the carry flag is set to the last bit shifted out,
  while the overflow flag is set to zero.
* For reasons that we will not delve into, the `inc` and `dec` instructions set
  the overflow and zero flags, but they leave the carry flag unchanged.

> Typically, the same operand is repeated (e.g., testq %rax,%rax to see whether
> %rax is negative, zero, or positive), or one of the operands is a mask
> indicating which bits should be tested.

### 3.6.2 Accessing the Condition Codes

|Instruction|Synonym|Effect|Set condition|
|-|-|-|-|
|`sete`|`setz`|`ZF`|Equal/zero|
|`setne`|`setnz`|`~ZF`|Not equal / not zero|
|`sets`||`SF`|Negative|
|`setns`||`~SF`|Nonnegative|
|`setg`|`setnle`|`~(SF^OF) & ZF`|Greater (signed >)|
|`setge`|`setnl`|`~(SF^OF)`|Greater or equal (signed >=)|
|`setl`|`setnge`|`SF^OF`|Less (signed <)|
|`setle`|`setng`|`(SF^OF) | ZF`|Less or equal (signed <=)|
|`seta`|`setnbe`|`CF ^ ~ZF`|Above (unsigned >)|
|`setae`|`setnb`|`~CF`|Above or equal (unsigned >=)|
|`setb`|`setnae`|`CF`|Below (unsigned <)|
|`setbe`|`setna`|`CF | ZF`|Below or equal(unsigned <=)|

```
cmpq %rsi, %rdi
setl %al
movzbl %al, %eax  ; Clear rest of %eax (and rest of %rax)
ret
```

### 3.6.3 Jump Instructions

```
  movq $0, %rax
  jmp .L1
  movq (%rax), %rdx
.L1:
  popq %rdx
```

|Instruction|Synonym|Jump condition|
|`jmp Label`||1|
|`jmp *Operand`||1|
|`je`|`jz`|`ZF`|
|`jne`|`jnz`|`~ZF`|
|`js`||`SF`|
|`jns`||`~SF`|
|`jg`|`jnle`|`~(SF^OF) & ~ZF`|
|`jge`|`jnl`|`~(SF^OF)`|
|`jl`|`jnge`|`SF^OF`|
|`jle`|`jng`|`(SF^OF) | ZF`|
|`ja`|`jnbe`|`~CF & ~ZF`|
|`jae`|`jnb`|`~CF`|
|`jb`|`jnae`|`CF`|
|`jbe`|`jna`|`CF | ZF`|

### 3.6.4 Jump Instruction Encodings

```
  movq %rdi, %rax
  jmp .L2
.L3:
  sarq %rax
.L2:
  testq %rax, %rax
  jg .L3
  rep; ret
```
  
```
0: 48 89          f8 mov %rdi,%rax
3: eb 03          jmp 8 <loop+0x8>
5: 48 d1 f8       sar %rax
8: 48 85 c0       test %rax,%rax
b: 7f f8          jg 5 <loop+0x5>
d: f3 c3          repz retq
```

```
4004d0: 48 89           f8 mov %rdi,%rax
4004d3: eb 03           jmp 4004d8 <loop+0x8>
4004d5: 48 d1 f8        sar %rax
4004d8: 48 85 c0        test %rax,%rax
4004db: 7f f8           jg 4004d5 <loop+0x5>
4004dd: f3 c3           repz retq
```

* The value of the program counter when performing PC-relative addressing is
  the address of the instruction following the jump, not that of the jump
  itself.
* This convention dates back to early implementations, when the processor would
  update the program counter as its first step in executing an instruction.

### 3.6.5 Implementing Conditional Branches with Conditional Control

```
if (test-expr)
  then-statement
else
  else-statement
```

```
  t = (test-expr)
  if (!t)
    goto false:
  then-statement
  goto done;
false:
  else-statement
done:
```

### 3.6.6 Implementing Conditional Branches with Conditional Moves

1. Conditional transfer of *control*
2. Conditional transfer of *data*

```
v = test-expr ? then-expr : else-expr;
```

```
    if (!test-expr)
        goto false;
    v = then-expr;
    goto done;
false:
    v = else-expr;
done:
```

```
v = then-expr;
ve = else-expr;
t = test-expr;
if (!t) v = ve;
```

* For the code based on a conditional move, both the then-expr and the
  else-expr are evaluated, with the final value chosen based on the evaluation
    test-expr.

### 3.6.7 Loops


#### Do-while loops

```
loop:
    body-statements
    t = test-expr
    if (t)
        goto loops
```

```
fact_do:
  movl $1, %eax
.L2:
  imulq %rdi %rax
  subq  $1   %rdi
  cmpq  $1   %rdi
  jg    .L2
  rep; ret
```

------------------------------------------------------------------------------

#### While Loop (Jump-to-middle)

```
    goto test;
loop:
    body-statement
test:
    t = test-expr
    if (t)
        goto loop;
```

```
  movl  $1, %rax
  jmp   .L5
.L6
  imulq %rdi, %rax
  subq  $1, %rdi
.L5
  cmpq  $1, %rdi
  jg    .L6
  rep;ret
```

------------------------------------------------------------------------------

#### While Loops (Guaded-do)

```
    t = test-expr
    if (!t)
        goto done;
loops:
    body-statement
    t = test-expr;
    if (t)
          goto loop;
done:
```

```
fact_while:
  movl %1, %eax
  cmpq $1, %rdi
  jle  .L7
.L6
  imulq %rdi, %rax
  subq  $1, %rdi
  cmpq  $1, %rdi
  jne   .L6
  rep; ret
.L7
  ret
```

* By using a conditional branch to skip over the loop if the initial test
  fails.
* Using this implementation strategy, the compiler can often optimize the
  initial test, for example, determining that the test condition will always
  hold.

#### For Loops (Jump-to-middle)

```
    init-expr;
    goto test;
loop:
    body-statement
    update-expr;
test:
    t = test-expr;
    if (t)
        goto loop;
```

#### For Loops (Guarded-do)

```
init-expr;
    t = test-expr;
    if (!t)
        goto done;
loop:
    body-statement
    update-expr;
    t = test-expr;
    if (t)
done:
```

### 3.6.8 Switch Statements

A jump table is an array where entry i is the address of a code segment
implementing the action the program should take when the switch index equals i.
The code performs an array reference into the jump table using the switch index
to determine the target for a jump instruction. 

```
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	.L8
	leaq	jt.1915(%rip), %rax
	jmp	*.L4(,%rsi,8)
.L3:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	jmp	.L2
.L5:
	addq	$10, %rdi
.L6:
	addq	$11, %rdi
	jmp	.L2
.L7:
	imulq	%rdi, %rdi
	jmp	.L2
.L8:
	movl	$0, %edi
.L2:
	movq	%rdi, (%rdx)
	ret
```

```
.section    .rodata
.align 8          ; align address to multiple of 8
.L4
  .quad	.L3
  .quad	.L8
  .quad	.L5
  .quad	.L6
  .quad	.L7
  .quad	.L8
  .quad	.L7
```

### 3.7.4 Local Storage on the Stack

```
caller:
  subq $16, %rsp
  movq $534, (%rsp)
  movq $1057, 8(%rsp)
  leaq 8(%rsp), %rsi
  movq %rsp, %rdi
  call swap_add 
  movq (%rsp), %rdi
  subq 8(%rsp), %rdx
  imulq %rdi, %rax
  addq %16, %rsp
  ret
```

```
call_proc:
  subq    $32, %rsp
  movq    $1, 24(%rsp)
  movl    $2, 20(%rsp)
  movw    $3, 18(%rsp)
  movb    $4, 17(%rsp)
  
  leaq    17(%rsp), %rax
  movq    %rax, 8(%rsp)   ; can not move from memory to memory
  movq    $4, (%rsp)
  leaq    18(%rsp), %r9
  movl    $3, %r8d
  leaq    20(%rsp), %rcx
  movl    $2, %edx
  leaq    24(%rsp), %rsi
  movl    $1, %edi

  call proc

  movslq  20(%rsp), %rdx
  addq    24(%rsp), %rdx
  
  movswl  18(%rsp), %eax
  movsbl  17(%rsp), %ecx
  subl    %ecx, %eax
  
  cltq
  
  imulq   %rdx, %rax
  
  addq    %32, %rsp
  ret
```

### 3.7.5 Local Storage in Registers

```
P:
  pushq %rbp        ; save rbp
  pushq %rbx        ; save rbx
  subq $8, %rsp
  
  movq %rdi, %rbp
  movq %rsi, %rdi   ; move y to first argument
  call Q
  movq %rax, %rbx   ; save result
  
  movq %rbp, %rdi
  call Q
  
  addq %rbx, %rax
  addq $8, %rsp
  
  popq %rbx         ; restore rbp
  popq %rbp         ; restore rbp
  ret
```

### Reursive Procedures

```
rfact:
  pushq   %rbx
  movq    %rdi, %rbx

  movl    $1, %eax
  cmpq    $1, %rdi
  jle     .L35
  
  leaq    -1(%rdi), %rdi
  call    rfact
  imulq   %rbx, %rax

.L35:
  popq    %rbx
  ret
```
