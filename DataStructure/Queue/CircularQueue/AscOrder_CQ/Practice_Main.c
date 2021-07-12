#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Practice_Array_Q.h"

int main(void) {

	Queue queue;
	QueueInit(&queue);
	QDataComp(&queue, PointComp);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		Point point;
		PointInit(&point, rand() % 9 + 1, rand() % 9 + 1);
		Enqueue(&queue, point);
	}

	while (!QIsEmpty(&queue)) {
		Point tmp = Dequeue(&queue);
		PointPrint(&tmp);
	}

	return 0;
}