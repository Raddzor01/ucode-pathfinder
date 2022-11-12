#include "../inc/pathfinder.h"

char** get_islands(char *str_file, int isl_nbr) {

    char *str = mx_strdup(str_file);
    char **islands = (char **)malloc(isl_nbr * 100);
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '-' || str[i] == ',' || str[i] == '\n' || mx_isdigit(str[i])) {
            str[i] = ' ';
        }
    }

    str = mx_del_extra_spaces(str);
    char **temp = mx_strsplit(str, ' ');

    int lines_count = 0;
    while (temp[lines_count]) {
        lines_count++;
    }
    
    check_loop(temp, lines_count);

    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (temp[j][0] == '\0' || j == i) {
                continue;
            }
            if (mx_strcmp(temp[i], temp[j]) == 0) {
                temp[j][0] = '\0';
            }    
        }
    }

    check_nbr_of_islands(temp, lines_count, isl_nbr);

    int j = 0;
    for (int i = 0; i < lines_count; i++) {
        if(mx_isalpha(temp[i][0])) {
            islands[j] = mx_strdup(temp[i]);
            j++;
        }
    }

    mx_strdel(&str);
    mx_del_strarr(&temp);

    return islands;
}

