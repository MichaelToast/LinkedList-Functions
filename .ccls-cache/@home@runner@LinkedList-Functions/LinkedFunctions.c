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

int removeFront(List list) {
  return 0;
}

int removeBack(List list);

Node* InitializeNode(int dataInit) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->key = dataInit;
  newNode->next = NULL;
  return newNode;
}

int IndexOf(List list, int target);
int returnLength(List list);
void removeElement(List, int target_val);
void defaultSearch();

void printList(List list) {
  Node* temp = list.lstruct->head->next;
  while (temp != NULL) {
    printf("[%d]", temp->key);
    temp = temp->next;
  }
  printf("\n");
}