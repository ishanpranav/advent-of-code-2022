// day08b.c
// Licensed under the MIT license.

// Treetop Tree House

#include <ctype.h>
#include <stdbool.h>
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
    size_t count[MAX_M][MAX_N] = { 0 };

    for (size_t i = 1; i < m - 1; i++)
    {
        for (size_t j = 1; j < n - 1; j++)
        {
            size_t left = 0;
            size_t right = 0;
            size_t up = 0;
            size_t down = 0;

            for (size_t x = j - 1; x != SIZE_MAX; x--)
            {
                left++;

                if (a[i][x] >= a[i][j])
                {
                    break;
                }
            }
            
            for (size_t x = j + 1; x < n; x++)
            {
                right++;
                
                if (a[i][x] >= a[i][j])
                {
                    break;
                }
            }

            for (size_t y = i - 1; y != SIZE_MAX; y--)
            {
                up++;
                
                if (a[y][j] >= a[i][j])
                {
                    break;
                }
            }
            
            for (size_t y = i + 1; y < m; y++)
            {
                down++;
                
                if (a[y][j] >= a[i][j])
                {
                    break;
                }
            }

            size_t k = up * down * left * right;

            if (k > max)
            {
                max = k;
            }
        }
    }

    printf("%zu\n", max);

    return EXIT_SUCCESS;
}
