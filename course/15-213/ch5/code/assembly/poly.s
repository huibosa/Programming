# %rdi:   a
# %rsi:   x
# %rdx:   degree
# %rcx:   a + i
# %xmm0:  xpwr
loop:
  mulsd (%rcx), %xmm0, %xmm0
  addq %xmm0, %rax
  mulsd %rsi, %xmm0, %xmm0
  # Update and compare index
