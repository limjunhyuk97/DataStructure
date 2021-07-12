#include "ListBaseQueue.h"

void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (pq->front == NULL) {
		pq->front = newNode;
	}	
	else {
		pq->rear->next = newNode;
	}
	pq->rear = newNode;
	
}

Data Dequeue(Queue* pq) {

	if (pq->front == NULL) {
		printf("Queue is full!\n");
		exit(1);
	}

	Node* tmpNode = pq->front;
	Data tmpData = pq->front->data;
	
	/*
	* 노드가 하나 남은 경우를 고려하지 않아도 된다.
	  - pq->front 값으로 큐가 비어있음을 고려하기 때문에, 쓰레기 값이 들어가더라도 고려하지 않아도 된다.
	
	if (pq->front == pq->rear)
		QueueInit(pq);
	else
	*/
	
	pq->front = pq->front->next;
	free(tmpNode);
	return tmpData;

}

Data QPeek(Queue* pq) {
	if (pq->front == NULL) {
		printf("Nothing in it!");
		exit(1);
	}

	return pq->front->data;
}
