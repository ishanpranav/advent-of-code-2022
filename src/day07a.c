// day07a.c
// Licensed under the MIT license.

// No Space Left On Device

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 32

struct Tree;

typedef struct Tree Tree;

struct Tree
{
    unsigned int nameLength;
    unsigned long weight;
    char* name;
    Tree* parent;
    Tree* firstChild;
    Tree* nextSibling;
};

static void tree_print(Tree* t, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }

    printf("'%.*s' (%lu)\n", t->nameLength, t->name, t->weight);

    for (Tree* v = t->firstChild; v; v = v->nextSibling)
    {
        tree_print(v, depth + 1);
    }
}

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
    }

    tree_print(s, 0);
    printf("%d\n", 0);

    return EXIT_SUCCESS;
}
