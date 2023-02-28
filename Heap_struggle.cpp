#include<iostream>
#include<vector>
using namespace std;
void swap_val(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
class Min_heap {
    vector<int>vec1;
    int size;
public:
    Min_heap(){
        this->size = 0;
        vec1.resize(size);
    }
    void insert(int val){
        size++;
        vec1.resize(size);
        int index = size - 1;
        vec1[index] = val;
        while (index != 0 && vec1[(index - 1) / 2] > vec1[index]) {
            swap_val(vec1[(index - 1) / 2], vec1[index]);
            index = (index - 1) / 2;
        }
    }
};
int main() {
	Min_heap m1;
    m1.insert(22);
    m1.insert(5);
    m1.insert(67);
    m1.insert(4);
    m1.insert(6);
    m1.insert(33);
    m1.insert(77);


	return 0;
}
