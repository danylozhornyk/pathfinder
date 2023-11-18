#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim)
{
    if (arr != NULL && delim != NULL)
    {
        int length = 0;
        mx_printstr(arr[length++]);
        while (arr[length])
        {
            mx_printstr(delim);
            mx_printstr(arr[length++]);
        }
        mx_printchar('\n');
    }
}
