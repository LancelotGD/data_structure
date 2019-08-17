#include <iostream>

using namespace std;
int PARTITION(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	int temp = 0;
	for (int j = p; j <= r - 1; j++) {
		if (a[j] <= x){
		++i;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}
void QUICKSORT(int a[], int p, int r) {
	if (p < r) {
		int q = PARTITION(a, p, r);
		QUICKSORT(a, p, q - 1);
		QUICKSORT(a, q + 1, r);
	}
}
int main() {
	int array[9] = { 8,3,2,5,4,1,6,9,7 };
	for (int i = 0; i <= 8; ++i)
		cout << array[i]<<" ";
	cout << endl;
	QUICKSORT(array, 0, 8);
	for (int i = 0; i <= 8; ++i)
		cout << array[i] << " ";
	cout << endl;
	cin.get();
	return 0;
}