#include "libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    int swaps = 0;
    if (left < right) {
        char *last = arr[right];
        int first = left - 1;
        for (int j = left; j <= right - 1; j++) 
        {
            if (mx_strcmp(arr[j], last) <= 0) 
            {
                first++;
                char temp = *arr[first];
                *arr[first] = *arr[j];
                *arr[j] = temp;
                swaps++;
            }
        }
        char temp = *arr[first + 1];
        *arr[first + 1] = *arr[right];
        *arr[right] = temp;
        swaps++;
        swaps += mx_quicksort(arr, left, first);
        swaps += mx_quicksort(arr, first + 2, right);
    }
    return swaps;
}
