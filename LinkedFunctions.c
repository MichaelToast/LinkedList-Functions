#include<stdio.h>
#include <stdlib.h>

#include "LinkedFunctions.h"


void InitializeIntNode(int dataInit, IntNode* thisNode) {
  /* Set the Value to dataInit and set the next node to NULL */
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = NULL;
}

int GetNodeData(IntNode* thisNode) {
  return thisNode->dataVal;
}

IntNode* GetNext(IntNode* thisNode) {
  /* Returns the Pointer to the next node */
  return thisNode->nextNodePtr;
}

/* Insert node after this node.
   Before: this -- next
   After:  this -- node -- next
*/
void InsertAfter(IntNode* thisNode, IntNode* newNode) {
  /* Inserts the newNode inbetween other nodes*/
  IntNode* tempNext = NULL;

  tempNext = thisNode->nextNodePtr;
  thisNode->nextNodePtr = newNode;
  newNode->nextNodePtr = tempNext;
}

int IndexOf(IntNode* headNode, int target) {
  /* Finds what number node that the Target Appears */
  int valIndex = 0;
  IntNode* tempNext = NULL; //Item we are using to search
  tempNext = headNode->nextNodePtr;

  //If the list itself is negative from the begining
  if (headNode -> nextNodePtr == NULL) {
      return -1;
  }

  while (tempNext -> nextNodePtr != NULL) {
      if (GetNodeData(tempNext) == target) {
          return valIndex;
      }
      //we have not found a match, so move forwards
      tempNext = GetNext(tempNext);
      valIndex ++;
  }
  return -1;

}

void deallocate(IntNode* head) {
  /* Going down the line to the right, freeing everything behind us */
  IntNode* temp = head;
  while (temp->nextNodePtr != NULL) {
    temp = temp -> nextNodePtr;
    free(head);
    head = temp; 
  }
  //Head contains NULL
  free(head); 

}

int returnLength(IntNode* head) {
  int count = 0;
  IntNode* temp = head;
  while (temp->nextNodePtr != NULL) {
    count ++;
    temp = GetNext(temp);
  }
  return count;

}