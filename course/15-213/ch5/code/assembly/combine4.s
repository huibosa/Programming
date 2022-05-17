# %xmm0:  acc
# %rdx:   data + i
# %rax:   data + length
loop:
  vmulsd (%rdx), %xmm0, %xmm0 
  addq $8, %rdx
  cmpq %rax, %rdx
