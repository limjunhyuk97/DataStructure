#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct edge {
	int cost;
	int v1;
	int v2;
}edge;

#endif