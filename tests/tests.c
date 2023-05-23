#include <stdio.h>

#include <ctest.h>
#include <libgraphs/filereader.h>
#include <libgraphs/graphs.h>
#include <libgraphs/stacknode.h>


CTEST(graphs, min_path)
{
    int graphSize, edgesSize;
    int **matrix;
    matrix = readMatrixFile("./tests/graph.txt", &graphSize);
    Edge *edges = matrixToEdges(matrix, graphSize, &edgesSize);
    Graph *graph = createGraph(edges, edgesSize, graphSize);

    StackNode* paths = getPathAllWrap(graph, 0, 2);
    StackNode* minPath = findMinPath(graph, paths);

    StackNode* rightPath = NULL;
    rightPath = pushIntStackNode(rightPath, 2);
    rightPath = pushIntStackNode(rightPath, 3);
    rightPath = pushIntStackNode(rightPath, 0);

    ASSERT_EQUAL(true, isIntStackEqual(minPath, rightPath));
}