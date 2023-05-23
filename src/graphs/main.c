#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <libgraphs/filereader.h>
#include <libgraphs/graphs.h>
#include <libgraphs/stacknode.h>

int main(int argc, char *argv[])
{
    int graphSize, edgesSize;
    int **matrix;
    int vertexStart, vertexEnd;
    bool exit = false;

    if (argv[1])
        matrix = readMatrixFile(argv[1], &graphSize);
    else
        matrix = readMatrixFile("./data/graph_test.txt", &graphSize);

    Edge *edges = matrixToEdges(matrix, graphSize, &edgesSize);
    Graph *graph = createGraph(edges, edgesSize, graphSize);
    printGraph(graph, graphSize);

    char buff[100];

    while (exit == false)
    {
        printf("Write vertex: <a> <b> to get info, or q to exit\n");
        while (fgets(buff, 100, stdin) != NULL)
        {
            if (strstr(buff, "q"))
            {
                exit = true;
                break;
            }
            sscanf(buff, "%d %d", &vertexStart, &vertexEnd);

            if (((vertexStart < 0 || vertexStart > graphSize - 1) || (vertexEnd < 0 || vertexEnd > graphSize - 1)) || (vertexStart == vertexEnd))
            {
                printf("Written data is not valid\n\n");
                break;
            }
            printf("\nSUMMARY INFO\n");
            StackNode *paths = getPathAllWrap(graph, vertexStart, vertexEnd);
            if (!paths)
            {
                printf("Path not found\n");
                break;
            }
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
            vertexStart = -1;
            vertexEnd = -1;
            printf("\n");
            break;
        }
    }

    return 0;
}