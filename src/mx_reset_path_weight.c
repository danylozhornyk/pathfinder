#include "../inc/pathfinder.h"

void mx_reset_path_weight(t_path **path)
{
    t_node *node = (*path)->islands_arr;
    int new_weight = 0;

    while (node != NULL)
    {
        new_weight += node->weight;
        node = node->next;
    }

    (*path)->weight = new_weight;
}
