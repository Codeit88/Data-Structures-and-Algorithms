#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;

class Queue
{
	int* arr;
	int front;
	int rear;
	int size;

public:
	Queue()
	{
		arr = nullptr;
		front = rear = -1;
	}
	Queue(int size)
	{
		this->size = size;
		arr = new int[size];
		front = rear = -1;
	}
	bool IsFull()
	{
		return ((rear + 1) % size == front);
	}
	bool IsEmpty()
	{
		return (rear == -1 && front == -1);
	}
	void enqueue(int data)
	{
		if (!IsFull())
		{
			if (rear == front && front == -1)
				front = 0;

			rear = (rear + 1) % size;
			arr[rear] = data;
		}
	}
	int dequeue()
	{
		int z;
		if (rear == front)
			front = rear = -1;

		else if (!IsEmpty())
		{
			z = arr[front];
			front = (front + 1) % size;
		}
		return z;
	}
	int* josephus(int &people,int key);
	void print()
	{
		int temp = front;
		while (temp != rear)
		{
			cout << arr[temp] << " ";
			temp = (temp + 1) % size;
		}
		cout << arr[rear];
	}

};
int* Queue::josephus(int&people,int key) {
	int k=0,*arr=new int[people-2];
	int tsize = size;
	int staying;
	if (!IsEmpty()) {
		while (tsize > 1) {
			for (int i = 0;i < key - 1;i++) {
				enqueue(dequeue());
			}
			arr[k]=dequeue();
			k +=1 ;
			tsize -= 1;
			cout << endl;
			print();
		}
	}
	return arr;
}
void draw(RenderWindow &window, RectangleShape *rect, int& people) {
	for (int i = 0;i < people;i++)
	{
		window.draw(rect[i]);
	}
}
void kill(RectangleShape *rect, int& killno) {
	rect[killno].setFillColor(Color().Red);
}
int main(){
	int people, gap;
	cout << " Enter Total People : ";
	cin >> people;
	cout << " Enter the Gap: ";
	cin >> gap;
	Queue q1(people);
	for (int i = 1;i < (people + 1);i++) {
		q1.enqueue(i);
	}
	q1.print();
	int z=0,*ptr=q1.josephus(people,gap);
	cout << endl;
	for (int i = 0; i < people; i++)
	{
		cout << *(ptr + i) << " ";
	}
	RenderWindow window(VideoMode(700, 600), "Josephus", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	RectangleShape* rect=new RectangleShape[people];
	int x = 60;
	for (int i = 0;i < people;i++) {
		rect[i].setSize(Vector2f(40.f, 40.f));
		rect[i].setFillColor(Color().Green);
		rect[i].setPosition(Vector2f(50 + (i * x), 200));
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{   
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::S) {
				kill(rect, ptr[z]);
				z++;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		draw(window,rect,people);
		window.display();
	}
    return 0;
}
