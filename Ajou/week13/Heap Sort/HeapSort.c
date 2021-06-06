#include "HeapSort.h"

int heapIsEmpty(Heap* heap) {
	if (heap->heapCount == 0)
		return TRUE;
	else
		return FALSE;
}

// 수가 작은 것이 Priority 높다.
// priorityComp < 0 이면 d1 < d2
// priorityComp > 0 이면 d1 > d2
int priorityComp(Data d1, Data d2) {
	return d1 - d2;
}

int getRChild(int parent) {
	return parent * 2 + 1;
}

int getLChild(int parent) {
	return parent * 2;
}

int getParent(int child) {
	return child / 2;
}

int getHiPriChild(Heap *heap, int parent){
	if (heap->heapCount < getLChild(parent))
		return 0;
	else if (heap->heapCount == getLChild(parent))
		return getLChild(parent);
	else {
		if (priorityComp(heap->arr[getLChild(parent)], heap->arr[getRChild(parent)]) > 0)
			return getRChild(parent);
		else
			return getLChild(parent);
	}
}

void heapInit(Heap* heap) {
	heap->heapCount = 0;
}

void heapInsert(Heap* heap, Data data) {
	
	if (heapIsEmpty(heap) == TRUE) {
		heap->arr[++(heap->heapCount)] = data;
		return;
	}

	int cIndex = ++(heap->heapCount);
	int pIndex = getParent(cIndex);

	while ((pIndex != 0) && (priorityComp(heap->arr[pIndex], data) > 0)) {
		heap->arr[cIndex] = heap->arr[pIndex];
		cIndex = pIndex;
		pIndex = getParent(cIndex);
	}

	heap->arr[cIndex] = data;

	return;
}

int heapDelete(Heap* heap, Data*data) {

	if (heapIsEmpty(heap) == TRUE) {
		return FALSE;
	}

	Data retData = heap->arr[1];
	Data tmpData = heap->arr[(heap->heapCount)--];
	
	int pIndex = 1;
	int cIndex = getHiPriChild(heap, pIndex);

	while ((cIndex != 0) && (priorityComp(tmpData, heap->arr[cIndex]) > 0 )) {
		heap->arr[pIndex] = heap->arr[cIndex];
		pIndex = cIndex;
		cIndex = getHiPriChild(heap, pIndex);
	}

	heap->arr[pIndex] = tmpData;
	*data = retData;

	return TRUE;
}