#include "HeapSort.h"

int arr[] = { 1, 100, 200, 105, 102, 91, 88, 60, 14, 31, 12, 25, 82, 51, 7 };

int main(void) {

	int cnt = 0;
	Heap heap;

	heapInit(&heap);

	printf(BEFORESORT);
	// ���� ������ �ְ�
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
		printf(" %d", arr[i]);
		heapInsert(&heap, arr[i]);
	}
	printf("\n\n");

	// ���� ��� arr�� �ٽ� �ִ´�.
	while (heapDelete(&heap, &arr[cnt++])) {}

	printf(AFTERSORT);
	// ���� ��� ���
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
		printf(" %d", arr[i]);
	printf("\n\n");

	return 0;
}