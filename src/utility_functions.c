#include "../inc/pathfinder.h"

int mx_atoi(const char *str)
{
    int result = 0;
    int i = 0;      

    while (mx_is_digit(str[i]))
    {
        result = result * 10 + (str[i++] - 48);
    }

    return result; 
}

bool mx_is_digit(int c)
{
    if (c >= 48 && c <= 57)
    {
        return true;
    }
    return false;
}
