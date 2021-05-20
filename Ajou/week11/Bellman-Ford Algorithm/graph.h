#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAXLEN 10
#define TRUE 1
#define FALSE 0
#define INPUTDSTVMSG "도착 vertex를 입력하세요 : "
#define PRINTPLENMSG "Vertex %d번에서 Vertex %d번까지 shortest path의 길이는 %d입니다.\n"
#define PRINTCYCLE "Graph에 cycle이 있습니다.\n"
#define MIN(i, j) (i > j ? j : i)

typedef struct Graph {
	int numV;
	int numE;
	int dist[MAXLEN];
	int direct[MAXLEN][MAXLEN];
	int arr[MAXLEN][MAXLEN];
}Graph;

void graphInit(Graph* graph, int vertex, int edge);

void addEdge(Graph* graph, int srcV, int dstV, int cost);

int bellmanFord(Graph* graph, int src);

void printPath(Graph* graph, int src);

#endif