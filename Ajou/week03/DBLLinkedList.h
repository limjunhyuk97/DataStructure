#ifndef __DBL_LINKED_LIST_H__
#define __DBL_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct node {
	struct node* next;
	struct node* before;
	LData data;
}Node;

typedef struct _LinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int (*compFunc)(LData, LData);
}List;

void ListInit(List* list);
int LEmpty(List* list);

int LInsert(List* list, LData data);
void LDelete(List* list, LData data);

void LPrint(List* list);
void LRPrint(List* list);

#endif
