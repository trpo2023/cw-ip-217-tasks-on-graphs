# Задачи на графах
Кратчайший путь между городами, количество разных маршрутов между городами, длиннейший путь между городами

Для сборки проекта нужно выполнить следующую команду
```
make
```

## Цель
Написать программу на языке программирования Си, которая будет решать задачи на графах: нахождение кратчайшего пути между городами, количество разных маршрутов между городами и длиннейшего пути между городами.

## Входные данные
- Взвешенная матрица смежности, представляющая граф в виде двумерного массива размерности NxN (N - количество вершин графа), в которой на пересечении i-ой строки и j-ого столбца стоит М,(М-растояние между вершинами) если существует ребро между i-ой и j-ой вершинами, и 0 в противном случае;
- Cтартовая и конечная вершины (цифры от 0 до N).

## Выходные данные
- Для задачи нахождения кратчайшего пути между городами – кратчайший путь и его длина;
- Для задачи количества разных маршрутов между городами – количество различных маршрутов между заданными вершинами;
- Для задачи нахождения длиннейшего пути между городами – длиннейший путь между заданными вершинами.

## Алгоритм решения задач
Для нахождения количество разных маршрутов между городами необходимо использовать алгоритм поиска в глубину (DFS).
Описание алгоритма:
1.Выбрать начальную вершину и пометить ее как посещенную.
2.Перебрать все непосещенные соседние вершины выбранной вершины.
3.Для каждой непосещенной вершины:
  -Пометить ее как посещенную.
  -Рекурсивно вызвать алгоритм поиска в глубину для этой вершины.
4.Повторять шаги 2-3 для всех непосещенных вершин в графе, пока все вершины не будут посещены.
Для правильной работы алгоритма необходимо проверять, была ли вершина уже посещена, чтобы избежать зацикливания на циклах

Для нахождения кратчайшего пути между городами используются данные (пути) полученные в ходе выполнения алгоритма "поиска количество разных маршрутов между городами". Алгоритм проходится по всем полученным путям, измеряет их длинну, после чего сравнивает длинны между собой для нахождение кратчайшего пути.

Для нахождения длиннейшего пути между городами используются данные (пути) полученные в ходе выполнения алгоритма "поиска количество разных маршрутов между городами". Алгоритм проходится по всем полученным путям, измеряет их длинну, после чего сравнивает длинны между собой для нахождение длинейшего пути.

## Требования к реализации программы
- Программа должна быть написана на языке Си;
- Ввод вывод информации должен производиться через консоль;
- Необходимо использовать матрицу смежности для представления графа;
- Программа должна содержать три функции для решения каждой из задач;
- Код программы должен быть чистым и читаемым;
- Результат выполнения программы должен быть выведен на экран;
- Реализовать базовую сборку проекта с помощью make;
- Покрыть тестами только те функции, которые отвечают за решение каждой задачи.
Задачи на графах
Кратчайший путь между городами, количество разных маршрутов между городами и длиннейший путь между городами.

Для сборки проекта необходимо выполнить следующую команду:

make
Цель
Написать программу на языке программирования C, которая будет решать задачи на графах: нахождение кратчайшего пути между городами, количество разных маршрутов между городами и длиннейшего пути между городами.

Входные данные
Взвешенная матрица смежности, представляющая граф в виде двумерного массива размерности NxN (N - количество вершин графа), в которой на пересечении i-ой строки и j-ого столбца стоит М (М - расстояние между вершинами), если существует ребро между i-ой и j-ой вершинами, и 0 в противном случае;
Стартовая и конечная вершины (цифры от 0 до N).
Выходные данные
Для задачи нахождения кратчайшего пути между городами – кратчайший путь и его длина;
Для задачи количества разных маршрутов между городами – количество различных маршрутов между заданными вершинами;
Для задачи нахождения длиннейшего пути между городами – длиннейший путь между заданными вершинами.
Алгоритм решения задач
Для нахождения количество разных маршрутов между городами необходимо использовать алгоритм поиска в глубину (DFS). Описание алгоритма:

Выбрать начальную вершину и пометить ее как посещенную.
Перебрать все непосещенные соседние вершины выбранной вершины.
Для каждой непосещенной вершины:
Пометить ее как посещенную.
Рекурсивно вызвать алгоритм поиска в глубину для этой вершины.
Повторять шаги 2-3 для всех непосещенных вершин в графе, пока все вершины не будут посещены. Для правильной работы алгоритма необходимо проверять, была ли вершина уже посещена, чтобы избежать зацикливания на циклах.
Для нахождения кратчайшего пути между городами используются данные (пути), полученные в ходе выполнения алгоритма "поиска количество разных маршрутов между городами". Алгоритм проходится по всем полученным путям, измеряя их длину, после чего сравнивает длины между собой для нахождения кратчайшего пути.

Для нахождения длиннейшего пути между городами используются данные (пути), полученные в ходе выполнения алгоритма "поиска количество разных маршрутов между городами". Алгоритм проходится по всем полученным путям, измеряя их длину, после чего сравнивает длины между собой для нахождения длинейшего пути.

Требования к реализации программы
Программа должна быть написана на языке Си;
Ввод-вывод информации должен производиться через консоль;
Необходимо использовать матрицу смежности для представления графа;
Программа должна содержать три функции для решения каждой из задач;
Код программы должен быть чистым и читаемым;
Результат выполнения программы должен быть выведен на экран;
Реализовать базовую сборку проекта с помощью make;
Покрыть тестами только те функции, которые отвечают за решение каждой задачи.
