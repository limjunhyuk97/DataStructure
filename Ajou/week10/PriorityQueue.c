#include "PriorityQueue.h"

void PQEdgeInit(PQ* pq) {
	pq->newpos = 1;
}

// cNode가 더 크면 Criteria > 0 OK
// pNode가 더 크면 Criteria < 0 NO
int Criteria(int pNode, int cNode) {
	return cNode - pNode;
}

int LChildIndex(int node) {
	return node * 2;
}

int RChildIndex(int node) {
	return node * 2 + 1;
}

int ParentIndex(int node) {
	return node / 2;
}

// parent의 수가 더 크면 return < 0 No 
// child의 수가 더 크면 return > 0 OK
int CompParentChild(Data parent, Data child) {
	return Criteria(parent.cost, child.cost);
}

int GetHPriChildIndex(PQ *pq, int parent) {
	if (pq->newpos < LChildIndex(parent))
		return 0;
	else {
		if (pq->newpos == LChildIndex(parent))
			return LChildIndex(parent);
		else {
			if (Criteria(pq->pqArr[LChildIndex(parent)].cost, pq->pqArr[RChildIndex(parent)].cost) < 0)
				return RChildIndex(parent);
			else
				return LChildIndex(parent);
		}

	}
}

void PQEdgePush(PQ* pq, Data data) {
	if (pq->newpos == 1) {
		pq->pqArr[(pq->newpos)++] = data;
		return;
	}

	int pNode, cNode;
	cNode = pq->newpos;
	pNode = ParentIndex(cNode);

	while (cNode > 1) {
		if (CompParentChild(pq->pqArr[pNode], data) < 0) {
			pq->pqArr[cNode] = pq->pqArr[pNode];
			cNode = pNode;
			pNode = ParentIndex(cNode);
		}
		else
			break;
	}

	pq->pqArr[cNode] = data;
	++(pq->newpos);

}

Data PQEdgePop(PQ* pq) {

	if (pq->newpos < 1)
		return pq->pqArr[0];

	Data retData = pq->pqArr[1];
	Data lastData = pq->pqArr[--(pq->newpos)];

	int pNode = 1;
	int cNode = GetHPriChildIndex(pq, pNode);

	while (cNode > 0) {
		if (CompParentChild(lastData, pq->pqArr[cNode]) < 0) {
			pq->pqArr[pNode] = pq->pqArr[cNode];
			pNode = cNode;
			cNode = GetHPriChildIndex(pq, pNode);
		}
		else
			break;
	}

	pq->pqArr[pNode] = lastData;

	return retData;

}