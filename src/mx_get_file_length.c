#include "../inc/pathfinder.h"

int mx_get_file_length(const char *filename) {
    int fd = open(filename, O_RDONLY);
    int size = 0;
    int length = 0;
    char buf;

    size = read(fd, &buf, 1);
    while (size > 0) {
        size = read(fd, &buf, 1);
        length++;
    }

    close(fd);
    return length;
}
