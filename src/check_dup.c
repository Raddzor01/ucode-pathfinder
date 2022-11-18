#include "../inc/pathfinder.h"

void check_dup(char **file_lines, int lines_count) {

    char **temp = (char **)malloc((lines_count + 1) * sizeof(char *));
    for (int i = 0; i < lines_count; i++) {
        temp[i] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], ','));
    }
    temp[lines_count] = NULL;
    
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (temp[j][0] == '\0' || j == i) {
                continue;
            }
            if (mx_strcmp(temp[i], temp[j]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }    
        }
    }

    mx_del_strarr(&temp);
    
}
