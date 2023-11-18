#include "libmx.h"

void mx_push_front(t_list **islands_arr, void *data)
{
    t_list *node = mx_create_node(data);
    node->next = *islands_arr;
    *islands_arr = node;
}
