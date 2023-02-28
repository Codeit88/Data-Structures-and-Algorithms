#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct Position {
	int x, y;
};

template<class T>
class Stack {
	T* arr;
	int size, top;
public:
	Stack() {
		size = 0;
		top = -1;
		arr = new T[size];
		arr = NULL;
	}
	Stack(int size) {
		this->size = size;
		top = -1;
		arr = new T[size];
	}
	bool isEmpty() {
		if (top == -1)
			return true;
		return false;
	}
	bool isFull() {
		if (top == size)
			return true;
		return false;
	}
	void gettop();
	T pop();
	void push(T val);
	void disp();
};
template<typename T>
T Stack<T>::pop() {
	top--;
	return this->arr[this->top];
}
template<typename T>
void Stack<T>::disp() {
	int temp = top;
	while (temp != -1) {
		cout << arr[temp].x << " , " << arr[temp].y << endl;
		temp -= 1;
	}
}
template<typename T>
void Stack<T>::push(T val) {
	top += 1;
	arr[top] = val;
}
template<typename T>
void Stack<T>::gettop() {
	cout << arr[top].x << " , " << arr[top].y << " -> ";
}
int main() {
	srand(time(0));
	int msize;
	cout << " Enter your maze size : \n";
	cin >> msize;
	int** maze = new int* [msize];
	for (int i = 0;i < msize;i++) {
		maze[i] = new int[msize];
	}
	for (int i = 0;i < msize;i++) {
		for (int j = 0;j < msize;j++) {
			maze[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < msize; i++) {
		for (int j = 0; j < msize; j++) {
			cout << "\t" << maze[i][j];
		}
		cout << endl;
	}
	bool** loc = new bool* [msize];
	for (int i = 0;i < msize;i++) {
		loc[i] = new bool[msize];
	}
	for (int i = 0; i < msize; i++) {
		for (int j = 0; j < msize; j++) {
			if (i == 0 && j == 0) {
				loc[i][j] = true;
			}
			else {
				loc[i][j] = false;
			}
		}
	}
	Stack <Position>s1(100);
	Position init, destiny, current;
	init.x = init.y = 0;
	current = init;
	destiny.x = (msize - 1);
	destiny.y = (msize - 1);
	int i = 0, j = i;
	s1.push(init);
	while (current.x != destiny.x && current.y != destiny.y) {
		if (maze[i][j + 1] == 1 && i >= 0 && i < msize && j >= 0 && j < msize && maze[i][j+1] != -1 && loc[i][j + 1] != true) {
			init.x = i;
			init.y = j + 1;
			current = init;
			loc[i][j + 1] = true;
			s1.push(current);
			j++;
		}
		else if (maze[i + 1][j] == 1 && i >= 0 && i < msize && j >= 0 && j < msize && maze[i+1][j] != -1 && loc[i + 1][j] != true) {
			init.x = i + 1;
			init.y = j;
			current = init;
			loc[i + 1][j] = true;
			s1.push(current);
			i++;
		}
		else if (maze[i][j - 1] == 1 && i >= 0 && i < msize && j >= 0 && j < msize && maze[i][j-1] != -1 && loc[i][j - 1] != true) {
			init.x = i;
			init.y = j - 1;
			current = init;
			loc[i][j - 1] = true;
			s1.push(current);
			j--;
		}
		else if (maze[i - 1][j] == 1 && i >= 0 && i < msize && j >= 0 && j < msize && maze[i-1][j] != -1 && loc[i - 1][j] != true) {
			init.x = i - 1;
			init.y = j;
			current = init;
			loc[i - 1][j] = true;
			s1.push(current);
			i--;
		}
		else if (i != 0 && j != 0) {
			maze[i][j] = -1;
			init = s1.pop();
			i = init.x;
			j = init.y;
		}
		else {
			cout << " No Path found ! \n";
			return 0;
		}
		s1.gettop();
	}
	s1.push(destiny);
	cout << "ENDED";
	cout << endl << " Your recorded path is : \n";
	s1.disp();
	return 0;
}
