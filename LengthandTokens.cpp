#include<iostream>
using namespace std;
int main() {/*
	char ar[50];
	cout << " Enter your string : ";
	cin.getline(ar, 50);*/
	char ar[50] = { 's','a','m','i',' ','i','s',' ','a',' ','i','s',' ','g','o','o','d','b','o','y'};
	int i = 0, charcount = 0, wordcount = 1;
	while (ar[i] != '\0') {
		charcount++;
		if (ar[i] == ' ')
			wordcount++;
		i++;
	}
	int j = 0, l = 0;
	int* count = new int[wordcount];
	for (int i = 0;(i < charcount + 1);i++) {
		if (ar[i] != ' ' && ar[i] != '\0')
			j++;
		else if (ar[i] == ' ' || ar[i] == '\0') {
			count[l] = j;
			j = 0;
			l++;
		}
	}
	char** br = new char* [10];
	for (int i = 0;i < 5;i++) {
		br[i] = new char[5];
	}
	int k = 0;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			br[i][j] = ar[k];
			k++;
		}
	}
	char** word = new char* [wordcount];
	for (int i = 0;i < wordcount;i++) {
		word[i] = new char[count[i]];
	}
	int m = 0, n = 0;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (br[i][j] != ' ') {
				word[m][n] = br[i][j];
				n++;
			}
			else if (br[i][j] == ' ') {
				word[m++][n] = br[i][j];
				n = 0;
			}
		}
	}
	for (int i = 0;i < wordcount;i++) {
		cout << word[i] << endl;
	}
	for (int i = 0;i < wordcount;i++) {
		int frq = 1;
		for (int j = i;j < wordcount;j++) {
			if (word[i] == word[j]) {
				frq++;
			}
		}
		if (frq > 1) {
			cout << word[i] << " is repeated " << endl;
		}
		else
			cout << word[i] << " is unique " << endl;
	}
	return 0;
}

