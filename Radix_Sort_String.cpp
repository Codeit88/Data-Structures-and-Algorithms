#include<iostream>
#include<string.h>
using namespace std;
class Queue {
	string* arr;
	int size, front, rear;
public:
	Queue() {
		this->front = this->rear = -1;
		this->size = 0;
		this->arr = new string[this->size];
	}
	Queue(int& size) {
		this->size = size;
		this->arr = new string[this->size];
		this->front = this->rear = -1;
	}
	bool IsFull(){
		return ((rear + 1) % size == front);
	//	return false;
	}
	bool IsEmpty(){
		return (rear == front);
	}
	void enqueue(string data)
	{
		if (!IsFull())
		{
			rear = (rear + 1) % size;
			arr[rear] = data;
		}
	}
	string dequeue()
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

	/*string getmax(string ar[], int& size) {
		string max = ar[0];
		for (int i = 0;i < size;i++) {
			if (ar[i] > max) {
				max = ar[i];
			}
		}
		return max;
	}
	int maxdig(string ar[], int& size) {
		string max = getmax(ar, size);
		int count = 0;
		while ('max' != 0) {
			count += 1;
			'max' = max / 10;
		}
		return count;
	}*/
	void print()
	{
		int temp = front;
		while (temp != rear)
		{
			if (temp != -1)
				cout << arr[temp] << " ";
			temp = (temp + 1) % size;
		}
		cout << arr[rear];
	}/*
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
	}*/
	void RadixSort(int maxnos) {
		int qsize = 10, count = 0;
		Queue* q2 = new Queue[256];
		for (int i = 0;i < 256;i++) {
			q2[i] = Queue(maxnos);
		}		
		char last;
		while (maxnos > 0) {
			for (int i = 0;i < this->size;i++) {
				string temp = arr[i];
				last = temp[maxnos-1];
				q2[(int)last].enqueue(arr[i]);
			}
			maxnos--;
			int k = 0;
			for (int i = 0;i < 10;i++) {
				while (!q2[i].IsEmpty()) {
					arr[k] = q2[i].dequeue();
					k++;
				}
			}
		}
		for (int i = 0;i < 10;i++) {
			cout << arr[i] << endl;
		}
	}
};
int main() {
	int qsize = 10;
	Queue q1(qsize);
	string keys[] = { "jgd","hgt","bne","qpo","muy","trf","vyub","cav","plq","lpt" };
	for (int i = 0;i < qsize;i++) {
		q1.enqueue(keys[i]);
	}
	q1.RadixSort(3);

	return 0;
}
