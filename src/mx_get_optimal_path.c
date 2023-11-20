#include "../inc/pathfinder.h"

int mx_get_optimal_path(int *distances, int *check, int size) {
  int not_visited = INT_MAX;
  int visited;

  for(int i = 0; i < size; i++){
    if(check[i] == 0 && distances[i] < not_visited){
      not_visited = distances[i];
      visited = i;
    }
  }

  return visited;
}
