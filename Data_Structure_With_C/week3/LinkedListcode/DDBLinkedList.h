#ifndef __DDB_LINKED_LIST__
#define __DDB_LINKED_LIST__

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	struct _node* next;
	struct _node* prev;
	LData data;
}Node;

typedef struct _DDBLinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}DDBLinkedList;

typedef DDBLinkedList List;

void ListInit(List* list);
void ListInsert(List* list, LData data);

int LFirst(List* list, LData* data);
int LNext(List* list, LData* data);

LData LRemove(List* list);
int LCount(List* list);

#endif
