#include "../inc/pathfinder.h"

bool mx_is_island_exist(char **islands, char *island) {
    if(islands[0] == NULL){
      return true;
    }

    for(int i = 0; islands[i] != NULL; i++){
      if(mx_strncmp(island, islands[i], mx_strlen(islands[i])) == 0){
        return false;
      }

    }

    return true;
}
