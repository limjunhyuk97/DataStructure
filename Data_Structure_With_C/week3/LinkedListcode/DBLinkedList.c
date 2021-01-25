#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _DLinkedList {
	Node* head;
	Node* cur;
	int numOfList;
}LinkedList;

typedef LinkedList List;

void ListInit(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
	list->head->prev = NULL;
	list->numOfList = 0;
}

void LInsertRight(List* list, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	newNode->prev = list->head;
	if (newNode->next != NULL)
		newNode->next->prev = newNode;
	++(list->numOfList);
}

void LInsertLeft(List* list, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = list->head->prev;
	list->head->prev = newNode;
	newNode->next = list->head;
	if (newNode->prev != NULL)
		newNode->prev->next = newNode;
	++(list->numOfList);
}

int LFirst(List* list, LData* data) {
	if (list->head->next == NULL && list->head->prev == NULL)
		return FALSE;
	else if (list->head->next == NULL) {
		list->cur = list->head->prev;
		*data = list->cur->data;
	}
	else if (list->head->prev == NULL) {
		list->cur = list->head->next;
		*data = list->cur->data;
	}
	else {
		list->cur = list->head;
	}
		
	return TRUE;
}

int LNext(List* list, LData* data) {
	if (list->cur->next == NULL || list->cur->next == list->head)
		return FALSE;

	list->cur = list->cur->next;
	*data = list->cur->data;
	return TRUE;
}

int LPrevious(List* list, LData* data) {
	if (list->cur->prev == NULL || list->cur->prev == list->head)
		return FALSE;
	list->cur = list->cur->prev;
	*data = list->cur->data;
	return TRUE;
}

LData LRemove(List* list) {
	Node* tmpNode = list->cur;
	LData tmpData = list->cur->data;
	list->cur->next->prev = list->cur->prev;
	list->cur->prev->next = list->cur->next;
	free(tmpNode);
	--(list->numOfList);
	return tmpData;
}

int LCount(List* list) {
	return list->numOfList;
}

int main(void) {
	List list;
	LData data;

	ListInit(&list);
	LInsertRight(&list, 1);
	LInsertRight(&list, 2);
	LInsertRight(&list, 3);
	LInsertRight(&list, 4);
	LInsertRight(&list, 5);
	LInsertRight(&list, 6);
	LInsertRight(&list, 7);

	printf("전체수 : %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
		while (LPrevious(&list, &data)) {
			printf("%d\n", data);
		}
	}
	printf("\n\n");

	return 0;
}
