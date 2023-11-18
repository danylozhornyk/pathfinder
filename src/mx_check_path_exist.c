#include "../inc/pathfinder.h"


static int list_of_node_size(t_node *list)
{
    t_node *node = list;
    int size = 0;

    while (node != NULL)
    {
        node = node->next;
        size++;
    }

    return size;
}

bool mx_check_path_exist(t_path *paths, t_node *new_path)
{
    t_path *path = paths;

    while (path != NULL)
    {
        t_node *islands_arr = paths->islands_arr;
        t_node *new_islands_arr = new_path;

        bool is_saved = true;

        if (list_of_node_size(islands_arr) != list_of_node_size(new_islands_arr))
        {
            is_saved = false;
        }

        while (islands_arr != NULL && new_islands_arr != NULL && is_saved)
        {
            if (islands_arr->index != new_islands_arr->index)
            {
                is_saved = false;
                break;
            }

            islands_arr = islands_arr->next;
            new_islands_arr = new_islands_arr->next;
        }
        if (is_saved)
        {
            return true;
        }

        path = path->next;
    }

    return false;
}
