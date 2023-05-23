#include <stdbool.h>

#ifndef STACKNODE_H
#define STACKNODE_H

typedef struct StackNode {
    struct StackNode* prev;
    void* data;
    int size;
} StackNode;

StackNode* pushStackNode(StackNode* sn, void* data, unsigned int size);
StackNode* pushStackInStackNode(StackNode* sn, StackNode* data);
StackNode* pushIntStackNode(StackNode* sn, int data);
StackNode* popStackNode(StackNode* sn);
void freeStack(StackNode** sn);
void printIntStackNode(StackNode* sn);
void recursivePrintIntStackNode(StackNode* sn);
bool isIntStackEqual(StackNode* first, StackNode* second);

#endif