#include <stdbool.h>

#include <libgraphs/stacknode.h>
#include <libgraphs/listnode.h>

#ifndef GRAPHS_H
#define GRAPHS_H

typedef struct Graph
{
    int numVertices;
    struct Node **head;
    int *visited;
    ListNode *passed;
} Graph;

typedef struct Node
{
    int vertex, weight;
    struct Node *next;
} Node;

typedef struct Edge
{
    int src, vertex, weight;
} Edge;

Graph *createGraph(Edge *edges, int edgesSize, int graphSize);
Edge *matrixToEdges(int **matrix, int matrixSize, int* out_size);
void printGraph(Graph *graph, int size);
void clearVisited(Graph *graph);
void dfs(struct Graph *graph, int vertex);
void bfs(struct Graph *graph, int startVertex);
StackNode *getPathAllWrap(Graph *graph, int startVertex, int endVertex);
void getPathAll(Graph *graph, int startVertex, int endVertex, StackNode **paths);
int calculateWeightForPath(Graph *graph, StackNode *path);
StackNode *findMinPath(Graph *graph, StackNode *paths);
StackNode *findMaxPath(Graph *graph, StackNode *paths);

void printPaths(StackNode *paths);
void printWithWeightPaths(StackNode *paths);
void printPath(StackNode *path);
void freePaths(StackNode *paths);

#endif