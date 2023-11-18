#include "../inc/pathfinder.h"

static void set_path(t_parent *u_node, t_node *current_path, t_src *path_graph, t_parent **parents, int dest_index) {
    int u_index = u_node->prev_index;

    if (u_index == -1) {
        if (!mx_check_path_exist(path_graph->destinations[dest_index].paths, current_path)) {
            mx_push_front_path(&path_graph->destinations[dest_index].paths, 0);
            mx_copy_list_of_nodes(&path_graph->destinations[dest_index].paths->islands_arr, current_path);
            mx_reset_path_weight(&path_graph->destinations[dest_index].paths);
        }
        return;
    }

    mx_push_front_node(&current_path, u_node->index, u_node->name, u_node->weight);

    t_parent *parent_node = parents[u_index];
    while (parent_node) {
        set_path(parent_node, current_path, path_graph, parents, dest_index);
        parent_node = parent_node->next;
    }

    mx_pop_front_node(&current_path);
}

static int paths_size(t_path *islands_arr) {
    t_path *node = islands_arr;
    int size = 0;

    while (node) {
        node = node->next;
        size++;
    }

    return size;
}

static void del_extra_paths(t_path **islands_arr, int weight) {
    t_path *node = (*islands_arr)->next;
    t_path *prev = *islands_arr;

    if (node == NULL) {
        if (prev->weight > weight) {
            mx_free_path_node(&prev);
        }
        return;
    }

    while (node->next) {
        if (node->weight > weight) {
            prev->next = node->next;
            mx_free_path_node(&node);
            node = prev->next;
            continue;
        }

        prev = prev->next;
        node = node->next;
    }

    if (node->weight > weight) {
        prev->next = NULL;
        mx_free_path_node(&node);
    }

    node = *islands_arr;
    if (node->weight > weight) {
        (*islands_arr) = (*islands_arr)->next;
        mx_free_path_node(&node);
    }
}

static void process_path(t_src *path_graph, t_parent **parents, int index, int weight_of_shortest) {
    t_parent *u = parents[index];
    t_node *current_path = NULL;

    while (u) {
        set_path(u, current_path, path_graph, parents, index);
        u = u->next;
    }

    if (paths_size(path_graph->destinations[index].paths) > 1) {
        del_extra_paths(&path_graph->destinations[index].paths, weight_of_shortest);
    }

    mx_free_list_of_nodes(&current_path);
}

void mx_dijkstra_algorithm(t_graph *graph, int src_index, char *src_name, t_src **path_graph) {
    int graph_size = graph->size;

    t_node *priority_queue = (t_node *)malloc(sizeof(t_node));
    priority_queue = NULL;
    t_parent **parents = malloc(graph_size * sizeof(*parents));
    long path_weight[graph_size];

    for (int i = 0; i < graph_size; i++) {
        path_weight[i] = __INT_MAX__;
        parents[i] = NULL;
    }

    mx_push_back_parent(&parents[src_index], -1, src_index, src_name, 0);
    path_weight[src_index] = 0;

    mx_push_back_node(&priority_queue, src_index, src_name, 0);

    while (priority_queue) {
        int u = priority_queue->index;
        mx_pop_front_node(&priority_queue); 

        t_node *neighbor_node = graph->islands_arr[u];

        while (neighbor_node) {
            int v = neighbor_node->index;

            if (path_weight[u] != __INT_MAX__) {
                long potential_weight = path_weight[u] + neighbor_node->weight;

                if (potential_weight <= path_weight[v]) {
                    if (potential_weight < path_weight[v]) {
                        path_weight[v] = potential_weight; 
                        mx_pop_back_parent(&parents[v]); 
                    }

                    if (!mx_check_parent_dup(parents[v], u, neighbor_node->index, neighbor_node->name, neighbor_node->weight)) {
                        mx_push_front_parent(&parents[v], u, neighbor_node->index, neighbor_node->name, neighbor_node->weight); 
                    }

                    mx_push_back_node(&priority_queue, v, neighbor_node->name, path_weight[v]);
                }
            }

            neighbor_node = neighbor_node->next;
        }
    }

    for (int i = 0; i < graph_size; i++) {
        process_path(*path_graph, parents, i, path_weight[i]);
    }

    mx_free_parents(parents, graph_size);
    mx_free_list_of_nodes(&priority_queue);
    free(priority_queue);
}
