#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListBaseQueue.h"

int main(void) {

	Queue Q;
	QueueInit(&Q);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		Enqueue(&Q, rand() % 9 + 1);
	}

	while (!QIsEmpty(&Q)) {
		printf("%d ", Dequeue(&Q));
	}
	printf("\n");

	return 0;
}
