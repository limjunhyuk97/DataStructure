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

// root를 찾는 과정
int Find(MST* mst, int v) {

	int root;

	for (root = v; mst->vArr[root] != root; root = mst->vArr[root]) {}

	return root;
}

// set 합치는 과정
void Union(MST* mst, int v1, int v2) {
	mst->vArr[v2] = Find(mst, v1);
}

void MakeMST(Graph* graph, MST * mst) {

	// MST 초기화
	mst->numV = graph->numV;
	mst->numE = 0;
	mst->mstEdge = (edge*)malloc(sizeof(edge) * (mst->numV));
	mst->flag = FALSE;
	for (int i = 0; i < graph->eArr.newpos; ++i) {
		mst->vArr[graph->eArr.pqArr[i].v1] = graph->eArr.pqArr[i].v1;
		mst->vArr[graph->eArr.pqArr[i].v2] = graph->eArr.pqArr[i].v2;
	}

	edge e = PQEdgePop(&(graph->eArr));

	// 꺼낼 edge가 없을 때까지 꺼낸다!
	while (e.cost != 0) {
		// cycle이 안만들어진다면!
		if (Find(mst, e.v1) != Find(mst, e.v2)) {
			Union(mst, e.v1, e.v2);
			mst->mstEdge[++(mst->numE)] = e;
		}
		// cycle이 만들어진다면!
		e = PQEdgePop(&(graph->eArr));
		// edge수가 vertice수 - 1 이면 종료
		if (mst->numE == mst->numV - 1)
			break;
	}
	
	// MST가 만들어졌다면 TRUE로 바꾼다!
	if (mst->numE == mst->numV - 1)
		mst->flag = TRUE;

}

void PrintMSTEdge(MST* mst) {

	if (mst->flag == TRUE) {
		printf("Kruskal's algorithm을 이용한 minimum cost spanning tree 생성 : {");
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