# Linked List

## 배열의 단점
  - 메모리의 길이가 정적이어서 메모리 길이 변경이 탄력적이지 못하다.
  - **필요로 하는 메모리의 크기에 유연한 대처가 불가능하다. : 동적인 메모리 구성이 요구된다.**
  
## 연결리스트(linked list)의 원리
  - **새로운 공간이 필요할 때마다, 원하는 정보와 다음 노드의 위치를 가리키는 정보를 담고 있는 노드를 동적할당하여 이들을 연결한다.**
  - 리스트 자료구조는 저장순서를 유지해야하는 자료구조가 아니다.
  - 머리 추가 연결리스트
    - 저장순서가 지켜지지 않는다
    - tail변수가 필요 없다.
  - 꼬리 추가 연결리스트
    - 저장순서가 지켜진다
    - tail변수가 필요하다.
  - 머리부분의 가장 첫번째 부분에, 아무 정보도 갖고 있지 않는 dummy node를 넣어주면 코드가 훨씬 간결해진다.
  
## 꼬리 추가 연결리스트

```cpp
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
```

## 더미노드 기반, 머리 추가 연결리스트
  - 