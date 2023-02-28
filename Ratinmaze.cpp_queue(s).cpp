#include<iostream>
using namespace std;
struct Position {
	int x, y;
};
template<typename T>
class Queue {
	T* arr;
	int size, front, rear;
public:
	Queue() {
		this->front = this->rear = -1;
		this->size = 0;
		this->arr = new T[this->size];
	}
	Queue(int size) {
		this->size = size;
		this->arr = new T[this->size];
		this->front = this->rear = -1;
	}
	bool IsFull()
	{
		return ((rear + 1) % size == front);
	}
	bool IsEmpty()
	{
		return (rear == front);
	}
	void enqueue(T data)
	{
		if (!IsFull())
		{
			rear = (rear + 1) % size;
			arr[rear] = data;
		}
	}
	int dequeue()
	{
		if (rear == front)
			front = rear = -1;
		else if (!IsEmpty())
		{
			arr[front] = -1;
			front = (front + 1) % size;
		}
		return arr[front];
	}
	void print()
	{
		int temp = front;
		while (temp != rear)
		{
			if (temp != -1)
				cout << arr[temp].x << " , " << arr[temp].y<<endl;
			temp = (temp + 1) % size;
		}
		cout << arr[rear].x << " , " << arr[rear].y;
	}
};
int main() {
	int maze[5][5] ={
		{1,0,0,0,0},
		{1,1,0,1,1},
		{0,1,1,0,1},
		{0,1,1,1,1},
		{0,0,0,0,1},
	};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "\t" << maze[i][j];
		}
		cout << endl;
	}
	bool** loc = new bool* [5];
	for (int i = 0;i < 5;i++) {
		loc[i] = new bool[5];
	}
	Queue <Position>q1(100); 
	Position init, destiny, current;
	init.x = init.y = 0;
	current = init;
	destiny.x = destiny.y = 4;
	int i = 0, j = i,count=1;
	while (current.x != destiny.x && current.y != destiny.y) {
		if (maze[i][j + 1] == 1 && i >= 0 && i < 5 && j >= 0 && j < 5 && maze[i][j]<count && loc[i][j + 1] != true) {
			count+=1;
			maze[i][j] = count;
			init.x = i;
			init.y = j + 1;
			current = init;
			loc[i][j] = true;
			q1.enqueue(current);
			j++;
		}
		else if (maze[i + 1][j] == 1 && i >= 0 && i < 5 && j >= 0 && j < 5 && maze[i+1][j] != -1 && loc[i + 1][j] != true) {
			count += 1;
			maze[i][j] = count;
			init.x = i + 1;
			init.y = j;
			current = init;
			loc[i][j] = true;
			q1.enqueue(current);
			i++;
		}
		else if (maze[i][j - 1] == 1 && i >= 0 && i < 5 && j >= 0 && j < 5 && maze[i][j-1] != -1 && loc[i][j - 1] != true) {
			count += 1;
			maze[i][j] = count;
			init.x = i;
			init.y = j - 1;
			current = init;
			loc[i][j] = true;
			q1.enqueue(current);
			j--;
		}
		else if (maze[i - 1][j] == 1 && i >= 0 && i < 5 && j >= 0 && j < 5 && maze[i-1][j] != -1 && loc[i - 1][j] != true) {
			count += 1;
			maze[i][j] = count;
			init.x = i - 1;
			init.y = j;
			current = init;
			loc[i][j] = true;
			q1.enqueue(current);
			i--;
		}
		else if (i != 0 && j != 0) {
			maze[i][j] = -1;
			/*init = q1.dequeue();
			i = init.x;
			j = init.y;*/
		}
		else {
			return 0;
		}
	}
	q1.enqueue(destiny);
	q1.print();
	return 0;
}
