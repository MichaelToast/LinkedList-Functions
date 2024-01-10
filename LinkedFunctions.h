typedef struct IntNode_struct {
  /* Each node contains a Value and a pointer pointing to the next Node */
  int dataVal;
  struct IntNode_struct* nextNodePtr;
} IntNode;

void InitializeIntNode(int dataInit, IntNode* thisNode);
int GetNodeData(IntNode* thisNode);
IntNode* GetNext(IntNode* thisNode);
void InsertAfter(IntNode* thisNode, IntNode* newNode);
int IndexOf(IntNode* headNode, int target);
void deallocate(IntNode* head);
int returnLength(IntNode* head);