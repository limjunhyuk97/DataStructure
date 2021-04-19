#include "BinarySearchTree.h"

int main(void) {

	BTNode* root;
	BTNode *tmpNode;
	InitBST(&root);

	int menuNum = 0, entryCnt = 0;
	printf(INTRODUCTIONMSG);

	while (menuNum != 5) {
		printf(MENUPRINTMSG);
		printf(INPUTMENUMSG);
		scanf_s("%d", &menuNum);
		while (getchar() != '\n') {}

		switch (menuNum)
		{
		case 1:
			if (entryCnt >= 100) {
				printf(EMTRYNUMINVALIDERMSG);
				break;
			}
			if (BSTInsert(&root))
				++entryCnt;
			break;

		case 2:
			if (entryCnt <= 0) {
				printf(SEARCHINVALIDAMOUNTERRMSG);
				break;
			}
			BSTPrint(&root);
			break;

		case 3:
			if (entryCnt <= 0) {
				printf(CHANGEINVALIDAMOUNTERRMSG);
				break;
			}
			BSTChange(&root);
			break;

		case 4:
			if (entryCnt <= 0) {
				printf(CANCELINVALIDAMOUTERRMSG);
				break;
			}
			tmpNode = BSTDelete(&root);
			if (tmpNode != NULL) {
				free(tmpNode);
				--entryCnt;
			}
			break;

		case 5:
			printf(TERMINATEMSG);
			break;

		default:
			printf(INVALIDMENUMSG);
			break;
		}
	}

	return 0;
}