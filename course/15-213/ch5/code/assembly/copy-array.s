loop:
  movq (%rdi, %rax, 8), %rcx
  movq %rcx, (%rsi, %rax, 8)
  addq $1, %rax
