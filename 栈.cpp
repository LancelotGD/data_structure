#include <iostream>

using namespace std;

typedef struct stack {
	int top=0;
	int a[10] = { 0 };
}stack;

bool stack_empty(stack s) {
	if (s.top == 0)
		return true;
	else
		return false;
}

void push(stack& s, int x) {
	if (s.top == 9) {
		cerr << "overflow" << endl;
	}
	else {
		s.top = s.top + 1;
		s.a[s.top] = x;
	}
}

void pop(stack &s) {
	if (stack_empty(s))
		cerr << "downflow" << endl;
	else {
		--s.top;
	}
}

void show_stack(stack& s){
	for (int i = 1; i <= s.top; i++)
		cout << s.a[i];
	cout << endl;
}
int main() {
	stack s;
	show_stack(s);
	push(s, 6);
	push(s, 3);
	show_stack(s);
	pop(s);
	show_stack(s);
	pop(s);
	show_stack(s);
	pop(s);
	cin.get();
	return 0;
}