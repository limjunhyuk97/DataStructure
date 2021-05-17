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
	
	//// min : ��� ���ŵ� + distance�� �����ϴ� ���� ���� edge cost ��
	int min = INT_MAX;

	// minpos : index��ġ ����
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

// v1�� source, v2�� destination
void FindSPath(SPath* sPath, Graph* graph) {

	// ���ͽ�Ʈ�󿡼� ���� vertex�� ����Ű�� ���� ����ϴ� next
	char src, dst;
	int next;

	printf(INPUTSVERTEX);
	scanf_s("%c", &src, 1); while (getchar() != '\n') {}
	printf(INPUTEVERTEX);
	scanf_s("%c", &dst, 1); while (getchar() != '\n') {}

	sPath->srcV = src - 65;
	sPath->dstV = dst - 65;

	// �ʱ�ȭ ����
	for (int i = 0; i < graph->numV; ++i) {
		// ���� �ƹ� vertex�� �鸰���� �����ϴ�.
		sPath->found[i] = FALSE;
		// src vertex ������ distance�� �Ҵ����ݴϴ�.
		sPath->distance[i] = graph->adjacencyMatrix[sPath->srcV][i];
		if (sPath->distance[i] < INT_MAX)
			sPath->pI[i] = sPath->srcV;
		else
			sPath->pI[i] = i;
	}

	// src vertex�� �������� ����ݴϴ�.
	sPath->found[sPath->srcV] = TRUE; 
	sPath->distance[sPath->srcV] = 0;

	// src���� dest�� ���� ���� Ž�� ����!
	for (int i = 0; i < graph->numV - 1; ++i) {
		
		// ���� vertex�� ���� ������ �ұ�
		next = chooseVertex(sPath, graph->numV);

		// ���� vertex�� ���� ó��
		sPath->found[next] = TRUE;

		// ���� vertex�� ����� ���׿� ���ؼ� ������ �κе��� ó��
		for (int j = 0; j < graph->numV; ++j) {

			// ���� set�� ������ ���� vertex�� ���ؼ�!
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
