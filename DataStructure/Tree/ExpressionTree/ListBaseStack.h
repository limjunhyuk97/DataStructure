#ifndef __LISTBASESTACK_H__
#define __LISTBASESTACK_H__

#include "BTree.h"

typedef struct _Stacknode {
	BTreeNode* BTNode;
	struct _Stacknode* next;
}StackNode;

typedef struct ListBaseStack {
	StackNode* head;
}Stack;

void InitStack(Stack* stack);

BTreeNode* Peek(Stack* stack);
void Push(Stack* stack, BTreeNode* bt);
BTreeNode* Pop(Stack* stack);
int IsEmpty(Stack* stack);

#endif