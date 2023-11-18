#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    char *start = dst;
    while (*src && len > 0)
    {
        *dst++ = *src++;
        len--;
    }
    while (len > 0)
    {
        *dst++ = '\0';
        len--;
    }
    return start;
}
