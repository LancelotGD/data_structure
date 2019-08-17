#include <iostream>
#include <vector>
using namespace std;

typedef struct Node{
	Node(int val):num(val),next(NULL){}
	int num;
	Node *next;
}node;

void bucketsort(int a[], int length) {
	vector<node*> b(length);
	for (int i = 0; i < length; i++) {
		b[a[i] / 10] = node_insert(b[a[i] / 10],a[i]);
	}
	//ºÏ²¢Á´±í
	for (int i = 0; i < length; i++) {
		node* head = b[i];
		while (head != NULL) {
			cout << head->num << ' ';
			head = head->next;
		}
	}
}

node* node_insert(node* head, int val) {
	node* prehead = head;
	if (val < (head->num)) {
		node *a = new node(val);
		a->next = head;
		head = a;
		return head;
	}
	else {
		while (head->next != NULL && val > (head->num)) {
			head = (head->next);
		}
		if (head->next != NULL && val < (head->num)) {
			node* a = new node(val);
			a->next = head;
			head = a;
		}
		else if (head->next == NULL) {
			if (val < (head->num)) {
				node *a = new node(val);
				a->next = head;
			}
			else {
				node *a = new node(val);
				head->next = a;
				head = a;
			}
		}
		return prehead;
	}
}

int main() {
	int a[] = { 53, 3, 42, 78, 14, 24, 15, 63, 36 };
	for (int i = 0; i <= 8; ++i)
		cout << a[i]<<" ";
	cout << endl;
	int length = sizeof(a) / sizeof(int);
	
	bucketsort(a,length);
	cin.get();
	return 0;
}