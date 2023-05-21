#ifndef GRAPHS_H
#define GRAPHS_H

typedef struct Graph
{
    int numVertices;
    struct Node **head;
    int *visited;
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
void clearVisited(Graph *graph, int graphSize);
void dfs(struct Graph *graph, int vertex);
void bfs(struct Graph *graph, int startVertex);

#endif