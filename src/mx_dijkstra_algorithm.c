#include "../inc/pathfinder.h"

void mx_dijkstra_algorithm(int ***islands_matrix, int size) {
  for(int i = 0; i < size; i++){
    int optimal_check[size];
    int distances[size];

    for (int j = 0; j < size; j++) {

      distances[j] = INT_MAX;
      optimal_check[j] = 0;
    }

    distances[i] = 0;

    for (int k = 0; k < size; k++) {
      int visited = mx_get_optimal_path(distances, optimal_check, size);
      optimal_check[visited] = 1;
      for(int n = 0; n < size; n++){

        if(distances[visited] != INT_MAX && 
           optimal_check[n] != 1 && 
           (*islands_matrix)[visited][n] && 
           distances[visited] + (*islands_matrix)[visited][n] < distances[n]){
          distances[n] = distances[visited] + (*islands_matrix)[visited][n];
        }
      }

      for (int m = 0; m < size; m++) {
        (*islands_matrix)[i][m] = distances[m];
      }
    }
  }
}
