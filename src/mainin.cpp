#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <locale>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define SIZE 6

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
  int a[SIZE][SIZE];// Матрица связей
  int **matr;
  matr=new  int *[SIZE];
  int d[SIZE]; // Минимальное расстояние 
  int cou[SIZE]; // Посещенные вершины
  int temp, minindex, min,count=0;
  int begin = 0;
  int end=0;
  bool eror = false;
  system("chcp 1251");
  system("cls");
  // Инициализация матриы связей (пока что рандомная для проверки кода)
 for (int i = 0; i<SIZE; i++)
  {
   	a[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      temp=rand()%10;
      printf("Введите расстояние %d - %d: %d\n ", i + 1, j + 1, temp); 
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }

  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  printf("\n");
  printf("Введите пункт отправления : ");
  scanf("%d",&begin);
  begin-=1;
  printf("Введите пункт назначения : ");
  scanf("%d",&end);
  end-=1;
  
  

  
  if(begin==end){
  	eror=true;
  }
  if(eror==false){
  
  //Инициализация вершин и расстояний
  for (int i = 0; i<SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin] = 0;
  

  // Шаг алгоритма
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    { // Если вершину еще не обошли и вес меньше min
      if ((v[i] == 1) && (d[i]<min))
      { // Переписываем значения 
        min = d[i];
        minindex = i;
      }
    }
    // Добавляем найденый минимальный вес 
    // к текущему весу вершины
    // и сравниваем с текущим минимальным весом вершины
    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);
  // Вывод кратчайших расстяоний до вершины 
  printf("\nКратчайшие расстояния до вершины: \n");
  for (int i = 0; i<SIZE; i++)
    printf("%d->%d=%d ",begin+1,i+1, d[i]);

  // Восстановление пути
  int ver[SIZE]; // массив посещенных вершин
   // индекс конечной вершины = 5 - 1 (до 5)
  ver[0] = end; // начальный элемент конечная вершина
  int k = 1; // индекс предыдущей вершины 
  int weight = d[end]; // Вес конченой вершины

  while (end != begin) 
  {
    for (int i = 0; i<SIZE; i++) // просматриваем все вершины
      if (a[i][end] != 0)   // если связь есть
      {
        int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины 
        if (temp == d[i]) // если вес совпал с расчитанным 
        {                 // значит из этой вершины и был переход
          weight = temp; // сохраняем новый вес 
          end = i;       // сохраняем предыдущую вершину 
          ver[k] = i + 1; // и записываем ее в массив
          k++;
        }
      }
  }
  // Вывод пути
  printf("\nВывод кратчайшего пути\n");
  for (int i = k - 1; i >= 0; i--){
  	if(i==0){
  		printf("%3d",ver[i]);
	  }
	else{
		printf("%3d ->",ver[i]);
	}
}
}
else
	printf("Error : Пункт назначение совпадает с пунктом отправления !");
  getchar(); getchar();
  return 0;
  

  for (int i=0;i<SIZE;i++)
   {  delete  matr[i]; 
         matr[i]=NULL;
    }

  delete  matr;
  matr=NULL;

 }







