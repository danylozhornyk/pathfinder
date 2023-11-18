#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (!size && ptr) 
    {
        free(ptr);
        return NULL;
    }
    if (!ptr && size)
    {
        return malloc(size);
    } 
    size_t length = *((size_t *)((char *) ptr - sizeof(size_t)));
    if (length > size)
    {
        size = length;
    }
    void *tmp = (void *)malloc(size);
    if (!tmp)
    {
        return NULL;
    }
    tmp = mx_memmove(tmp, ptr, length);
    free(ptr);
    return tmp;
}
