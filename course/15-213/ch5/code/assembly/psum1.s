# a: %rdi
# p: %rsi
# n: %rdx
# i: %rax

loop:
  movq %rax, %rcx
  subq $1, %rcx
  movq (%rdi, %rax, 8)
