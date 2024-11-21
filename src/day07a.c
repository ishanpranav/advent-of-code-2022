// day07a.c
// Licensed under the MIT license.

// No Space Left On Device

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

struct Tree;

typedef struct Tree Tree;

struct Tree
{
    unsigned long weight;
    char name[BUFFER_SIZE];
    Tree* parent;
    Tree* firstChild;
    Tree* nextSibling;
};

Tree* tree_print(Tree* t, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        printf("--");
    }

    printf("name: %s, weight: %u\n", t->name, t->weight);

    for (Tree* v = t->firstChild; v; v = v->nextSibling)
    {
        tree_print(v, depth + 1);
    }
}

Tree* tree_find(Tree* t, char* name, size_t nameLength)
{
    for (Tree* v = t->firstChild; v; v = v->nextSibling)
    {
        if (memcmp(name, v->name, nameLength) == 0)
        {
            return v;
        }
    }

    return NULL;
}

int main()
{
    int n = 0;
    Tree* s = calloc(1, sizeof * s);
    Tree* t;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin))
    {
        if (*buffer == '$')
        {
            char* command = buffer + 2;

            if (memcmp(command, "cd", 2) == 0)
            {
                char* name = buffer + 5;

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
                    size_t nameLength = strlen(name);

                    if (name[nameLength - 1] == '\n')
                    {
                        nameLength--;
                    }

                    t = tree_find(t, name, nameLength);
                }
            }
        }
        else if (memcmp(buffer, "dir", 3) == 0)
        {
            char* name = buffer + 4;

            Tree* v = malloc(sizeof * v);

            v->parent = t;
            v->firstChild = NULL;
            v->nextSibling = NULL;

            size_t nameLength = strlen(name);

            if (name[nameLength - 1] == '\n')
            {
                nameLength--;
            }

            memcpy(v->name, name, nameLength);

            v->name[nameLength] = '\0';

            Tree* u = t->firstChild;

            if (u)
            {
                v->nextSibling = u->nextSibling;
                u->nextSibling = v;
            }
            else
            {
                t->firstChild = v;
            }
        }
        else
        {
            Tree* v = malloc(sizeof * v);

            v->parent = t;
            v->firstChild = NULL;
            v->nextSibling = NULL;
            *v->name = '\0';
            v->weight = strtoul(buffer, NULL, 10);

            Tree* u = t->firstChild;

            if (u)
            {
                v->nextSibling = u->nextSibling;
                u->nextSibling = v;
            }
            else
            {
                t->firstChild = v;
            }
        }
    }

    tree_print(s, 0);

    printf("%d\n", n);

    return EXIT_SUCCESS;
}
