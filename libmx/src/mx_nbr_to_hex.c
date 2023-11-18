#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
    if (nbr == 0)
    {
        return "0";
    }
    int length = 0;
    unsigned long temp = nbr;
    while (temp)
    {
        temp /= 16;
        length++;
    }
    char *result = malloc(length);
    unsigned long part = nbr;
    for (int i = length - 1; i >= 0; i--)
    {
        if (part % 16 < 10)
        {
            result[i] = (part % 16) + 48;
        }
        else
        {
            result[i] = (part % 16) + 87;
        }
        part /= 16;
    }
    return result;
}
