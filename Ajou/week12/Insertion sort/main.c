#include <stdio.h>
#define BEFOREINSSORTMSG "정렬할 데이터:"
#define AFTERINSSORTMSG "Insertion Sort:"

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		printf(" %d", arr[i]);
	}
	printf("\n\n");
}

void InsertionSort(int arr[], int n) {

	int i, j;

	printf(BEFOREINSSORTMSG);
	printArr(arr, n);

	for (i = 1; i < n; ++i) {
		int ins = arr[i];
		for (j = i - 1; j >= 0; --j) {
			if (arr[j] > ins)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = ins;
	}

	printf(AFTERINSSORTMSG);
	printArr(arr, n);

}

int main(void) {

	int arr[] = { 1, 300, 200, 104, 101, 91, 88, 60, 15, 31, 12, 26, 82, 51, 6 };

	InsertionSort(arr, sizeof(arr)/ sizeof(int));

	return 0;
}