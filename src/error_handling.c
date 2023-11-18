#include "../inc/pathfinder.h"

void mx_file_validation(char const *filename)
{
    char *str_file = mx_file_to_str(filename);

    if (str_file == NULL)
    {
        mx_error_invalid_file(filename);
    }

    if (mx_strlen(str_file) == 0)
    {
        mx_error_empty_file(filename);
    }

    mx_strdel(&str_file);
}

bool mx_check_parent_dup(t_parent *parents, int prev_index, int index, char *name, int weight)
{
    t_parent *node = parents;

    while (node != NULL)
    {
        if (node->index == index && !mx_strcmp(node->name, name) && node->weight == weight && node->prev_index == prev_index)
        {
            return true; 
        }

        node = node->next;
    }

    return false;
}
