#include "Practice_Array_Q.h"

void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;

	for (int i = 0; i < 100; ++i) {
		PointInit(&pq->arr[i], 100, 100);
	}
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int QNext(int point) {
	if (point == MAX_LEN - 1)
		return 0;
	else
		return point + 1;
}

int QBefore(int point) {
	if (point == 0)
		return MAX_LEN - 1;
	else
		return point - 1;
}

void Enqueue(Queue* pq, QData data) {
	if (pq->front == QNext(pq->rear)) {
		printf("Queue Is Full!!\n");
		exit(1);
	}

	if (pq->func == NULL) {
		pq->rear = QNext(pq->rear);
		pq->arr[pq->rear] = data;
	}
	else {
		if (QIsEmpty(pq)) {
			pq->rear = QNext(pq->rear);
			pq->arr[pq->rear] = data;
		}
		else {
			int idx = QNext(pq->front);
			while (PointComp(pq->arr[idx], data)) {
				idx = QNext(idx);
			}
			if (pq->rear < idx) {
				pq->arr[idx] = data;
				pq->rear = QNext(pq->rear);
			}
			else {
				for (int i = pq->rear; i >= idx; i = QBefore(i)) {
					pq->arr[QNext(i)] = pq->arr[i];
				}
				pq->arr[idx] = data;
				pq->rear = QNext(pq->rear);
			}
		}
	}

}

QData Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue is Empty!!\n");
		exit(1);
	}
	pq->front = QNext(pq->front);

	return pq->arr[pq->front];

}

QData QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue is Empty!!\n");
		exit(1);
	}

	return pq->arr[QNext(pq->front)];
}

void QDataComp(Queue* pq, int(*func)(QData data1, QData data2)) {
	if (func == NULL)
		pq->func = NULL;
	else
		pq->func = func;
}