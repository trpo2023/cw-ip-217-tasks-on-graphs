#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "graphs.h"
#include "stacknode.h"

int main()
{
    int graphSize = 12;
    Edge edges[] = {
        {7, 6, 3},
        {6, 7, 5},

        {7, 2, 2},
        {2, 7, 1},

        {7, 5, 3},
        {5, 7, 7},

        {6, 4, 4},
        {4, 6, 8},

        {2, 1, 9},
        {1, 2, 11},

        {5, 9, 3},
        {9, 5, 1},

        {4, 10, 2},
        {10, 4, 3},

        {1, 10, 5},
        {10, 1, 3},

        {9, 10, 4},
        {10, 9, 7},
    };

    int n = sizeof(edges) / sizeof(edges[0]);

    struct Graph *graph = createGraph(edges, n, graphSize);
    printGraph(graph, graphSize);

    StackNode *paths = getPathAllWrap(graph, 4, 7);
    printf("Detected paths:\n");
    printPaths(paths);
    printf("\n");

    printf("Min paths:\n");
    StackNode *minPath = findMinPath(graph, paths);
    printPath(minPath);
    printf("Weight: %d\n", calculateWeightForPath(graph, minPath));
    printf("\n");

    printf("Max paths:\n");
    StackNode *maxPath = findMaxPath(graph, paths);
    printPath(maxPath);
    printf("Weight: %d\n", calculateWeightForPath(graph, maxPath));

    freePaths(paths);

    return 0;
}