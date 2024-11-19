// day06a.c
// Licensed under the MIT license.

// Tuning Trouble

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 8192

int main()
{
    char buffer[BUFFER_SIZE];
    size_t i = 0;
    int n = 0;
    bool d[256] = { false };
    size_t read = fread(buffer, 1, BUFFER_SIZE, stdin);

    while (i < read)
    {
        if (d[(int)buffer[i]])
        {
            i -= n - 1;
            n = 0;

            memset(d, false, 256);
        }

        d[(int)buffer[i]] = true;
        i++;
        n++;

        if (n == 4)
        {
            break;
        }
    }

    printf("%zu\n", i);

    return EXIT_SUCCESS;
}
