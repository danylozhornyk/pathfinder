#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2)
{
    int j = mx_strlen(s1);
    for(int i = 0; i < mx_strlen(s2); i++, j++)
    {
        s1[j] = s2[i];
    }
    s1[j++] = '\0';
    return s1;
}
