#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
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
	T pop();
	void push(T val);
	void disp();
};
template<typename T>
T Stack<T>::pop() {
	T z = arr[top];
	top -= 1;
	return z;
}
template<typename T>
void Stack<T>::disp() {
	while (top != -1) {
		cout << arr[top].x << " , " << arr[top].y << endl;
		top -= 1;
	}
}
template<typename T>
void Stack<T>::push(T val) {
	top += 1;
	arr[top] = val;
}
struct Position {
	int x, y;
};
int main() {
	int maze[3][3] =
	{
		{1,0,0},
		{0,1,1},
		{1,1,0}
	};
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			maze[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "\t" << maze[i][j];
		}
		cout << endl;
	}
	bool** loc = new bool* [3];
	for (int i = 0;i < 3;i++) {
		loc[i] = new bool[3];
	}
	Stack <Position>s1(100);
	Position init, destiny, current;
	init.x = init.y = 0;
	current = init;
	destiny.x = destiny.y = 2;
	int i = 0, j = i;
	while (current.x != destiny.x && current.y != destiny.y) {
		if (maze[i][j + 1] == 1 && i >= 0 && i < 3 && j >= 0 && j < 3 && maze[i][j] != -1 && loc[i][j + 1] != true) {
			init.x = i;
			init.y = j + 1;
			current = init;
			loc[i][j] = true;
			s1.push(current);
			j++;
		}
		else if (maze[i + 1][j] == 1 && i >= 0 && i < 3 && j >= 0 && j < 3 && maze[i][j] != -1 && loc[i + 1][j] != true) {
			init.x = i + 1;
			init.y = j;
			current = init;
			loc[i][j] = true;
			s1.push(current);
			i++;
		}
		else if (maze[i][j - 1] == 1 && i >= 0 && i < 3 && j >= 0 && j < 3 && maze[i][j] != -1 && loc[i][j - 1] != true) {
			init.x = i;
			init.y = j - 1;
			current = init;
			loc[i][j] = true;
			s1.push(current);
			j--;
		}
		else if (maze[i - 1][j] == 1 && i >= 0 && i < 3 && j >= 0 && j < 3 && maze[i][j] != -1 && loc[i - 1][j] != true) {
			init.x = i - 1;
			init.y = j;
			current = init;
			loc[i][j] = true;
			s1.push(current);
			i--;
		}
		else {
			maze[i][j] = -1;
			/*init = s1.pop();
			i = init.x;
			j = init.y;*/
		}
		s1.disp();
	}
	return 0;
}
