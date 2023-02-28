#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next,*prev;
};
void circulartraversal(Node*ptr) {
	Node* elem = new Node[sizeof(Node)];
	elem=ptr;
	do{
		cout << " " << elem->data;
		elem = elem->next;
	} while (elem != ptr);
}
int main() {
	Node* head = new Node[sizeof(Node)], 
		* first = new Node[sizeof(Node)], 
		* sec = new Node[sizeof(Node)], 
		* third = new Node[sizeof(Node)];
	head->data = 21;
	head->next = first;
	first->data = 12;
	first->next = sec;
	sec->data = 213;
	sec->next = third;
	third->data = 43;
	third->next = NULL;
	circulartraversal(head);
	return 0;
}
