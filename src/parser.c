#include <stdio.h> #include <stdlib.h>

#define MAX_VERTICES 100

int main() { 
FILE *input; 
int num_vertices; 
int adj_matrix[MAX_VERTICES][MAX_VERTICES]; 
int i, j;

input = fopen("i.txt", "r");
if (input == NULL) {
    printf("Error opening file.\n");
    return 1;
}

fscanf(input, "%d", &num_vertices);

for (i = 0; i < num_vertices; i++) {
    for (j = 0; j < num_vertices; j++) {
        fscanf(input, "%d", &adj_matrix[i][j]);
    }
}

printf("Adjacency Matrix:\n");
for (i = 0; i < num_vertices; i++) {
    for (j = 0; j < num_vertices; j++) {
        printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
}

fclose(input);
return 0;
}
