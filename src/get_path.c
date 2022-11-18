#include "../inc/pathfinder.h"

char **get_path(char *line) {

    char **strarr = (char **)malloc(4 * sizeof(char *));
    for (int i = 0; i <= 3; i++) {
        strarr[i] = NULL;
    }
    
    strarr[0] = mx_strndup(line, mx_get_char_index(line, '-'));
    line += mx_get_char_index(line, '-') + 1;
    strarr[1] = mx_strndup(line, mx_get_char_index(line, ','));
    line += mx_get_char_index(line, ',') + 1;
    strarr[2] = mx_strndup(line, mx_get_char_index(line, '\n'));
     
    return strarr;
}
