#include<iostream>
using namespace std;
int** splitter(int br[][4], int& b) {
	int* a1 = new int[b];
	int* a2 = new int[b];
	int* a3 = new int[4-b];
	int* a4 = new int[4-b];
	for (int i = 0;i < 1;i++) {
		for (int j = 0;j < b;j++) {
			if (j < b)
				a1[j] = br[i][j];
		}
	}
	for (int i = 0;i < 1;i++) {
		for (int j = b;j <4;j++) {
				a3[j] = br[i][j];
		}
	}
	for (int i = 1;i < 2;i++) {
		for (int j = 0;j < b;j++) {
				a2[j] = br[i][j];
		}
	}
	for (int i = 1;i < 2;i++) {
		for (int j = b;j < 4;j++) {
			a4[j] = br[i][j];
		}
	}
	int** cr=new int*[4];
	cr[0] = a1;
	cr[1] = a2;
	cr[2] = a3;
	cr[3] = a4;
	return cr;
}
int main() {
	int a,ar[2][4] = { {11,22,31,45,},{16,47,68,19} };
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			cout << " "<<ar[i][j];
		}
		cout << endl;
	}
	cout << " Enter your seperation index : ";
	cin >> a;
	int **dr=splitter(ar, a);
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			cout << " "<<dr[i][j]<<endl;
		}
		cout << endl;
	}
	return 0;
}
