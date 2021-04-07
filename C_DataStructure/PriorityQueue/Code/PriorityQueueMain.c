#include "PriorityQueue.h"

int DataPriorityComp(HData data1, HData data2) {
	return data2 - data1;
}

int main(void) {

	PQueue pqueue;
	PQueueInit(&pqueue, DataPriorityComp);

	PEnqueue(&pqueue, 'A');
	PEnqueue(&pqueue, 'B');
	PEnqueue(&pqueue, 'C');
	printf("%c \n", PDequeue(&pqueue));

	PEnqueue(&pqueue, 'A');
	PEnqueue(&pqueue, 'B');
	PEnqueue(&pqueue, 'C');
	printf("%c \n", PDequeue(&pqueue));

	while (!PQIsEmpty(&pqueue))
		printf("%c \n", PDequeue(&pqueue));

	return 0;
}