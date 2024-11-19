// day02a.c
// Licensed under the MIT license.

// Rock, paper, scissors

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 8

int main()
{
    int a = 0;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        char s[2] =
        {
            buffer[0] - 'A' + 1,
            buffer[2] - 'X' + 1
        };

        a += s[1];

        if (s[0] == s[1])
        {
            a += 3;
            
            continue;
        }

        if ((s[0] == 1 && s[1] == 2) ||
            (s[0] == 2 && s[1] == 3) ||
            (s[0] == 3 && s[1] == 1))
        {
            a += 6;
        }
    }

    printf("%d\n", a);

    return EXIT_SUCCESS;
}
