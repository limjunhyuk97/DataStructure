#ifndef __DEQUEUE_H__
#define __DEQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	struct _node* next;
	struct _node* prev;
	Data data;
}Node;

typedef struct _DBLDequeue {
	Node* head;
	Node* tail;
}_Dequeue;

typedef _Dequeue Dequeue;

void DequeueInit(Dequeue* pdeq);
int DQIsEmpty(Dequeue* pdeq);

void DQAddFirst(Dequeue* pdeq, Data data);
void DQAddLast(Dequeue* pdeq, Data data);

Data DQRemoveFirst(Dequeue* pdeq);
Data DQRemoveLast(Dequeue* pdeq);

Data DQGetFirst(Dequeue* pdeq);
Data DQGetLast(Dequeue* pdeq);

#endif