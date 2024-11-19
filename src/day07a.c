// day07a.c
// Licensed under the MIT license.

// No Space Left On Device

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 8192

int main()
{
    int count = 0;
    char buffer[BUFFER_SIZE];
    bool discovered[256] = { false };
    size_t index = 0;
    size_t read = fread(buffer, 1, BUFFER_SIZE, stdin);

    while (index < read)
    {
        if (discovered[(int)buffer[index]])
        {
            index -= count - 1;
            count = 0;

            memset(discovered, false, 256);
        }

        discovered[(int)buffer[index]] = true;
        count++;
        index++;

        if (count == 14)
        {
            break;
        }
    }

    printf("%zu\n", index);

    return EXIT_SUCCESS;
}
