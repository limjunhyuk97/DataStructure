#include "MaxHeap.h"

int main(void) {

	char FLAG = 1;

	Heap pq;
	PQInit(&pq);

	printf(HEADER);
	
	while (FLAG) {
		printf(PRINTMENU);
		scanf_s("%c", &FLAG, 1);

		switch (FLAG) {
		case 'i':
			PQInsert(&pq);
			break;
		case 'd':
			PQDelete(&pq);
			break;
		case 'p':
			PQPrint(&pq);
			break;
		case 'e':
			FLAG = 0;
			break;
		default:
			printf(ERRMENUINPUT);
			break;
		}

		while (getchar() != '\n') {}
	}



	return 0;
}