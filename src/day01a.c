// day01a.c
// Licensed under the MIT license.

// Calorie Counting

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 8

int main()
{
    unsigned long max = 0;
    unsigned long sum = 0;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        if (*buffer == '\n' || *buffer == '\0')
        {
            if (sum > max)
            {
                max = sum;
            }

            sum = 0;
        }

        unsigned long e = strtoul(buffer, NULL, 10);

        sum += e;
    }

    if (sum > max)
    {
        max = sum;
    }

    printf("%lu\n", max);

    return EXIT_SUCCESS;
}
