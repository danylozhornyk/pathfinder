#include "../inc/pathfinder.h"

void mx_push_back_node(t_node **islands_arr, int index, char *name, int weight)
{
    t_node *new_node = mx_init_graph_node(index, name, weight);

    t_node *last_node = *islands_arr;

    if (*islands_arr == NULL)
    {
        *islands_arr = new_node;
        return;
    }

    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void mx_push_front_node(t_node **islands_arr, int index, char *name, int weight)
{
    t_node *new_node = mx_init_graph_node(index, name, weight);

    new_node->next = *islands_arr;

    *islands_arr = new_node;
}

void mx_push_back_parent(t_parent **parents, int prev_index, int index, char *name, int weight)
{
    t_parent *new_node = mx_init_parent(prev_index, index, name, weight);

    t_parent *last_node = *parents;

    if (*parents == NULL)
    {
        *parents = new_node;
        return;
    }

    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void mx_push_front_parent(t_parent **parents, int prev_index, int index, char *name, int weight)
{
    t_parent *new_node = mx_init_parent(prev_index, index, name, weight);

    new_node->next = *parents;

    *parents = new_node;
}

void mx_push_back_path(t_path **paths, int weight) {
    t_path *new_path = mx_init_path(weight);
    if (*paths == NULL) {
        *paths = new_path; 
    } else {
        t_path *current = *paths;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_path;
    }
}

void mx_push_front_path(t_path **paths, int weight)
{
    t_path *new_node = mx_init_path(weight);

    new_node->next = *paths;

    *paths = new_node;
}
