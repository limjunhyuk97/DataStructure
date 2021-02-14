#ifndef __PRACTICE_ARRAY_Q_H__
#define __PRACTICE_ARRAY_Q_H__

#include <stdio.h>
#include "Point.h"

#define TRUE 1
#define FALSE 0
#define MAX_LEN 100

typedef Point QData;

typedef struct _Array_Queue {
	int front;
	int rear;
	QData arr[MAX_LEN];
	int(*func)(QData data1, QData data2);
}_Queue;

typedef _Queue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, QData data);
QData Dequeue(Queue* pq);

QData QPeek(Queue* pq);
void QDataComp(Queue* pq, int(*func)(QData data1, QData data2));

#endif