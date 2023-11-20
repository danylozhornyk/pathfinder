#ifndef  PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include <limits.h>

//Type handling
int mx_atoi(char* str);
bool mx_isalpha(int c);
bool mx_isdigit(int c);

//Error handling
int mx_get_file_length(const char *filename);
void mx_line_validation(char *str, int index, int fd);
void mx_file_validation(char *filename, const char *temp_str);
void mx_printerr(const char *s);

//Islands handling
int mx_get_island_count(const char *islands);
int mx_get_island_index(char **islands, char *island);
char *mx_islands_indexator(int index, char **islands);
int mx_get_size_of_str_arr(char **str_arr);
bool mx_is_island_exist(char **islands, char *island);
char **mx_islands_arr_fill(char **arr_to_fill, int new_size);

//Dijkstra algorithm
int mx_get_optimal_path(int *distances, int *check, int size);
int **mx_form_dijkstra_matrix(char **islands_arr, char **line_arr, int matrix_size);
void mx_dijkstra_algorithm(int ***islands_matrix, int size);

//Printing paths
void mx_print_paths_between_islands(int **start, int **end, int size, char **islands, int *route, int route_size);
void mx_print_all_paths(int **start, int **end, int size, char **islands);


#endif
