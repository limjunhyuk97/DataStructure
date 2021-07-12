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

// ���� Node ����, �ֺ� node�� index ��ȯ���ִ� �Լ���
int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

// �ڽ� Node �� ��, priority�� ���� �ڽ� ��带 ��ȯ -> delete���� ����ؾ� ��
// �ڽ� Node�� ������ �Ǻ��ϴ� �����ڷν� numOfData ������ �̿��Ͽ���.
int GetHiPriChildIdx(Heap* hp, int idx) {

	// ������ 0�� ��ȯ�Ѵ�.
	if (GetLChildIDX(idx) > hp->numOfData) return 0;
	
	// �������� �������� �ϴ� �� �߿��ϴ�..! : complete binary tree�̱� ������!
	else if (GetLChildIDX(idx) == hp->numOfData) return GetLChildIDX(idx);

	// ����������, GetLChildIdx���� pr�� ���� ��, �������� �������� �Ѵ�!
	else {
		if (hp->heapArr[GetLChildIDX(idx)].pr > hp->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

// heap�� data ����
void HInsert(Heap* ph, HData data, Priority pr) {
	
	// idx�� ���� ������ ��带 ����Ű�鼭, ���� ������ ��忡 ������ �� ġ�� ���̴�.
	int idx = ph->numOfData + 1;
	HeapElem tmpElem = { data, pr };

	// ����ؼ� ���� �����Ͱ� �� ��ġ�� ���� ������, ��ȯ�� �����ش�.
	while (idx > 1) {
		if (pr < ph->heapArr[GetParentIDX(idx)].pr) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else break;
	}

	// ���� �Է��� �����͸� idx�� ����Ű�� �ִ� ��ġ�� �־��ش�.
	ph->heapArr[idx] = tmpElem;

	// heap�� ũ�⸦ �ϳ� �÷��ش�!
	(ph->numOfData)++;
}

// ������ ������ ����
HData HDelete(Heap* ph) {

	HData tmpData = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	// lastElem�� �� ��ġ�� ã�´�.
	// 1���� �����ϸ鼭 ��ġ�� ã�´� + ��ġ�� ã�� �������� �ڸ����� �޲۴�.
	int parentIdx = 1;
	int childIdx;

	// ������ 0��ȯ, �������� �������� �ϴ�, GetHiPriChildIdx() �Լ��� Ư���� �� �̿��ߴ�.
	// childIdx�� ������ 0 -> Ż��
	// childIdx�� ���ʿ��� ������ ���� child idx ��ȯ -> �� ����
	// childIdx�� ���ʿ� ��� ������ pr�� �� ���� ģ�� ��ȯ -> �� ����
	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) {

		// �������� �����ϴ� ����� �켱�������� ũ�ų� '���� ��', ����. 
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	// ��� �ڸ��ٲ��� ����ǰ� ���� element ���ڸ��� ��ġ������
	ph->heapArr[parentIdx] = lastElem;
	(ph->numOfData)--;

	return tmpData;

}