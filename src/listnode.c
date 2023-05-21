#include "listnode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#ifndef LISTNODE_C
#define LISTNODE_C

ListNode *pushListNode(ListNode *sn)
{
    ListNode *t = (ListNode *)malloc(sizeof(ListNode));
    t->data = NULL;
    if (!sn)
        t->next = t->prev = NULL;
    else
    {
        t->prev = sn;
        sn->next = t;
        t->next = NULL;
    }

    return t;
}

static ListNode *popListNode(ListNode *sn)
{
    if (!sn)
        return NULL;

    if (sn->data)
        free(sn->data);

    ListNode *t;
    if (sn->next == NULL)
    {
        if (sn->prev == NULL)
            t = NULL;
        else
        {
            t = sn->prev;
            t->next = sn->next;
        }
    }
    else if (sn->prev == NULL)
    {
        t = sn->next;
        t->prev = sn->prev;
    }
    else
    {
        t = sn->prev;
        t->next = sn->next;
        (sn->next)->prev = t;
    }

    free(sn);
    return t;
}

static ListNode *findHead(ListNode *sn)
{
    while (sn->next != NULL)
        sn = sn->next;

    return sn;
}

// Return head of list
ListNode *removeListNode(ListNode *sn)
{
    if (!sn)
        return NULL;

    ListNode *t = popListNode(sn);
    if (!t->next)
        return t;
    return findHead(t);
}

void freeList(ListNode **sn)
{
    while (*sn)
        *sn = popListNode(*sn);
}

void setListNodeData(ListNode *sn, void *data, unsigned int size)
{
    if (sn->data)
        free(sn->data);

    sn->data = malloc(size);
    memcpy(sn->data, data, size);
}

void printListNode(ListNode *sn)
{
    while (sn != NULL)
    {
        printStudent((Student *)sn->data);
        sn = sn->prev;
    }
    printf("\n");
}

#endif