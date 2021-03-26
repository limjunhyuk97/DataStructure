#include "Ajou_Hw1_queue.h"

int main(void) {

	int input, pick;
	char name[50];
	Queue queue;
	QInit(&queue);

	do {
		memset(name, 0, 50);
		printf("\n입력대기\n");
		printf("1. 관공서 도착\n");
		printf("2. 관공서 퇴장\n");
		printf("3. 서비스 종료\n");
		printf("입력 (1 / 2 / 3 의 값으로 입력하세요) : "); scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("\n1. 대기자 등록\n");
			printf("2. 취소\n");
			printf("입력 (1 / 2 의 값으로 입력하세요) : "); scanf_s("%d", &pick);

			switch (pick) {
			case 1:
				if (Enqueue(&queue, name)) {
					printf("서비스를 제공할 수 없음(대기 인원 만원)\n");
				}
				break;
			case 2:
				break;
			default:
				printf("잘못된 input");
				break;
			}
			break;

		case 2:
			if(Dequeue(&queue, name))
				printf("고객 : %s\n", name);
			break;

		case 3:
			printf("종료");
			break;

		default:

			break;

		}

	} while (input != 3);

	return 0;
}
