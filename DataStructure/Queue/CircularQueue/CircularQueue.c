#include "CircularQueue.h"

void QueueInit(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

int QIsEmpty(Queue* q) {
	if (q->front == q->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* q, Data data) {
	if (NextPosIdx(q->rear) == q->front) {
		printf("Queue is full!\n");
		return;
	}
	q->rear = NextPosIdx(q->rear);
	q->queArr[q->rear] = data;
}

Data Dequeue(Queue* q) {
	if (q->rear == q->front) {
		printf("Queue is empty!\n");
		return;
	}
	q->front = NextPosIdx(q->front);
	return q->queArr[q->front];
}

Data QPeek(Queue* q) {
	if (q->rear == q->front) {
		printf("Queue is empty!\n");
		return;
	}
	return q->queArr[NextPosIdx(q->front)];
}
