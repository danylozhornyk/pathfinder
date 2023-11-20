#include "../inc/pathfinder.h"

void mx_line_validation(char *str, int index, int fd) {
    for (int i = 0; i < mx_strlen(str); i++) {
        if (!mx_isalpha(str[i])) {
            close(fd);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(index + 1));
            mx_printerr(" is not valid\n");

            exit(-1);
        }
    }
}
