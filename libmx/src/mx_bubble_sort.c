#include "libmx.h"

int mx_bubble_sort(char **arr, int size)
{
    int temp = 0;
    char *temparr;
    for (int i = 0; i < size - 1; i++) 
    {
        for(int j = i + 1; j < size; j++)
        {
            if (mx_strcmp(arr[i], arr[j]) > 0)
            {
                temparr = arr[i];
                arr[i] = arr[j];
                arr[j] = temparr;
                temp++;
            }
        }
    }
    return temp;
}
