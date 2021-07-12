#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	// Stack의 생성
	Stack newStack;
	StackInit(&newStack);
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		SPush(&newStack, rand() % 9 + 1);
		printf("%d ", SPeek(&newStack));
	}
	printf("\t");

	while (!SIsEmpty(&newStack)) {
		printf("%d ", SPop(&newStack));
	}

	return 0;
}
