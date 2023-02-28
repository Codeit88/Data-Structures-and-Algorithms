#include<iostream>
using namespace std;
int* evenodd(int *arr,int &temps,int size,int*brr,int k,int m) {
	if (k==temps) {
		return brr;
	}
	else {
		if (arr[k] % 2 == 0) {
			brr[m] = arr[k];
			return evenodd(arr,temps,size,brr,k+1,m+1);
		}
		else {
			brr[size -1] = arr[k];
			return evenodd(arr,temps, size-1, brr, k + 1,m);
		}
	}
}
int main() {
	int* arr=new int[100],size=0;
	cout << " Enter your array size: ";
	cin >> size;
	for (int i = 0;i < size;i++) {
		cin >> *(arr + i);
	}
	int* brr = new int[size];
	int* ptr = evenodd(arr,size, size, brr,0,0);
	for (int i = 0;i < size;i++) {
		cout << ptr[i] << " ";
	}
	return 0;
}

