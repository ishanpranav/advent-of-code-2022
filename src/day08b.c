// day08b.c
// Licensed under the MIT license.

// Treetop Tree House

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_M 128
#define MAX_N 128

int main()
{
    char a[MAX_M][MAX_N];
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

    size_t max = 0;
    size_t b[MAX_M][MAX_N];

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            b[i][j] = 1;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        size_t k[10] = { 0 };
        
        for (size_t j = 0; j < n; j++)
        {
            size_t max = 0;
            unsigned int current = a[i][j] - '0';

            for (unsigned int x = current; x < 10; x++)
            {
                if (k[x] > max)
                {
                    max = k[x];
                }
            }

            b[i][j] *= j - max;
            k[current] = j;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        size_t k[10] = { 0 };
        
        for (size_t j = n - 1; j != SIZE_MAX; j--)
        {
            size_t max = 0;
            unsigned int current = a[i][j] - '0';

            for (unsigned int x = current; x < 10; x++)
            {
                if (k[x] > max)
                {
                    max = k[x];
                }
            }

            b[i][j] *= j - max;
            k[current] = j;

            printf("right length of %d is %zu\n", current, j - max);
        }
    }

    for (size_t j = 0; j < n; j++)
    {
        size_t k[10] = { 0 };

        for (size_t i = 0; i < m; i++)
        {
            size_t max = 0;
            unsigned int current = a[i][j] - '0';

            for (unsigned int x = current; x < 10; x++)
            {
                if (k[x] > max)
                {
                    max = k[x];
                }
            }

            b[i][j] *= j - max;
            k[current] = j;
        }
    }

    for (size_t j = 0; j < n; j++)
    {
        size_t k[10] = { 0 };

        for (size_t i = m - 1; i != SIZE_MAX; i--)
        {
            size_t max = 0;
            unsigned int current = a[i][j] - '0';

            for (unsigned int x = current; x < 10; x++)
            {
                if (k[x] > max)
                {
                    max = k[x];
                }
            }

            b[i][j] *= j - max;
            k[current] = j;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (b[i][j] > max)
            {
                max = b[i][j];
            }
        }
    }

    printf("%zu\n", max);

    return EXIT_SUCCESS;
}
