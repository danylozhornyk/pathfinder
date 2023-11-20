#include "../inc/pathfinder.h"

int mx_get_island_index(char **islands, char *island) {
  if(islands[0] == NULL){
    return -1;
  }

  for(int i = 0; islands[i] != NULL; i++){
    if(mx_strncmp(island, islands[i], mx_strlen(islands[i])) == 0){
      return i;
    }
  }

  return -1;
}
