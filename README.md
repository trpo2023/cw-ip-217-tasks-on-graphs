# Задачи на графах
Кратчайший путь между городами, количество разных маршрутов между городами, длиннейший путь между городами

Для сборки проекта нужно выполнить следующую команду
```
make all
make run
```
Для прогона unit тестов необходимо выполнить команду
```
make test
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
- Выбрать начальную вершину и пометить ее как посещенную.  
- Перебрать все непосещенные соседние вершины выбранной вершины.  
- Для каждой непосещенной вершины:
  - Пометить ее как посещенную.
  - Рекурсивно вызвать алгоритм поиска в глубину для этой вершины.
- Повторять шаги 2-3 для всех непосещенных вершин в графе, пока все вершины не будут посещены.  
Для правильной работы алгоритма необходимо проверять, была ли вершина уже посещена, чтобы избежать зацикливания на циклах


Для нахождения длиннейшего пути между городами можно использовать алгоритм Дейкстры. Алгоритм заключается в том, чтобы найти все кратчайшие пути между всеми парами вершин графа, а затем выбрать путь с максимальной длиной.

## Требования к реализации программы
- Программа должна быть написана на языке Си;
- Ввод вывод информации должен производиться через консоль;
- Необходимо использовать матрицу смежности для представления графа;
- Программа должна содержать три функции для решения каждой из задач;
- Код программы должен быть чистым и читаемым;
- Результат выполнения программы должен быть выведен на экран;
- Реализовать базовую сборку проекта с помощью make;
- Покрыть тестами только те функции, которые отвечают за решение каждой задачи.