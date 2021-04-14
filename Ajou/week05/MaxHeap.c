#include "MaxHeap.h"

int descOrder(int data1, int data2) {
	return data1 - data2;
}

int getLChildIdx(int idx) {
	return idx * 2;
}

int getRChildIdx(int idx) {
	return idx * 2 + 1;
}

int getParentIdx(int idx) {
	return idx / 2;
}

int getPriChildIdx(Heap *heap, int idx) {
	if (getLChildIdx(idx) > heap->numOfData) return 0;
	else if (getLChildIdx(idx) == heap->numOfData) return heap->numOfData;
	else {
		if (heap->comp(heap->bundle[getLChildIdx(idx)].capacity, heap->bundle[getRChildIdx(idx)].capacity) < 0)
			return getRChildIdx(idx);
		else
			return getLChildIdx(idx);
	}
}

void PQInit(Heap* heap) {
	heap->numOfData = 0;
	heap->comp = descOrder;
}

int PQIsEmpty(Heap* heap) {
	if (heap->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int PQIsFull(Heap* heap) {
	if (heap->numOfData == MAX_HEAPLEN - 1)
		return TRUE;
	else
		return FALSE;
}

void PQDelete(Heap* heap) {
	
	int capacity;
	char data[50];
	int FLAG = 0;
	int targetIdx, childIdx;
	Bundle lastBundle = heap->bundle[heap->numOfData];
	int lastBundleCapaciy = lastBundle.capacity;

	if (PQIsEmpty(heap)) {
		printf(ERREMPTYHEAP);
		return;
	}

	printf(PRINTDELETEDATAINPUT);
	scanf_s("%s", data, 50);

	for (int i = 1; i <= heap->numOfData; ++i) {
		if (strcmp(heap->bundle[i].data, data) == 0) {
			FLAG = 1; targetIdx = i;
		}
	}

	if (FLAG == 0) {
		printf(ERRDATAINVALID, data);
		return;
	}

	while (childIdx = getPriChildIdx(heap, targetIdx)) {
		if (heap->comp(heap->bundle[childIdx].capacity, lastBundleCapaciy) > 0) {
			heap->bundle[targetIdx].capacity = heap->bundle[childIdx].capacity;
			strcpy_s(heap->bundle[targetIdx].data, 50, heap->bundle[childIdx].data);
			targetIdx = childIdx;
			continue;
		}
		break;
	}

	heap->bundle[targetIdx] = lastBundle;
	--(heap->numOfData);
	printf(SUCCESSDELETE, data);
	
	return;
}

void PQInsert(Heap* heap) {
	
	if (PQIsFull(heap)) {
		printf(ERRFULLHEAP);
		return;
	}
	
	int capacity;
	char data[50];

	printf(PRINTDATAINPUT); scanf_s("%s", data, 50);
	for (int i = 1; i <= heap->numOfData; ++i) {
		if (strcmp(heap->bundle[i].data, data) == 0) {
			printf(ERRDUPLICATEDATAINPUT);
			return;
		}
	}
	printf(PRINTCAPACITYINPUT); scanf_s("%d", &capacity);

	int insertIdx = ++(heap->numOfData);

	while (insertIdx > 1) {
		if (heap->comp(heap->bundle[getParentIdx(insertIdx)].capacity, capacity) < 0) {
			heap->bundle[insertIdx].capacity = heap->bundle[getParentIdx(insertIdx)].capacity;
			strcpy_s(heap->bundle[insertIdx].data, 50, heap->bundle[getParentIdx(insertIdx)].data);
			insertIdx = getParentIdx(insertIdx);
			continue;
		}
		break;
	}

	heap->bundle[insertIdx].capacity = capacity;
	strcpy_s(heap->bundle[insertIdx].data, 50, data);
	printf(SUCCESSINSERT);
	return;
}

Bundle PQPop(Heap* heap) {

	Bundle retBundle = heap->bundle[1];
	Bundle lastBundle = heap->bundle[heap->numOfData];
	int lastBundleCapacity = lastBundle.capacity;

	int parentIdx = 1, childIdx;
	while (childIdx = getPriChildIdx(heap, parentIdx)) {
		if (heap->comp(heap->bundle[childIdx].capacity, lastBundleCapacity) > 0) {
			heap->bundle[parentIdx].capacity = heap->bundle[childIdx].capacity;
			strcpy_s(heap->bundle[parentIdx].data, 50, heap->bundle[childIdx].data);
			parentIdx = childIdx;
			continue;
		}
		break;
	}

	heap->bundle[parentIdx].capacity = lastBundle.capacity;
	strcpy_s(heap->bundle[parentIdx].data, 50, lastBundle.data);
	--(heap->numOfData);

	return retBundle;
}

void PQPrint(Heap* heap) {
	if (PQIsEmpty(heap)) {
		printf(ERREMPTYHEAP);
		return;
	}
	
	Heap tmpHeap;
	PQInit(&tmpHeap);
	tmpHeap.numOfData = heap->numOfData;

	for (int i = 1; i <= heap->numOfData; ++i) {
		tmpHeap.bundle[i].capacity = heap->bundle[i].capacity;
		strcpy_s(tmpHeap.bundle[i].data, 50, heap->bundle[i].data);
	}

	while (!PQIsEmpty(&tmpHeap)) {
		Bundle tmpBundle;
		tmpBundle = PQPop(&tmpHeap);
		printf(PRINTPQNODE, tmpBundle.data, tmpBundle.capacity);
	}

	return;
}