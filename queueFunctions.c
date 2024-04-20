#include<stdio.h>
#include <stdlib.h>

#include "queueFunctions.h"

Queue initalizeQueue(int *errorCode) {
  Queue s;
  s.qstruct = malloc(sizeof(qInfo));
  if (s.qstruct == NULL) {
    printf("COULD NOT ALLOCATE MEMORY\n");
    return s;
  }

  doubleNode* dummy;
  dummy = malloc(sizeof(doubleNode));
  if (dummy == NULL) {
    printf("COULD NOT ALLOCATE MEMORY\n");
    // Need to free the other allocated thing
    free(s.qstruct);
    return s;      
  }
  dummy->next = NULL;
  dummy->key = -1.00;

  s.qstruct->head = s.qstruct->tail = dummy;
  s.qstruct->qLength = 0;
  return s;
}

Queue deleteQueue(Queue q) {
  doubleNode* temp = q.qstruct->head; 
  if (q.qstruct->head ==NULL) {
    return q;
  }
  while (q.qstruct->head != NULL) {
    temp = q.qstruct->head;
    q.qstruct->head = q.qstruct->head->next;
    free(temp);
  }
  free(q.qstruct);

  return q;
}

doubleNode *InitalizeDoubleNode(double key) {
  doubleNode* newNode = malloc(sizeof(doubleNode));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->key = key;
  newNode->next = NULL;
  return newNode;
}


int enqueue(Queue q, double key) {
  // Add to the tail
  doubleNode* newNode = InitalizeDoubleNode(key);
  if (newNode == NULL) {
    return 0; 
  }
  q.qstruct->tail->next = newNode;
  q.qstruct->tail = newNode;
  q.qstruct->qLength ++;

  return 1;
}


int dequeue(Queue q, int *errorCode) {
  //remove from the head
  doubleNode * temp = NULL;
  int key = 0;

  if (q.qstruct->head->next == NULL) {
    // There is nothing here to remove
    *errorCode = 0;
    return 0;
  }
  temp = q.qstruct->head->next;
  q.qstruct->head->next = temp->next;

  key = temp->key;
  free(temp);  

  q.qstruct->qLength --;

  return key;
}


int getQueueSize(Queue q) {
  return q.qstruct->qLength;  
}

void printQueue(Queue q) {
  doubleNode* temp = q.qstruct->head->next;
  printf("Queue: ");
  while (temp != NULL) {
    printf("[%d]", temp->key);
    temp = temp->next;
  }
  printf("\n");
}