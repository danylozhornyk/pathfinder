#include "../inc/pathfinder.h"

void mx_copy_list_of_nodes(t_node **dest, t_node *src)
{
    if (dest != NULL && *dest != NULL)
    {
        mx_free_list_of_nodes(&(*dest));
        *dest = NULL;
    }

    while (src)
    {
        mx_push_back_node(dest, src->index, src->name, src->weight);
        src = src->next;
    }
}
