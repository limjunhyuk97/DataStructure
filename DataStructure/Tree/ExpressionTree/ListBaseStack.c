#include "ListBaseStack.h"

void InitStack(Stack* stack) {
	stack->head = NULL;
}

BTreeNode* Peek(Stack* stack) {
	return stack->head->BTNode;
}

void Push(Stack* stack, BTreeNode* bt) {
	StackNode* newNode = malloc(sizeof(StackNode));
	newNode->BTNode = bt;
	newNode->next = NULL;

	if (IsEmpty(stack)) {
		stack->head = newNode;
		return;
	}
	newNode->next = stack->head;
	stack->head = newNode;
	return;
}

BTreeNode* Pop(Stack* stack) {
	if (IsEmpty(stack)) return NULL;
	
	StackNode* tmpNode = stack->head;
	BTreeNode* tmpBTreeNode = stack->head->BTNode;
	// pointer <= pointer 값 받아오면 그래도 내부 값들이 없어지지는 않는구나!
	if (stack->head->next == NULL) {
		stack->head = NULL;
	}
	else {
		stack->head = stack->head->next;
	}
	free(tmpNode);

	return tmpBTreeNode;

}

int IsEmpty(Stack* stack) {
	if (stack->head == NULL)
		return TRUE;
	else 
		return FALSE;
}