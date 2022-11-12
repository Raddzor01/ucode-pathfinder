#pragma once

#include "../libmx/inc/libmx.h"

#define INFINITY __INT_MAX__

void check_errors(char *file, char **argv);
void check_nbr_of_islands(char **temp, int lines, int nbr_of_islands);
void invalid_n_line(int number_of_line);
void check_lines(char **file_lines, int lines_count);
void check_dup(char **file_lines, int lines_count);
void check_loop(char **strarr, int count_lines);
char** get_islands(char *str, int isl_nbr);
int **get_bridge_matrix(char *str, char **vertex_arr, int size);
int **AlgoritmFloydWarshall(int **matrix, int numberOfVert);
void algorithm(int ***w, int size);
void print_route(int count, int *route, char **islands);
void print_dist(int nbr_of_steps, int *way_to_island, int **adj_matrix, int **matrix_of_paths);
void print(char **islands, int **adj_matrix, int **matrix_of_paths, int nbr_of_islands, int *way_to_island, int nbr_of_steps);
