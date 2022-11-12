#include "../inc/pathfinder.h"

void print_route(int count, int *route, char **islands) {
    if (count > 2) {
        for (int i = 1; i < count + 1; i++) {
            mx_printstr(islands[route[i]]);
            if (i < count)
                mx_printstr(" -> ");

        }
    } else {
        mx_printstr(islands[route[1]]);
        mx_printstr(" -> ");
        mx_printstr(islands[route[0]]);
    }
}
