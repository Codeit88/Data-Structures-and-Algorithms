
	void search(Node*curr,queue<Node>*q1) {
		if (curr) {
			search(curr->left,q1);
			q1->push(curr->data);
			search(curr->right, q1);
		}
	}
	Node wrapper_search(int a) {
		queue<Node>* q1 = new queue<Node>;
		search(this->root,q1);
		while (!q1->empty()) {
			if (q1->front().data == a) {
				return q1->front();
			}
			q1->pop();
		}
		return 0;
	}
