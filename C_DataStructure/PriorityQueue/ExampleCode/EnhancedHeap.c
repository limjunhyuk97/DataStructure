#include "EnhancedHeap.h"

void HeapInit(Heap* ph, PriorityComp pc) {
	ph->comp = pc;
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else return FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

// �ڽ� �� �켱������ ���� ���� ��ȯ
int GetHiPriChildIDX(Heap *ph,int idx) {
	if (ph->numOfData < GetLChildIDX(idx))
		return 0;
	else if (ph->numOfData == GetLChildIDX(idx))
		return GetLChildIDX(idx);

	// ���� �켱������ ������ ���� �ڽ� idx ��ȯ
	// �װ��� �ƴϸ� �ظ��ϸ� ���� �ڽ� idx ��ȯ
	else {
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data) {
	int idx = ++(ph->numOfData);
	ph->heapArr[idx] = data;

	while (idx > 1) {
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}

	ph->heapArr[idx] = data;
}

HData HDelete(Heap* ph) {

	HData tmpData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];
	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(ph->heapArr[childIdx], lastElem) > 0) {
			ph->heapArr[parentIdx] = ph->heapArr[childIdx];
			parentIdx = childIdx;
		}
		else break;
	}

	ph->heapArr[parentIdx] = lastElem;
	--(ph->numOfData);

	return tmpData;
}

/*
* ���� ������ HDelete �Լ�

HData HDelete(Heap* ph) {

	HData tmpData = ph->heapArr[1];
	int idx = 1;

	while (GetHiPriChildIDX(ph, idx)) {
		if (ph->comp(ph->heapArr[GetHiPriChildIDX(ph, idx)], ph->heapArr[ph->numOfData]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetHiPriChildIDX(ph, idx)];
			idx = GetHiPriChildIDX(ph, idx);
		}
		else break;
	}

	ph->heapArr[idx] = ph->heapArr[ph->numOfData];
	--(ph->numOfData);

	return tmpData;
}
*/