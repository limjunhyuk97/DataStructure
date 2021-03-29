#include "DBLLinkedList.h"
#define MENUMSG "1. �߰�, 2. ����, 3.���, 4.���� ���, 5. ����\n"
#define INPUT "\"�Է�\" : "
#define PRINT "\"���\"  "
#define REVERSEPRINT "\"���� ���\"  "
#define DELETE "\"����\" : "
#define ERRMSG_MENUFLAGINPUT "\"�߸��� �Է��Դϴ�\"\n"
#define ERRMSG_INSERT "\"�ߺ��� �������Դϴ�\"\n"
#define SUCCESSMSG "�����߽��ϴ�\n"

int main(void) {

	int menuFlag = 0, num = 0, ProgramFlag = 1;
	List newList; ListInit(&newList);

	while (ProgramFlag) {
		printf(MENUMSG);
		scanf_s("%d", &menuFlag);
		switch (menuFlag) {
		case 1:
			printf(INPUT); scanf_s("%d", &num);
			if (LInsert(&newList, num)) printf(SUCCESSMSG);
			else printf(ERRMSG_INSERT);
			break;
		case 2:
			printf(DELETE); scanf_s("%d", &num);
			LDelete(&newList, num);
			break;
		case 3:
			printf(PRINT); LPrint(&newList);
			break;
		case 4:
			printf(REVERSEPRINT); LRPrint(&newList);
			break;
		case 5:
			ProgramFlag = 0;
			break;
		default:
			printf(ERRMSG_MENUFLAGINPUT);
			break;
		}

	}

}