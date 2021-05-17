#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "Declaration.h"
#define MAX_LEN 100

typedef edge Data;

typedef struct priorityQueue {
	Data pqArr[MAX_LEN];
	int newpos;
}PQ;

void PQEdgeInit(PQ* pq);

void PQEdgePush(PQ* pq, Data data);

Data PQEdgePop(PQ* pq);

#endif
