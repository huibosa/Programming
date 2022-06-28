doubling test can't tee

-----------------------------------------------------------------------

/home/huibosa/Programming/languages/golang/src/gopl/ch1/ex1.12/server.go

* with empty query value, log gets print double times

-----------------------------------------------------------------------

Some bit wise exercise:

/home/huibosa/Programming/languages/golang/gopl/ch2/ex2.2
/home/huibosa/Programming/languages/golang/gopl/ch2/ex2.3
/home/huibosa/Programming/languages/golang/gopl/ch2/ex2.4
/home/huibosa/Programming/languages/golang/gopl/ch2/ex2.5

-----------------------------------------------------------------------

/home/huibosa/Programming/languages/golang/snippet/one-to-three/one-to-three.go

-----------------------------------------------------------------------

/home/huibosa/Programming/languages/golang/gopl/ch8/select-even

-----------------------------------------------------------------------

/home/huibosa/Packages/Learning/gopl/ex8.9

* use two slices instead

-----------------------------------------------------------------------

What is a re-entrant mutex lock

-----------------------------------------------------------------------

why a net.Conn is passed by value

-----------------------------------------------------------------------

integer division round toward zero

-----------------------------------------------------------------------

long P(long x, long y) {
  long u = Q(y);
  long v = Q(x);
  return u + v;
}

push %rbp
push %rbx
sub  $8, %rsp     # why
mov  %rdi, %rbp
mov  %rsi, %rdi
call Q
mov  %rax, %rbx
mov  %rbp, %rdi
call Q
add  %rbx, %rax
add  $8, %rsp
pop  rbx
pop  rbp

---

write back && write through

---

> Further, the cost of reading the first byte from a disk sector is about
> 100,000 times slower than reading successive bytes in the sector.

---

The data segment follows the code segment after a suitable alignment gap.

---

An important point to realize is that at any point in time, the swap space
bounds the total amount of virtual pages that can be allocated by the currently
running processes.

---

alignment (P309)

---

* errno
* strerro

---

what is dump core
