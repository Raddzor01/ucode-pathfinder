#include "../inc/pathfinder.h"

void print(char **islands, int **adj_matrix, int **matrix_of_paths, int nbr_of_islands, int *way_to_island, int nbr_of_steps) {

    int start_island = way_to_island[0];
    int end_island = way_to_island[nbr_of_steps];

    for (int i = 0; i < nbr_of_islands; i++) {
        if((adj_matrix[end_island][i] == matrix_of_paths[end_island][start_island] - matrix_of_paths[i][start_island])
        && i != way_to_island[nbr_of_steps]) {

            nbr_of_steps++;
            way_to_island[nbr_of_steps] = i;

            print(islands, adj_matrix, matrix_of_paths, nbr_of_islands, way_to_island, nbr_of_steps);

            nbr_of_steps--;
        }
    }

    if (way_to_island[nbr_of_steps] != start_island) {
        return;
    } 

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(islands[way_to_island[1]]);
    mx_printstr(" -> ");
    mx_printstr(islands[way_to_island[0]]);
    mx_printstr("\nRoute: ");
    print_route(nbr_of_steps, way_to_island, islands);
    mx_printstr("\nDistance: ");
    print_dist(nbr_of_steps, way_to_island, adj_matrix, matrix_of_paths);
    mx_printstr("\n========================================\n");

}
