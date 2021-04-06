#include "SimpleHeap.h"

void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

// 현재 Node 기준, 주변 node의 index 반환해주는 함수들
int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

// 자식 Node 둘 중, priority가 높은 자식 노드를 반환 -> delete에서 사용해야 함
// 자식 Node의 갯수를 판별하는 가늠자로써 numOfData 정보를 이용하였다.
int GetHiPriChildIdx(Heap* hp, int idx) {

	// 없으면 0을 반환한다.
	if (GetLChildIDX(idx) > hp->numOfData) return 0;
	
	// 왼쪽으로 내려오게 하는 것 중요하다..! : complete binary tree이기 때문에!
	else if (GetLChildIDX(idx) == hp->numOfData) return GetLChildIDX(idx);

	// 마찬가지로, GetLChildIdx또한 pr이 같을 때, 왼쪽으로 내려오게 한다!
	else {
		if (hp->heapArr[GetLChildIDX(idx)].pr > hp->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

// heap에 data 저장
void HInsert(Heap* ph, HData data, Priority pr) {
	
	// idx로 가장 마지막 노드를 가리키면서, 가장 마지막 노드에 저장한 셈 치는 것이다.
	int idx = ph->numOfData + 1;
	HeapElem tmpElem = { data, pr };

	// 계속해서 들어온 데이터가 정 위치를 잡을 때까지, 교환을 시켜준다.
	while (idx > 1) {
		if (pr < ph->heapArr[GetParentIDX(idx)].pr) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}

	// 이제 입력할 데이터를 idx가 가리키고 있는 위치에 넣어준다.
	ph->heapArr[idx] = tmpElem;

	// heap의 크기를 하나 늘려준다!
	(ph->numOfData)++;
}

// 힙에서 데이터 삭제
HData HDelete(Heap* ph) {

	HData tmpData = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	// lastElem이 들어갈 위치를 찾는다.
	// 1부터 하향하면서 위치를 찾는다 + 위치를 찾는 과정에서 자리들을 메꾼다.
	int parentIdx = 1;
	int childIdx;

	// 없으면 0반환, 왼쪽으로 내려오게 하는, GetHiPriChildIdx() 함수의 특성을 잘 이용했다.
	// childIdx가 없으면 0 -> 탈출
	// childIdx가 왼쪽에만 있으면 왼쪽 child idx 반환 -> 비교 가능
	// childIdx가 양쪽에 모두 있으면 pr이 더 높은 친구 반환 -> 비교 가능
	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) {

		// 마지막에 존재하던 요소의 우선순위보다 크거나 '같을 때', 종료. 
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	// 모든 자리바꿈이 종료되고 나면 element 제자리로 위치시켜줌
	ph->heapArr[parentIdx] = lastElem;
	(ph->numOfData)--;

	return tmpData;

}