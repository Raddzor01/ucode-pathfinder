#include "../inc/pathfinder.h"

void print_dist(int count, int *route, int **adj_matrix, int **matrix_of_paths) {
    if (count > 2) {
       for (int i = 1; i < count; i++) {
            int temp = adj_matrix[route[i]][route[i + 1]];

            mx_printint(temp);

            if (i < count - 1) {
                mx_printstr(" + ");
               }
        }
        mx_printstr(" = ");
        mx_printint(matrix_of_paths[route[0]][route[1]]);
    } else {
        mx_printint(matrix_of_paths[route[0]][route[1]]);
    }
}
