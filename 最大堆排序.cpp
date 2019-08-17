#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void heapbuild(int a[],int root,int length) {
	int lchild = root * 2 + 1;
	if (lchild < length) {
		int flag = lchild;
		int rchild = lchild + 1;
		if (rchild < length) {
			if (a[rchild] > a[flag]) {
				flag = rchild;
			}
		}
		if (a[flag] > a[root]) {
			swap(a[flag], a[root]);
		}
		if (flag * 2 + 1 < length) {
			heapbuild(a, flag, length);
		}
	}

}

void heapsort(int a[],int length) {
	for (int i = length / 2; i >= 0; --i) {
		heapbuild(a, i, length);
	}

}


int main() {
	int a[9] = { 53, 3, 42, 78, 14, 24, 15, 63, 36 };
	for (int i = 0; i <= 8; ++i)
		cout << a[i]<<"  ";
	cout << endl;
	int length = sizeof(a) / sizeof(int);
	heapsort(a, 8);
	for (int j = length-1; j > 0; j--) {
		cout << a[0]<<"  ";
		swap(a[0], a[j]);
		heapsort(a, j);
	}
	cout << a[0];

	cin.get();
	return 0;
}