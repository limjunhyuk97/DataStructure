#include "Ajou_Hw1_queue.h"

void QInit(Queue* queue) {
	queue->head = NULL;
	queue->tail = NULL;
	queue->LEN = 0;
}

int QIsEmpty(Queue* queue) {
	if (queue->head == NULL)
		return TRUE;
	else
		return FALSE;
}

int Enqueue(Queue* queue, QData* name) {

	if (queue->LEN >= QUEUEMAX) {
		return TRUE;
	}

	printf("이름 입력 : "); scanf_s("%s", name, 50); getchar();

	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy_s(newNode->name, 50, name);
	newNode->next = NULL;

	if (QIsEmpty(queue)) {
		queue->head = newNode;
	}
	else {
		queue->tail->next = newNode;
	}
	queue->tail = newNode;
	
	++(queue->LEN);

	return FALSE;
}

int Dequeue(Queue* queue, QData name[]) {
	if (QIsEmpty(queue)) {
		printf("대기 중인 고객 없음\n\n");
		return FALSE;
	}

	Node* tmpNode = queue->head;
	QData tmpData[50] = {0 , };
	strcpy_s(tmpData, 50, queue->head->name);

	if (queue->head == queue->tail) {
		queue->head = NULL;
	}
	else {
		queue->head = queue->head->next;
	}

	free(tmpNode);
	strcpy_s(name, 50, tmpData);

	--(queue->LEN);

	return TRUE;

}
