#include <stdio.h>
#include <stdlib.h>
#include "LinkedFunctions.h"


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
  iterativeReverse(list);
  printList(list);

  
  
  
  deleteList(list);

  return 0;
}

