#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphs.h"

#ifndef GRAPHS_C
#define GRAPHS_C

#define MAXN 100
#define SIZE 6

void allPaths(int currVertex, int endVertex, int graph[][SIZE], int *path, bool *visited, int *pathCount)
{
    visited[currVertex] = true;
    path[endVertex] = currVertex;

    if (currVertex == endVertex)
        (*pathCount)++;

    else
        for (int i = 0; i < SIZE; i++)
            if (graph[currVertex][i] && !visited[i])
                allPaths(i, endVertex, graph, path, visited, pathCount);

    visited[currVertex] = false;
    path[endVertex] = -1;
}

void dijkstra(int start, int end, int n)
{
    int visited[MAXN] = {0};
    int i, j, u, max_dist;

    for (i = 0; i < n; i++)
    {
        dist[i] = INT_MIN;
    }

    dist[start - 1] = 0;

    for (i = 0; i < n - 1; i++)
    {
        max_dist = INT_MIN;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] > max_dist)
            {
                max_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++)
        {
            if (graph[u][j] && !visited[j] && dist[u] != INT_MIN && dist[u] + (-graph[u][j]) > dist[j])
            {
                dist[j] = dist[u] + (-graph[u][j]);
                parent[j] = u;
            }
        }
    }

    if (dist[end - 1] == INT_MIN)
        printf("No path from %d to %d\n", start, end);

    else
    {
        printf("The longest way between %d and %d: %d\n", start, end, dist[end - 1]);
        printf("The Way: ");

        int path[MAXN];
        int len = 0;
        int current = end - 1;

        while (current != start - 1)
        {
            path[len++] = current;
            current = parent[current];
        }

        path[len++] = start - 1;

        for (i = len - 1; i >= 0; i--)
        {
            printf("%d ", path[i] + 1);

            if (i > 0)
                printf("-> ");
        }

        printf("\n");
    }
}

void minPath(int a[SIZE][SIZE], int begin, int end)
{
  int d[SIZE];
  int v[SIZE];
  int cou[SIZE];
  int temp, minIndex, min, count = 0;
  int ver[SIZE];
  ver[0] = end + 1;
  int k = 1;
  int weight = 0;

  for (int i = 0; i < SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 0;
  }
  d[begin] = 0;

  do
  {
    minIndex = 10000;
    min = 10000;
    for (int i = 0; i < SIZE; i++)
    {
      if ((v[i] == 0) && (d[i] < min))
      {
        min = d[i];
        minIndex = i;
      }
    }

    if (minIndex != 10000)
    {
      for (int i = 0; i < SIZE; i++)
      {
        if (a[minIndex][i] > 0)
        {
          temp = min + a[minIndex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minIndex] = 1;
    }
  } while (minIndex < 10000);

  printf("\nShortest distances to summits: \n");
  for (int i = 0; i < SIZE; i++)
    if (i == end)
      printf("%d->%d=%d ", begin + 1, i + 1, d[i]);

  weight = d[end];

  while (end != begin)
  {
    for (int i = 0; i < SIZE; i++)
      if (a[i][end] != 0)
      {
        int temp = weight - a[i][end];
        if (temp == d[i])
        {
          weight = temp;
          end = i;
          if (i == 0)
            i++;

          ver[k] = i + 1;
          k++;
        }
      }
  }

  printf("\nShortest path output\n");
  for (int i = k - 1; i >= 0; i--)
    if (i == 0)
      printf("%3d", ver[i]);
    else
      printf("%3d ->", ver[i]);
}

#endif