#ifndef __DECLARATION_H__
#define __DECLARATION_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HEAPLEN 13
#define TRUE 1
#define FALSE 0

//ERR MSG
#define ERREMPTYHEAP "Heap�� ����ֽ��ϴ�!\n"
#define ERRFULLHEAP "Heap�� ����á���ϴ�!\n"
#define ERRDATAINVALID "%s �� Heap�� �����ϴ�!\n"
#define ERRMENUINPUT "i, d, p, e ���� ���ĺ����� �ٽ� �Է����ּ���!\n"
#define ERRDUPLICATEDATAINPUT "�̹� ���� �̸��� �����Ͱ� �ֽ��ϴ�!\n" // �Ŀ� ������ ���� �� �߻������� ���� �̿��� ����

// SUCCESS MSG
#define SUCCESSDELETE "%s �� ������\n"
#define SUCCESSINSERT "������ �����߽��ϴ�!\n"

// PRINT MSG
#define PRINTPQNODE "%s-%dKB\n"
#define PRINTMENU "\n����(i), ����(d), ���(p), ����(e) : "
#define PRINTDATAINPUT "ó���� ������ : "
#define PRINTCAPACITYINPUT "�뷮(����:KB) : "
#define PRINTDELETEDATAINPUT "������ ������ : "

// HEADER MSG
#define HEADER "5���� �ڷᱸ�� ����. 201820740 ������.\n========================\n"

#endif