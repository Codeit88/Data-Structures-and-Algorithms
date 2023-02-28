#include<iostream>
using namespace std;
struct Queue {
	int* ar, r, f,size;
};
void disp(Queue *q) {
	while (q->r > q->f) {
		cout <<" "<< q->ar[q->r];
		q->r = q->r - 1;
	}
}
void enqeue(Queue *Q,int val) {
	Q->r++;
	Q->ar[Q->r] = val;
}
 int dequeue(Queue* q) {
	q->f++;
	return q->ar[q->f];
}
int main() {
	Queue* q1 = new Queue[sizeof(Queue)];
	q1->size = 5;
	q1->r= q1->f = -1;
	q1->ar = new int[q1->size * sizeof(int)];
	enqeue(q1, 6);
	enqeue(q1, 5);
	enqeue(q1, 32);
	disp(q1);
	cout << endl;
	cout << dequeue(q1);
	disp(q1);
	return 0;
}
