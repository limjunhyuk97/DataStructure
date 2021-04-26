#include "Graph.h"

void GraphInit(Graph* graph, char data, int args, ...) {
	graph->list = malloc(sizeof(LL));
	graph->data = data;

	ListInit(graph->list);

	va_list ap;
	va_start(ap, args);

	for (int i = 0; i < args; ++i) {
		char ch = va_arg(ap, char);
		LInsert(graph->list, ch);
	}
	va_end(ap);

}
