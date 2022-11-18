#include "../inc/pathfinder.h"

int **AlgoritmFloydWarshall(int **matrix, int numberOfVert) {

    int **temp = (int **)malloc(numberOfVert * numberOfVert * sizeof(int *));
    for (int i = 0; i < numberOfVert; i++) {

        temp[i] = (int *)malloc(numberOfVert * sizeof(int));

        for (int j = 0; j < numberOfVert; j++)
            temp[i][j] = matrix[i][j];

    }

    for(int k = 0 ; k < numberOfVert; k++) {
        for(int i = 0 ; i < numberOfVert; i++) {
            for(int j = 0 ; j < numberOfVert; j++) {
                if(i != j && temp[i][k] != INFINITY && temp[k][j] != INFINITY) {
                    if(temp[i][j] == INFINITY){
                        temp[i][j] = temp[i][k] + temp[k][j];
                    } else {
                        temp[i][j] = MX_MIN(temp[i][j], temp[i][k] + temp[k][j]);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < numberOfVert; i++) {
        for (int j = 0; j < numberOfVert; j++) {
            if (temp[i][j] == INFINITY) {
                temp[i][j] = 0;
            }
        }
        
    }
    return temp;
}
