#ifndef __STACK_IN_C_LINKED_LIST_H__
#define __STACK_IN_C_LINKED_LIST_H__
#include "CLinkedList.h"
#include <stdlib.h>

typedef struct _CLL_Stack {
	List* plist;
} _Stack;

typedef _Stack Stack;
typedef LData SData;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);
void SPush(Stack* pstack, SData data);
SData SPop(Stack* pstack);
SData SPeek(Stack* pstack);

#endif
