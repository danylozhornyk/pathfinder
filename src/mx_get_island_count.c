#include "../inc/pathfinder.h"

int mx_get_island_count(const char *islands) {
  char **line_arr = mx_strsplit(islands, '\n');

  int count = mx_atoi(line_arr[0]);

  mx_del_strarr(&line_arr);

  return count;
}
