// day01b.c
// Licensed under the MIT license.

// Calorie Counting

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 8

static void main_step(long s, long m[3])
{
    if (s <= m[2])
    {
        return;
    }

    if (s <= m[1])
    {
        m[2] = s;

        return;
    }

    if (s <= m[0])
    {
        m[2] = m[1];
        m[1] = s;

        return;
    }

    m[2] = m[1];
    m[1] = m[0];
    m[0] = s;
}

int main()
{
    long m[3] = { 0 };
    long s;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        if (*buffer == '\n' || *buffer == '\0')
        {
            main_step(s, m);

            s = 0;
        }

        long e = strtol(buffer, NULL, 10);

        s += e;
    }

    main_step(s, m);
    printf("%ld\n", m[0] + m[1] + m[2]);

    return EXIT_SUCCESS;
}
