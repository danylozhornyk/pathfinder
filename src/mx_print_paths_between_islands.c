#include "../inc/pathfinder.h"

void mx_print_paths_between_islands(int **start, int **end, int size, char **islands, int *route, int route_size) {
  int from = route[route_size];
  int to = route[0];

  for(int i = 0; i < size; i++){
    if(start[from][i] == end[from][to] - end[i][to] && i != route[route_size]){
      route_size++;

      route[route_size] = i;

      mx_print_paths_between_islands(start, end, size, islands, route, route_size);

      route_size--;
    }
    
  }

  if(route[route_size] != route[0]){
    return;
  }


  for (int i = 0; i < 40; i++) {
    mx_printchar('=');
  }

  mx_printstr("\nPath: ");
  mx_printstr(mx_islands_indexator(route[1], islands));
  mx_printstr(" -> ");
  mx_printstr(mx_islands_indexator(route[0], islands));
  mx_printchar('\n');

  mx_printstr("Route: ");

  for(int i = 1; i < route_size + 1; i++){
    mx_printstr(mx_islands_indexator(route[i], islands));

    if(i < route_size){
      mx_printstr(" -> ");
    }
  }

  int result_distance = 0;

  mx_printstr("\nDistance: ");

  for(int i = 1; i < route_size; i++){
    int current_distance = start[route[i]][route[i + 1]];
    mx_printint(current_distance);
    result_distance += current_distance;

    if(i < route_size - 1){
      mx_printstr(" + ");
    }
  }

  if(route_size != 2){
    mx_printstr(" = ");
    mx_printint(result_distance);
  }

  mx_printchar('\n');

  for (int i = 0; i < 40; i++) {
      mx_printchar('=');
  }

  mx_printchar('\n');
}
