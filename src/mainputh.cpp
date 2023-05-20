#include <iostream>
#include <vector>
#include <time.h>
#include <locale>
#define SIZE 6


using namespace std;



void allPaths(int currVertex, int endVertex, int graph[][SIZE], vector<int>& path, vector<bool>& visited, int& pathCount) {
    visited[currVertex] = true; // Отмечаем текущую вершину как посещенную
    path.push_back(currVertex); // Добовляем текущую вершину в текущий путь

    if (currVertex == endVertex) { // Если мы достигаем конечной вершины 
        pathCount++;               // Увеличиваем счетчик путей
    } else { // Если мы не достигли конченой вершины
        for (int i = 0; i < SIZE; i++) {
            if (graph[currVertex][i] && !visited[i]) { // Если есть непосещенное ребро и вершина
                allPaths(i, endVertex, graph, path, visited, pathCount); // Рекурсивный поиск дальше
            }
        }
    }

    visited[currVertex] = false; // убираем метку о посещении текущей вершины, чтобы в дальнейшем ее можно использовать в других путях 
    path.pop_back();             // убираем иекущую вепшину из текущего пути
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int a[SIZE][SIZE];
	int b[SIZE][SIZE];
	int begin = 0;
  	int end=0;
  	int temp;
     for (int i = 0; i<SIZE; i++)
  {
   	a[i][i] = 0;
   	b[i][i] =0;
    for (int j = i + 1; j<SIZE; j++) {
      temp=rand()%10;
      printf("Ââåäèòå ðàññòîÿíèå %d - %d: %d\n ", i + 1, j + 1, temp);
	  if(temp!=0){
	  	b[i][j] = 1;
      	b[j][i] = 1;
	  }
	  else{
	  	b[i][j] = 0;
      	b[j][i] = 0;
	  }
      a[i][j] = temp;
      a[j][i] = temp;
    }

  }

  // Вывод матрицы связей 
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  printf("\n"); 
  printf("Введите пункт отправления  : ");
  scanf("%d",&begin);
  begin-=1;
  printf("Введите пункт назначения : ");
  scanf("%d",&end);
  end-=1;

    vector<int> path;                // создаем вектор для хранения текущего пути
    vector<bool> visited(SIZE, false);  // Создаем вектор для отметки о посещенных вершинах
    int pathCount = 0;               // Инициализируем счетчик путей

    allPaths(begin, end, b, path, visited, pathCount); // Ищем все пути из начальной вершины в конечную

    if (pathCount == 0) { // Если путь не найден
        cout << "Paths not found" << endl;
    } else { // Если путь найден выводим их количество
        cout << "Number of paths found: " << pathCount << endl;
    }

    return 0;
}
