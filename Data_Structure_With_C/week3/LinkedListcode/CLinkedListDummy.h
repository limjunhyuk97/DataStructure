#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _CLL {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List* list);
void LInsert(List* list, LData data);

int LFirst(List* list, LData* data);
int LNext(List* list, LData* data);
LData LRemove(List* list);
int LCount(List* list);
