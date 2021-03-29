#include "DBLLinkedList.h"
#define MENUMSG "1. 추가, 2. 삭제, 3.출력, 4.역순 출력, 5. 종료\n"
#define INPUT "\"입력\" : "
#define PRINT "\"출력\"  "
#define REVERSEPRINT "\"역순 출력\"  "
#define DELETE "\"삭제\" : "
#define ERRMSG_MENUFLAGINPUT "\"잘못된 입력입니다\"\n"
#define ERRMSG_INSERT "\"중복된 데이터입니다\"\n"
#define SUCCESSMSG "성공했습니다\n"

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