#include <iostream>
using namespace std;

void Hanoi(int num, char from, char by, char to) {
	if (num == 1) cout << "1짜리 원판이 " << from << "에서 " << to << "로 이동했다." << endl;
	// 기저사례
	else {
		Hanoi(num - 1, from, to, by);
    // num -1 개의 원판을 경유지로 보내고
		cout << num << "짜리 원판이 " << from << "에서 " << to << "로 이동했다." << endl;
    // 제일 큰 원판을 종착지로 보내고
		Hanoi(num - 1, by, from, to);
    // 경유지에 있던 num-1 개의 원판을 종착지로 다시 보내고~
	}
}

int main(void) {

	int cnt;
	cout << "조각의 갯수 : ";
	cin >> cnt;

	Hanoi(cnt, 'A', 'B', 'C');

	return 0;
}
