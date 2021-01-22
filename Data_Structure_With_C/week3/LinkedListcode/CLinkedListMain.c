#include "CLinkedListDummy.h"
#include <stdlib.h>
#include <time.h>
int main(void) {

	List list;
	LData data;
	int remove;
	int tmpLen;
	srand((unsigned int)time(NULL));

	ListInit(&list);
	for (int i = 0; i < 10; ++i) {
		LInsert(&list, rand()%10 +1);
	}

	printf("%d개의 정보 3번 출력\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		for (int i = 2; i < LCount(&list) * 3 + 1; ++i) {
			LNext(&list, &data);
			printf("%d\n", data);
			if (i % 10 == 0)
				printf("\n");
		}
	}

	printf("몇 배수 제거? : ");
	scanf_s("%d", &remove);
	tmpLen = LCount(&list);
	if (LFirst(&list, &data)) {
		if (data % remove == 0)
			LRemove(&list);
		for (int i = 0; i < tmpLen - 1; ++i) {
			LNext(&list, &data);
			if (data % remove == 0)
				LRemove(&list);
		}
	}

	printf("%d개의 정보 출력\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		for (int i = 0; i < LCount(&list) - 1; ++i) {
			LNext(&list, &data);
			printf("%d\n", data);
		}
	}

	return 0;
}
