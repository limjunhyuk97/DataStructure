#include <stdio.h>
#define BEFORESELSORTMSG "정렬할 데이터:"
#define AFTERSELSORTMSG "Selection Sort:"

void swap(int* n, int* m) {
	int tmp = *n;
	*n = *m;
	*m = tmp;
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		printf(" %d", arr[i]);
	}
	printf("\n\n");
}

void SelectionSort(int arr[], int n) {

	int i, j;

	printf(BEFORESELSORTMSG);
	printArr(arr, n);

	for (i = 0; i < n-1; ++i) {
		int index = i;
		for (j = i + 1; j < n; ++j) {
			if (arr[index] > arr[j])
				index = j;
		}
		swap(&arr[i], &arr[index]);
	}

	printf(AFTERSELSORTMSG);
	printArr(arr, n);

}

int main(void) {

	int arr[] = { 1, 300, 200, 104, 101, 91, 88, 60, 15, 31, 12, 26, 82, 51, 6 };

	SelectionSort(arr, sizeof(arr) / sizeof(int));

	return 0;
}
