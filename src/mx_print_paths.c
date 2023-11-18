#include "../inc/pathfinder.h"

static void print_equality_sign() {
    for (size_t i = 0; i < 40; i++) {
        mx_printchar('=');
    }
    mx_printchar('\n');
}

void mx_print_paths(t_src *path_graph, int src) {
    for (int i = src + 1; i < path_graph->size; i++) {
        t_path *paths = path_graph->destinations[i].paths;

        while (paths != NULL) {
            print_equality_sign();

            mx_printstr("Path: ");
            mx_printstr(path_graph->src_name);
            mx_printstr(" -> ");
            mx_printstr(path_graph->destinations[i].name);
            mx_printstr("\n");

            mx_printstr("Route: ");
            mx_printstr(path_graph->src_name);
            mx_printstr(" -> ");

            t_node *vert = paths->islands_arr;
            while (vert != NULL) {
                mx_printstr(vert->name);
                if (vert->next != NULL) {
                    mx_printstr(" -> ");
                }
                vert = vert->next;
            }
            mx_printstr("\n");

            mx_printstr("Distance: ");
            vert = paths->islands_arr;
            if (vert->next != NULL) {
                while (vert != NULL) {
                    mx_printint(vert->weight);

                    if (vert->next != NULL) {
                        mx_printstr(" + ");
                    }
                    vert = vert->next;
                }
                mx_printstr(" = ");
            }
            mx_printint(paths->weight);

            mx_printstr("\n");

            print_equality_sign();

            paths = paths->next;
        }
    }
}
