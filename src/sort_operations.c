#include "../inc/pathfinder.h"

int paths_size(t_path *paths) {
    int size = 0;
    t_path *current = paths;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool compare_paths(t_node *path1, t_node *path2) {
    bool is_greater = false;
    while (path2 != NULL && path1 != NULL) {
        if (path2->index > path1->index) {
            is_greater = true;
        }
        if (path1->index > path2->index && !is_greater) {
            return true;
        }
        path1 = path1->next;
        path2 = path2->next;
    }
    return false;
}

static t_path *merge(t_path *left, t_path *right) {
    t_path *result = NULL;

    while (left && right) {
        if (compare_paths(left->islands_arr, right->islands_arr)) {
            mx_push_front_path(&result, left->weight); 
            left = left->next;
        } else {
            mx_push_front_path(&result, right->weight); 
            right = right->next;
        }
    }

    while (left) {
        mx_push_front_path(&result, left->weight);
        left = left->next;
    }

    while (right) {
        mx_push_front_path(&result, right->weight);
        right = right->next;
    }

    return result; 
}

static t_path *merge_sort(t_path *paths) {
    if (!paths || !paths->next) {
        return paths;
    }

    t_path *left = NULL;
    t_path *right = NULL;
    t_path *current = paths;
    int size = paths_size(paths) / 2;

    for (int i = 0; i < size; i++) {
        mx_push_back_path(&left, current->weight);
        current = current->next;
    }

    while (current) {
        mx_push_back_path(&right, current->weight);
        current = current->next;
    }

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right); 
}

t_path *mx_sort_paths_list(t_path *paths) {
    if (!paths) {
        return NULL;
    }

    return merge_sort(paths);
}

void mx_sort_path_graph(t_src *path_graph)
{
    for (int i = 0; i < path_graph->size; i++)
    {
        mx_sort_paths_list(path_graph->destinations[i].paths);
    }
}
