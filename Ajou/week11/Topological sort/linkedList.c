#include "linkedList.h"
#include <stdlib.h>

void initList(LL* ll) {
	ll->head = (node*)malloc(sizeof(node));
	ll->head->next = NULL;
	ll->tail = ll->head;
	ll->cur = ll->head;
}

void listInsert(LL* ll, Data data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	ll->tail->next = newNode;
	ll->tail = newNode;
}

int listIsEmpty(LL* ll) {
	if (ll->head == ll->tail)
		return TRUE;
	else
		return FALSE;
}

int listFirst(LL* ll, Data* data) {
	if (listIsEmpty(ll) == TRUE) {
		data = NULL;
		return FALSE;
	}
	else {
		ll->cur = ll->head->next;
		*data = ll->cur->data;
		return TRUE;
	}
}

int listNext(LL* ll, Data* data) {
	if (listIsEmpty(ll) == TRUE || ll->cur->next == NULL) {
		data = NULL;
		return FALSE;
	}
	else {
		ll->cur = ll->cur->next;
		*data = ll->cur->data;
		return TRUE;
	}
}