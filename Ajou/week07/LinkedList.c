#include "LinkedList.h"

void ListInit(LL* list) {

	node* newNode = malloc(sizeof(node));
	newNode->next = NULL;

	list->head = newNode;
	list->tail = newNode;
	list->cur = newNode;
}

void LInsert(LL* list, char data) {
	node *newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	
	list->tail->next = newNode;
	list->tail = newNode;
}

int LSNext(LL* list) {
	if (list->cur->next == NULL)
		return FALSE;
	else
		list->cur = list->cur->next;
	return TRUE;
}
