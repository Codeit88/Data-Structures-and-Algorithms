#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
class BST {
	Node* root;
public:
	BST() {
		this->root = NULL;
	}
	bool insert(int V) {
		Node* nnew = new Node;
		nnew->left = nnew->right = NULL;
		nnew->data = V;
		if (root == NULL) {
			root = nnew;
			return true;
		}
		else {
			Node* curr = root, * prev = NULL;
			while (curr != NULL) {
				prev = curr;
				if (nnew->data > curr->data) {
					curr = curr->right;
				}
				else if (nnew->data < curr->data) {
					curr = curr->left;
				}
				else {
					cout << " Element already exist ! \n";
					return false;
				}
			}
			if (prev->data > V) {
				prev->left = nnew;
				return true;
			}
			else if (prev->data < V) {
				prev->right = nnew;
				return true;
			}
		}
	}
	BST(const BST& a) {
		this->root = a.root;
		while (a.root->left != NULL) {
			root->left = a.root->left;
			a.root->left = a.root->left->left;
		}
		while (a.root->right != NULL) {
			root->right = a.root->right;
			a.root->right = a.root->right->right;
		}
	}
	void visit(Node* curr) {
		cout << curr->data << " \t ";
	}
	void inorderPrint(Node*curr)  {
		if (curr) {
			inorderPrint(curr->left);
			visit(curr);
			inorderPrint(curr->right);
		}
	}
	void wrapper() {
		inorderPrint(this->root);
	}
};
int main() {
	BST b1;
	b1.insert(43);
	b1.insert(54);
	b1.insert(22);
	b1.insert(10);
	b1.wrapper();
	BST b2=b1;
	return 0;
}
