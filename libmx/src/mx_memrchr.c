#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t a)
{
    for (size_t i = a; i > 0; i--) 
    {
        if (((char *)s)[i] == (char)c) 
        {
            return (void *)&(((char *)s)[i]); 
        }
    }
    return NULL;
}
