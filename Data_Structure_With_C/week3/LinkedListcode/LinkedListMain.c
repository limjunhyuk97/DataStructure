#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"

int compareInt(LData data1, LData data2) {
	if (data1 > data2)
		return 0;
	else
		return 1;
}

int main(void) {

	List list;
	LData data;

	ListInit(&list);
	ListGetCompFunction(&list, compareInt);
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		data = rand() % 10 + 1;
		LInsert(&list, data);
	}
	printf("%d개의 입력이 들어왔다!\n\n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) {
			printf("%d\n", data);
		}
		printf("\n\n");
	}

	return 0;
}
