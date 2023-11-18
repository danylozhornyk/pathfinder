#include "../inc/pathfinder.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        mx_error_invalid_input();
    }
    char const *filename = argv[1];

    mx_file_validation(filename);

    t_graph *graph;
    char **islands = mx_parse_file(mx_file_to_str(filename), &graph);

    mx_pathfinder(graph, islands);

    mx_del_strarr(&islands);
    mx_free_graph(&graph);

    return 0;
}
