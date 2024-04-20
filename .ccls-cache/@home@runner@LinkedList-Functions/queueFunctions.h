#include <stdio.h>
#include <stdlib.h>
#include "LinkedFunctions.h" //For Nodes

typedef struct {
  Node *head, *tail;
  int listLength; 
} qInfo; 

typedef struct strctStruct{
  qInfo *qstruct;
} Queue;

Queue initalizeQueue(int *errorCode);
Queue deleteQueue(Queue q);
int enqueue(Queue q, int key);
int dequeue(Queue q);
int getQueueSize(Queue q);
void printQueue(Queue q);