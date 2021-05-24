#include "graph.h"

#include <stdlib.h>
#include <stdio.h>

void initGraph(Graph* graph, int v) {
	
	graph->numV = v;
	graph->numE = 0;

	graph->predecessor = (int*)malloc(sizeof(int) * (graph->numV));
	graph->adjacencyList = (LL*)malloc(sizeof(LL) * (graph->numV));
	for (int i = 0; i < graph->numV; ++i) {
		initList(&(graph->adjacencyList[i]));
		graph->predecessor[i] = 0;
	}

}

void addEdge(Graph* graph, int v1, int v2) {

	graph->numE += 1;
	graph->predecessor[v2] += 1;
	listInsert(&(graph->adjacencyList[v1]), v2);

}

int topSort(Graph* graph) {

	Stack stack;
	initStack(&stack);
	int vertex, cnt = 0, next;

	printf(PRINTINTROMSG);

	// cycle 거르고 predecessor있는 vertex 찾기.
	for (int i = 0; i < graph->numV; ++i) {
		if (graph->predecessor[i] == 0) {
			Push(&stack, i);	// stack에게 predecessor 없는 인덱스 번호가 전달됨.
			break;
		}
	}

	for (int i = 0; i < graph->numV; ++i) {

		if (i != 0) printf(" ->");
		
		// cycle 있으면 종료한다
		if (StackIsEmpty(&stack) == TRUE) {
			printf(PRINTCYCLEMSG);
			return FALSE;
		}

		// cycle 없으면 1. 저장하고, 2. 나의 immediate successor들의 count -1, 3. 다음 index 찾기
		else {
			Pop(&stack, &vertex);
			printf(PRINTVERTEXMSG, vertex);
			for (int i = listFirst(&(graph->adjacencyList[vertex]), &next); i == TRUE; i = listNext(&(graph->adjacencyList[vertex]), &next)) {
				graph->predecessor[next] -= 1;
				if (graph->predecessor[next] == 0) {
					Push(&stack, next);
				}
			}
		}

	}

}