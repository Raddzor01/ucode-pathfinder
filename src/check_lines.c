#include "../inc/pathfinder.h"


void check_lines(char **file_lines, int lines_count) {
    for (int i = 1; i < lines_count; i++) {

        int j = 0;
        int temp = 0;

        while (mx_isalpha(file_lines[i][j])) {
            j++;
        }

        if (j == 0 || file_lines[i][j] != '-') {
            mx_del_strarr(&file_lines);
            invalid_n_line(i + 1);
        }

        j++;
        temp = j;

        while (mx_isalpha(file_lines[i][j])) {
            j++;
        }

        if (j == temp || file_lines[i][j] != ',') {
            mx_del_strarr(&file_lines);
            invalid_n_line(i + 1);
        }

        j++;
        temp = j;

        while (mx_isdigit(file_lines[i][j])) {
            j++;
        }

        if (j == temp || file_lines[i][j] != '\0') {
            mx_del_strarr(&file_lines);
            invalid_n_line(i + 1);
        }
        
    }
}
