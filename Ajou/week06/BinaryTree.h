#include "Declaration.h"

typedef struct entry {
	int date;
	char name[22];
	char region[42];
	struct entry* lsub;
	struct entry* rsub;
}BTNode;

BTNode* makeBTNode();
void setBTNode(BTNode* bt, char *name, char *region, int date);

BTNode* getRightSubTree(BTNode* bt);
BTNode* getLeftSubTree(BTNode* bt);

void setRightSubTree(BTNode* bt, BTNode* rsub);
void setLeftSubTree(BTNode* bt, BTNode* lsub);

BTNode* deleteLeftSubTree(BTNode* bt);
BTNode* deleteRightSubTree(BTNode* bt);
