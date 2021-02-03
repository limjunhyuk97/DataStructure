// 배열 기반의 순차 리스트

#include <iostream>
#define MAX_LEN 50
#define TRUE 1
#define FALSE 0
using namespace std;
typedef int Ldata;

class List {
private:
	Ldata arr[MAX_LEN];
	int curcnt;
	int listnum;
public:
	List() :curcnt(-1), listnum(0) {}

	void ListInsert(Ldata data) {
		if (listnum >= MAX_LEN) {
			cout << "List is full\n";
		}

		arr[listnum] = data;
		++listnum;
	}

	int LFirst(Ldata* pdata) {
		if (listnum == 0) {
			return FALSE;
		}

		curcnt = 0;
		*pdata = arr[curcnt];
		return TRUE;
	}

	int LNext(Ldata* pdata) {
		if (listnum - 1 <= curcnt) {
			return FALSE;
		}
		*pdata = arr[++curcnt];
		return TRUE;
	}

	Ldata LRemove() {
		Ldata rdata = arr[curcnt];
		for (int i = curcnt; i < listnum - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		--listnum;
		--curcnt;
		return rdata;
	}

	int Lcount() {
		return listnum;
	}

};

int main(void) {

	List list;
	int data;

	// 5개의 데이터 저장
	list.ListInsert(11);
	list.ListInsert(11);
	list.ListInsert(22);
	list.ListInsert(22);
	list.ListInsert(33);

	// 저장된 데이터 전체 출력
	if (list.LFirst(&data)) {
		cout << data << " ";
		while (list.LNext(&data))
			cout << data << " ";
		cout << endl << endl;
	}

	// 숫자 22 모두 삭제
	if (list.LFirst(&data)) {
		if (data == 22)
			list.LRemove();
		while (list.LNext(&data))
			if (data == 22)
				list.LRemove();
	}

	// 삭제후 남은 데이터 전체 출력
	cout << "현재 데이터의 수 : " << list.Lcount()<<endl<<endl;
	if (list.LFirst(&data)) {
		cout << data << " ";
		while (list.LNext(&data))
			cout << data << " ";
		cout << endl << endl;
	}

	return 0;
}
