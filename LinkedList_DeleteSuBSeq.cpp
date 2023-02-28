
#include<iostream>
using namespace std;
template<class T>
class List {
public:
	class Node {
		friend class List<T>;
		T data;
		Node* next, * prev;
		Node() {
			next = prev = NULL;
		}
		Node(T data, Node* next) {
			this->data = data;
			this->next = next;
		}
	};
	class Iterator {
		Node* current;
		friend class List<T>;
	public:
		Iterator() {
			current = NULL;
		}
		Iterator(Node* current) {
			this->current = current;
		}
		T& operator*() const {
			return current->data;
		}
		Iterator& operator++() {
			if (current != NULL)
				this->current = this->current->next;
			return *this;
		}
		Iterator& operator++(int) {
			this->current = this->current->next;
			Node* old = this->current;
			this->current = old;
			return *this;
		}
		Iterator& operator--() {
			if (current != NULL)
				this->current = this->current->prev;
			return *this;
		}
		Iterator& operator--(int) {
			Node* old = *this;
			--(*this);
			return old;
		}
		bool operator==(const Iterator& rhs) const {
			return current == rhs.current;
		}
		bool operator!=(const Iterator& rhs) const {
			return !(*this == rhs);
		}
	};
	Iterator begin() const {
		return head;
	}
	Iterator end() const {
		return NULL;
	}
	void insert(T value) {
		int count = 0;
		Node* temp = new Node;
		temp->data = value;
		if (head == NULL) {
			temp->next = NULL;
			head = temp;
			tail = temp;
			temp->prev = NULL;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			temp->next = NULL;
			tail = temp;
		}
	}
	bool Search(T value) const {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == value)
				return true;
			temp = temp->next;
		}
		return false;
	}
	void erase(T value) {
		Node* t, * temp = head;
		while (temp != NULL) {
			t = temp->prev;
			if (temp->data == value) {
				t->next = temp->next;
				temp->next->prev = t;
			}
			temp = temp->next;
		}
	}
	void printfor() const {
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << " -> ";
			curr = curr->next;
		}
		cout << " NULL " << endl;
	}
	void printbac() const {
		Node* curr = tail;
		while (curr != head->prev) {
			cout << curr->data << " -> ";
			curr = curr->prev;
		}
		cout << " NULL " << endl;
	}
	List() {
		head = tail = NULL;
	}
	void deleteAfter(Iterator& p) {
		if (p.current == NULL)
			return;
		Node* current = p.current->next;
		if (current != NULL) {
			if (tail.next == current)
				tail.next = p.current;
			p.current->next = current->next;
			delete current;
			if (p.current->next == NULL)
				tail.next = NULL;

		}
	}
	void deleteSubSequence() {
		List<T>::Iterator inext = NULL; //point to next of i
		List<T>::Iterator iprev = begin(); // points to prevous of i
		List<T>::Iterator i = begin(); // traverse the list
		while (i != end()) {
			inext = i;
			inext++;
			if (i != NULL && *i == 1 && inext != end() && *inext == 0) {// fourn 10
				if (i == begin())
				{
					deleteAfter(i); //delete first 1
				}
				else { //first update i and then delete it
					i++;
					deleteAfter(iprev);
				}
				void printList();
				while (i != end() && *i == 0) //removes zeros
				{
					if (i == begin()) { //if zeros are at start of list
						deleteAfter(i);
						iprev = i;
					}
					else if (iprev != NULL) // if at somewhere else in list
					{
						i++;
						deleteAfter(iprev);
					}
					printList();
				}
			}
			else {
				iprev = i; //updating previous and i
				i++;
			}
		}
	}
	void deleteSubSequence2() {
		List<T>::Iterator inext = NULL; //point to next of i
		List<T>::Iterator iprev = begin(); // points to prevous of i
		List<T>::Iterator i = begin(); // traverse the list
		//L++;
		while (i != end()) {
			inext = i;
			inext++;
			if (*i == 1 && inext != end() && *inext == 0) {// found 10
				for (i++; i != end() && *i == 0; i++);
				while (iprev.current != NULL && iprev.current->next != i.current)
				{
					temp = iprev.current->next;
					iprev.current->next = iprev.current->next->next;
					delete temp;
					if (iprev.current->next == NULL)
						tail.next = NULL;

				}
			}
			else {
				iprev = i;
				i++;
			}
		}
	}
	~List()
	{
		Node* temp;
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}

	}
private:
	Node* head, * tail;
};
int main() {
	List<int>l1;
	l1.insert(1);
	l1.insert(0);
	l1.insert(0);
	l1.insert(1);
	l1.insert(0);
	l1.insert(1);
	l1.printfor();
	List<int>::Iterator I;
	I = l1.begin();
	cout << *(I);
	return 0;
}
