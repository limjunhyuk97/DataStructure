#ifndef __AJOU_HW1_QUEUE_H__
#define __AJOU_HW1_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define QUEUEMAX 6

typedef char QData;

typedef struct _node {
	struct _node * next;
	QData name[50];
}Node;

typedef struct _queue {
	Node* head;
	Node* tail;
	int LEN;
}Queue;

void QInit(Queue* queue); 
int QIsEmpty(Queue* queue);
int Enqueue(Queue* queue, QData* name);
int Dequeue(Queue* queue, QData name[]);
#endif
