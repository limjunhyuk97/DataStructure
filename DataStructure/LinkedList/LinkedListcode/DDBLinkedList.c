#include "DDBLinkedList.h"

void ListInit(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));
	list->head->prev = NULL;
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->tail->next = NULL;
	list->numOfData = 0;
}

void ListInsert(List* list, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->tail;
	newNode->prev = list->tail->prev;
	list->tail->prev->next = newNode;
	list->tail->prev = newNode;
	++(list->numOfData);
}

int LFirst(List* list, LData* data) {
	if (list->head->next == list->tail)
		return FALSE;
	list->cur = list->head->next;
	*data = list->cur->data;
	return TRUE;
}

int LNext(List* list, LData* data) {
	if (list->cur->next == list->tail)
		return FALSE;
	list->cur = list->cur->next;
	*data = list->cur->data;
	return TRUE;
}

LData LRemove(List* list) {
	Node* tmpNode = list->cur;
	LData tmpData = list->cur->data;
	list->cur->prev->next = list->cur->next;
	list->cur->next->prev = list->cur->prev;
	list->cur = list->cur->prev;
	free(tmpNode);
	--(list->numOfData);
	return tmpData;
}

int LCount(List* list) {
	return list->numOfData;
}
