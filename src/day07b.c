// day07a.c
// Licensed under the MIT license.

// No Space Left On Device

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

struct Tree;

typedef struct Tree Tree;

struct Tree
{
    bool visited;
    unsigned int nameLength;
    unsigned long weight;
    char* name;
    Tree* parent;
    Tree* firstChild;
    Tree* nextSibling;
    Tree* nextList;
};

static Tree* tree_find_child(Tree* t, char* name, size_t nameLength)
{
    for (Tree* v = t->firstChild; v; v = v->nextSibling)
    {
        if (v->nameLength == nameLength &&
            memcmp(name, v->name, nameLength) == 0)
        {
            return v;
        }
    }

    return NULL;
}

static size_t main_name_length(char* name)
{
    size_t length = strlen(name);

    while (isspace(name[length - 1]))
    {
        length--;
    }

    return length;
}

int main()
{
    Tree* s = calloc(1, sizeof * s);
    Tree* t;
    Tree* list = s;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        if (*buffer == '$')
        {
            char* command = buffer + 2;

            if (memcmp(command, "cd", 2) == 0)
            {
                char* name = command + 3;

                if (*name == '/')
                {
                    t = s;
                }
                else if (memcmp(name, "..", 2) == 0)
                {
                    t = t->parent;
                }
                else
                {
                    t = tree_find_child(t, name, main_name_length(name));
                }
            }

            continue;
        }

        Tree* v = malloc(sizeof * v);

        v->firstChild = NULL;
        v->visited = false;

        if (memcmp(buffer, "dir", 3) == 0)
        {
            char* name = buffer + 4;
            size_t nameLength = main_name_length(name);
            char* copy = malloc(nameLength * sizeof * copy);

            memcpy(copy, name, nameLength);

            v->name = copy;
            v->nameLength = nameLength;
            v->weight = 0;
        }
        else
        {
            v->name = NULL;
            v->nameLength = 0;
            v->weight = strtoul(buffer, NULL, 10);
        }

        v->parent = t;
        v->nextSibling = t->firstChild;
        t->firstChild = v;
        v->nextList = list;
        list = v;
    }

    Tree* stack = s;

    s->parent = NULL;

    while (stack)
    {
        Tree* u = stack;

        if (u->visited)
        {
            for (Tree* v = u->firstChild; v; v = v->nextSibling)
            {
                u->weight += v->weight;
            }

            stack = stack->parent;
        }
        else
        {
            for (Tree* v = u->firstChild; v; v = v->nextSibling)
            {
                v->parent = stack;
                stack = v;
            }

            u->visited = true;
        }
    }

    unsigned long min = ULONG_MAX;

    while (list)
    {
        Tree* u = list;
        Tree* v = list->nextList;

        if (u->firstChild && u->weight <= min &&
            70000000 - (s->weight - u->weight) >= 30000000)
        {
            min = u->weight;
        }

        if (u->name)
        {
            free(u->name);
        }

        free(u);

        list = v;
    }

    printf("%lu\n", min);

    return EXIT_SUCCESS;
}
