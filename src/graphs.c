#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "graphs.h"
#include "queue.h"
#include "stacknode.h"
#include "listnode.h"

#ifndef GRAPHS_C
#define GRAPHS_C

Graph *createGraph(Edge *edges, int edgesSize, int graphSize)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->head = (Node **)malloc(sizeof(Node *) * graphSize);
    graph->numVertices = graphSize;
    graph->visited = malloc(graph->numVertices * sizeof(int));
    graph->passed = NULL;

    for (int i = 0; i < graphSize; i++)
    {
        graph->head[i] = NULL;
        graph->visited[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++)
    {
        int src = edges[i].src;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->vertex = edges[i].vertex;
        newNode->weight = edges[i].weight;
        newNode->next = graph->head[src];

        graph->head[src] = newNode;
    }

    return graph;
}
Edge *matrixToEdges(int **matrix, int matrixSize, int *out_size)
{
    StackNode *temp = NULL;

    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
        {
            if (matrix[i][j] > 0)
            {
                Edge edge = {i, j, matrix[i][j]};
                temp = pushStackNode(temp, &edge, sizeof(Edge));
            }
        }

    int edgesSize = temp->size;
    Edge *edges = malloc(edgesSize * sizeof(Edge));
    StackNode *headTemp = temp;
    while (temp)
    {
        Edge *edgeTemp = (Edge *)temp->data;
        Edge edge = {edgeTemp->src, edgeTemp->vertex, edgeTemp->weight};
        edges[temp->size - 1] = edge;
        temp = temp->prev;
    }
    freeStack(&headTemp);
    *out_size = edgesSize;
    if (edges == NULL)
    {
        printf("Graph edges are not detected\n");
        exit(0);
    }
    return edges;
}

void printGraph(Graph *graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        Node *ptr = graph->head[i];
        if (!ptr)
            continue;
        while (ptr != NULL)
        {
            printf("%d -> %d (%d)\t", i, ptr->vertex, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
    printf("\n");
}

void clearVisited(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;

    freeList(&(graph->passed));
}

void dfs(Graph *graph, int vertex)
{
    Node *adjList = graph->head[vertex];
    Node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void bfs(Graph *graph, int startVertex)
{
    Queue *q = createQueue();

    graph->visited[startVertex] = 1;
    addQueue(q, startVertex);

    while (!isEmpty(q))
    {
        printQueue(q);
        int currentVertex = removeQueue(q);
        printf("Visited %d\n", currentVertex);

        Node *ptr = graph->head[currentVertex];

        while (ptr)
        {
            int adjVertex = ptr->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                addQueue(q, adjVertex);
            }
            ptr = ptr->next;
        }
    }
}

bool getPath(Graph *graph, int startVertex, int endVertex, StackNode **path)
{
    Node *temp = graph->head[startVertex];
    graph->visited[startVertex] = 1;

    if (startVertex == endVertex)
    {
        *path = pushIntStackNode(*path, startVertex);
        return true;
    }

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
            if (getPath(graph, connectedVertex, endVertex, path))
            {
                *path = pushIntStackNode(*path, startVertex);
                return true;
            }

        temp = temp->next;
    }
}

StackNode *getPathAllWrap(Graph *graph, int startVertex, int endVertex)
{
    Node *temp = graph->head[startVertex];
    StackNode *paths = NULL;
    if (startVertex < 0 || startVertex > graph->numVertices)
        return paths;
    getPathAll(graph, startVertex, endVertex, &paths);
    return paths;
}

static void getPathAll(Graph *graph, int startVertex, int endVertex, StackNode **paths)
{
    if (startVertex == endVertex)
    {
        StackNode *pathTemp = NULL;
        ListNode *tv = findHead(graph->passed);
        while (tv)
        {
            pathTemp = pushIntStackNode(pathTemp, ((int *)tv->data)[0]);
            tv = tv->next;
        }
        pathTemp = pushIntStackNode(pathTemp, endVertex);
        *paths = pushStackInStackNode(*paths, pathTemp);

        return;
    }

    Node *temp = graph->head[startVertex];
    graph->passed = pushIntListNode(graph->passed, startVertex);

    while (temp)
    {
        int currentVertex = temp->vertex;

        if (!findListNode(graph->passed, currentVertex))
            getPathAll(graph, currentVertex, endVertex, paths);

        temp = temp->next;
    }
    ListNode *rem = findListNode(graph->passed, startVertex);
    graph->passed = removeListNode(rem);
}

int calculateWeightForPath(Graph *graph, StackNode *path)
{
    int weight = 0;
    while (path->prev)
    {
        int currentVertex = *((int *)(path->data));
        int nextVertex = ((int *)(path->prev->data))[0];
        Node *node = graph->head[currentVertex];
        while (node->vertex != nextVertex)
            node = node->next;

        weight += node->weight;

        path = path->prev;
    }
    return weight;
}

StackNode *findMinPath(Graph *graph, StackNode *paths)
{
    if (!paths)
        return NULL;
    StackNode *minPath = paths->data;
    int minPathWeight = calculateWeightForPath(graph, paths->data);
    paths = paths->prev;
    while (paths)
    {
        int pathWeight = calculateWeightForPath(graph, paths->data);
        if (pathWeight < minPathWeight)
        {
            minPathWeight = pathWeight;
            minPath = paths->data;
        }
        paths = paths->prev;
    }
    return minPath;
}

StackNode *findMaxPath(Graph *graph, StackNode *paths)
{
    if (!paths)
        return NULL;
    StackNode *maxPath = paths->data;
    int maxPathWeight = calculateWeightForPath(graph, paths->data);
    paths = paths->prev;
    while (paths)
    {
        int pathWeight = calculateWeightForPath(graph, paths->data);
        if (pathWeight > maxPathWeight)
        {
            maxPathWeight = pathWeight;
            maxPath = paths->data;
        }
        paths = paths->prev;
    }

    return maxPath;
}

void printPaths(StackNode *paths)
{
    while (paths)
    {
        printIntStackNode((StackNode *)(paths->data));
        paths = paths->prev;
    }
}

void printPath(StackNode *path)
{
    printIntStackNode(path);
}

void freePaths(StackNode *paths)
{
    while (paths)
    {
        StackNode *t = (StackNode *)(paths->data);
        freeStack(&t);
        paths = paths->prev;
    }
}

#endif