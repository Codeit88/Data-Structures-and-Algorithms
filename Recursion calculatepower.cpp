#include<iostream>
using namespace std;
int calpow(int num,int store,int power){
	if (power == 1)
		return store;
	else
		return calpow(num, store * num, power - 1);
}
int main() {
	cout << calpow(2,2,5);
	return 0;
}
