#ifndef __MAX_HEAP_H__
#define __MAX_HEAP_H__

#include "Delcaration.h"

typedef int (*compFunc)(int, int);
// 辦摹牖嬪陛..!
// 謝 > 辦 : return +
// 謝 < 辦 : return -
// 謝 = 辦 : return 0

typedef struct DataBundle {
	int capacity;
	char data[50];
}Bundle;

typedef struct MaxHeap {
	Bundle bundle[MAX_HEAPLEN];
	int numOfData;
	compFunc comp;
}Heap;

void PQInit(Heap *heap);
int PQIsEmpty(Heap* heap);
int PQIsFull(Heap* heap);

void PQDelete(Heap* heap);
void PQInsert(Heap* heap);
void PQPrint(Heap* heap);

#endif