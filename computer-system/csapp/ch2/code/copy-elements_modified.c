#include <memory.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// illustration of code vulnerability similar to that found in
void* copy_elements(void* ele_src[], int ele_count, int ele_size) {
  // Allocate buffer for ele_cnt objects, each of ele_size bytes
  // and copy from locations designated by ele_src
  uint64_t required_size = ele_count * (uint64_t)ele_size;
  size_t   request_size  = (size_t)required_size;
  if (request_size != required_size) {
    // Overflow must has occured. Abort operation
    return NULL;
  }

  void* restult = malloc(request_size);
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
