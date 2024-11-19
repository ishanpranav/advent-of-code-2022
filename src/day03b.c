// day03b.c
// Licensed under the MIT license.

// Rucksack Reorganization

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64

static int main_step(char buffer[3][BUFFER_SIZE])
{
    int count[256] = { 0 };

    for (char* p = buffer[0]; *p != '\n' && *p != '\0'; p++)
    {
        count[(int)*p] |= 0x1;
    }
    
    for (char* p = buffer[1]; *p != '\n' && *p != '\0'; p++)
    {
        count[(int)*p] |= 0x2;
    }
    
    for (char* p = buffer[2]; *p != '\n' && *p != '\0'; p++)
    {
        if (count[(int)*p] == 0x3)
        {
            int priority = *p + 1;

            if (isupper(*p))
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
    char buffer[3][BUFFER_SIZE];

    while (
        fgets(buffer[0], BUFFER_SIZE, stdin) && 
        fgets(buffer[1], BUFFER_SIZE, stdin) &&
        fgets(buffer[2], BUFFER_SIZE, stdin))
    {
        sum += main_step(buffer);
    }

    printf("%d\n", sum);

    return EXIT_SUCCESS;
}
