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
Node* insertfirst(Node* ptr, int num) {
	Node* elem = new Node[sizeof(Node)];
	elem->next = ptr;
	elem->data = num;
	return elem;
}
Node* insert(Node *ptr,int index,int num) {
	Node* elem = new Node[sizeof(Node)];
	Node* p = ptr;
	int i = 0;
	while (i != (index-1)) {
		p=p->next;
		i++;
	}
	elem->next = p->next;
	elem->data = num;
	p->next = elem;
	return ptr;
}
Node* insertatend(Node* ptr,int num) {
	int i = 0,count=0;
	Node* p = new Node[sizeof(Node)];
	p = ptr;
	Node* elem = new Node[sizeof(Node)];
	elem->data = num;
	while (p->next != NULL) {
		p = p->next;
		i++;
	}
	p->next = elem;
	elem->next = NULL;
	return p;
}
Node* insertafternode(Node*head,Node* prevptr,int num) {
	Node* elem = new Node[sizeof(Node)];
	elem->data = num;
	elem->next=prevptr->next;
	prevptr->next = elem;
	return head;
}
int main() {
	Node* head = new Node[sizeof(Node)],//first=head of linkedlist
	* first = new Node[sizeof(Node)],
		* second = new Node[sizeof(Node)],
		*third = new Node[sizeof(Node)];
	head->data = 01;
	head->next = first;
	first->data = 12;
	first->next = second;
	second->data = 45;
	second->next = third;
	third->data = 50;
	third->next = NULL;
	cout << " Oiriginal linked list : \n";
	linkedlisttraversal(first);
	cout << endl;
	Node* sec = insertfirst(first, 44);
	cout << " 0 index inserted linked list : \n";
	linkedlisttraversal(sec);
	cout << endl;
	Node* thi = insert(first,1,76);
	cout << " Random inserted linked list : \n";
	linkedlisttraversal(thi);
	cout << endl;
	Node* fo = insertatend(first, 40);
	cout << " On end inserted linked list : \n";
	linkedlisttraversal(fo);
	cout << endl;
	Node* after = insertafternode(head, first,221);
	cout << " After inserted linked list : \n";
	linkedlisttraversal(after);
		return 0;
}
