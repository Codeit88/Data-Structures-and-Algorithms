#include<iostream>
using namespace std;
struct Stack {
	int size, top = -1;
	char* ar;
};
int isempty(Stack*s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
int isoperator(char a) {
	if (a == '+' || a == '-' || a == '*' || a == '/') {
		return 1;
	}
	else
		return 0;
}
int precedence(char a) {
	if (a == '*' || a == '/') {
		return 2;
	}
	else if (a == '-' || a == '+') {
		return 1;
	}
}
int topget(Stack* s) {
	return s->ar[s->top];
}
void push(Stack* s, int val) {
	s->top += 1;
	s->ar[s->top] = val;
}
int pop(Stack* s) {
	int val = s->ar[s->top];
		s->top--;
		return val;
}
void disp(Stack* s) {
	while (s->top != -1) {
		cout << " " << s->ar[s->top];
		s->top = s->top - 1;
	}
}
char* intopost(char* infix) {
	char* postfix = new char[8];
	Stack* s = new Stack[sizeof(Stack)];
	s->size = 80;
		s->top = -1;
	s->ar = new char[s->size * sizeof(char)];int i = 0, j = 0;
	while (infix[i] != '\0') {
		if (!isoperator(infix[i])) {
			postfix[j] = infix[i];
			i++;j++;
		}
		else if (precedence(infix[i]) > precedence(topget(s))) {
			push(s, infix[i]);
			i++;
		}
		else {
			postfix[j] = pop(s);
			j++;
		}
	}
	while (!isempty(s)) {
		postfix[j] = pop(s);
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}
int main() {
	char* infix{ new char[7]{'a','+','b','*','c','/','d'} };
	char* t = intopost(infix);
	for (int i = 0;t[i]!='\0';i++) {
		cout << t[i] << " ";
	}
	return 0;
}
