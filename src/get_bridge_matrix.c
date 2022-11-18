#include "../inc/pathfinder.h"

int **get_bridge_matrix(char **file_lines, char **vertex_arr, int size) {

    int **adj_matrix = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        adj_matrix[i] = (int *)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            adj_matrix[i][j] = INFINITY;
        }
    }
    
    for (int i = 1; file_lines[i]; i++) {

        char **temp = get_path(file_lines[i]);

        if (mx_atoi(temp[2]) >= __INT_MAX__) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(0);
        }

        adj_matrix[mx_get_strarr_index(vertex_arr, temp[0])][mx_get_strarr_index(vertex_arr, temp[1])] = mx_atoi(temp[2]);
        adj_matrix[mx_get_strarr_index(vertex_arr, temp[1])][mx_get_strarr_index(vertex_arr, temp[0])] = mx_atoi(temp[2]);
    
        mx_del_strarr(&temp);

    }

    return adj_matrix;

}

