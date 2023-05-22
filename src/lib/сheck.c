#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "check.h"

#ifndef CHECK_C
#define CHECK_C

bool check_file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Couldn't open file for reading\n");
        return false;
    }
    fclose(fp);
    return true;
}

bool check_num_vertices(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int n;
    if (fscanf(fp, "%d", &n) != 1)
    {
        printf("Couldn't read number of vertices\n");
        fclose(fp);
        return false;
    }
    fclose(fp);
    if (n < 0)
    {
        printf("Invalid number of vertices\n");
        return false;
    }
    return true;
}

bool check_matrix(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int n;
    if (fscanf(fp, "%d", &n) != 1)
    {
        fclose(fp);
        return false;
    }
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(fp, "%d", &x) != 1)
            {
                printf("Couldn't read adjacency matrix element at position (%d, %d)\n", i + 1, j + 1);
                fclose(fp);
                return false;
            }
            if (!check_matrix_element(x, i + 1, j + 1))
            {
                fclose(fp);
                return false;
            }
        }
    }
    long curr_pos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long end_pos = ftell(fp);
    if (end_pos != curr_pos)
    {
        printf("Adjacency matrix is not square\n");
        fclose(fp);
        return false;
    }
    fclose(fp);
    return true;
}

bool check_matrix_element(int x, int row, int col)
{
    if (x < 0)
    {
        printf("Invalid value in adjacency matrix at position (%d, %d)\n", row, col);
        return false;
    }
    else if (isalpha(x))
    {
        printf("Invalid character in adjacency matrix at position (%d, %d)\n", row, col);
        return false;
    }
    return true;
}

#endif