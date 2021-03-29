#include "DBLLinkedList.h"

int dataCompFunc(LData data1, LData data2) {
	if (data1 > data2) return 1;
	else if (data1 == data2) return 0;
	else return -1;
}

void ListInit(List* list) {
	list->head = NULL;
	list->tail = NULL;
	list->cur = NULL;
	list->compFunc = dataCompFunc;
}

int LEmpty(List* list) {
	if (list->head == NULL && list->tail == NULL)
		return TRUE;
	else
		return FALSE;

}

int LInsert(List* list, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; newNode->before = NULL; newNode->next = NULL;

	if (LEmpty(list)) {
		list->head = newNode;
	}
	else {
		list->cur = list->head;
		// list에 하나의 값만 있는 경우
		if (list->head == list->tail) {
			if (list->compFunc(newNode->data, list->cur->data) == 1) {
				list->head->before = newNode; newNode->next = list->head; list->head = list->head->before;
				return TRUE;
			}
			else if (list->compFunc(newNode->data, list->cur->data) == 0) return FALSE;
			else {
				list->tail->next = newNode; newNode->before = list->tail; list->tail = list->tail->next;
				return TRUE;
			}
		}

		// list에 값이 여러개인 경우
		else {
			while(1){
				if (list->compFunc(newNode->data, list->cur->data) == 0) return FALSE;
				else if (list->compFunc(newNode->data, list->cur->data) == 1) {
					if(list->cur == list->head){ list->head->before = newNode; newNode->next = list->head; list->head = list->head->before; }
					else { list->cur->before->next = newNode; newNode->before = list->cur->before; list->cur->before = newNode; newNode->next = list->cur; }
					return TRUE;
				}
				if (list->cur->next == NULL) break;
				else list->cur = list->cur->next;
			}
			list->tail->next = newNode; newNode->before = list->tail; list->tail = list->tail->next;
			return TRUE;
		}

	}
	list->tail = newNode;
	return TRUE;
}

void LDelete(List* list, LData data) {
	if (LEmpty(list)) {
		printf("리스트가 비어있습니다\n");
		return;
	}
	else {
		list->cur = list->head;
		while (1) {

			if (list->compFunc(list->cur->data, data) == 0) {
				if (list->head == list->tail) { list->head = NULL; list->tail = NULL; free(list->cur); }
				else {
					if (list->cur == list->head) { list->cur->next->before = NULL; list->head = list->head->next; free(list->cur);}
					else if (list->cur == list->tail) { list->tail->before->next = NULL; list->tail = list->tail->before; free(list->cur);}
					else {
						list->cur->before->next = list->cur->next;
						list->cur->next->before = list->cur->before;
						free(list->cur);
					}
				}
				printf("성공했습니다\n");
				return;
			}

			if (list->cur->next == NULL) break;
			else list->cur = list->cur->next;
		}
		printf("찾는 값이 없습니다\n");
		return;
	}
}

void LPrint(List* list) {
	if (LEmpty(list)) {
		printf(" 리스트가 비어있습니다\n");
		return;
	}
	else {
		list->cur = list->head;
		printf("  %d", list->cur->data);
		while (list->cur->next != NULL) {
			list->cur = list->cur->next;
			printf(" %d", list->cur->data);
		}
		printf("\n끝\n");
		return;
	}
}

void LRPrint(List* list) {
	if (LEmpty(list)) {
		printf(" 리스트가 비어있습니다\n");
		return;
	}
	else {
		list->cur = list->tail;
		printf("  %d", list->cur->data);
		while (list->cur->before != NULL) {
			list->cur = list->cur->before;
			printf(" %d",list->cur->data);
		}
		printf("\n끝\n");
		return;
	}
}
