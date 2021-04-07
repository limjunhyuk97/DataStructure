#include "PriorityQueue.h"

void PQueueInit(PQueue* ppq, PriorityComp pc) {
	ppq->comp = pc;
	ppq->numOfData = 0;
}

int PQIsEmpty(PQueue* ppq) {
	if (ppq->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void PEnqueue(PQueue* ppq, PQData data) {
	HInsert(ppq, data);
}

PQData PDequeue(PQueue* ppq) {
	return HDelete(ppq);
}