#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace)
    {
        return NULL;
    }
    int str_len = mx_strlen(str), sub_len = mx_strlen(sub), replace_len = mx_strlen(replace);
    int length = str_len + mx_count_substr(str, sub) * (replace_len - sub_len);
    char *result = mx_strnew(length);
    for (int i = 0; i < length; i++)
    {
        if (mx_is_start_substr(str,sub))
        {
            str += sub_len;
            for (int j = 0; j < replace_len; i++, j++)
            {
                result[i] = replace[j];
            }
        }
        if (mx_is_start_substr(str,sub))
        {
            str--;
            i--;
        }
        else
        {
            result[i] = *str;
        }
        str++;  
    }
    return result;
}
