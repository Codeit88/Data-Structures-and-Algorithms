#include<iostream>
using namespace std;
class Linklist {
	class Node {
		int data;
		Node* next, *prev;
		friend class Linklist;
	public:
		Node() {
			this->next = this->prev = NULL;
		}
		Node(int data) {
			this->data = data;
			this->next = this->prev = NULL;
		}
	};
	Node* head;
public:
	Linklist();
	void insert(int data);
	void print(Node*curr);
	void wrapper() {
		Node* temp = head;
		print(temp);
	}
};
Linklist::Linklist() {this->head = NULL;}
void Linklist::insert(int data){
	Node* nnew = new Node(data);
	if (head == NULL) {
		head = nnew;
	}
	else {
		nnew->next = head;
		head = nnew;
	}
}
void Linklist::print(Node*curr) {
	if (curr == NULL) {
		return;
	}
	else {
		cout << curr->data << " ";
		return print(curr->next);
	}
}
int main() {
	Linklist l1;
	l1.insert(5);
	l1.insert(10);
	l1.insert(15);
	l1.insert(63);
	l1.insert(33);
	l1.wrapper();
	return 0;
}
