#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    char *d = (char *)dst;
    const char *s = (const char *)src;
    if (d == s || len == 0) 
    {
        return dst; 
    }
    if (d < s) 
    {
        for (size_t i = 0; i < len; i++) 
        {
            d[i] = s[i];
        }
    } 
    else 
    {
        for (size_t i = len; i > 0; i--) 
        {
            d[i - 1] = s[i - 1];
        }
    }
    return dst;
}
