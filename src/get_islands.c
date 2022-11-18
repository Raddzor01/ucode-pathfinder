#include "../inc/pathfinder.h"

char** get_islands(char *str_file, int isl_nbr) {

    char *str = mx_strdup(str_file);
    int lines_count = 0;
    char **islands = (char **)malloc((isl_nbr + 1) * sizeof(char *));

    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '-' || str[i] == ',' || str[i] == '\n' || mx_isdigit(str[i])) {
            str[i] = ' ';
        }
    }

    char *str_no_spaces = mx_del_extra_spaces(str);
    char **temp = mx_strsplit(str_no_spaces, ' ');
    while (temp[lines_count]) {
        lines_count++;
    }
    
    check_loop(temp, lines_count);

    int k = 0;
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (temp[j][0] == ' ' || j == i)
                continue;
            if (mx_strcmp(temp[i], temp[j]) == 0)
                temp[j][0] = ' ';
        }
        if(mx_isalpha(temp[i][0])) {
            islands[k] = mx_strdup(temp[i]);
            k++;
        }
    }
    islands[isl_nbr] = NULL;

    check_nbr_of_islands(temp, lines_count, isl_nbr);

    mx_strdel(&str);
    mx_strdel(&str_no_spaces);
    mx_del_strarr(&temp);

    return islands;
}

