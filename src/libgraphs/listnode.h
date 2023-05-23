#ifndef LISTNODE_H
#define LISTNODE_H

typedef struct ListNode {
    struct ListNode* next;
    struct ListNode* prev;
    void* data;
} ListNode;

ListNode* pushListNode(ListNode* sn);
ListNode* removeListNode(ListNode* sn);
void freeList(ListNode** sn);
void setListNodeData(ListNode* sn, void* data, unsigned int size);
void printListNode(ListNode* sn);
ListNode* pushIntListNode(ListNode* sn, int data);
ListNode* findHead(ListNode* sn);
ListNode* findListNode(ListNode* sn, int key);
void printIntListNode(ListNode* sn);

#endif