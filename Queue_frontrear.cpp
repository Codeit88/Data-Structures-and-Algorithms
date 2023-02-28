#include<iostream>
using namespace std;
struct Queue {
	int r, f, size,*ar;
};
void enqueuerear(Queue* q, int val) {
	q->r = (q->r + 1) % q->size;
	q->ar[q->r] = val;
}
void enqueuefront(Queue*q,int val) {
	q->ar[0] = val;
}
int dequeuerear(Queue* q2) {
	q2->r = (q2->r - 1) % q2->size;
	return q2->ar[q2->r+1];
}
int dequeuefront(Queue*q2) {
	q2->f = (q2->f + 1) % q2->size;
	return q2->ar[q2->f];
}
int main() {
	Queue *q1 = new Queue[sizeof(Queue)];
	q1->size = 4;
	q1->r = q1->f = -1;
	q1->ar = new int[q1->size * sizeof(int)];
	enqueuerear(q1, 43);
	enqueuerear(q1, 44);
	enqueuerear(q1, 42);
	cout<<dequeuefront(q1)<<endl;
	enqueuerear(q1, 45);
	cout << dequeuerear(q1) << endl;
	return 0;
}
