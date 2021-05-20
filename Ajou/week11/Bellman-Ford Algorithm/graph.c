#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


void graphInit(Graph* graph, int vertex, int edge) {
	graph->numE = edge;
	graph->numV = vertex;
	for (int i = 0; i < MAXLEN; ++i) {
		for (int j = 0; j < MAXLEN; ++j) {
			if (i == j) {
				graph->arr[i][j] = 0;
				continue;
			}
			graph->arr[i][j] = 1000;
			graph->direct[i][j] = FALSE;
		}
	}
}

void addEdge(Graph* graph, int srcV, int dstV, int cost) {
	graph->arr[srcV][dstV] = cost;
	graph->direct[srcV][dstV] = TRUE;
}

int bellmanFord(Graph* graph, int src) {

	for (int i = 0; i < graph->numV; ++i)
		graph->dist[i] = graph->arr[src][i];

	// i�� path ������ 2���� �ִ� (vetex���� - 1)������ ��츦 counting �ϴ� �� 
	for (int i = 2; i <= (graph->numV - 1); ++i) {
		// j vertex�� ���ϴ� edge�鿡 ���ؼ� ����
		for (int j = 0; j < graph->numV; ++j) {
			for (int k = 0; k < graph->numV; ++k) {
				if (graph->direct[k][j] == TRUE)
					graph->dist[j] = MIN((graph->dist[j]), (graph->dist[k] + graph->arr[k][j]));
			}
		}
	}
	for (int i = 0; i < graph->numV; ++i) {
		for (int j = 0; j < graph->numV; ++j) {
			if (graph->dist[i] > graph->dist[j] + graph->arr[j][i]) {
				return FALSE;
			}
		}
	}

	return TRUE;
}

void printPath(Graph* graph, int src) {

	int dst;

	printf(INPUTDSTVMSG);
	scanf_s("%d", &dst); while (getchar() != '\n') {}

	if (bellmanFord(graph, src) == FALSE) {
		printf(PRINTCYCLE);
	}

	else {
		printf(PRINTPLENMSG, src, dst, graph->dist[dst]);
	}
}