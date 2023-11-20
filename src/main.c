#include "../inc/pathfinder.h"

int main(int argc, char *argv[]){
  if(argc != 2){
    mx_printerr("usage: ./pathfinder [filename]\n");
    exit(-1);
  }

  char *str_file = mx_file_to_str(argv[1]);
  mx_file_validation(argv[1], str_file);

  int islands_count = mx_get_island_count(str_file);
  char **line_arr = mx_strsplit(str_file, '\n');
  char **islands_arr = mx_islands_arr_fill(line_arr, islands_count);

  int **islands_matrix = mx_form_dijkstra_matrix(islands_arr, line_arr, islands_count);
  int **islands_matrix_copy =  mx_form_dijkstra_matrix(islands_arr, line_arr, islands_count);

  mx_dijkstra_algorithm(&islands_matrix, islands_count);

  mx_print_all_paths(islands_matrix_copy, islands_matrix, islands_count, islands_arr);

  mx_strdel(&str_file);
  mx_del_strarr(&line_arr);
  mx_del_strarr(&islands_arr);

  for (int i = 0; i < islands_count; i++) {
    free(islands_matrix[i]);
    free(islands_matrix_copy[i]);
  }

  free(islands_matrix);
  free(islands_matrix_copy);

  return 0;

}
