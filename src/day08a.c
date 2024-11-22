// day08a.c
// Licensed under the MIT license.

// Treetop Tree House

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_M 128
#define MAX_N 128

struct Matrix
{
    char data[MAX_M][MAX_N];
    size_t m;
    size_t n;
};

typedef struct Matrix Matrix;

int main()
{
    size_t k = 0;
    struct Matrix a;

    a.m = 0;
    a.n = 0;

    if (fgets(a.data[0], MAX_N, stdin))
    {
        a.n = strlen(a.data[0]);

        while (a.n > 1 && isspace(a.data[0][a.n - 1]))
        {
            a.n--;
        }
    }

    a.m++;

    while (fgets(a.data[a.m], MAX_N, stdin))
    {
        a.m++;
    }

    bool visible[MAX_M][MAX_N] = { 0 };

    for (size_t i = 1; i < a.m - 1; i++)
    {
        char max = a.data[i][0];

        for (size_t j = 1; j < a.n - 1; j++)
        {
            if (a.data[i][j] > max)
            {
                max = a.data[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t i = 1; i < a.m - 1; i++)
    {
        char max = a.data[i][a.n - 1];

        for (size_t j = a.n - 1; j >= 1; j--)
        {
            if (a.data[i][j] > max)
            {
                max = a.data[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t j = 1; j < a.n - 1; j++)
    {
        char max = a.data[0][j];

        for (size_t i = 1; i < a.m - 1; i++)
        {
            if (a.data[i][j] > max)
            {
                max = a.data[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t j = 1; j < a.n - 1; j++)
    {
        char max = a.data[a.m - 1][j];

        for (size_t i = a.m - 1; i >= 1; i--)
        {
            if (a.data[i][j] > max)
            {
                max = a.data[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t i = 1; i < a.m - 1; i++)
    {
        for (size_t j = 1; j < a.n - 1; j++)
        {
            if (visible[i][j])
            {
                k++;
            }
        }
    }

    k += 2 * a.m + 2 * a.n - 4;

    printf("%zu\n", k);

    return EXIT_SUCCESS;
}
