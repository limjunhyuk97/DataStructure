#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	
	Queue newQ;
	QueueInit(&newQ);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		int num = rand() % 9 + 1;
		printf("%d ", num);
		Enqueue(&newQ, num);
	}
	printf("\n");

	while (!QIsEmpty(&newQ))
		printf("%d ", Dequeue(&newQ));
	Dequeue(&newQ);

	return 0;

}
