#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgraphs/listnode.h>

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

ListNode *findHead(ListNode *sn)
{
    while (sn->prev != NULL)
        sn = sn->prev;

    return sn;
}

ListNode *removeListNode(ListNode *sn)
{
    if (!sn)
        return NULL;

    ListNode *t = popListNode(sn);

    return t;
}

ListNode *findListNode(ListNode *sn, int key)
{
    ListNode *head = findHead(sn);
    while (head)
    {
        if (((int *)head->data)[0] == key)
            return head;

        head = head->next;
    }

    return NULL;
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

ListNode *pushIntListNode(ListNode *sn, int data)
{
    sn = pushListNode(sn);
    int *t = malloc(sizeof(int));
    t[0] = data;

    setListNodeData(sn, t, sizeof(int *));

    free(t);
    return sn;
}

void printIntListNode(ListNode *sn)
{
    while (sn)
    {
        printf("%d ", ((int *)sn->data)[0]);
        sn = sn->next;
    }
    printf("\n");
}

#endif