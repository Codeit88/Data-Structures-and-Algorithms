#include<iostream>
#include<vector>
using namespace std;
void swap_val(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
class Min_heap {
	vector<int> vec;
public:
	Min_heap() {
		vec.resize(1);
		vec[0] = 1;
	}
	void insert(int val){
			vec.push_back(val);
			int index = vec.size() - 1;
			bubble_up(index);
		}
    void bubble_up(int index)
     { 
    if (index == 1)
    {
        return;
    }
    else if (vec[index / 2] < vec[index])
    { 
        return;
    }
    else
    {
        swap_val(vec[index / 2], vec[index]);
        bubble_up(index / 2);
    }
}
    void bubble_down(int index)
    { 
        if (2 * index > (vec.size() - 1))
        {
            return;
        }
        else
        {
            if (2 * index + 1 <= vec.size() - 1) {
                if ((vec[index] > vec[2 * index]) || (vec[index] > vec[2 * index + 1])) {
                    if (vec[2 * index] < vec[2 * index + 1])
                    {
                        swap_val(vec[index], vec[2 * index]);
                        bubble_down(2 * index);
                    }
                    else
                    {
                        swap_val(vec[index], vec[2 * index + 1]);
                        bubble_down(2 * index + 1);
                    }
                }
            }
            else if (vec[index] > vec[2 * index]) {
                swap_val(vec[index], vec[2 * index]);
                bubble_down(2 * index);
            }
        }
    }
    int find_min(int &x,int&y){
        if (x < y)
            return x;
        return y;
    }
    void Heapify()
    {
        int parent = (vec.size() - 1) / 2;
        int index = vec.size() - 1;
        int min = 0;
        while (index >= 1)
        {
            if (parent * 2 + 1 < vec.size())
                min = find_min(vec[parent * 2], vec[parent * 2 + 1]);
            else
                min = vec[parent * 2];
            if (vec[parent] > min)
            {
                bubble_down(parent);
            }
            index--;
            parent = index / 2;
        }
    }
};
int main() {
	Min_heap m1;
    
	return 0;
}
