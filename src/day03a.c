// day03a.c
// Licensed under the MIT license.

// Rucksack Reorganization

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64

static int main_step(char a[BUFFER_SIZE])
{
    size_t length = strlen(a) / 2;
    bool discovered[256] = { 0 };

    for (size_t i = 0; i < length; i++)
    {
        discovered[(int)a[i]] = true;
    }

    for (size_t i = length; i < length * 2; i++)
    {
        if (discovered[(int)a[i]])
        {
            int priority = a[i] + 1;

            if (isupper(a[i]))
            {
                priority -= 'A' - 26;
            }
            else
            {
                priority -= 'a';
            }

            return priority;
        }
    }

    return 0;
}

int main()
{
    int sum = 0;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        sum += main_step(buffer);
    }

    printf("%d\n", sum);

    return EXIT_SUCCESS;
}
