#ifndef __ENHANCED_HEAP_H__
#define __ENHANCED_HEAP_H__

#include "declaration.h"

typedef char* HData;
typedef int (*PriorityComp) (HData, HData);
// PriorityComp는 HData 두개를 비교한다.
// 앞 인자 > 뒤 인자 우선순위를 갖으면 1 return
// 앞 인자 < 뒤 인자 우선순위를 갖으면 -1 return
// 앞 인자 == 뒤 인자 우선순위를 갖으면 0 return

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