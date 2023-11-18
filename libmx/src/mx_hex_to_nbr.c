#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    unsigned long hex_pow = 1;
    unsigned long result = 0;
    for (int i = mx_strlen(hex) - 1; i >= 0; i--) 
    {
        if (hex[i] >= 48 && hex[i] <= 57) 
        {
            result += (hex[i] - 48) * hex_pow;
            hex_pow *= 16;
        }
        else if (hex[i] >= 65 && hex[i] <= 70) 
        {
            result += (hex[i] - 55) * hex_pow;
            hex_pow *= 16;
        }
        else if (hex[i] >= 97 && hex[i] <= 102) 
        {
            result += (hex[i] - 87) * hex_pow;
            hex_pow *= 16;
        }
    }
    return result;
}
