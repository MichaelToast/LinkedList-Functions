#include <stdio.h>
#include <stdlib.h>

#include "stackFunctions.h"


Stack initalizeStack(int *errorCode) {
  Stack s;
  s.sStruct = malloc(sizeof(sInfo));
  if (s.sStruct == NULL) {
    return s;
  }

  charNode* dummy = InitalizeCharNode('\0');
  if (dummy == NULL) {
    free(s.sStruct);
    return s;      
  }

  s.sStruct->head = s.sStruct->tail = dummy;
  s.sStruct->stackLength = 0;
  return s;
}

Stack deleteStack(Stack s) {
  charNode* temp = s.sStruct->head; 
  if (s.sStruct->head ==NULL) {
    return s;
  }
  while (s.sStruct->head != NULL) {
    temp = s.sStruct->head;
    s.sStruct->head = s.sStruct->head->next;
    free(temp);
  }

  free(s.sStruct);

  return s;
}

charNode* InitalizeCharNode(char key) {
  charNode* newNode = malloc(sizeof(charNode));
  if (newNode == NULL) {
    return NULL;
  }
  else {
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
  }
}

int push(Stack s, char c) {
  // Insert at head
  charNode *newNode = InitalizeCharNode(c);
  if (newNode == NULL) {
    printf("FAILED TO ALLOCATE MEMORY\n");
    return 0;
  }

  if (s.sStruct->head->next == NULL) {
    //First item added, change the tail
    s.sStruct->tail = newNode;
  }

  newNode->next = s.sStruct->head->next;
  s.sStruct->head->next = newNode;
  s.sStruct->stackLength ++;
  
  return 1;
  
}

char pop(Stack s) {
  char val;
  charNode* temp;
  temp = s.sStruct->head->next;

  if (s.sStruct->stackLength == 0) {
    // Nothing to pop
    return '\0';
  }

  s.sStruct->head->next = s.sStruct->head->next->next;
  val = temp->key;
  free(temp);
  s.sStruct->stackLength --;

  return val;
}

int getStackSize(Stack s) {
  return s.sStruct->stackLength;
}

void printStack(Stack s) {
  charNode* temp = s.sStruct->head->next;
  
  printf("Queue: ");
  while (temp != NULL) {
    printf("[%c]", temp->key);
    temp = temp->next;
  }
  printf("\n");
}

