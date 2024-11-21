// day02a.c
// Licensed under the MIT license.

// Rock, Paper, Scissors

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 8

int main()
{
    unsigned int a = 0;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        char s = buffer[0] - 'A' + 1;
        char t = (buffer[2] - 'X') * 3;

        a += t;

        switch (t)
        {
        case 0:
            a += s == 1 ? 3 : s - 1;
            break;

        case 3:
            a += s;
            break;

        case 6:
            a += s == 3 ? 1 : s + 1;
            break;
        }
    }

    printf("%u\n", a);

    return EXIT_SUCCESS;
}
