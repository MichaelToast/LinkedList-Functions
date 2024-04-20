#include<stdio.h>
#include <stdlib.h>

#include "queueFunctions.h"

Queue initalizeQueue(int *errorCode);
Queue deleteQueue(Queue q);
int enqueue(Queue q, int key);
int dequeue(Queue);
int getQueueSize(Queue);
void printQueue(Queue);