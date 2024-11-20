// day04a.c
// Licensed under the MIT license.

// Camp Cleanup

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 16

int main()
{
    int n = 0;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        char* comma = strchr(buffer, ',');
        char* firstHyphen = strchr(buffer, '-');
        char* secondHyphen = strchr(comma, '-');
        int a[2] = { atoi(buffer), atoi(firstHyphen + 1) };
        int b[2] = { atoi(comma + 1), atoi(secondHyphen + 1) };

        if ((a[0] <= b[0] && b[1] <= a[1]) ||
            (b[0] <= a[0] && a[1] <= b[1]))
        {
            n++;
        }
    }

    printf("%d\n", n);

    return EXIT_SUCCESS;
}
