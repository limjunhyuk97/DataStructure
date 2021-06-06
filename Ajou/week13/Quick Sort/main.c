#include <stdio.h>

int arr[] = { 1, 100, 200, 105, 102, 91, 88, 60, 14, 31, 12, 25, 82, 51, 7 };

void swap(int* n, int* m) {
	int tmp;
	tmp = *n;
	*n = *m;
	*m = tmp;
}

void quickSort(int arr[], int start, int end) {

	int low = start + 1, high = end, pivot = start;

	if (start > end)
		return;

	while (low <= high) {

		while (arr[low] < arr[pivot])
			low++;
		
		while (arr[high] > arr[pivot])
			high--;

		if (low <= high)
			swap(&arr[low], &arr[high]);

	}

	swap(&arr[high], &arr[pivot]);

	quickSort(arr, start, high - 1);
	quickSort(arr, high + 1, end);
}

int main(void) {

	printf("정렬할 데이터:");
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
		printf(" %d", arr[i]);
	printf("\n\n");

	quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	printf("Quick Sort:");
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
		printf(" %d",arr[i]);
	printf("\n\n");

	return 0;
}