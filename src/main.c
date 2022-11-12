#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    if (open(argv[1], O_RDONLY) < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    char *str_file = mx_file_to_str(argv[1]);
    check_errors(str_file, argv);
    char **file_lines = mx_strsplit(str_file, '\n');
    int nbr_of_islands = mx_atoi(file_lines[0]);
    char **islands = get_islands(str_file, nbr_of_islands);
    int **adj_matrix = get_bridge_matrix(str_file, islands, nbr_of_islands);
    int **matrix_of_paths = AlgoritmFloydWarshall(adj_matrix, nbr_of_islands);
    int *way_to_island = (int *)malloc((nbr_of_islands + 1) * 4);
    int nbr_of_steps = 1;
    
    for (int i = 0; i < nbr_of_islands; i++) {
        for (int j = i + 1; j < nbr_of_islands; j++) {

            way_to_island[1] = i;
            way_to_island[0] = j;

            print(islands, adj_matrix, matrix_of_paths, nbr_of_islands, way_to_island, nbr_of_steps);
        }
    }

    mx_strdel(&str_file);
    mx_del_strarr(&file_lines);
    mx_del_strarr(&islands);
    mx_del_2dintarr(&adj_matrix, nbr_of_islands);
    mx_del_2dintarr(&matrix_of_paths, nbr_of_islands);
    free(way_to_island);

    return 0;
}
