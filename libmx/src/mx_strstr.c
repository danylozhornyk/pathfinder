#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    while (*haystack) {
        if (mx_is_start_substr(haystack,needle)) 
        {
            return (char*)haystack; 
        }
        haystack++;
    }
    return NULL;
}
