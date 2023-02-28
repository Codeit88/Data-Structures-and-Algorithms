#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
void linkedlisttraversal(Node*ptr) {
	while (ptr != NULL) {
		cout <<" "<< ptr->data;
		ptr=ptr->next;
	}
}
int main() {
	Node* first = new Node[sizeof(Node)],//first=head of linkedlist
		* second = new Node[sizeof(Node)],
		*third = new Node[sizeof(Node)];
	first->data = 12;
	first->next = second;
	second->data = 45;
	second->next = third;
	third->data = 50;
	third->next = NULL;
	linkedlisttraversal(first);
		return 0;
}
