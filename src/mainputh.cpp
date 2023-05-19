#include <iostream>
#include <vector>
#include <time.h>
#include <locale>
#define SIZE 6


using namespace std;



void allPaths(int currVertex, int endVertex, int graph[][SIZE], vector<int>& path, vector<bool>& visited, int& pathCount) {
    visited[currVertex] = true; // Отмечаем текущую вершину как посещенную
    path.push_back(currVertex); // Добавляем текущую вершину в текущий путь

    if (currVertex == endVertex) { // Если мы достигли конечной вершины
        pathCount++;               // Увеличиваем счетчик путей
    } else { // Если мы еще не достигли конечной вершины
        for (int i = 0; i < SIZE; i++) {
            if (graph[currVertex][i] && !visited[i]) { // Если есть ребро и вершина еще не была посещена
                allPaths(i, endVertex, graph, path, visited, pathCount); // Рекурсивный поиск дальше
            }
        }
    }

    visited[currVertex] = false; // Убираем метку о посещении текущей вершины, чтобы в дальнейшем её можно было использовать в других путях
    path.pop_back();             // Убираем текущую вершину из текущего пути
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
      printf("Введите расстояние %d - %d: %d\n ", i + 1, j + 1, temp);
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
  printf("Введиет пункт отправления : ");
  scanf("%d",&begin);
  begin-=1;
  printf("Введиет пункт назначения : ");
  scanf("%d",&end);
  end-=1;

    vector<int> path;                // Создаем вектор для хранения текущего пути
    vector<bool> visited(SIZE, false);  // Создаем вектор для отметки о посещенных вершинах
    int pathCount = 0;               // Инициализируем счетчик путей

    allPaths(begin, end, b, path, visited, pathCount); // Ищем все пути из начальной вершины в конечную

    if (pathCount == 0) { // Если пути не найдены, выводим сообщение об этом
        cout << "Paths not found" << endl;
    } else { // Если пути найдены, выводим их количество
        cout << "Number of paths found: " << pathCount << endl;
    }

    return 0;
}
