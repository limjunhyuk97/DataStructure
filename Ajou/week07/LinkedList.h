#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "Declaration.h"

typedef struct node {
	char data;
	struct node* next;
}node;

typedef struct LinkedList {
	node* head;
	node* tail;
	node* cur;
}LL;

void ListInit(LL* list);
void LInsert(LL* list, char data);
int LSNext(LL* list);

#endif