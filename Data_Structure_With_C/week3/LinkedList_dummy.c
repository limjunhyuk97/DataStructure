#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {


	Node* dummy = (Node*)malloc(sizeof(Node));
	Node* head = dummy;
	Node* tail = dummy;
	Node* cur = NULL;


	Node* newNode = NULL;
	int readData;

  // 데이터 입력 과정
	while (1) {
		printf("자연수 입력 : ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		// 노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");


	// 데이터를 출력하는 과정
	printf("입력받은 전체데이터 출력!\n");
	if (dummy->next != NULL) {
		cur = dummy->next;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	else {
		printf("입력받은 데이터 없음!");
	}
	printf("\n\n");


	// 메모리 해제과정
	printf("메모리 해제과정!\n");
	if (dummy->next != NULL) {
		Node* delNode = dummy->next;
		Node* delNextNode = delNode->next;
		while (delNode != NULL) {
			printf("%d 소멸~\n", delNode->data);
			free(delNode);
			delNode = delNextNode;
			delNextNode = delNode->next;
		}
	}
	else {
		printf("해제할 메모리 없음!\n");
		return 0;
	}
	
	return 0;

}
