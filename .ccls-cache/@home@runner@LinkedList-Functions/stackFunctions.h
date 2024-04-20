#include <stdio.h>
#include <stdlib.h>

typedef struct cStruct {
  char key;
  struct cStruct* next; 
} charNode;

typedef struct {
  charNode *head, *tail;
  int listLength; 
} sInfo; 

typedef struct strctStruct{
  sInfo *sStruct;
} Stack;

Stack initalizeStack(int *);
Stack deleteStack(Stack);
int push(void *, Stack);
void * pop(Stack);
int getStackSize(Stack);
void printStack(Stack);

