// day05b.c
// Licensed under the MIT license.

// Supply Stacks

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64
#define STACK_SIZE 128
#define STACK_COUNT 16

struct Stack
{
    char items[STACK_SIZE];
    unsigned int count;
};

typedef struct Stack Stack;

static void stack_push(Stack* s, char item)
{
    s->items[s->count] = item;
    s->count++;
}

static void stack_reverse(char* items, unsigned int count)
{
    if (count < 2)
    {
        return;
    }

    unsigned int left = 0;
    unsigned int right = count - 1;

    while (left < right)
    {
        char swap = items[left];

        items[left] = items[right];
        items[right] = swap;
        left++;
        right--;
    }
}

int main()
{
    char buffer[BUFFER_SIZE];
    Stack stacks[STACK_COUNT];

    for (size_t i = 0; i < STACK_COUNT; i++)
    {
        stacks[i].count = 0;
    }

    size_t stackCount = 0;

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        if (*buffer == '\n')
        {
            break;
        }

        size_t n = strlen(buffer);

        while (n > 1 && isspace(buffer[n - 1]))
        {
            n--;
        } 

        size_t stack = 0;

        for (size_t i = 0; i < n; i += 4)
        {
            if (buffer[i] == '[')
            {
                stack_push(stacks + stack, buffer[i + 1]);
            }

            stack++;

            if (stack > stackCount)
            {
                stackCount++;
            }
        }
    }

    for (size_t stack = 0; stack < stackCount; stack++)
    {
        stack_reverse(stacks[stack].items, stacks[stack].count);
    }

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        size_t a;
        size_t b;
        unsigned int c;

        if (sscanf(buffer, "move %u from %zu to %zu", &c, &a, &b) == 3)
        {
            a--;
            b--;
            stacks[a].count -= c;

            char* aLast = stacks[a].items + stacks[a].count;
            char* bLast = stacks[b].items + stacks[b].count;

            stack_reverse(aLast, c);
            memcpy(bLast, aLast, c);
            
            stacks[b].count += c;
        }
    }

    for (size_t stack = 0; stack < stackCount; stack++)
    {
        printf("%c", stacks[stack].items[stacks[stack].count - 1]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}
