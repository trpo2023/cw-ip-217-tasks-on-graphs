#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 20

typedef struct Queue
{
  int items[SIZE];
  int front;
  int rear;
} Queue;

Queue *createQueue();
int isEmpty(Queue *q);
void addQueue(Queue *q, int value);
int removeQueue(Queue *q);
void printQueue(Queue *q);

#endif