#include "../inc/pathfinder.h"

void check_loop(char **strarr, int count_lines) {
    for (int i = 0, count = 1; i < count_lines; i += 2, count++) {
        if(mx_strcmp(strarr[i], strarr[i + 1]) == 0) {
            invalid_n_line(count + 1);
        }
    }
}
