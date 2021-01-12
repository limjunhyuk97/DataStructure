#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_LEN 100

typedef int LData;
typedef struct __ArrayList {
    LData arr[MAX_LEN];
    int currentpos;
    int listlen;
}ArrayList;
typedef ArrayList List;

void ListInit(List* plist) {
    plist->currentpos = -1;
    plist->listlen = 0;
}

void ListInsert(List* plist, LData data) {
    if ((plist->listlen) >= MAX_LEN) {
        puts("list is full\n");
        return;
    }
    arr->plist[(plist->listlen)++] = data;
}

int ListFirst(List* plist, LData* data) {
    if (plist->listlen == 0)
        return FALSE;

    plist->currentpos = 0;
    *data = plist->arr[plist->currentpos];
    return TRUE;
}

int ListNext(List* plist, LData* data) {
    if ((plist->listlen) - 1 <= (plist->currentpos))
        return FALSE;

    *data = plist->arr[++(plist->currentpos)];
    return TRUE;
}

LData LRemove(List* plist) {
    LData removed = plist->arr[plist->currentpos];
    for (int i = (plist->currentpos); i < (plist->listlen) - 1; ++i) {
        plist->arr[i] = plist->arr[i + 1];
    }

    --(plist->currentpos);
    --(plist->listlen);
    return removed;
}

int ListCount(List* plist) {
    return plist->listlen;
}

// 함수 : list 초기화, 항목추가, 첫번째 항목 반환, 다음 항목 반환, 항목 제거, 항목 수 반환
