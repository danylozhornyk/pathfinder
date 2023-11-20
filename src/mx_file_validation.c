#include "../inc/pathfinder.h"

void mx_file_validation(char *filename, const char *temp_str) {
    int f = open(filename, O_RDONLY);
    if (f == -1) {
        close(f);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(-1);
    }

    int file_size = mx_get_file_length(filename);

    if (file_size <= 0) {
        close(f);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(-1);
    }
    int island_count = mx_get_island_count(temp_str);
    char **line_arr = mx_strsplit(temp_str, '\n');

    for (int i = 0; i < mx_strlen(line_arr[0]); i++) {
        if (!mx_isdigit(line_arr[0][i])) {
            close(f);
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
        }
    }

    if (mx_atoi(line_arr[0]) <= 0) {
        close(f);
        mx_printerr("error: line 1 is not valid\n");
        exit(-1);
    }

    for (int i = 1; line_arr[i] != NULL; i++) {
        if (mx_get_char_index(line_arr[i], '-') < 0 || mx_get_char_index(line_arr[i], ',') < 0) {
            close(f);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }

        if (mx_count_substr(line_arr[i], "-") > 1 || mx_count_substr(line_arr[i], ",") > 1) {
            close(f);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }

        char **connected_islands = mx_strsplit(line_arr[i], '-');

        mx_line_validation(connected_islands[0], i, f);

        mx_line_validation(mx_strndup(connected_islands[1], mx_get_char_index(connected_islands[1], ',')), i, f);

        for (int j = mx_get_char_index(connected_islands[1] ,',') + 1; j < mx_strlen(connected_islands[1]); j++) {
            if(!mx_isdigit(connected_islands[1][j])) {
                close(f);
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(-1);
            }
        }

        if (mx_strcmp(connected_islands[0], mx_strndup(connected_islands[1], mx_get_char_index(connected_islands[1] ,','))) == 0) {
            close(f);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-1);
        }

        mx_del_strarr(&connected_islands);
    }


    char **islands_arr = mx_islands_arr_fill(line_arr, island_count);

    if (mx_get_size_of_str_arr(islands_arr) != mx_atoi(line_arr[0])) {
        close(f);
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }

    for (int i = 1; i < mx_get_size_of_str_arr(line_arr) - 1; i++){
      char **line_island_path = mx_strsplit(line_arr[i], ',');
      char **islands_in_path = mx_strsplit(line_island_path[0], '-');
      char *reverse_line_island_path = mx_strjoin(islands_in_path[1], "-");
      reverse_line_island_path = mx_strjoin(reverse_line_island_path, islands_in_path[0]);

      for (int j = i + 1; j < mx_get_size_of_str_arr(line_arr); j++){
        if ((mx_strncmp(line_island_path[0], line_arr[j], mx_strlen(line_island_path[0])) == 0) || (mx_strncmp(line_arr[j], reverse_line_island_path, mx_strlen(reverse_line_island_path)) == 0)){
          close(f);
          mx_printerr("error: duplicate bridges\n");
          exit(-1);
        }
      }
      mx_del_strarr(&line_island_path);
      mx_del_strarr(&islands_in_path);
      mx_strdel(&reverse_line_island_path);
    }

    mx_del_strarr(&islands_arr);
    mx_del_strarr(&line_arr);

    close(f);
}
