#include <iostream>
using namespace std;
class Graphs
{
private:
	int** Matrix;
	int vertices;// total number of vertices
	bool isDirected; // 0 for undirected, 1 for directed
public:
	Graphs(int Tvertices, bool dir) {
		dir = false;
		vertices = Tvertices;
		Matrix = new int* [vertices];
		for (int i = 0;i < vertices;i++) {
			Matrix[i] = new int[vertices];
		}
		for (int i = 0;i < vertices;i++) {
			for (int j = 0;i < vertices;j++) {
				Matrix[i][j] = 0;
			}
		}
	}
	Graphs(const Graphs& obj) {
		vertices = obj.vertices;
		isDirected = obj.isDirected;

		Matrix = new int* [vertices];

		for (int i = 0;i < vertices;i++) {
			Matrix[i] = new int[vertices];

			for (int i = 0;i < vertices;i++) {
				for (int j = 0;i < vertices;j++) {
					Matrix[i][j] = 0;
				}
			}
		}


	}
	Graphs(string fName);
	bool addEdge(int x, int y) {
		Matrix[x][y] = 1;
		Matrix[y][x] = 1;

	}
	bool removeEdge(int x, int y) {
		Matrix[x][y] = 0;
		Matrix[y][x] = 0;

	}
	bool isConnected(int x, int y) {
		if (Matrix[x][y] = 0)
			return false;
		else if (Matrix[x][y] = 1)
			return true;
	}
	int getIndegree(int x) {
		int Idegree = 0;
		for (int i = 0;i < vertices;i++) {
			if (Matrix[i][x] == 1) {
				Idegree += 1;
			}
		}
		return Idegree;
	}
	int getOutdegree(int x) {
		int Odegree = 0;
		for (int i = 0;i < vertices;i++) {
			if (Matrix[x][i] == 1) {
				Odegree += 1;
			}
		}
		return Odegree;
	}
	void printAllAdjc(int x) {
		for (int i = 0;i < vertices;i++) {
			if (Matrix[x][i] == 1) {
				cout << "Adjacent: " << x << " " << i << endl;
			}
		}
	}
	bool isComplete()
	{
		int flag = 0;
		for (int i = 0;i < vertices;i++) {
			for (int j = 0;j < vertices;j++) {
				if (i != j) {
					if (Matrix[i][j] == 1) {
						flag = 1;
					}
					else {
						flag = 0;
						return false;
						break;
					}
				}
			}

		}

	}// is every node connected to any other node
	void printGraph() {
		for (int i = 0;i < vertices;i++) {
			for (int j = 0;j < vertices;j++) {
				cout << Matrix[i][j] << " ";
			}
			cout << endl;
		}

	}// print the whole Matrix
	~Graphs();
};
int main() {
	Graphs g1(8,0);

	return 0;
}

