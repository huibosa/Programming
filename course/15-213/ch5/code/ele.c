typedef struct {
  struct ELE * next;
  long data;
} list_ele, *list_ptr;

long list_len(list_ptr ls) {
  long len = 0;
  while (ls) {
    len++;
    ls = (list_ptr)(ls->next);
  }
  return len;
}

//   xorq %rax, %rax
//   testq %rdi, %rdi
//   je done
// loop:
//   addq $1, %rax
//   movq (%rdi), rdi
//   testq %rdi, %rdi
//   jne loop
// done:
//   ret
