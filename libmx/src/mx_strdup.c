#include "libmx.h"

char *mx_strdup(const char *s1)
{
    if (s1 == NULL)
    {
        return NULL;
    }
    char *newstr = mx_strnew(mx_strlen(s1));
    mx_strcpy(newstr, s1);
    return newstr;
}
