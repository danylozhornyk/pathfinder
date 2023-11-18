#include "../inc/pathfinder.h"

void mx_pathfinder(t_graph *graph, char **islands_names)
{
    for (int i = 0; i < graph->size; i++)
    {
        t_src *path_graph = mx_init_path_graph(graph->size, islands_names, i);

        mx_dijkstra_algorithm(graph, i, islands_names[i], &path_graph);
        mx_sort_path_graph(path_graph);
        mx_print_paths(path_graph, i);
        mx_free_path_graph(&path_graph);
    }
}
