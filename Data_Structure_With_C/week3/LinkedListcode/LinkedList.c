#include "LinkedList.h"

void ListInit(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
	list->comp = NULL;
	list->listLen = 0;
}

void ListGetCompFunction(List* list, int(*comp)(LData data1, LData data2)) {
	list->comp = comp;
}

void CInsert(List* list, LData data) {
	Node* token = list->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	while (token->next != NULL && list->comp(data, token->next->data) != 0) {
		token = token->next;
	}
	newNode->next = token->next;
	token->next = newNode;
	++(list->listLen);
}

void NInsert(List* list, LData data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	++(list->listLen);
}

void LInsert(List* list, LData data) {
	if (list->comp != NULL) {
		CInsert(list, data);
	}
	else
		NInsert(list, data);
}

int LFirst(List* list, LData* data) {
	if (list->head->next == NULL)
		return FALSE;

	list->cur = list->head->next;
	list->before = list->head;
	*data = list->cur->data;
	
	return TRUE;
}

int LNext(List* list, LData* data) {
	if (list->cur->next == NULL)
		return FALSE;

	list->before = list->cur;
	list->cur = list->cur->next;
	*data = list->cur->data;

	return TRUE;
}

LData LRemove(List* list) {
	Node* tmpNode = list->cur;
	LData tmpData = tmpNode->data;

	list->before->next = list->cur->next;
	list->cur = list->before;
	free(tmpNode);
	--(list->listLen);

	return tmpData;

}

int LCount(List* list) {
	return list->listLen;
}
