#include<iostream>
using namespace std;
int main() {
	int elem;
	cout << " enter the search value : ";
	cin >> elem;
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int low=0, mid, high=9;
	mid = (low + high) / 2;
	while (low <= high) {
		if (elem==ar[mid]) {
			flag=1;
		}
		else if (elem > ar[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << " E;ement was fount at : " << mid << endl;
		return 0;
}
