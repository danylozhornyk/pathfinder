#include "../libmx/inc/libmx.h"

typedef struct s_bridge {
    char *first_island;    
    char *second_island;    
    int bridge_weight;    
} t_bridge;

typedef struct s_node {
    int index;     
    char *name;     
    int weight;      
    struct s_node *next; 
} t_node;

typedef struct s_graph {
    int size;              
    t_node **islands_arr;  
} t_graph;

typedef struct s_path {
    int weight;         
    t_node *islands_arr;       
    struct s_path *next;
} t_path;

typedef struct s_dst {
    char *name;      
    t_path *paths;  
} t_dst;

typedef struct s_src {
    char *src_name;
    int size;       
    t_dst *destinations;  
} t_src;

typedef struct s_parent {
    int prev_index;  
    int index;            
    char *name;           
    int weight;           
    struct s_parent *next;  
} t_parent;


// Error Handling
void mx_error_invalid_input();
void mx_error_invalid_file(const char *file);
void mx_error_empty_file(const char *file);
void mx_error_invalid_line(int index);
void mx_error_invalid_num_of_all_islands();
void mx_error_duplicate_bridges();
void mx_error_invalid_sum_of_bridges_length();
void mx_file_validation(char const *file);
bool mx_check_parent_dup(t_parent *parents, int prev_index, int index, char *name, int weight);

// Utility Functions
bool mx_is_digit(int c);
int mx_atoi(const char *str);

// Node Operations
t_node *mx_init_graph_node(int index, char *name, int weight);
void mx_push_back_node(t_node **islands_arr, int index, char *name, int weight);
void mx_free_list_of_nodes(t_node **islands_arr);
void mx_free_node(t_node **node);
void mx_copy_list_of_nodes(t_node **dest, t_node *src);
void mx_push_front_node(t_node **islands_arr, int index, char *name, int weight);
void mx_pop_front_node(t_node **head);

// Graph operations
t_graph *mx_init_graph(int graphSize);
void mx_free_graph(t_graph **graph);

// Path Operations
t_path *mx_init_path(int weight);
t_path *mx_sort_paths_list(t_path *paths);
void mx_reset_path_weight(t_path **path);
bool mx_check_path_exist(t_path *paths, t_node *new_path);
void mx_push_front_path(t_path **paths, int weight);
void mx_push_back_path(t_path **paths, int weight);
void mx_free_list_of_paths(t_path **paths);
void mx_free_path_node(t_path **node);

// File Parsing
char **mx_parse_file(char *src, t_graph **graph);

// Parent Operations
t_parent *mx_init_parent(int prev_index, int index, char *name, int weight);
void mx_push_back_parent(t_parent **parents, int prev_index, int index, char *name, int weight);
void mx_push_front_parent(t_parent **parents, int prev_index, int index, char *name, int weight);
void mx_pop_back_parent(t_parent **head);
void mx_free_parents(t_parent **arr, int size);

// Path graph Handling
t_src *mx_init_path_graph(int size, char **islands_names, int src_index);
void mx_sort_path_graph(t_src *path_graph);
void mx_print_paths(t_src *path_graph, int src);
void mx_free_path_graph(t_src **path_graph);

// Pathfinding
void mx_pathfinder(t_graph *graph, char **islands_names);
void mx_dijkstra_algorithm(t_graph *graph, int src_index, char *src_name, t_src **path_graph);
