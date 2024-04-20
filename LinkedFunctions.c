#include<stdio.h>
#include <stdlib.h>

#include "LinkedFunctions.h"

List initalizeList(int* errorCode) {
  List list;
  list.lstruct = malloc(sizeof(listInfo));
  if (list.lstruct == NULL) {
    //Failed to allocate memory
    *errorCode = 0;
    return list;
  }

  list.lstruct->head = list.lstruct->tail = NULL;
  list.lstruct->listLength = 0;
  // Dummy Node - Secret Node hidden from the user, used to eliminate test cases
  Node* dummy = malloc(sizeof(Node));
  if (dummy == NULL) {
    *errorCode = 0;
    free(list.lstruct);
    return list; 
  }
  dummy->key = -1;
  dummy->next = NULL;
  list.lstruct->head = list.lstruct->tail = dummy;
  *errorCode = 1;

  return list;
}

List deleteList(List list) {
  Node *t = list.lstruct->head;
  while (t->next != NULL) {
    t = t->next;
    free(list.lstruct->head);
    list.lstruct->head = t;
  }
  free(list.lstruct->head);
  list.lstruct->head = list.lstruct->tail = NULL;
  list.lstruct->listLength = 0;

  free(list.lstruct);
  list.lstruct = NULL;
  return list;
}

int appendFront(List list, int value) {
  Node* newNode = InitializeNode(value);
  if (newNode == NULL) {
    // Failure to allocate memory
    return 0;
  }
  if (list.lstruct->head->next == NULL) {
    // This is the first value that we are adding in, we will need to update the tail
    list.lstruct->tail = newNode;
  }
  newNode->next = list.lstruct->head->next;
  list.lstruct->head->next = newNode;
  list.lstruct->listLength = 0;
  list.lstruct->listLength ++;

  return 1;

}

int appendBack(List list, int value) {
  Node* newNode = InitializeNode(value);
  if (newNode == NULL) {
    return 0; 
  }
  list.lstruct->tail->next = newNode;
  list.lstruct->tail = newNode;
  list.lstruct->listLength ++;

  return 1;
}

int removeFront(List list, int* errorCode) {
  // Returns the integer of the item we have just removed
  Node * temp = NULL;
  int key = 0;

  if (list.lstruct->head->next == NULL) {
    // There is nothing here to remove
    *errorCode = 0;
    return 0;
  }
  temp = list.lstruct->head->next;
  list.lstruct->head->next = temp->next;

  key = temp->key;
  free(temp);  

  list.lstruct->listLength --;
  
  return key;
}

int removeBack(List list, int* errorCode) {
  Node * temp = NULL;
  int key = 0;
  if (list.lstruct->head->next == NULL) {
    // There is nothing to remove
    *errorCode = 0;
    return 0;
  }
  temp = list.lstruct->head;
  while (temp->next != list.lstruct->tail) {
    temp = temp->next;
  }
  key = list.lstruct->tail->key;
  //Temp is now the value before the key
  temp->next = NULL;
  free(list.lstruct->tail);
  list.lstruct->tail = temp;
  list.lstruct->listLength --;
  
  return key;
}

Node* InitializeNode(int dataInit) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->key = dataInit;
  newNode->next = NULL;
  return newNode;
}

int IndexOf(List list, int target) {
  //Negative index if it does not exist
  Node* temp = list.lstruct->head->next;
  int index = 0;

  while (temp != NULL && temp->key != target) {
    temp = temp->next;
    index ++;
  }
  //This loop ending means we either found the target or got to the end of the list
  if (temp == NULL) {
    // Failed to find
    return -1;
  }
  else {
    return index;
  }
}

int returnLength(List list) {
  return list.lstruct->listLength;
}

int removeElement(List list, int targetVal, int* errorCode) {
  Node *prev = NULL;
  Node *temp = list.lstruct->head;
  int key = 0;

  // Need to independently check the head and the tail
  if (list.lstruct->head->key == targetVal) {
    return removeFront(list, errorCode);
  }
  else if(list.lstruct->tail->key == targetVal) {
    return removeBack(list, errorCode);
  }
  
  while (temp != NULL && temp->key != targetVal) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    // Could not find the target value
    return 0;
  }

  key = temp->key;
  prev->next = temp->next;

  free(temp);
  return key;
  
}

void printList(List list) {
  Node* temp = list.lstruct->head->next;
  while (temp != NULL) {
    printf("[%d]", temp->key);
    temp = temp->next;
  }
  printf("\n");
}