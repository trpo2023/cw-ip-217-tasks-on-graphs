#include <stdbool.h>
#include "stacknode.h"
#include "listnode.h"

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
void printGraph(Graph *graph, int size);
void clearVisited(Graph *graph);
void dfs(struct Graph *graph, int vertex);
void bfs(struct Graph *graph, int startVertex);
bool getPath(Graph *graph, int startVertex, int endVertex, StackNode **path);
StackNode *getPathAllWrap(Graph *graph, int startVertex, int endVertex);
static void getPathAll(Graph *graph, int startVertex, int endVertex, StackNode **paths);

void printPaths(StackNode* paths);
void freePaths(StackNode* paths);

#endif