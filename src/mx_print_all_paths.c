#include "../inc/pathfinder.h"

void mx_print_all_paths(int **start, int **end, int size, char **islands) {
  int *route = (int*)malloc((size + 1)  *sizeof(int));
  int route_size = 1;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      route[1] = i;
      route[0] = j;

      mx_print_paths_between_islands(start, end, size, islands, route, route_size);
    }
  }

  free(route);
}
