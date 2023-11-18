#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
    {
        return -2;
    }
    int count = 0;
    while (*str) 
    {
        if (mx_is_start_substr(str,sub))
        {
            return count; 
        }
        str++;
        count++;
    }
    return -1;
}
