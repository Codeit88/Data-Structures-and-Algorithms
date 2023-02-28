#include<iostream>
using namespace std;
class Queue {
	class Node {
		Node* next;
		int data;
		friend class Queue;
	public:
		Node(){
			this->next = NULL;
			this->data = 0;
		}
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
	};
	Node* front, * rear;
public:
	Queue() {}
	bool isfull() {
		return false;
	}
	bool isempty() {
		if (front == rear && front == NULL)
			return true;
		return false;
	}
	void enqueue(int data) {
		Node* nnew = new Node(data);
		if (front == rear && front == NULL) {
			front = rear = nnew;
		}
		else {
			rear->next = nnew;
			rear = nnew;
		}
	}
	void dequeue() {
		front = front->next;
	}
	void print() {
		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
};
int main() {
	Queue q1;
	q1.enqueue(44);
	q1.enqueue(48);
	q1.enqueue(47);
	q1.enqueue(49);
	q1.enqueue(31);
	q1.enqueue(21);
	q1.print();
	cout << endl;
	q1.dequeue();
	q1.print();
	return 0;
}
