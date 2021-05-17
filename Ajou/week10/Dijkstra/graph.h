#ifndef __GRAPH_H__
#define __GRAPH_H__

#define INPUTSVERTEX "출발 vertex를 입력하세요 : "
#define INPUTEVERTEX "도착 vertex를 입력하세요 : "
#define NOPATH "shortest path가 존재하지 않습니다.\n"
#define PRINTNOPATH "출발지와 도착지가 일치합니다! (경로가 없습니다.)\n"
#define PRINTPATH1 "Vertex %c에서 Vertex %c로 가는 최단 경로는"
#define PRINTPATH2 "이며, 이때 최단거리는 %d입니다.\n"

#define INT_MAX 1000
#define MAX_LEN 10
#define TRUE 1
#define FALSE 0

enum nodeName {A, B, C, D, E, F, G};

typedef struct AMGraph {
	int numE;
	int numV;
	int adjacencyMatrix[MAX_LEN][MAX_LEN];
}Graph;

typedef struct Dijkstra {
	
	int srcV;
	int dstV;
	short flag;
	
	// found, distance, pI는 시작 vertex 기준이 될것이다.
	short found[MAX_LEN];
	int distance[MAX_LEN];
	int pI[MAX_LEN];

}SPath;

void GraphInit(Graph* graph, int edgeNum, int vertexNum);

void AddEdge(Graph* graph, int v1, int v2, int cost);

void FindSPath(SPath* sPath, Graph* graph);

#endif