#include <iostream>
#include <vector>
using namespace std;
void MERGE(int a[],int p,int q,int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1+1),R(n2+1);
	for (int i = 0; i <n1; i++) {
		L[i] = a[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = a[q + j+1];
	}
	L[n1]=10000;
	R[n2]=10000;
	int i = 1, j = 1;
	for (int k = p; k <= r; k++) {
		if (L[i - 1] <= R[j - 1]) {
			a[k] = L[i-1];
			++i;
		}
		else {
			a[k] = R[j-1];
			++j;
		}
	}
}
void MERGE_SORT(int a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MERGE_SORT(a, p, q);
		MERGE_SORT(a, q+1, r);
		MERGE(a, p, q, r);
	}
}
int main() {
	int array[9] = { 8,3,2,5,4,1,6,9,7 };
	for (int i = 0; i <= 8; ++i)
		cout << array[i]<<" ";
	cout << endl;
	MERGE_SORT(array, 0, 8);
	for (int i = 0; i <= 8; ++i)
		cout << array[i] << " ";
	cout << endl;
	cin.get();
	return 0;
}