#include <stdio.h>
#include <stdlib.h>

typedef struct cStruct {
  char key;
  struct cStruct* next; 
} charNode;

typedef struct {
  charNode *head, *tail;
  int stackLength; 
} sInfo; 

typedef struct strctStruct{
  sInfo *sStruct;
} Stack;

Stack initalizeStack(int *errorCode);
Stack deleteStack(Stack s);
charNode* InitalizeCharNode(char key);
int push(Stack s,char c);
char pop(Stack s);
int getStackSize(Stack s);
void printStack(Stack s);

