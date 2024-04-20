#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node* next;
} Node;

typedef struct list_Info {
  Node* head;
  Node* tail;
  int listLength;
} listInfo;

typedef struct list {
  listInfo* lstruct;
} List;

List initalizeList(int* errorCode);
List deleteList(List list);
int appendFront(List list, int value); 
int appendBack(List list, int value);
int removeFront(List list, int *errorCode);
int removeBack(List list, int *errorCode);
Node* InitializeNode(int dataInit);
int IndexOf(List list, int target);
int returnLength(List list);
int removeElement(List, int targetVal, int *errorCode);
void printList(List);
void iterativeReverse(List list);
int loop(List list);