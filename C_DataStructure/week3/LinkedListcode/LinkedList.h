#ifndef __LinkedList_H__
#define __LinkedList_H__
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedlist {
	Node* head;
	Node* cur;
	Node* before;
	int (*comp)(LData data1, LData LData2);
	int listLen;
}LinkedList;

typedef LinkedList List;

void ListInit(List* list);

void ListGetCompFunction(List* list, int(*comp)(LData data1, LData data2));

void CInsert(List* list, LData data);
void NInsert(List* list, LData data);
void LInsert(List* list, LData data);

int LFirst(List* list, LData* data);
int LNext(List* list, LData* data);

LData LRemove(List* list);
int LCount(List* list);

#endif
