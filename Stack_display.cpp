#include<iostream>
using namespace std;
struct Stack {
	int size, top, * ar;
};
int isfull(Stack* s) {
	if (s->top == s->size) {
		return 1;
	}
	else
		return 0;
}
int isempty(Stack* s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
void push(Stack* s, int val) {
	if (isfull(s)) {
		cout << " Stack overloaded " << endl;
	}
	else
		s->top++;
	s->ar[s->top] = val;
}
void pop(Stack* s) {
	if (isempty(s)) {
		cout << " Stack underflowed \n";
	}
	else {
		s->top--;
		//s->top = s->ar[s->top - 1];
	}
}
void disp(Stack*s) {
	while (s->top != -1) {
		cout << " " << s->ar[s->top];
		s->top = s->top - 1;
	}
}
int main() {
	Stack* sp = new Stack[sizeof(Stack)];
	sp->size = 5;
	sp->top = -1;
	sp->ar = new int[sp->size * sizeof(int)];
	push(sp, 3);
	push(sp,44);
	push(sp, 14);
	pop(sp);
	pop(sp);
	push(sp,56);
	pop(sp);
	disp(sp);
	return 0;
}
