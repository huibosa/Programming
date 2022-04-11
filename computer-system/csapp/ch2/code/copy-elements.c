#include <memory.h>
#include <stdlib.h>
#include <string.h>

// Illustration of code vulnerability similar to that found in
void* copy_elements(void* ele_src[], int ele_count, int ele_size) {
  // Allocate buffer for ele_cnt objects, each of ele_size bytes
  // and copy from locations designated by ele_src
  void* restult = malloc(ele_count * ele_size);
  if (restult == NULL) {
    return NULL;
  }
  void* next = restult;

  for (int i = 0; i < ele_count; i++) {
    memcpy(next, ele_src[i], ele_size);
    next += ele_size;
  }
  return restult;
}
