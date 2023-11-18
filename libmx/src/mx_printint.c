#include "libmx.h"

void mx_printint(int n)
{
    if (n == 0)
    {
        mx_printchar('0');
        return;
    }
    int temp = 0;
    int length = 0;
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if( n < 0)
    {
        n *= -1;
        mx_printchar('-');
    }
    temp = n;
    for (int i = 0; temp > 0; i++)
    {
        temp /=10;
        length++;
    }
    char digits[length];
    for (int i = length - 1; i >= 0; i--)
    {
        temp = n % 10;
        digits[i] = temp + 48;
        n /=10;
    }
    for (int i = 0; i < length; i++)
    {
        mx_printchar(digits[i]);
    }
}
