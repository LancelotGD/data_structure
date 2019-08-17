#include <iostream>
#include <vector>
using namespace std;
void COUNTSORT(int a[],int k) {
	int b[10];
	vector<int> c(k+1, 0);
	for (int i = 0;i<9; i++) {
		++c[a[i]];
	}
	for (int i = 1; i <= k; ++i) {
		c[i] = c[i] + c[i - 1];
	}
	for (int j = 9; j >= 1; --j) {
		b[c[a[j - 1]]] = a[j - 1];
		c[a[j - 1]]--;
	}
	for (int i = 1; i <= 9; ++i)
		cout << b[i] << " ";
	cout << endl;
}
int main() {
	int array[9] = { 8,3,2,5,4,1,6,9,7 };
	for (int i = 0; i <= 8; ++i)
		cout << array[i]<<" ";
	cout << endl;
	COUNTSORT(array, 9);
	cout << endl;
	cin.get();
	return 0;
}