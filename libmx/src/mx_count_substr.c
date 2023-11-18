#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
    {
        return -1;
    }
    if (mx_strlen(sub) == 0)
    {
        return 0;
    }
    int count = 0;
    while (*str)
    {
        if (mx_is_start_substr(str,sub))
        {
            count++;
        }
        str++;
    }
    return count;
}
