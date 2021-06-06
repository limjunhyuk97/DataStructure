#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#include <stdio.h>

#define MAXLEN 100
#define TRUE 1
#define FALSE 0

#define BEFORESORT "������ ������:"
#define AFTERSORT "Heap Sort:"

typedef int Data;

typedef struct Heap{
	Data arr[100];
	int heapCount;
}Heap;

void heapInit(Heap* heap);

void heapInsert(Heap* heap, Data data);

int heapDelete(Heap* heap, Data*data);

int heapIsEmpty(Heap* heap);

#endif
