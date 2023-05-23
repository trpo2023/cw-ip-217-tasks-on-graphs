#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <libgraphs/stacknode.h>

#ifndef STACKNODE_C
#define STACKNODE_C

StackNode *pushStackNode(StackNode *sn, void *data, unsigned int size)
{
    StackNode *t = (StackNode *)malloc(sizeof(StackNode));
    t->data = malloc(size);
    memcpy(t->data, data, size);

    t->prev = sn;
    t->size = sn ? sn->size + 1 : 1;

    return t;
}

StackNode *pushStackInStackNode(StackNode *sn, StackNode *data)
{
    StackNode *t = (StackNode *)malloc(sizeof(StackNode));
    t->data = data;

    t->prev = sn;
    t->size = sn ? sn->size + 1 : 1;

    return t;
}

StackNode *pushIntStackNode(StackNode *sn, int data)
{
    int *t = malloc(sizeof(int));
    t[0] = data;
    sn = pushStackNode(sn, t, sizeof(int *));

    free(t);
    return sn;
}

StackNode *popStackNode(StackNode *sn)
{
    if (!sn)
        return NULL;

    if (sn->data)
        free(sn->data);

    StackNode *t = sn->prev;
    free(sn);

    return t;
}

void freeStack(StackNode **sn)
{
    while (*sn)
        *sn = popStackNode(*sn);
}

void printIntStackNode(StackNode *sn)
{
    recursivePrintIntStackNode(sn);
    printf("\n");
}

void recursivePrintIntStackNode(StackNode *sn)
{
    if (!sn) return;
    
    recursivePrintIntStackNode(sn->prev);
    printf("%d ", ((int *)sn->data)[0]);
}

bool isIntStackEqual(StackNode *first, StackNode *second)
{
    while (first)
    {
        if(!second) return false;
        if(*(int *)(first->data) != *(int *)(second->data)) return false;
        first = first->prev;
        second = second->prev;
    }
    return true;    
}

#endif