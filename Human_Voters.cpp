#include<iostream>
using namespace std;
class Human {
protected:
	char* name;int age;
	bool eligibility;
public:
	Human(){}
	virtual void disp() = 0;
	virtual ~Human(){}
};
class Elders :public Human {
public:
	Elders(const char name[], int age, bool eligibility) {
		this->name = new char[20];
		for (int i = 0;i<20;i++) {
			this->name[i] = name[i];
		}
		this->age = age;
	}
	void disp() {
		cout << "................... For Adults ....................\n";
		cout << " Name is : ";
		for (int i = 0;name[i] != '\0';i++) {
			cout << name[i];
		}
		cout << endl;
		cout << " Age is : " << age << endl;
		cout << " He is eligible for voting !" << endl;
	}
	~Elders() {
		delete[]name;
	}
};
class Child :public Human {
public:
	Child(const char name[], int age, bool eligibility) {
		this->name = new char[20];
		for (int i = 0;i<20;i++) {
			this->name[i] = name[i];
		}
		this->age = age;
	}
	void disp() {
		cout << "................... For Childs ....................\n";
		cout << " Name is : ";
		for (int i = 0;name[i] != '\0';i++) {
			cout << name[i];
		}
		cout << endl;
		cout << " Age is : " << age << endl;
		cout << " He is not eligible for voting !" << endl;
	}
	~Child() {
		delete[]name;
	}
};
int main() {
	Human* h1[2];
	h1[0] = new Elders("Ali", 41, true);
	h1[1] = new Child("Azam", 14, false);
	for (int i = 0;i < 2;i++) {
		h1[i]->disp();
	}
	for (int i = 0;i < 2;i++) {
		delete h1[i];
	}
	return 0;
}
