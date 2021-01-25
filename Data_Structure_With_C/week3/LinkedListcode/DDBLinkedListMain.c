#include "DDBLinkedList.h"
#include <stdlib.h>
#include <time.h>

int main(void) {

	List list;
	LData data, tmp;

	// list 초기화
	ListInit(&list);
	srand((unsigned int)time(NULL));

	// list 삽입
	for (int i = 0; i < 10; ++i) {
		ListInsert(&list, rand() % 20 + 1);
	}

	// list 순환 출력
	printf("list에 저장된 수의 갯수 : %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}

	// list 원하는 수 제거
	printf("무슨 수 제거? : ");
	scanf_s("%d", &tmp);
	if (LFirst(&list, &data)) {
		if (data == tmp)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data == tmp)
				LRemove(&list);
		}
	}

	// list 순환 출력
	printf("list에 저장된 수의 갯수 : %d\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
	}

	return 0;
}
