#include "CLinkedListDummy.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* list) {
	list->tail = (Node*)malloc(sizeof(Node));
	list->tail->next = list->tail;
	list->cur = NULL;
	list->before = NULL;
	list->numOfData = 0;
}

// 머리에 넣기
void LInsert(List* list, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = list->tail->next;
	list->tail->next = newNode;
	++(list->numOfData);
}

int LFirst(List* list, LData* data) {
	if (list->tail->next == list->tail)
		return FALSE;

	list->before = list->tail;
	list->cur = list->tail->next;
	*data = list->cur->data;
	return TRUE;
}

// 순환참조 가능한 LNext
int LNext(List* list, LData* data) {
	if (list->cur->next == list->tail) {
		LFirst(list, data);
	}
	else {
		list->before = list->cur;
		list->cur = list->before->next;
		*data = list->cur->data;
		return TRUE;
	}
}

LData LRemove(List* list) {
	Node* tmpNode = list->cur;
	LData tmpData = list->cur->data;

	list->before->next = list->cur->next;
	list->cur = list->before;
	free(tmpNode);

	--(list->numOfData);
	return tmpData;
}

int LCount(List* list) {
	return list->numOfData;
}
