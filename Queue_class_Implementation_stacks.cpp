#include<iostream>
using namespace std;
class Queue {
	int top;
	int* arr;
public:
	Queue() {
		top = -1;
		arr = new int[5];//hardcoded size is 5
	}
	void push(Queue*q1,int val) {
		q1->top+=1;
		q1->arr[top] = val;
	}
	int pop(Queue*q1) {
		return q1->arr[top--];
	}
	bool isempty() {
		if (top == -1) {
			return true;
		}
		else false;
	}
	bool isfull() {
		if (top == 5) {
			return true;
		}
		return false;
	}
	void enqueue(int val) {
		top++;
		arr[top] = val;
	}
	int dequeue() {
		Queue* q2=new Queue;
		for (int i = 0;i < 5;i++) {
			int a = pop(this);
			push(q2, a);
		}
		int b=	pop(q2);
		return b;
	}
	void print() {
		for (int i = 4;i >= 0;i--) {
			cout << arr[i] << " ";
		}
	}
};

int main() {
	Queue q1;
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(65);
	q1.enqueue(21);
	q1.enqueue(42);
	q1.print();
	cout << endl << q1.dequeue() << endl;
	return 0;
}
