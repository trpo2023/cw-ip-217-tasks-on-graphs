#ifndef GRAPHS_H
#define GRAPHS_H

#define SIZE 6

void allPaths(int currVertex, int endVertex, int graph[][SIZE], int *path, bool *visited, int *pathCount);
void dijkstra(int start, int end, int n);
void minPath(int a[SIZE][SIZE], int begin, int end);

#endif