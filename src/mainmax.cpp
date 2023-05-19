#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale>
#define MAXN 100
#define SIZE 6
int graph[SIZE][SIZE];
int dist[MAXN];
int parent[MAXN];

void dijkstra(int start, int end, int n) {
    int visited[MAXN] = {0};
    int i, j, u, min_dist;
    for (i = 0; i < n; i++) {
        dist[i] = INT_MIN;
    }
    dist[start-1] = 0;
    for (i = 0; i < n-1; i++) {
        min_dist = INT_MIN;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] > min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (graph[u][j] && !visited[j] && dist[u] != INT_MIN && dist[u] + (-graph[u][j]) > dist[j]) {
                dist[j] = dist[u] + (-graph[u][j]);
                parent[j] = u; // Запоминаем предка для каждой вершины
            }
        }
    }
    if (dist[end-1] == INT_MIN) {
        printf("No path from %d to %d\n", start, end);
    } else {
        printf("Longest path between %d and %d is %d\n", start, end, dist[end-1]);
        printf("Path: ");
        int path[MAXN], len = 0;
        int current = end-1;
        while (current != start-1) { // Восстанавливаем маршрут, начиная с конца
            path[len++] = current;
            current = parent[current];
        }
        path[len++] = start-1;
        for (i = len-1; i >= 0; i--) { // Выводим маршрут в обратном порядке
            printf("%d ", path[i]+1);
            if (i > 0) {
                printf("-> ");
            }
        }
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int temp;
    int n=SIZE, i, j, start, end;
    for (int i = 0; i<SIZE; i++)
  {
   	graph[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      temp=rand()%10;
      printf("Введите расстояние %d - %d: %d\n ", i + 1, j + 1, temp);
      graph[i][j] = temp;
      graph[j][i] = temp;
    }

  }

  // Вывод матрицы связей
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", graph[i][j]);
    printf("\n");
  }
  
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j]) {
                graph[i][j] = -graph[i][j];
            }
        }
    }
    printf("Enter start node: ");
    scanf("%d", &start);
    printf("Enter end node: ");
    scanf("%d", &end);
    dijkstra(start, end, n);
    return 0;
}
