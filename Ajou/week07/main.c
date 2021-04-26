#include "Graph.h"

int ch[7];

void DFS(int v, Graph **graph) {
	if (ch[v] == TRUE)
		return;

	printf("%c ", graph[v]->data);
	ch[v] = TRUE;
	while (TRUE) {
		if (LSNext(graph[v]->list)) {
			int num = graph[v]->list->cur->data - 65;
			if (ch[num] == 0)
				DFS(num, graph);
		}
		else
			break;
	}
}

int main(void) {

	Graph* graph[7];

	for (int i = 0; i < 7; ++i) {
		graph[i] = malloc(sizeof(Graph));
	}

	GraphInit(graph[0], 'A', 2, 'B', 'C');
	GraphInit(graph[1], 'B', 3, 'A', 'D', 'E');
	GraphInit(graph[2], 'C', 2, 'A', 'E');
	GraphInit(graph[3], 'D', 2, 'B', 'G');
	GraphInit(graph[4], 'E', 3, 'B', 'C', 'G');
	GraphInit(graph[5], 'F', 1, 'G');
	GraphInit(graph[6], 'G', 3, 'D', 'E', 'F');

	DFS(0, graph);

	for (int i = 0; i < 7; ++i) {
		free(graph[i]);
	}

	return 0;
}