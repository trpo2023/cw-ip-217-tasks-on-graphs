#include <stdio.h>

#include "../thirdparty/ctest.h"
#include <libgraphs/filereader.h>
#include <libgraphs/graphs.h>
#include <libgraphs/stacknode.h>

CTEST(graphs, all_path)
{
    int graphSize, edgesSize;
    int **matrix;
    matrix = readMatrixFile("test/data/graph.txt", &graphSize);
    Edge *edges = matrixToEdges(matrix, graphSize, &edgesSize);
    Graph *graph = createGraph(edges, edgesSize, graphSize);

    StackNode *paths = getPathAllWrap(graph, 0, 2);
    StackNode *path = NULL;

    StackNode *expectedPath = NULL;
    path = (StackNode *)paths->data;
    expectedPath = pushIntStackNode(expectedPath, 0);
    expectedPath = pushIntStackNode(expectedPath, 1);
    expectedPath = pushIntStackNode(expectedPath, 3);
    expectedPath = pushIntStackNode(expectedPath, 2);

    ASSERT_EQUAL(true, isIntStackEqual(expectedPath, path));

    path = (StackNode *)paths->prev->data;
    freeStack(&expectedPath);
    expectedPath = pushIntStackNode(expectedPath, 0);
    expectedPath = pushIntStackNode(expectedPath, 2);

    ASSERT_EQUAL(true, isIntStackEqual(expectedPath, path));

    path = (StackNode *)paths->prev->prev->data;
    freeStack(&expectedPath);
    expectedPath = pushIntStackNode(expectedPath, 0);
    expectedPath = pushIntStackNode(expectedPath, 3);
    expectedPath = pushIntStackNode(expectedPath, 2);

    ASSERT_EQUAL(true, isIntStackEqual(expectedPath, path));

    freePaths(paths);
}

CTEST(graphs, min_path)
{
    int graphSize, edgesSize;
    int **matrix;
    matrix = readMatrixFile("test/data/graph.txt", &graphSize);
    Edge *edges = matrixToEdges(matrix, graphSize, &edgesSize);
    Graph *graph = createGraph(edges, edgesSize, graphSize);

    StackNode *paths = getPathAllWrap(graph, 0, 2);
    StackNode *minPath = findMinPath(graph, paths);

    StackNode *rightPath = NULL;
    rightPath = pushIntStackNode(rightPath, 0);
    rightPath = pushIntStackNode(rightPath, 3);
    rightPath = pushIntStackNode(rightPath, 2);

    ASSERT_EQUAL(true, isIntStackEqual(minPath, rightPath));
    freePaths(paths);
}

CTEST(graphs, max_path)
{
    int graphSize, edgesSize;
    int **matrix;
    matrix = readMatrixFile("test/data/graph.txt", &graphSize);
    Edge *edges = matrixToEdges(matrix, graphSize, &edgesSize);
    Graph *graph = createGraph(edges, edgesSize, graphSize);

    StackNode *paths = getPathAllWrap(graph, 0, 2);
    StackNode *maxPath = findMaxPath(graph, paths);

    StackNode *rightPath = NULL;
    rightPath = pushIntStackNode(rightPath, 0);
    rightPath = pushIntStackNode(rightPath, 1);
    rightPath = pushIntStackNode(rightPath, 3);
    rightPath = pushIntStackNode(rightPath, 2);

    ASSERT_EQUAL(true, isIntStackEqual(maxPath, rightPath));
    freePaths(paths);
}