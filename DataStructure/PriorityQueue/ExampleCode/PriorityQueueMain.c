#include "PriorityQueue.h"

int DataPriorityComp(HData data1, HData data2) {
	return strlen(data2) - strlen(data1);
}

int main(void) {

	PQueue pqueue;
	PQueueInit(&pqueue, DataPriorityComp);

	PEnqueue(&pqueue, "Tom");
	PEnqueue(&pqueue, "Jack");
	PEnqueue(&pqueue, "Gibson");
	printf("%s \n", PDequeue(&pqueue));

	PEnqueue(&pqueue, "Tom");
	PEnqueue(&pqueue, "Jack");
	PEnqueue(&pqueue, "Gibson");
	printf("%s \n", PDequeue(&pqueue));

	while (!PQIsEmpty(&pqueue))
		printf("%s \n", PDequeue(&pqueue));

	return 0;
}