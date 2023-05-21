#include <iostream>
#include <vector>
#include <time.h>
#include <locale>
#define SIZE 6


using namespace std;



void allPaths(int currVertex, int endVertex, int graph[][SIZE], vector<int>& path, vector<bool>& visited, int& pathCount) {
    visited[currVertex] = true; // �������� ������� ������� ��� ����������
    path.push_back(currVertex); // ��������� ������� ������� � ������� ����

    if (currVertex == endVertex) { // ���� �� �������� �������� �������
        pathCount++;               // ����������� ������� �����
    } else { // ���� �� ��� �� �������� �������� �������
        for (int i = 0; i < SIZE; i++) {
            if (graph[currVertex][i] && !visited[i]) { // ���� ���� ����� � ������� ��� �� ���� ��������
                allPaths(i, endVertex, graph, path, visited, pathCount); // ����������� ����� ������
            }
        }
    }

    visited[currVertex] = false; // ������� ����� � ��������� ������� �������, ����� � ���������� � ����� ���� ������������ � ������ �����
    path.pop_back();             // ������� ������� ������� �� �������� ����
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
      printf("������� ���������� %d - %d: %d\n ", i + 1, j + 1, temp);
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

  // ����� ������� ������
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  printf("\n"); 
  printf("������� ����� ����������� : ");
  scanf("%d",&begin);
  begin-=1;
  printf("������� ����� ���������� : ");
  scanf("%d",&end);
  end-=1;

    vector<int> path;                // ������� ������ ��� �������� �������� ����
    vector<bool> visited(SIZE, false);  // ������� ������ ��� ������� � ���������� ��������
    int pathCount = 0;               // �������������� ������� �����

    allPaths(begin, end, b, path, visited, pathCount); // ���� ��� ���� �� ��������� ������� � ��������

    if (pathCount == 0) { // ���� ���� �� �������, ������� ��������� �� ����
        cout << "Paths not found" << endl;
    } else { // ���� ���� �������, ������� �� ����������
        cout << "Number of paths found: " << pathCount << endl;
    }

    return 0;
}
