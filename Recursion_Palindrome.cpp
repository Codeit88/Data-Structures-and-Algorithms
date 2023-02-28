#include<iostream>
using namespace std;
bool palin(char*ar,int size,const int &min) {
	if (min >=size ) {
		return true;
	}
	else if(ar[min]==ar[size-1]) {
		return palin(ar, size - 1, min + 1);
	}
	return false;
}
int main() {
	int min = 0;
	char* ar = new char[100];
	cout << " Enter your string : ";
	cin.getline(ar, 100);
	int i = 0,count=0;
	while (ar[i] != '\0') {
		count++;
		i++;
	}
	bool check=palin(ar,count,min);
	if (check == true) {
		cout << " Yes string is palindromic! \n";
	}
	else {
		cout << " Not a palindrome ! \n";
	}
	return 0;
}
