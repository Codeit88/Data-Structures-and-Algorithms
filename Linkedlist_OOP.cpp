#include<iostream>
using namespace std;
class Linklist {
	class Node {
	public:
		int data;
		Node* next;
		friend class Linklist;
		Node() {}
		Node(int data, Node* next) {
			this->data = data;
			this->next = next;
		}
		~Node() {
			delete next;
		}
	};
private:
	Node* head, * tail;
public:
	Linklist() {
		head = tail = NULL;
	}
	void insertathead(int const elem) {
		Node* temp = new Node;
		temp->data = elem;
		if (head == NULL) {
			temp->next = head;
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}
	void insertAtTail(int const elem) {
		Node* temp = new Node;
		temp->data = elem;
		if (head == NULL) {
			temp->next = head;
			head = temp;
		}
		else {
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
		}
	}

	void DeleteFromHead() {
		head = head->next;
	}
	void DeleteFromTail() {
		Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		temp->next = NULL;
		tail = temp;
	}
	int getsize() const {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}
	int getMiddle() const {
		int count = getsize();
		Node* temp = head;
		for (int i = 0;i < (count / 2);i++) {
			temp = temp->next;
		}
		return temp->data;
	}
	bool IsEmpty() {
		if (head == nullptr) {
			return true;
		}
		else
			return false;
	}
	void InsertAfter(int val, int key) {
		Node* temp = head;
		int count = 0, flag = 0;
		while (temp != NULL) {
			if (temp->data == key) {
				flag = 1;
				Node* temp2 = new Node;
				temp2->data = val;
				temp2->next = temp->next;
				temp->next = temp2;
				count++;
			}
			temp = temp->next;
			count++;
		}
		if (count == getsize() && flag != 1) {
			Node* temp3 = new Node;
			temp3->data = val;
			temp3->next = NULL;
			tail->next = temp3;
			tail = temp3;
		}
	}
	void InsertBefore(int val, int key) {
		Node* temp = head;
		Node* prev = head;
		int count = 0, flag = 0;
		while (temp != NULL) {
			if (temp->data == key) {
				flag = 1;
				Node* temp2 = new Node;
				temp2->data = val;
				temp2->next = prev->next;
				prev->next = temp2;
				count++;
			}
			prev = temp;
			temp = temp->next;
			count++;
		}
		if (count == getsize() && flag != 1) {
			Node* temp3 = new Node;
			temp3->data = val;
			temp3->next = NULL;
			tail->next = temp3;
			tail = temp3;
		}
	}
	int getMax() const {
		Node* temp = head;
		int max = temp->data;
		while (temp != NULL) {
			if (temp->data > max) {
				max = temp->data;
			}
			temp = temp->next;
		}
		return max;
	}
	int getMin() const {
		Node* temp = head;
		int min = temp->data;
		while (temp != NULL) {
			if (temp->data < min) {
				min = temp->data;
			}
			temp = temp->next;
		}
		return min;
	}
	int getAverage() const {
		int avg = 0;
		Node* temp = head;
		while (temp != NULL) {
			avg += temp->data;
			temp = temp->next;
		}
		return avg / getsize();
	}
	bool Swap(int Left_Index, int right_index)
	{
		int List_Size = getsize();
		Node* ptr1 = head;
		Node* ptr2 = head;
		Node* ptr3 = head;
		int counter = 0;

		if (right_index > List_Size || Left_Index < 0)
		{
			cout << "not found";
			return false;
		}
		else
		{
			while (counter < Left_Index)
			{
				ptr1 = ptr1->next;
				counter++;
			}
			counter = 0;
			while (counter < right_index)
			{
				ptr2 = ptr2->next;
				counter++;
			}
			counter = 0;
			while (counter < Left_Index - 1)
			{
				ptr3 = ptr3->next;
				counter++;
			}
		//	ptr1->next = ptr2->next;
		//	ptr2->next = ptr1;
		//	ptr3->next = ptr2;

			return true;
		}
	}
	void merge(Linklist l) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		if (temp->next == NULL) {
			temp->next = l.head;
			this->tail = l.tail;
		}
		}
	void split(int val) {
		int count = 1;
		Node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			count++;
			if (count == val) {
				temp->next = NULL;
				this->tail = temp;
			}
		}
	}
	void printForward() const {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
		cout << endl;
	}
};

int main() {
	Linklist l1, l2;
	l1.insertathead(42);
	l1.insertathead(24);
	l1.insertathead(32);
	l1.insertathead(12);
	l1.insertathead(41);
	l1.insertathead(85);
	l1.printForward();
	l2.insertathead(32);
	l2.insertathead(10);
	l2.insertathead(38);
	l2.insertathead(14);
	l2.insertathead(41);
	l2.printForward();
	l1.merge(l2);
	l1.printForward();
	l1.split(5);
	l1.printForward();
	l1.Swap(4,5);
	l1.printForward();
	return 0;
}
