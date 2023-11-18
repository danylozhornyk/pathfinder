#include "libmx.h"

void mx_push_back(t_list **islands_arr, void *data)
{
    t_list *node = mx_create_node(data);
    if (*islands_arr == NULL) 
    {
        *islands_arr = node;
    }
    else
    {
        t_list *current = *islands_arr;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = node;
    }
}
