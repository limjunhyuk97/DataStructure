#ifndef __STACK_H__
#define __STACK_H__

#define MAX_LEN 20
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct Stack {
	int cnt;
	Data arr[MAX_LEN];
}Stack;

void initStack(Stack* stack);

void Push(Stack* stack, Data data);

void Pop(Stack* stack, Data *data);

int StackIsEmpty(Stack* stack);

#endif
