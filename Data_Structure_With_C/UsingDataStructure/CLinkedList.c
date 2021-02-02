#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* list) {
	list->numOfData = 0;
	list->tail = NULL;
	list->before = NULL;
	list->cur = NULL;
}

// 꼬리에 노드 추가
void LInsert(List* list, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (list->tail == NULL) {
		list->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = list->tail->next;
		list->tail->next = newNode;
		list->tail = newNode;
	}
	++(list->numOfData);
}

// 머리에 노드 추가
void LInsertFront(List* list, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (list->tail == NULL) {
		list->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = list->tail->next;
		list->tail->next = newNode;
	}
	++(list->numOfData);
}

int LFirst(List* list, LData* data) {
	if (list->tail == NULL)
		return FALSE;
	list->before = list->tail;
	list->cur = list->before->next;
	*data = list->cur->data;
	
	return TRUE;
}

int LNext(List* list, LData* data) {
	if (list->tail == NULL)
		return FALSE;
	list->before = list->cur;
	list->cur = list->before->next;
	*data = list->cur->data;

	return TRUE;
}

LData LRemove(List* list) {

	Node* tmpNode = list->cur;
	LData tmpData = list->cur->data;

	if (tmpNode == list->tail) {
		if (list->tail->next == list->tail)
			list->tail = NULL;
		else {
			list->tail = list->before;
		}
	}

	list->before->next = list->cur->next;
	list->cur = list->before;

	free(tmpNode);
	--(list->numOfData);

	return tmpData;
	
	// 예외1) tail이 삭제할 노드인 경우
	// 예외2) 삭제할 노드가 홀로 남은 경우
}

int LCount(List* list) {
	return list->numOfData;
}
