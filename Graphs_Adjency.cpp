#include<iostream>
using namespace std;
class Linklist {
	class Node {
		int data;
		Node* next;
		friend class Linklist;
	public:
		Node(){}
			Node(int data){
				this->data = data;
				this->next = NULL;
    }
};
public:

};
class Graphs{
private:
	int** Matrix;
	int vertices;// total number of vertices
	bool isDirected; // 0 for undirected, 1 for directed
public:
	Graphs(int Tvertices, bool dir);
	Graphs(const Graphs& obj);
	Graphs(string fName);
	bool addEdge(int x, int y);
	bool removeEdge(int x, int y);
	bool isConnected(int x, int y);
	int getIndegree();
	int getOutdegree();
	void printAllAdjc();
	bool isComplete();// is every node connected to any other node
	void printGraph();// print the whole Matrix
	~Graphs();
};

int main() {
	cout << " Hello World \n";
	return 0;
}
