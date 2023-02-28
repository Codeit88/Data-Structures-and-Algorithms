#include<iostream>
#include<string>
using namespace std;
struct Computer {
	int ID,weight;
	string loc;
	Computer() {
		this->weight = 9999;
		this->ID = 0;
		this->loc = "0";
	}
};
class List {
	class Node {
		Node* next, * prev;
		int data;
		friend class List;
		Node(int data) {
			this->data = data;
			this->next = this->prev = NULL;
		}
	};
	Node* head, * tail;
public:
	List() {
		this->head = this->tail = NULL;
	}
	void insert(int data) {
		Node* nnew = new Node(data);
		if (head == NULL) {
			head = tail = nnew;
			nnew->prev = NULL;
		}
		else {
			tail->next = nnew;
			nnew->prev = tail;
			tail = nnew;
		}
	}
	void print_list() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data<<" -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};
class Graph {
public:
};
int main() {
	cout << " Hello World \n";
	return 0;
}
