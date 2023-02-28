#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
int main() {
	Node* first = new Node[sizeof(Node)],*second = new Node[sizeof(Node)],*third = new Node[sizeof(Node)];
	first->data = 12;
	first->next = second;
	second->data = 45;
	second->next = third;
	third->data = 50;
	third->next = NULL;
		return 0;
}
