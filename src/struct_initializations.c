#include "../inc/pathfinder.h"

t_graph *mx_init_graph(int graphSize)
{
    t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
    graph->size = graphSize;

    graph->islands_arr = (t_node **)malloc(graphSize * sizeof(t_node));

    for (int i = 0; i < graphSize; ++i)
    {
        graph->islands_arr[i] = malloc(sizeof(*(graph->islands_arr[i])));
        graph->islands_arr[i] = NULL;
    }

    return graph;
}

t_node *mx_init_graph_node(int index, char *name, int weight)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->index = index;
    new_node->name = mx_strdup(name);
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}

t_parent *mx_init_parent(int prev_index, int index, char *name, int weight)
{
    t_parent *new_node = malloc(sizeof(t_parent));
    new_node->prev_index = prev_index;
    new_node->index = index;
    new_node->name = mx_strdup(name);
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}

t_src *mx_init_path_graph(int size, char **islands_names, int src_index)
{
    t_src *path_graph = (t_src *)malloc(sizeof(t_src));
    
    path_graph->size = size;
    path_graph->src_name = mx_strdup(islands_names[src_index]);

    path_graph->destinations = (t_dst *)malloc(size * sizeof(*(path_graph->destinations)));
    for (int i = 0; i < size; i++)
    {
        path_graph->destinations[i].name = mx_strdup(islands_names[i]);
        path_graph->destinations[i].paths = NULL;
    }

    return path_graph;
}

t_path *mx_init_path(int weight)
{
    t_path *new_node = malloc(sizeof(t_path));
    new_node->weight = weight;
    new_node->islands_arr = NULL;
    new_node->next = NULL;

    return new_node;
}
