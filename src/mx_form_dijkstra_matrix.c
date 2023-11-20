#include "../inc/pathfinder.h"

int **mx_form_dijkstra_matrix(char **islands_arr, char **line_arr, int matrix_size) {
  int **result_matrix = (int **) malloc((matrix_size + 1)  *sizeof(int *));

  for (int i = 0; i < matrix_size; i++) {
    result_matrix[i] = (int *)malloc((matrix_size)  *sizeof(int));
  }

  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      if(i == j) {
        result_matrix[i][j] = 0;
      }
      else {
        result_matrix[i][j] = 1000000;
      }
    }
  }

  int bridge_count = 0;

  for (int i = 0; line_arr[i] != NULL; i++) {
    bridge_count++;
  }

  long bridge_weights[bridge_count];
  long long sum_of_bridge_weight = 0;

  for (int i = 1; i < bridge_count; i++) {
    char **temp = mx_strsplit(line_arr[i], ',');
    bridge_weights[i] = mx_atoi(temp[1]);
    sum_of_bridge_weight += bridge_weights[i];

    mx_del_strarr(&temp);

    if(sum_of_bridge_weight > INT_MAX){
      mx_printerr("error: sum of bridges lengths is too big\n");
      exit(-1);
    }
  }

  for(int j = 1; line_arr[j] != NULL; j++){
    char **connected_islands_arr = mx_strsplit(line_arr[j], '-');
    int first_island;
    int second_island;

    for (int n = 0; n < 2; n++) {

      if(n == 0){
        first_island = mx_get_island_index(islands_arr, connected_islands_arr[n]);
      }
      else{
        second_island = mx_get_island_index(islands_arr, connected_islands_arr[n]);
      }
    }

    result_matrix[first_island][second_island] = bridge_weights[j];
    result_matrix[second_island][first_island] = bridge_weights[j];

    mx_del_strarr(&connected_islands_arr);
  }

  return result_matrix;
}
