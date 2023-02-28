#include<iostream>
using namespace std;
template <class T>
class Queue
{
public:
	Queue()
	{
		front = -1;
		rear = -1;
		maxsize = 6;
		arr = new T[maxsize];
	}
	Queue(int Maxsize)
	{
		front = -1;
		rear = -1;
		this->maxsize = Maxsize;
		arr = new T[maxsize];
	}
	void setQueue(int size) {
		maxsize = size;
		arr = new T[maxsize];
	}
	bool IsFull()
	{
		if ((rear + 1) % maxsize == front)
		{
			return true;
		}
		return false;
	}
	bool IsEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		return false;
	}
	void Enqueue(T curr)
	{
		if (!IsFull())
		{
			if (front == -1 && rear == -1)
			{
				front = 0;
			}
			rear = (rear + 1) % maxsize;
			arr[rear] = curr;
		}
		else
		{
			cout << "-----CANNOT ENQUEUE QUEUE IS FULL-----\n";
		}
	}
	T Dequeue()
	{
		if (front == rear)
		{
			T element = arr[front];
			front = rear = -1;
			return element;
		}
		else if (!IsEmpty())
		{
			T element = arr[front];
			front = (front + 1) % maxsize;
			return element;
		}
	}
	void Print_Queue()
	{
		int i = front;
		while (i != rear)
		{
			cout << arr[i];
			cout << " ";
			i = (i + 1) % maxsize;
		}
		cout << arr[i] << endl;
	}
	T Front() {
		return arr[front];
	}
public:
	int front;
	int rear;
	T* arr;
	int maxsize;

};

template <class T>
class Tree
{
	class Node {
	public:
		T data;
		Node* left = NULL;
		Node* right = NULL;

		Node(T data, Node* left, Node* right)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

private:
	Node* root;
public:
	Tree()
	{
		root = NULL;
	}
	Tree(const Tree& copy)
	{
		root = copy.root;		
	}
	Tree* Wrapper(Node* curr)
	{
		if (curr == NULL)
		{
			return NULL;
		}
		else
			return new Node(curr, curr->left, curr->right);
	}
	void Insert(T d)
	{
		Node* newNode = new Node(d, NULL, NULL);
		Node* prev = root;
		Node* curr = root;

		while (curr)
		{
			prev = curr;

			if (prev->data > d)
				curr = curr->left;

			else if (prev->data <= d)
				curr = curr->right;
		}

		if (prev == NULL)
			root = newNode;

		else if (prev->data > d)
			prev->left = newNode;

		else if (prev->data <= d)
			prev->right = newNode;

	}
	void InOrder(Node* curr)
	{
		if (curr)
		{
			InOrder(curr->left);
			visit(curr);
			InOrder(curr->right);
		}
	}
	int Nodes_Counter_LVR(Node* curr)
	{
		static int counter = 0;
		if (curr)
		{
			Nodes_Counter_LVR(curr->left);
			counter++;
			Nodes_Counter_LVR(curr->right);
		}
		return counter;
	}
	int Wrapper_LVR()
	{
		Node* curr = root;
		static int counter = Nodes_Counter_LVR(curr);
		return counter;
	}
	int Leaf_Counter_VLR(Node* curr)
	{
		static int counter = 0;

		if (curr != NULL)
		{
			if ((curr->left == NULL) && (curr->right == NULL))
			{
				counter++;
			}
			else
			{
				Leaf_Counter_VLR(curr->left);
				Leaf_Counter_VLR(curr->right);
			}

		}
		return counter;
	}
	int Wrapper_Leaf_Counter()
	{
		Node* curr = root;
		static int counter = 0;
		counter = Leaf_Counter_VLR(curr);
		return counter;
	}
	void LevelOrderTraversal()
	{
		Queue<Node*> obj;
		Node* curr = root;

		while (curr != NULL || !obj.IsEmpty())
		{
			if (curr != NULL)
			{
				cout << curr->data<<" ";
				obj.Enqueue(curr->left);
				obj.Enqueue(curr->right);
			}
			curr = obj.Dequeue();
		}
	}
	bool Search(Node* curr, T data)
	{
		if (curr)
		{
			if (curr->data > data)
				Search(curr->left, data);

			else if (curr->data < data)
				Search(curr->right, data);

			else
				return true;
		}
		else
			return false;
	}
	bool Search(T data)
	{
		return Search(root, data);
	}
	void visit(Node* curr)
	{
		cout << curr->data << " ";
	}
	void Print()
	{
		Node* curr = root;
		InOrder(curr);
	}
	void Destroy(Node*& curr)
	{
		if (curr != NULL)
		{
			if ((curr->left == NULL) && (curr->right == NULL))
			{
				delete curr;
				curr = NULL;
			}
			else
			{
				Destroy(curr->left);
				Destroy(curr->right);
			}
		}
	}
	void Delete(int key)
	{
		DeleteNode(this->root, key);
	}
	void DeleteNode(Node* curr, T data)
	{
		static Node*  previous = root;
		if (curr)
		{
			if (curr->data > data)
			{
				previous = curr;
				DeleteNode(curr->left, data);
			}

			else if (curr->data < data)
			{
				previous = curr;
				DeleteNode(curr->right, data);
			}
			else
			{
				if (curr->right == NULL && curr->left == NULL)
				{
					delete curr;
					cout << "Node deleted" << endl;

				}
			}
		}
		else
			cout<<"Node don't exsists "<<endl;

	}
	~Tree()
	{
		Destroy(root);
	}
};
int main()
{
	Tree<int> tree_1;
	tree_1.Insert(8);
	tree_1.Insert(1);
	tree_1.Insert(4);
	tree_1.Insert(5);
	tree_1.Insert(10);
	cout << "Insertion : ";
	tree_1.Print();
	cout << endl;
	cout << "--------------------------------------" << endl;

	Tree<int> tree_2 = tree_1;
	cout << "Deep Copy : ";
	tree_2.Print();
	cout << endl;
	cout << "--------------------------------------" << endl;

	int data = 0;
	cout << "Enter data to Search..." << endl;
	cin >> data;
	if (tree_1.Search(data))
		cout << "Element Exsists" << endl;
	else
		cout << "Data don't Exsists " << endl;

	cout << "--------------------------------------" << endl;

	int counter = tree_1.Wrapper_LVR();
	cout << "Total Number of Nodes in the Tree : " << counter << endl;;

	cout << "--------------------------------------" << endl;

	int counter_2 = tree_1.Wrapper_Leaf_Counter();
	cout << "Total Number of Leafs in the Tree : " << counter_2 << endl;

	cout << "--------------------------------------" << endl;

	cout << "Level Order Traversal : ";
	tree_2.LevelOrderTraversal();
	cout << "\n--------------------------------------" << endl;
	cout << "Enter data to delete " << endl;
	cin >> data;

	tree_1.Delete(data);
}
