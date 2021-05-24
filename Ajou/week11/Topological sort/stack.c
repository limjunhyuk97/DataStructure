#include "stack.h"

int StackIsEmpty(Stack* stack) {
	if (stack->cnt == 0) return TRUE;
	else return FALSE;
}

void initStack(Stack* stack) {
	stack->cnt = 0;
}

void Push(Stack* stack, Data data) {

	if (stack->cnt == 20)
		return;

	stack->arr[stack->cnt] = data;
	stack->cnt += 1;
}

void Pop(Stack* stack, Data *data) {

	if (StackIsEmpty(stack) == TRUE)
		return;

	stack->cnt -= 1;
	*data = stack->arr[stack->cnt];
	
}