// n개 중에 m개를 모두 고르는 재귀 함수.

#include <iostream>
#include <vector>
using namespace std;

void PickMFromN(int start, int end, vector <int> arr, int topick);
void printAll(vector <int> arr);
int main(void) {

	int num;
	int pick;
	cout << "1부터 n까지 숫자 (n의 값) : "; cin >> num;
	cout << "고를 숫자의 갯수 : "; cin >> pick;
	
	vector <int> arr;
	PickMFromN(1, num, arr, pick);

	return 0;
}
void PickMFromN(int start, int end, vector <int> arr, int topick) {
	if (topick == 0) {
		printAll(arr);
		return;
	}

	for (int i = start; i <= end; ++i) {
		arr.push_back(i);
		PickMFromN(i + 1, end, arr, topick - 1);
		arr.pop_back();
	}

}
void printAll(vector <int> arr) {
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] <<" ";
	cout << endl;
	return;
}
