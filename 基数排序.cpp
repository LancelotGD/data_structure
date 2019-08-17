#include <iostream>
#include <vector>
using namespace std;

int getmax(int a[], int length) {
	int max = a[0];
	for (int i = 1; i < length; i++) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}

void basesort(int a[],int length,int exp) {
	vector<int>output(length, 0);
	int temp = 0;
	for (int i = 0; i < length; i++)
		output[i] = (a[i] / exp) % 10;
	for (int i = 0; i <length-1; i++) {
		for (int j = i+1; j < length; j++) {
			if (output[i] > output[j]) {
				temp = output[i];
				output[i] = output[j];
				output[j] = temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

}

void radicalsort(int a[], int length) {
	int max=getmax(a, length);
	for (int exp = 1; max / exp > 0; exp *= 10)
		basesort(a, length, exp);
}
int main() {
	int a[] = { 53, 3, 542, 748, 14, 214, 154, 63, 616 };
	for (int i = 0; i <= 8; ++i)
		cout << a[i]<<" ";
	cout << endl;
	int length = sizeof(a) / sizeof(int);
	radicalsort(a, length);
	for (int i = 0; i <= 8; ++i)
		cout << a[i] << " ";
	cout << endl;
	cin.get();
	return 0;
}