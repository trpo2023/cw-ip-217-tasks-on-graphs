#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef CHECK_H
#define CHECK_H
bool check_input(const char* filename);

bool check_input(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Couldn't open file for reading\n");
        return false;
    }

    int n;
    if (fscanf(fp, "%d", &n) != 1) {
        printf("Couldn't read number of vertices\n"); //Check int N
        fclose(fp);
        return false;
    }

    if (n < 0) {
        printf("Invalid number of vertices\n");// Check -N
        fclose(fp);
        return false;
    }

    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(fp, "%d", &x) != 1) {
                printf("Couldn't read adjacency matrix element at position (%d, %d)\n", i+1, j+1);
                fclose(fp);
                return false;
            }

            if (x < 0) {
                printf("Invalid value in adjacency matrix at position (%d, %d)\n", i+1, j+1);
                fclose(fp);
                return false;
            }
            // Проверяем, что символ не является буквой, если является - выводим ошибку
            else if (isalpha(x)) {
                printf("Invalid character in adjacency matrix at position (%d, %d)\n", i+1, j+1);
                fclose(fp);
                return false;
            }
        }
    }

    // Проверяем, что матрица квадратная
    long curr_pos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long end_pos = ftell(fp);
    if (end_pos != curr_pos) { // +1 потому что после каждой строки матрицы есть символ новой строки
        printf("Adjacency matrix is not square\n");
        fclose(fp);
        return false;
    }

    fclose(fp);
    return true;
}

#endif

