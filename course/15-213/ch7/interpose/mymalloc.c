/////////////////////////////////////////
///        COMPILETIME
/////////////////////////////////////////
#ifdef COMPILETIME
#include <malloc.h>
#include <stdio.h>

void* mymalloc(size_t size) {
  void* p = malloc(size);
  printf("malloc(%d) = %p\n", (int)size, p);
  return p;
}

void myfree(void* p) {
  free(p);
  printf("free(%p)\n", p);
}
#endif

/////////////////////////////////////////
///        LINKTIME
/////////////////////////////////////////

#ifdef LINKTIME
#include <stdio.h>

void* __real_malloc(size_t size);
void __real_free(void* ptr);

void* __wrap_malloc(size_t size) {
  void* ptr = __real_malloc(size);
  printf("malloc(%d) = %p\n", (int)size, ptr);
  return ptr;
}

void __wrap_free(void* ptr) {
  __real_free(ptr);
  printf("free(%p)\n", ptr);
}
#endif

/////////////////////////////////////////
///        RUNTIME
/////////////////////////////////////////

#ifdef RUNTIME
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// NOTE: Use sprint() and write() since printf() will call malloc() recursively
void* malloc(size_t size) {
  void* (*mallocp)(size_t);
  char* error;
  char buf[100];

  mallocp = dlsym(RTLD_NEXT, "malloc");  // Get address of libc malloc
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  char* ptr = mallocp(size);  // Call libc malloc
  // printf("malloc(%d) = %p\n", (int)size, ptr);
  sprintf(buf, "malloc(%d) = %p\n", (int)size, ptr);
  write(STDOUT_FILENO, buf, strlen(buf));
  return ptr;
}

void free(void* ptr) {
  void (*freep)(void*) = NULL;
  char* error;
  char buf[100];

  if (!ptr) {
    return;
  }

  freep = dlsym(RTLD_NEXT, "free");  // Get address of libc free
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  freep(ptr);  // Call libc free
  // printf("free(%p)\n", ptr);
  sprintf(buf, "free(%p)\n", ptr);
  write(STDOUT_FILENO, buf, strlen(buf));
}
#endif
