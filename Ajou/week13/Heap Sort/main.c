#include "HeapSort.h"

int arr[] = { 1, 100, 200, 105, 102, 91, 88, 60, 14, 31, 12, 25, 82, 51, 7 };

int main(void) {

	int cnt = 0;
	Heap heap;

	heapInit(&heap);

	printf(BEFORESORT);
	// 힙에 정렬해 넣고
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
		printf(" %d", arr[i]);
		heapInsert(&heap, arr[i]);
	}
	printf("\n\n");

	// 정렬 결과 arr에 다시 넣는다.
	while (heapDelete(&heap, &arr[cnt++])) {}

	printf(AFTERSORT);
	// 정렬 결과 출력
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
		printf(" %d", arr[i]);
	printf("\n\n");

	return 0;
}