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

int main()
{
    char a[MAX_M][MAX_N];
    size_t k = 0;
    size_t m = 0;
    size_t n = 0;

    if (fgets(a[0], MAX_N, stdin))
    {
        n = strlen(a[0]);

        while (n > 1 && isspace(a[0][n - 1]))
        {
            n--;
        }
    }

    m++;

    while (fgets(a[m], MAX_N, stdin))
    {
        m++;
    }

    bool visible[MAX_M][MAX_N] = { 0 };

    for (size_t i = 1; i < m - 1; i++)
    {
        char max = a[i][0];

        for (size_t j = 1; j < n - 1; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t i = 1; i < m - 1; i++)
    {
        char max = a[i][n - 1];

        for (size_t j = n - 1; j >= 1; j--)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t j = 1; j < n - 1; j++)
    {
        char max = a[0][j];

        for (size_t i = 1; i < m - 1; i++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t j = 1; j < n - 1; j++)
    {
        char max = a[m - 1][j];

        for (size_t i = m - 1; i >= 1; i--)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                visible[i][j] = true;
            }
        }
    }

    for (size_t i = 1; i < m - 1; i++)
    {
        for (size_t j = 1; j < n - 1; j++)
        {
            if (visible[i][j])
            {
                k++;
            }
        }
    }

    k += 2 * m + 2 * n - 4;

    printf("%zu\n", k);

    return EXIT_SUCCESS;
}
