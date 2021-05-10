#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

#include "declaration.h"

typedef struct _disjointSet {
	
	// index : child, value : parent
	int disjointSet[MAX_LEN];

}disjointSet;

void SetInit(disjointSet * set);

void Union(int n, int m, disjointSet* set);

int Find(int n, disjointSet* set);

void PrintAllRoot(disjointSet* set);

void SetCheck(disjointSet* set);

#endif