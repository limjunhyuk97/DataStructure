#include "Dequeue.h"

void DequeueInit(Dequeue* pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Dequeue* pdeq) {
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Dequeue* pdeq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pdeq->head;
	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Dequeue* pdeq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;
	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Dequeue* pdeq) {
	Node* tmpNode = pdeq->head;
	Data tmpData = pdeq->head->data;

	if (DQIsEmpty(pdeq)) {
		printf("Dequeue is Empty!\n");
		exit(-1);
	}

	if (pdeq->head == pdeq->tail) {
		pdeq->head = NULL;
	}
	else {
		pdeq->head = pdeq->head->next;
	}
	free(tmpNode);

	return tmpData;
}

Data DQRemoveLast(Dequeue* pdeq) {
	Node* tmpNode = pdeq->tail;
	Data tmpData = pdeq->tail->data;

	if (DQIsEmpty(pdeq)) {
		printf("Dequeue is Empty!\n");
		exit(-1);
	}

	if (pdeq->head == pdeq->tail) {
		pdeq->head = NULL;
	}
	else {
		pdeq->tail = pdeq->tail->prev;
	}
	free(tmpNode);

	return tmpData;
}

Data DQGetFirst(Dequeue* pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Dequeue is Empty!\n");
		exit(-1);
	}
	return pdeq->head->data;
}

Data DQGetLast(Dequeue* pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Dequeue is Empty!\n");
		exit(-1);
	}
	return pdeq->tail->data;
}