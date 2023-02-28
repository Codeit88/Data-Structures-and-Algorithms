#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
struct Hash_Item {
	char val;
	bool status;
	Hash_Item* next,*tail;
	Hash_Item() {
		this->val = 0;
		this->status = false;
		this->next  = this->next = NULL;
	}
	Hash_Item(int val) {
		this->val = val;
		this->status = false;
		this->next = this->next = NULL;
	}
};
class Hash_Table {
  private:
	int currsize,size;// Size will always be odd
	Hash_Item* arr;
  public:
	  Hash_Table() {
		  this->currsize = 0;
		  this->size = 0;
		  this->arr = NULL;
	  }
	  Hash_Table(int size){
		  this->currsize = 0;
		  this->size = size;
		  this->arr = new Hash_Item[this->size];
	  }
	  //Hash_Table(int method,bool rehash) {}
	  Hash_Item access(int index) {
		  return this->arr[index];
	  }
	  void Update(int &key,char val) {
		  for (int i = 0; i < this->size; i++)	  {
			  if (arr[i].val == key)
				  arr[i].val = val;
		  }
	  }
	  int Hash_it(char &val){
		  return val % 10;
	  }
	  void insert(char val){
		 /* this->currsize += 1;
		  if (currsize > (this->size / 2)) {
			  this->size *= 2;
		  }*/
		  int index = Hash_it(val);
		  if (arr[index].status == false) {
			  arr[index].val = val;
			  arr[index].status = true;
		  }
		  else {
			  Hash_Item *b=new Hash_Item(val);
			  if (arr[index].next == NULL) {
				  arr[index].next = b;
				  arr[index].tail = b;
			  }
			  else {
				  arr[index].tail->next = b;
			  }
		  }
	  }
	  void double_hashing(int& index, char& val) {
		  int i = 1;
		  int hf2 = 1 + (val % 8);//8-(val%8);
			  i = index % 10;
			  index = (i + hf2) % 10;
		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void pseudo_random_probe(int& index, char& val){
		  unsigned seed = time(0);
		  srand(seed);
		  int r=0,i=0;
		  while (arr[index].status != false) {
			  r = 2 * val + rand() % 10;
			  index = r % 10;
		  }

		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void linear_probe(int &index,char &val) {
		  int i = 1;
		  while (arr[index].status != false) {
			  index = (index + i) % 10;
		  }
		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void linear_probe_steps(int& index, char& val) {
		  int i = 1;
		  while (arr[index].status != false) {
			  index = (index + i*3) % 10;
		  }
		  arr[index].val = val;
		  arr[index].status = true;
	  }
	  void delete_val(char val) {
		  for (int i = 0; i < this->size; i++){
			  if (arr[i].val == val) {
				  for (int j = i; j < this->size; j++) {
					  arr[j] = arr[j+1];
				  }
			  }
		  }
		 this->size--;
	  }
	  void print_table() {
		  for (int i = 0; i < this->size; i++){
			  if (arr[i].next != NULL) {
				  while (arr[i].next != NULL) {
					  cout <<i<< " : "<< arr[i].val << endl;
					  arr[i] = arr[i].next->val;
				  }
			  }
			  cout << i << " : " << arr[i].val << endl;
		  }
	  }
};
int main() {
	Hash_Table h1(10);
	h1.insert('a');
	h1.insert('b');
	h1.insert('d');
	h1.insert('j');
	h1.insert('k');
	h1.insert('5');
	h1.insert('u');
	h1.insert('8');
	h1.insert('12');
	cout << endl;
	h1.print_table();
	return 0;
}
