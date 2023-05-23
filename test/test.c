#include "../src/lib/check.h"
#include "../thirdparty/ctest.h"

#include <stdio.h>
#define FILENAME "test_input.txt"

CTEST(INPUT_CHECK, READER1)
{
    const char *filename = FILENAME;
    FILE *fp = fopen(filename, "r");
    bool expec = true;
    if (fp == NULL)
    {
        expec = false;
    }
    fclose(fp);
    bool real = check_file_exists(filename);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, READER2)
{
    const char *filename = FILENAME;
    FILE *fp = fopen(filename, "r");
    bool expec = false;
    if (fp == NULL)
    {
        expec = true;
    }
    fclose(fp);
    bool real = check_file_exists(filename);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, FIRST_STRING1)
{
    const char *filename = FILENAME;
    FILE *fp = fopen(filename, "r");
    int n;
    bool expec = true;
    if (fscanf(fp, "%d", &n) != 1)
    {
        fclose(fp);
        expec = false;
    }
    fclose(fp);
    if (n < 0)
    {
        expec = false;
    }
    bool real = check_file_exists(filename);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, FIRST_STRING2)
{
    const char *filename = FILENAME;
    FILE *fp = fopen(filename, "r");
    int n;
    bool expec = false;
    if (fscanf(fp, "%d", &n) != 1)
    {
        fclose(fp);
        expec = true;
    }
    fclose(fp);
    if (n < 0)
    {
        expec = true;
    }
    bool real = check_file_exists(filename);

    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, CHECK_MATRIX1)
{
    const char *filename = FILENAME;
    FILE *fp = fopen(filename, "r");
    int n;
    if (fscanf(fp, "%d", &n) != 1)
    {
        fclose(fp);
        expec = false;
    }
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(fp, "%d", &x) != 1)
            {
                fclose(fp);
                expec = false;
            }
            if (!check_matrix_element(x, i + 1, j + 1))
            {
                fclose(fp);
                expec = false;
            }
        }
    }
    long curr_pos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long end_pos = ftell(fp);
    if (end_pos != curr_pos)
    {
        fclose(fp);
        expec = false;
    }
    fclose(fp);
    expec = true;
    bool real = check_file_exists(filename);
    ASSERT_EQUAL(expec, real);
}

CTEST(INPUT_CHECK, CHECK_MATRIX2)
{
    const char *filename = FILENAME;
    FILE *fp = fopen(filename, "r");
    int n;
    if (fscanf(fp, "%d", &n) != 1)
    {
        fclose(fp);
        expec = true;
    }
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(fp, "%d", &x) != 1)
            {
                fclose(fp);
                expec = true;
            }
            if (!check_matrix_element(x, i + 1, j + 1))
            {
                fclose(fp);
                expec = true;
            }
        }
    }
    long curr_pos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long end_pos = ftell(fp);
    if (end_pos != curr_pos)
    {
        fclose(fp);
        expec = true;
    }
    fclose(fp);
    expec = false;
    bool real = check_file_exists(filename);
    ASSERT_EQUAL(expec, real);
}
