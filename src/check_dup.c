#include "../inc/pathfinder.h"

void check_dup(char **file_lines, int lines_count) {

    for (int i = 0; i < lines_count; i++) {
        file_lines[i] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], ','));
    }
    
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (file_lines[j][0] == '\0' || j == i) {
                continue;
            }
            if (mx_strcmp(file_lines[i], file_lines[j]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }    
        }
    }
}
