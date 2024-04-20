#include <stdio.h>
#include <stdlib.h>

typedef struct doubleNode {
  double key;
  struct doubleNode* next;
} doubleNode;

typedef struct {
  doubleNode *head, *tail;
  int qLength; 
} qInfo; 

typedef struct strctStruct{
  qInfo *qstruct;
} Queue;

Queue initalizeQueue(int *errorCode);
Queue deleteQueue(Queue q);
doubleNode* InitalizeDoubleNode(double key);
int enqueue(Queue q, double key);
double dequeue(Queue q, int *errorCode);
int getQueueSize(Queue q);
void printQueue(Queue q);