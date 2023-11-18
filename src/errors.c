#include "../inc/pathfinder.h"

void mx_write_error(const char *s)
{
    write(2, s, mx_strlen(s));
}

void mx_error_invalid_input() 
{
    mx_write_error("usage: ./pathfinder [filename]\n");
    exit(-1);
}

void mx_error_invalid_file(const char *file)
{
    mx_write_error("error: file ");
    mx_write_error(file);
    mx_write_error(" does not exist\n");
    exit(-1);
}

void mx_error_empty_file(const char *file)
{
    mx_write_error("error: file ");
    mx_write_error(file);
    mx_write_error(" is empty\n");
    exit(-1);
}

void mx_error_invalid_line(int index)
{
    mx_write_error("error: line ");
    mx_write_error(mx_itoa(index));
    mx_write_error(" is not valid\n");
    exit(-1);
}

void mx_error_invalid_num_of_all_islands()
{
    mx_write_error("error: invalid number of islands\n");
    exit(-1);
}

void mx_error_duplicate_bridges()
{
    mx_write_error("error: duplicate bridges\n");
    exit(-1);
}

void mx_error_invalid_sum_of_bridges_length()
{
    mx_write_error("error: sum of bridges lengths is too big\n");
    exit(-1);
}
