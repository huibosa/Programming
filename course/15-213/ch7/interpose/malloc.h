#define malloc(size) mymalloc(size)
#define free(ptr) myfree(ptr)

void* mymalloc(size_t size);
void free(void* p);
