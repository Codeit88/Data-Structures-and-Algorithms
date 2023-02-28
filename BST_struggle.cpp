#include<iostream>
using namespace std;
template<class T>
struct Node {
	T data;
	Node* right, * left;
	Node() {
		this->left = this->right = NULL;
	}
	Node(T data);
};
template<class T>
Node<T>::Node(T data){
	this->data = data;
	this->left = this->right = NULL;
}
template<class T>
class BST {
	Node<T>* root;
public:
	BST();
	void rec_insertion(Node<T>*&curr,T data);
	void wrapper_rec_insertion(T data);
	void inorder_print(Node<T>* curr);
	void wrapper_inorder_print();
	bool ite_search(Node<T>*curr,T key);
	bool wrapper_ite_search(T data);
	Node<T>* rec_search(Node<T>* curr, T key);
	Node<T>* wrapper_rec_search(T data);
	void ite_delete_node(Node<T>* curr,T data);
	void wrapper_ite_delete_node(T data);
	void wrapper_destructor(Node<T>* curr);
	~BST();
};
template<class T>
BST<T>::BST() {
	this->root = NULL;
}
template<class T>
void BST<T>::wrapper_rec_insertion(T data) {
	rec_insertion(this->root,data);
}
template<class T>
void BST<T>::rec_insertion(Node<T>*&curr,T data) {
	if (curr == NULL) {
		curr = new Node<T>(data);
		return;
	}
	else if (curr->data > data){
		rec_insertion(curr->left,data);
	}
	else {
		rec_insertion(curr->right, data);
	}
}
template<class T>
void BST<T>::wrapper_inorder_print() {
	inorder_print(this->root);
}
template<class T>
void BST<T>::inorder_print(Node<T>* curr) {
	if (curr == NULL)
		return;
	else {
		inorder_print(curr->left);
		cout << curr->data << " ";
		inorder_print(curr->right);
	}
}
template<class T>
bool BST<T>::wrapper_ite_search(T data) {
	return ite_search(this->root,data);
}
template<class T>
bool BST<T>::ite_search(Node<T>* curr,T key) {
	while (curr != NULL) {
		if (curr == NULL)
			return false;
		else if (curr->data == key)
			return true;
		else if(curr->data > key) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
}
template<class T>
Node<T>* BST<T>::wrapper_rec_search(T data) {
	return rec_search(this->root, data);
}
template<class T>
Node<T>* BST<T>::rec_search(Node<T>* curr, T key) {
	if (curr == NULL)
		return NULL;
	else if (curr->data == key) {
		return curr;
	}
	else if (curr->data > key) {
		rec_search(curr->left, key);
	}
	else
		rec_search(curr->right, key);
}
template<class T>
void BST<T>::wrapper_ite_delete_node(T data) {
	Node<T>*temp = wrapper_rec_search(data);
	if (temp != NULL)
		ite_delete_node(temp, data);
	else
		cout << "\nNode not found! \n";
}
template<class T>
void BST<T>::ite_delete_node(Node<T>* curr,T data) {
	if (curr->right == NULL && curr->left == NULL){}
}

template<class T>
void BST<T>::wrapper_destructor(Node<T>*curr) {
	if (curr) {
		wrapper_destructor(curr->left);
		wrapper_destructor(curr->right);
		delete curr;
	}
}
template<class T>
BST<T>::~BST() {
	wrapper_destructor(this->root);
}
int main() {
	BST<int>b1;
	b1.wrapper_rec_insertion(32);
	b1.wrapper_rec_insertion(54);
	b1.wrapper_rec_insertion(13);
	b1.wrapper_rec_insertion(12);
	b1.wrapper_rec_insertion(73);
	b1.wrapper_rec_insertion(64);
	b1.wrapper_rec_insertion(27);
	b1.wrapper_inorder_print();
	b1.wrapper_ite_delete_node(13);
	return 0;
}
