#include "../inc/pathfinder.h"

void check_errors(char *file, char *argv[]) {

    if (mx_strlen(file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }

    char **file_lines = mx_strsplit(file, '\n');
    int lines_count = 0;
    while (file_lines[lines_count]) {
        lines_count++;
    }
    

    for (int i = 0; file_lines[0][i]; i++) {
        if(!mx_isdigit(file_lines[0][i])) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
    }
    
    if (file_lines[0][0] == '0' || file_lines[0][0] == '-') {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }

    check_lines(file_lines, lines_count);
    check_dup(file_lines, lines_count);
    
    mx_del_strarr(&file_lines);

}
