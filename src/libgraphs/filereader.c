#include <stdio.h>
#include <stdlib.h>

#ifndef FILEREADER_C
#define FILEREADER_C

int** readMatrixFile(char* fileName, int* size_out)
{
    FILE* file;
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    fscanf(file, "%d", &(*size_out));
    int size = *size_out;

    int** adj_matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        adj_matrix[i] = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (feof(file)) {
                printf("Cannot read file\n");
                fclose(file);
                for (int i = 0; i < size; i++)
                    free(adj_matrix[i]);
                free(adj_matrix);
                return NULL;
            }
            fscanf(file, "%d", &adj_matrix[i][j]);
            if ((!feof(file) && i == size - 1 && j == size - 1)) {
                printf("Cannot read file\n");
                fclose(file);
                for (int i = 0; i < size; i++)
                    free(adj_matrix[i]);
                free(adj_matrix);
                return NULL;
            }
        }

    fclose(file);
    return adj_matrix;
}

#endif
