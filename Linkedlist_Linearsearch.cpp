#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
void display(Node*ptr) {
	while (ptr != NULL) {
		cout << " " << ptr->data;
		ptr = ptr->next;
	}
}
void search(Node*head,int val) {
	Node* ptr = head;
	int i = 0;
	while (ptr != NULL) {
		if (ptr->data == val) {
			cout << i+1;
			break;
		}
		else
		{
			ptr = ptr->next;
			i++;
		}
	}
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
	display(head);
	cout << endl;
		search(head, 122);
	return 0;
}
