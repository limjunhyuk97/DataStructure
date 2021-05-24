#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	struct node* next;
	Data data;
}node;

typedef struct LinkedList {
	node* cur;
	node* tail;
	node* head;
}LL;

void initList(LL* ll);

void listInsert(LL* ll, Data data);

int listFirst(LL* ll, Data *data);

int listNext(LL* ll, Data* data);

int listIsEmpty(LL* ll);

#endif 
