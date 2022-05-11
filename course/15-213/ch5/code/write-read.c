void write_read(long *src, long *dst, long n) {
  long cnt = n;
  long val = 0;

  while (cnt) {
    *dst = val;
    val = (*src) + 1;
    cnt--;
  }
};

// src in %rdi, dst in %rsi, val in %rax, cnt in %rdx

//   testq %rdx, %rdx
//   je done
//   movq $0, %rax
// loop:
//   movq %rax, (%rsi)
//   movq (%rdi), %rax
//   addq $1, %rax
//   subq $1, %rdx
//   jne loop
// done:
//   ret
// 
