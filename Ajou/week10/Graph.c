#include "Graph.h"

void GraphInit(Graph* graph, int numV, int numE) {
	graph->vP = 0;
	graph->numV = numV;
	graph->numE = numE;
	PQEdgeInit(&(graph->eArr));
}

void MakeEdge(Graph* graph, int v1, int v2, int cost) {
	edge newV = { cost, v1, v2 };
	PQEdgePush(&(graph->eArr), newV);
}

// root�� ã�� ����
int Find(MST* mst, int v) {

	int root;

	for (root = v; mst->vArr[root] != root; root = mst->vArr[root]) {}

	return root;
}

// set ��ġ�� ����
void Union(MST* mst, int v1, int v2) {
	mst->vArr[v2] = Find(mst, v1);
}

void MakeMST(Graph* graph, MST * mst) {

	// MST �ʱ�ȭ
	mst->numV = graph->numV;
	mst->numE = 0;
	mst->mstEdge = (edge*)malloc(sizeof(edge) * (mst->numV));
	mst->flag = FALSE;
	for (int i = 0; i < graph->eArr.newpos; ++i) {
		mst->vArr[graph->eArr.pqArr[i].v1] = graph->eArr.pqArr[i].v1;
		mst->vArr[graph->eArr.pqArr[i].v2] = graph->eArr.pqArr[i].v2;
	}

	edge e = PQEdgePop(&(graph->eArr));

	// ���� edge�� ���� ������ ������!
	while (e.cost != 0) {
		// cycle�� �ȸ�������ٸ�!
		if (Find(mst, e.v1) != Find(mst, e.v2)) {
			Union(mst, e.v1, e.v2);
			mst->mstEdge[++(mst->numE)] = e;
		}
		// cycle�� ��������ٸ�!
		e = PQEdgePop(&(graph->eArr));
		// edge���� vertice�� - 1 �̸� ����
		if (mst->numE == mst->numV - 1)
			break;
	}
	
	// MST�� ��������ٸ� TRUE�� �ٲ۴�!
	if (mst->numE == mst->numV - 1)
		mst->flag = TRUE;

}

void PrintMSTEdge(MST* mst) {

	if (mst->flag == TRUE) {
		printf("Kruskal's algorithm�� �̿��� minimum cost spanning tree ���� : {");
		for (int i = 1; i <= (mst->numE); ++i) {
			printf(" (%d, %d)", mst->mstEdge[i].v1, mst->mstEdge[i].v2);
		}
		printf(" }\n");
	}
	else {
		printf("No MST EXISTS.\n");
	}
		return;
}