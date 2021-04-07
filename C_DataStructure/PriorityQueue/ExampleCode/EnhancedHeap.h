#ifndef __ENHANCED_HEAP_H__
#define __ENHANCED_HEAP_H__

#include "declaration.h"

typedef char* HData;
typedef int (*PriorityComp) (HData, HData);
// PriorityComp�� HData �ΰ��� ���Ѵ�.
// �� ���� > �� ���� �켱������ ������ 1 return
// �� ���� < �� ���� �켱������ ������ -1 return
// �� ���� == �� ���� �켱������ ������ 0 return

typedef struct EnhancedHeap {
	HData heapArr[HEAP_LEN];
	int numOfData;
	PriorityComp comp;
}Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif