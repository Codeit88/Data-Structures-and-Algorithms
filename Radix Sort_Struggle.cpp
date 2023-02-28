#include<iostream>
using namespace std;
class Queue {
	int* arr;
	int size, front, rear;
public:
	Queue() {
		this->front = this->rear = -1;
		this->size = 0;
		this->arr = new int[this->size];
	}
	Queue(int& size) {
		this->size = size;
		this->arr = new int[this->size];
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
	void enqueue(int data)
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

	int getmax(int ar[], int& size) {
		int max = ar[0];
		for (int i = 0;i < size;i++) {
			if (ar[i] > max) {
				max = ar[i];
			}
		}
		return max;
	}
	int maxdig(int ar[], int& size) {
		int max = getmax(ar, size);
		int count = 0;
		while (max != 0) {
			count += 1;
			max = max / 10;
		}
		return count;
	}
	void print()
	{
		int temp = front;
		while (temp != rear)
		{
			if(temp!=-1)
			cout << arr[temp] << " ";
			temp = (temp + 1) % size;
		}
		cout << arr[rear];
	}
	int digitgetter(int& num, int& dig) {
		int rem, rev = 0;
		int num1 = num;
		while (num1 != 0) {
			rem = num1 % 10;
			rev = rev * 10 + rem;
			num1 /= 10;
		}
		int i = 0;
		while (i < dig) {
			rem = rev % 10;
			rev /= 10;
			i++;
		}
		return rem;
	}
	void RadixSort( int& maxnos) {
		int qsize = 10,count=0;
		Queue *q2=new Queue[10];
		for (int i = 0;i < qsize;i++) {
			q2[i] = Queue(maxnos);
		}
		int temp;
		while (maxnos > 0) {
			for (int i = 0;i < this->size;i++) {				
				temp = digitgetter(arr[i], maxnos);
				q2[temp].enqueue(arr[i]);
			}
			maxnos--;
			int k = 0;
			for (int i = 0;i < 10;i++) {
				while (!q2[i].IsEmpty()) {
					arr[k] = q2[i].dequeue();
					k++;
				}
			}
			/*int j = 0;
			while(j<10) {
				q2[j].print();
				cout << endl;
				j++;
			}*/
		}
		/*for(int i=0;i<size;i++)
		{
			while (!q2[i].IsEmpty())
			{
				arr[i] = q2[i].dequeue();
			}
		}*/
		/*for (int i = 0;i < size;i++) {
			arr[i] = q2[i].dequeue();
		}*/
		/*for (int i = 0;i < 10;i++) {
			cout << i << " : ";
			q2[i].print();
			cout << endl;
		}*/
		for (int i = 0;i < 10;i++) {
			cout << arr[i] << endl;
		}
	}
};
int main() {
	int qsize = 10;
	Queue q1(qsize);
	int keys[] = {111,321,234,546,879,543,124,654,678,543};
	for (int i = 0;i < qsize;i++) {
		q1.enqueue(keys[i]);
	}
	int maxnos = q1.maxdig(keys, qsize);
	q1.RadixSort( maxnos);

	return 0;
}
