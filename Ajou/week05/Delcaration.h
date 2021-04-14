#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HEAPLEN 13
#define TRUE 1
#define FALSE 0

//ERR MSG
#define ERREMPTYHEAP "Heap이 비어있습니다!\n"
#define ERRFULLHEAP "Heap이 가득찼습니다!\n"
#define ERRDATAINVALID "%s 가 Heap에 없습니다!\n"
#define ERRMENUINPUT "i, d, p, e 중의 알파벳으로 다시 입력해주세요!\n"
#define ERRDUPLICATEDATAINPUT "이미 동일 이름의 데이터가 있습니다!\n" // 후에 데이터 삭제 시 발생가능한 문제 미연에 방지

// SUCCESS MSG
#define SUCCESSDELETE "%s 가 삭제됨\n"
#define SUCCESSINSERT "삽입이 성공했습니다!\n"

// PRINT MSG
#define PRINTPQNODE "%s-%dKB\n"
#define PRINTMENU "\n삽입(i), 삭제(d), 출력(p), 종료(e) : "
#define PRINTDATAINPUT "처리할 데이터 : "
#define PRINTCAPACITYINPUT "용량(단위:KB) : "
#define PRINTDELETEDATAINPUT "삭제할 데이터 : "

// HEADER MSG
#define HEADER "5주차 자료구조 과제. 201820740 임준혁.\n========================\n"

#endif