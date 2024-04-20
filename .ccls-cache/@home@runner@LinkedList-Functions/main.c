#include <stdio.h>
#include <stdlib.h>
#include "LinkedFunctions.h"

/*
void printList(IntNode* head);
void iterativeReverse(IntNode** head);
void swapElements(IntNode* head, IntNode* targetOne, IntNode* targetTwo);
IntNode* recursiveReverse(IntNode* head);
int loop(IntNode* head);
*/

int main() {
  int errorCode = 0;
  List list = initalizeList(&errorCode);
  if (errorCode == 0) {
    printf("THERE HAS BEEN AN ERROR\n");    
    return 1;
  }
  for (int i = 0; i < 5; i ++) {
    appendFront(list, (i * 2));
  }

  printList(list);
  
  appendBack(list, 200);
  printList(list);
  
  removeBack(list, &errorCode);
  appendBack(list, 900);
  printList(list);

  IndexOf(list, 9);
  
  
  
  deleteList(list);

  return 0;
}


// Will update these functions later: 
/*
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

Function to test if the linked list is a giant loop
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
*/