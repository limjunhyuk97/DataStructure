#include "StackInCLinkedList.h"

void StackInit(Stack* pstack) {
	/*
	* pstack 내에는 List의 포인터인 plist가 있을 뿐이다.
	* List list와 List *plist는 당연히 다르다.
	* list는 내부에 공간들이 마련되있지만, plist는 List변수를 가리킬 수 있는 포인터일 뿐이다.
	*/
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack* pstack) {
	if (!LCount(pstack->plist))
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, SData data) {
	LInsertFront(pstack->plist, data);
}

SData SPop(Stack* pstack) {
	SData data;
	LFirst(pstack->plist, &data);
	data = LRemove(pstack->plist);
	return data;
}

SData SPeek(Stack* pstack) {
	SData data;
	LFirst(pstack->plist, &data);
	return data;
}
