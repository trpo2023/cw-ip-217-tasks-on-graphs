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
  int a[SIZE][SIZE];
  int **matr;
  matr = new int *[SIZE];
  int d[SIZE];
  int cou[SIZE];
  int temp, minindex, min, count = 0;
  int begin = 0;
  int end = 0;

  for (int i = 0; i < SIZE; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j < SIZE; j++)
    {
      temp = rand() % 10;
      printf("Введите расстояние %d - %d: %d\n ", i + 1, j + 1, temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  printf("\n");
  printf("Введите пункт отправления : ");
  scanf("%d", &begin);
  begin -= 1;
  printf("Введите пункт назначения : ");
  scanf("%d", &end);
  end -= 1;

  for (int i = 0; i < SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin] = 0;

  do
  {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i < SIZE; i++)
    {
      if ((v[i] == 1) && (d[i] < min))
      {
        min = d[i];
        minindex = i;
      }
    }

    if (minindex != 10000)
    {
      for (int i = 0; i < SIZE; i++)
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

  printf("\nКратчайшие расстояния до вершины: \n");
  for (int i = 0; i < SIZE; i++)
    printf("%d->%d=%d ", begin + 1, i + 1, d[i]);

  int ver[SIZE];

  ver[0] = end;
  int k = 1;
  int weight = d[end];

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
          ver[k] = i + 1;
          k++;
        }
      }
  }

  printf("\nВывод кратчайшего пути\n");
  for (int i = k - 1; i >= 0; i--)
    if (i == 0)
      printf("%3d", ver[i]);
    else
      printf("%3d ->", ver[i]);

  for (int i = 0; i < SIZE; i++)
  {
    delete matr[i];
    matr[i] = NULL;
  }

  delete matr;
  matr = NULL;

  return 0;
}
