#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAXLEN 10
#define TRUE 1
#define FALSE 0
#define INPUTDSTVMSG "���� vertex�� �Է��ϼ��� : "
#define PRINTPLENMSG "Vertex %d������ Vertex %d������ shortest path�� ���̴� %d�Դϴ�.\n"
#define PRINTCYCLE "Graph�� cycle�� �ֽ��ϴ�.\n"
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