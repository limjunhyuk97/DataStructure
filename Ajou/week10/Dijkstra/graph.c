#include "graph.h"
#include <stdio.h>
#include <string.h>

void GraphInit(Graph* graph, int edgeNum, int vertexNum) {
	graph->numE = edgeNum;
	graph->numV = vertexNum;

	for (int i = 0; i < LEN_MAX; ++i) {
		for (int j = 0; j < LEN_MAX; ++j) {
			graph->adjacencyMatrix[i][j] = INT_MAX;
			if (i == j) graph->adjacencyMatrix[i][j] = 0;
		}
	}
}

void AddEdge(Graph* graph, int v1, int v2, int cost) {
	graph->adjacencyMatrix[v1][v2] = cost;
	graph->adjacencyMatrix[v2][v1] = cost;
}

int chooseVertex(SPath* sPath, int vertexNum) {
	
	//// min : 계속 갱신됨 + distance에 존재하는 가장 작은 edge cost 값
	int min = INT_MAX;

	// minpos : index위치 갱신
	int minpos = -1;

	for (int i = 0; i < vertexNum; ++i) {
		if (sPath->distance[i] < min && (sPath->found[i] == FALSE)) {
			minpos = i;
			min = sPath->distance[i];
		}
	}

	return minpos;
}

void printSPath(SPath* sPath) {

	int cnt = 0, p = sPath->dstV;
	char printArr[LEN_MAX];

	if (sPath->flag == FALSE) {
		printf(NOPATH);
		return;
	}

	if (sPath->distance[sPath->dstV] == 0) {
		printf(PRINTNOPATH);
		return;
	}

	printf(PRINTPATH1, sPath->srcV + 65, sPath->dstV + 65);
	while (TRUE) {
		printArr[cnt++] = sPath->pI[p] + 65;
		if (sPath->pI[p] == sPath->srcV)
			break;
		p = sPath->pI[p];
	}
	for (int i = cnt-1; i >= 0; --i) {
		printf(" %c", printArr[i]);
	}
	printf(" %c", sPath->dstV + 65);
	printf(PRINTPATH2, sPath->distance[sPath->dstV]);
}

// v1이 source, v2가 destination
void FindSPath(SPath* sPath, Graph* graph) {

	// 다익스트라에서 다음 vertex를 가리키기 위해 사용하는 next
	char src, dst;
	int next;

	printf(INPUTSVERTEX);
	scanf_s("%c", &src, 1); while (getchar() != '\n') {}
	printf(INPUTEVERTEX);
	scanf_s("%c", &dst, 1); while (getchar() != '\n') {}

	sPath->srcV = src - 65;
	sPath->dstV = dst - 65;

	// 초기화 과정
	for (int i = 0; i < graph->numV; ++i) {
		// 아직 아무 vertex도 들린적이 없습니다.
		sPath->found[i] = FALSE;
		// src vertex 기준의 distance를 할당해줍니다.
		sPath->distance[i] = graph->adjacencyMatrix[sPath->srcV][i];
		if (sPath->distance[i] < INT_MAX)
			sPath->pI[i] = sPath->srcV;
		else
			sPath->pI[i] = i;
	}

	// src vertex을 기준으로 잡아줍니다.
	sPath->found[sPath->srcV] = TRUE; 
	sPath->distance[sPath->srcV] = 0;

	// src에서 dest로 가는 과정 탐색 시작!
	for (int i = 0; i < graph->numV - 1; ++i) {
		
		// 다음 vertex를 어디로 잡아줘야 할까
		next = chooseVertex(sPath, graph->numV);

		// 다음 vertex에 대한 처리
		sPath->found[next] = TRUE;

		// 다음 vertex로 진행된 사항에 대해서 갱신할 부분들을 처리
		for (int j = 0; j < graph->numV; ++j) {

			// 아직 set에 들어오지 못한 vertex에 대해서!
			if (sPath->found[j] == FALSE) {
				if (sPath->distance[j] > sPath->distance[next] + graph->adjacencyMatrix[next][j]) {
					sPath->distance[j] = sPath->distance[next] + graph->adjacencyMatrix[next][j];
					sPath->pI[j] = next;
				}
			}
		}

	}

	if(sPath->found[sPath->dstV] == TRUE)
		sPath->flag = TRUE;

	printSPath(sPath);
}
