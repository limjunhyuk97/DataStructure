#include "ListBaseStack.h"
#include <stdlib.h>

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, SData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	pstack->head = newNode;

}

SData SPop(Stack* pstack) {
	SData tmpdata;
	Node* tmpNode;

	if (SIsEmpty(pstack)) {
		printf("Stack is Empty!\n");
		exit(-1);
	}

	tmpNode = pstack->head;
	tmpdata = pstack->head->data;
	pstack->head = pstack->head->next;
	
	free(tmpNode);
	return tmpdata;
}

SData SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Nothing here!\n");
		exit(-1);
	}
	else
		return pstack->head->data;
}
