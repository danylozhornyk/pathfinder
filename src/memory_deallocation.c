#include "../inc/pathfinder.h"

void mx_free_graph(t_graph **graph) {
    if (*graph == NULL) {
        return; 
    }

    for (int i = 0; i < (*graph)->size; i++) {
        if ((*graph)->islands_arr[i] != NULL) {
            mx_free_list_of_nodes(&(*graph)->islands_arr[i]);

            free((*graph)->islands_arr[i]);
        }
    }

    free((*graph)->islands_arr);

    free(*graph);

    *graph = NULL;
}

void mx_free_node(t_node **node)
{
    if (*node) {
        mx_strdel(&(*node)->name);
        free(*node);
        *node = NULL;
    }
}

static void del_node(t_node *node) {
    mx_strdel(&node->name);

    free(node);
}

void mx_free_list_of_nodes(t_node **islands_arr) {
    t_node *node = *islands_arr;

    while (node != NULL) {
        t_node *next = node->next;

        del_node(node);

        node = next;
    }

    *islands_arr = NULL;
}

void mx_free_list_of_paths(t_path **paths)
{
    t_path *node = *paths;
    t_path *next = NULL;

    while (node != NULL)
    {
        next = node->next;

        mx_free_path_node(&node);

        node = next;
    }

    *paths = NULL;
}

static void free_list_of_parent(t_parent **islands_arr) {
    t_parent *node = *islands_arr;
    t_parent *next = NULL;

    while (node) {
        next = node->next; 
        mx_strdel(&node->name);
        free(node);
        node = next; 
    }

    *islands_arr = NULL; 
}

void mx_free_parents(t_parent **arr, int size) {
    for (int i = 0; i < size; i++) {
        free_list_of_parent(&arr[i]); 
    }
    free(arr);
}

void mx_free_path_node(t_path **node)
{
    mx_free_list_of_nodes(&(*node)->islands_arr);
    free((*node));
}

void mx_free_path_graph(t_src **path_graph)
{
    for (int i = 0; i < (*path_graph)->size; i++)
    {
        mx_free_list_of_paths(&(*path_graph)->destinations[i].paths);
        
        mx_strdel(&(*path_graph)->destinations[i].name);
    }

    mx_strdel(&(*path_graph)->src_name);

    free((*path_graph)->destinations);
    free((*path_graph));
}
