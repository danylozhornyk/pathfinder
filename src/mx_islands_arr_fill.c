#include "../inc/pathfinder.h"

char **mx_islands_arr_fill(char **arr_to_fill, int new_size) {
  char **result = (char **) malloc((new_size  *sizeof(char*)) + 1);

  for(int i = 0; i < new_size; i++){
    result[i] = NULL;
  }

  int i = 0;
  for (int j = 1; arr_to_fill[j]; j++) {
    char **temp = mx_strsplit(arr_to_fill[j], '-');

    for(int n = 0; n < 2; n++){
      if(mx_is_island_exist(result, temp[n])){

        if(n == 0){
          result[i] = mx_strdup(temp[n]);
          i++;
        }
        else{
          result[i] = mx_strndup(temp[n], (mx_get_char_index(temp[1], ',')));
          i++;
        }
      }
    }

    mx_del_strarr(&temp);

  }

  return result;
}
