#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef char SData;

typedef struct _node {
	SData data;
	struct _node* next;
}Node;

typedef struct _listStack {
	Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, SData data);
SData SPop(Stack* pstack);
SData SPeek(Stack* pstack);


#endif
