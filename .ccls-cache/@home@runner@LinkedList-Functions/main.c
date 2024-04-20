#include <stdio.h>
#include <stdlib.h>
#include "LinkedFunctions.h"


void printList(IntNode* head);
void iterativeReverse(IntNode** head);
void swapElements(IntNode* head, IntNode* targetOne, IntNode* targetTwo);
IntNode* recursiveReverse(IntNode* head);
int loop(IntNode* head);

int main() {
  IntNode* headNode;
  IntNode* currNode;
  IntNode* lastNode;
  int index;
  int length;

  // Initiaize head node
  headNode = (IntNode*)malloc(sizeof(IntNode));
  InitializeIntNode(-1, headNode);
  lastNode = headNode;

  // Add nodes to the list
  for (int i = 0; i < 5; ++i) {
     currNode = (IntNode*)malloc(sizeof(IntNode));
     InitializeIntNode(i, currNode);
     InsertAfter(lastNode, currNode);
     lastNode = currNode;
  }
  /* making the list a loop for the purpose of testing */
  // lastNode->nextNodePtr = ((headNode->nextNodePtr)->nextNodePtr)->nextNodePtr;
  if (loop(headNode)) {
    printf("Loop detected\n");;
  }
  else {
    printf("No loop detected\n");
  }
  

  //printList(headNode);
  //printf("Reversing...\n");
  //iterativeReverse(&headNode);
  //recursiveReverse(headNode);
  //printList(lastNode);
  deallocate(headNode);
  return 0;
}




void printList(IntNode* head) {
  int index = 0;
  IntNode* temp = head;
  while (temp != NULL) {
    printf("%d\n", GetNodeData(temp));
    temp = GetNext(temp);
    index ++;

    if (index > 20) {
      // THIS IS ONLY HERE FOR TESTING PURPOSES. PLEASE REMOVE
      printf("MISTAKES HAVE BEEN MADE\n");
      break;
    }
  }
  if (index == 0) {
    printf("List is empty\n");
  }
}

void iterativeReverse(IntNode** head) {
  IntNode* prev = NULL;
  IntNode* current = *head;
  IntNode* next = NULL;
  
  while (current != NULL) { 
    next = current -> nextNodePtr;
    current -> nextNodePtr = prev;

    prev = current;
    current = next;
  }
  *head = prev;  
}
// Print by using the last node
IntNode* recursiveReverse(IntNode* head) {
  // Base Case: To find the "end" of the linked list
  if (head == NULL || head -> nextNodePtr == NULL) {
    return head;
  }
  IntNode* rest = recursiveReverse(head -> nextNodePtr);
  // Link rest to the head
  head -> nextNodePtr -> nextNodePtr = head; 
  head -> nextNodePtr = NULL;
  return rest;
}

/* Function to test if the linked list is a giant loop */
int loop(IntNode* head) {
  IntNode* slow = head; // Jumping by 1
  IntNode* fast = head; // Jumping by 2
  
  while (slow != NULL && fast != NULL && fast -> nextNodePtr != NULL) {
    slow = slow -> nextNodePtr;
    fast = fast -> nextNodePtr -> nextNodePtr;
    if (slow == fast) {
      return 1;
    }
    
  }
  return 0;
}