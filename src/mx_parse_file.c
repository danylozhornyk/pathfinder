#include "../inc/pathfinder.h"

static int count_bridges(char **lines)
{
    int i = 0;
    while (lines[i + 1] != NULL)
    {
        i++;
    }
    return i;
}

static bool is_number_valid(char *str)
{
    
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (!mx_is_digit(str[i]))
        {
            return false;
        }
        i++;
    }
    if (i == 0)
    {
        return false;
    }
    return true;
}

static bool is_letter(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return true;
    }
    return false;
}

static bool is_name_valid(char *str, int length)
{
    if (length <= 0)
    {
        return false;
    }
    
    for (int i = 0; i < length; i++)
    {
        if (!is_letter((unsigned char)str[i]))
        {
            return false;
        }
    }
    return true;
}

static bool is_new_island(char **islands, int num_of_current_islands, char *island)
{
    for (int i = 0; i < num_of_current_islands; i++)
    {
        if (!mx_strcmp(islands[i], island))
        {
            return false;
        }
    }
    return true;
}

static void add_new_island(char **islands, int num_of_all_islands, int *num_of_current_islands, char *island)
{
    if (is_new_island(islands,*num_of_current_islands, island))
    {
        if (*num_of_current_islands < num_of_all_islands)
        {
            islands[*num_of_current_islands] = mx_strdup(island);
        }
        (*num_of_current_islands)++;
    }
}

static int find_index(char **islands, char *island)
{
    for (int i = 0; islands[i] != NULL; i++)
    {
        if (!mx_strcmp(island, islands[i]))
        {
            return i;
        }
    }
    return -1;
}

static t_bridge parse_bridge(char *line, int line_index) {
    t_bridge result;
    char *first_island, *second_island;
    int bridge_weight;
    
    if (mx_count_substr(line, "-") != 1 || mx_count_substr(line, ",") != 1) {
        mx_error_invalid_line(line_index);
    }

    first_island = mx_strndup(line, mx_get_char_index(line, '-'));
    line += mx_get_char_index(line, '-') + 1;

    second_island = mx_strndup(line, mx_get_char_index(line, ','));
    line += mx_get_char_index(line, ',') + 1;

    if (!is_name_valid(first_island, mx_strlen(first_island)) || !is_name_valid(second_island, mx_strlen(second_island)) || !is_number_valid(line)) {
        mx_error_invalid_line(line_index);
    }

    bridge_weight = mx_atoi(line);
    
    if (bridge_weight <= 0) {
        mx_error_invalid_line(line_index);
    }

    if (!mx_strcmp(first_island, second_island)) {
        mx_error_invalid_line(line_index);
    }

    result.first_island = first_island;
    result.second_island = second_island;
    result.bridge_weight = bridge_weight;

    return result;
}

static bool is_duplicate_bridge(t_bridge *parsed_bridges, int size, t_bridge bridge) {
    for (int i = 0; i < size; i++) {
        if (parsed_bridges[i].first_island != NULL &&
            ((mx_strcmp(parsed_bridges[i].first_island, bridge.first_island) == 0 && mx_strcmp(parsed_bridges[i].second_island, bridge.second_island) == 0) ||
             (mx_strcmp(parsed_bridges[i].first_island, bridge.second_island) == 0 && mx_strcmp(parsed_bridges[i].second_island, bridge.first_island) == 0))) {
            return true;
        }
    }
    return false;
}

static void build_graph(t_graph **graph, t_bridge *parsed_bridges, int num_of_bridges, char **islands, int num_of_all_islands) {
    *graph = mx_init_graph(num_of_all_islands);

    for (int i = 0; i < num_of_bridges; i++) {
        int src_index = find_index(islands, parsed_bridges[i].first_island);
        int dst_index = find_index(islands, parsed_bridges[i].second_island);
        char *src_name = parsed_bridges[i].first_island;
        char *dst_name = parsed_bridges[i].second_island;
        int weight = parsed_bridges[i].bridge_weight;

        mx_push_back_node(&(*graph)->islands_arr[src_index], dst_index, dst_name, weight);
        mx_push_back_node(&(*graph)->islands_arr[dst_index], src_index, src_name, weight);
    }
}

char **mx_parse_file(char *str_file, t_graph **graph) {
    char **lines = mx_strsplit(str_file, '\n');
    int num_of_bridges = count_bridges(lines);

    if (lines[0] == NULL || !is_number_valid(lines[0]) || mx_atoi(lines[0]) <= 0) {
        mx_error_invalid_line(1);
    }

    int num_of_all_islands = mx_atoi(lines[0]);

    char **islands = malloc(sizeof(char *) * (num_of_all_islands + 1));
    islands[num_of_all_islands] = NULL;

    int num_of_current_islands = 0;

    t_bridge *parsed_bridges = malloc(sizeof(t_bridge) * num_of_bridges);

    for (int i = 1; lines[i] != NULL; i++) {
        parsed_bridges[i - 1] = parse_bridge(lines[i], i + 1);

        if (is_duplicate_bridge(parsed_bridges, i - 1, parsed_bridges[i - 1])) {
            mx_error_duplicate_bridges();
        }

        add_new_island(islands, num_of_all_islands, &num_of_current_islands, parsed_bridges[i - 1].first_island);
        add_new_island(islands, num_of_all_islands, &num_of_current_islands, parsed_bridges[i - 1].second_island);
    }

    long long sum_bridges_weight = 0;
    for (int i = 0; i < num_of_bridges; i++) {
        sum_bridges_weight += parsed_bridges[i].bridge_weight;
        if (sum_bridges_weight > __INT_MAX__) {
            mx_error_invalid_sum_of_bridges_length();
        }
    }

    if (num_of_current_islands != num_of_all_islands) {
        mx_error_invalid_num_of_all_islands();
    }

    build_graph(graph, parsed_bridges, num_of_bridges, islands, num_of_all_islands);

    mx_del_strarr(&lines);

    for (int i = 0; i < num_of_bridges; i++) {
        mx_strdel(&(parsed_bridges[i].first_island));
        mx_strdel(&(parsed_bridges[i].second_island));
    }
    free(parsed_bridges);

    return islands;
}
