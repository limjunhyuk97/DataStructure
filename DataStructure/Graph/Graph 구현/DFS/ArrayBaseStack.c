#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = 0;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->topIndex == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	pstack->stackArr[pstack->topIndex++] = data;
}

Data SPop(Stack * pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[--(pstack->topIndex)];
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex - 1];
}