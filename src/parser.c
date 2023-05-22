#include <stdio.h>
#include <stdlib.h>

#ifndef PARSER_C
#define PARSER_C

#define MAX_VERTICES 100

int **readFile(char *fileName);

int **readFile(char *fileName)
{
    FILE *input;
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int i, j;

    input = fopen(fileName, "r");
    if (input == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(input, "%d", &num_vertices);

    for (i = 0; i < num_vertices; i++)
        for (j = 0; j < num_vertices; j++)
            fscanf(input, "%d", &adj_matrix[i][j]);

    return adj_matrix;
}

#endif
