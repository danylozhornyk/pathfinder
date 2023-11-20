#include "../inc/pathfinder.h"

int mx_get_size_of_str_arr(char **str_arr) {
    int file_size = 0;

    for (int i = 0; str_arr[i] != NULL; i++) {
        file_size++;
    }

    return file_size;
}
