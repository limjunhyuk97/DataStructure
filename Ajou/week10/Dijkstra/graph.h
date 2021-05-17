#ifndef __GRAPH_H__
#define __GRAPH_H__

#define INPUTSVERTEX "��� vertex�� �Է��ϼ��� : "
#define INPUTEVERTEX "���� vertex�� �Է��ϼ��� : "
#define NOPATH "shortest path�� �������� �ʽ��ϴ�.\n"
#define PRINTNOPATH "������� �������� ��ġ�մϴ�! (��ΰ� �����ϴ�.)\n"
#define PRINTPATH1 "Vertex %c���� Vertex %c�� ���� �ִ� ��δ�"
#define PRINTPATH2 "�̸�, �̶� �ִܰŸ��� %d�Դϴ�.\n"

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
	
	// found, distance, pI�� ���� vertex ������ �ɰ��̴�.
	short found[MAX_LEN];
	int distance[MAX_LEN];
	int pI[MAX_LEN];

}SPath;

void GraphInit(Graph* graph, int edgeNum, int vertexNum);

void AddEdge(Graph* graph, int v1, int v2, int cost);

void FindSPath(SPath* sPath, Graph* graph);

#endif