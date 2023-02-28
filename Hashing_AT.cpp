#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
using namespace std;
int a = 1;//used for Qhash
int d = 2;//for D hash
bool d_check = false;
template<class V>
struct HashItem
{
	V value;
	int key;
	short status;
};
template<class V>
class HashMap
{
public:
	HashItem<V>* array;
	int size;
	int capacity;
	virtual int getNextCandidateIndex(int key, int index)
	{
		if (index == capacity - 1)//at last
		{
			bool is_space = false;
			for (int a = 0; a < capacity; a++)//checking if there any space behind
			{
				if ((array[a]).status != 1 && (array[a]).status != 2)//means space there
				{
					is_space = true;
					return a;
					break;
				}
			}
			if (is_space == false)//no space need array to be doubled
			{
				double_capacity();
				index = key % capacity;
				return index;
			}
		}
		else
		{
			int a = index + key;
			return  a % capacity;
		}
	}

	//-----------------------------------------------------------------------------------------------------------

	HashMap()
	{
		capacity = 10;
		array = new HashItem<V>[10];
		size = 0;
		for (int i = 0; i < capacity; i++)
		{
			(array[i]).status = 0;//means empty already
			(array[i]).key = -99999;//delimeter
			(array[i]).value = -99999;//delimeter

		}
	}
	HashMap(int a)
	{
		capacity = a;
		array = new HashItem<V>[a];
		size = 0;
		for (int i = 0; i < capacity; i++)
		{
			(array[i]).status = 0;//means empty already
			(array[i]).key = -99999;//delimeter
			(array[i]).value = -99999;//delimeter

		}
	}
	HashItem<V>* double_capacity()
	{
		capacity = capacity * 2;
		HashItem<V>* replica = new HashItem<V>[capacity];
		for (int i = 0; i < capacity/2; i++)
		{
			(replica[i]).key = (array[i]).key;
			(replica[i]).value = (array[i]).value;
			(replica[i]).status = (array[i]).status;
		}
		delete[] array;
		array = new HashItem<V>[capacity];
		for (int i = 0; i < capacity; i++)
		{
			(array[i]).key = (replica[i]).key;
			(array[i]).value = (replica[i]).value;
			(array[i]).status = (replica[i]).status;
		}
		delete[] replica;
		
		return this->array;
	}
	void insert(int k, V val)
	{
		if (d_check == false)
		{
			size++;
			int index;
			index = k % capacity;
			if ((array[index]).status == 0 || (array[index]).status == 1)//not occupied
			{
				(array[index]).key = k;
				(array[index]).value = val;
				(array[index]).status = 2;
			}
			else if ((array[index]).status == 2)//occupied
			{
				bool is_inserted = false;
				while (is_inserted == false)
				{
					index = getNextCandidateIndex(k, index);
					if ((array[index]).status != 2 && index > capacity - 1);
					{
						is_inserted = true;
						(array[index]).key = k;
						(array[index]).value = val;
						(array[index]).status = 2;
						a = 1;
					}
				}
			}
		}
		else//for d map
		{
			size++;
			int index;
			index = k % capacity;
			if ((array[index]).status == 0 || (array[index]).status == 1)//not occupied
			{
				(array[index]).key = k;
				(array[index]).value = val;
				(array[index]).status = 2;
			}
			else if ((array[index]).status == 2)//occupied
			{
				bool is_inserted = false;
				while (is_inserted == false)
				{
					
					index = getNextCandidateIndex(k, index); //cout << "Index = " << index << endl;
					if ((array[index]).status != 2 && index < capacity - 1)
					{
						is_inserted = true;
					//	cout << val << " Inserted at " << index << endl;
						(array[index]).key = k;
						(array[index]).value = val;
						(array[index]).status = 2;
						d = 1;//inserted
					}
					else
					{
							d++;
					}
						
				}
			}
		}
	}
	bool Delete(int key)
	{
		bool check = false;
		for (int i = 0; i < capacity; i++)
		{
			if ((array[i]).key == key)
			{
				(array[i]).status = 1;
				cout << "Deleting " << (array[i]).value << endl;
				check = true;
			}
		}
		return check;
	}
	V get(int key)
	{
		V val = "NULL";
		for (int i = 0; i < capacity; i++)
		{
			if ((array[i]).key == key)
			{
				val = (array[i]).value;
				break;
			}
		}
		return val;
	}
	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if ((array[i]).status == 2)
				cout << (array[i]).value << endl;
		}
	}
	~HashMap()
	{
		//cout << "Parent hash map destructor " << endl;
		delete[]array;
	}
};
template<class V>
class Qhashmap :public HashMap<V>
{
public:
	
	Qhashmap() :HashMap<V>()
	{

	}
	Qhashmap(int a) :HashMap<V>(a)
	{

	}
	int getNextCandidateIndex(int key, int index)
	{
		int capacity = HashMap<V>::capacity;
		HashItem<V>* array = HashMap<V>::array;
		if (index == capacity - 1 || index > capacity - 1)//at last
		{
			bool is_space = false;
			for (int a = 0; a < capacity; a++)//checking if there any space behind
			{
				if ((array[a]).status != 1 && (array[a]).status != 2)//means space there
				{
					is_space = true;
					return a;
					break;
				}
			}
			if (is_space == false)//no space need array to be doubled
			{
				HashMap<V>::double_capacity();
				index = key % capacity;
				return index;
			}
		}
		else
		{
			int t;
			t= index + (a * a);
			a++;
			return t;
		}
	}
	void insert(int k, V val)
	{
		HashMap<V>::insert(k, val);
	}
	void Delete(int k)
	{
		HashMap<V>::Delete(k);
	}
	void display()
	{
		HashMap<V>::display();
	}
	~Qhashmap()
	{
		//cout << "Q hash map destructor " << endl;
	}
};
template<class V>
class Dhashmap :public HashMap<V>
{
public:
	Dhashmap() :HashMap<V>()
	{
		d = 1;
		d_check = true;
	}
	Dhashmap(int a) :HashMap<V>(a)
	{
		d = 1;
		d_check = true;
	}
	int getNextCandidateIndex(int key, int index)
	{
		int capacity = HashMap<V>::capacity;
		HashItem<V>* array = HashMap<V>::array;
		if (index == capacity - 1 || index > capacity - 1)//at last
		{
			bool is_space = false;
			for (int a = 0; a < capacity; a++)//checking if there any space behind
			{
				if ((array[a]).status != 1 && (array[a]).status != 2)//means space there
				{
					is_space = true;
					return a;
					break;
				}
			}
			if (is_space == false)//no space need array to be doubled
			{
				HashMap<V>::double_capacity();
				capacity = HashMap<V>::capacity;
			    array = HashMap<V>::array;
				index = key % capacity;
				return index;
			}
		}
		else
		{
			if (d == 2)//for second value
			{
				int prime;
				int x = 1 + (rand() % (key - 1));
				prime = (x * x) - x + 11;
				int second_value = (prime - (key % prime));
				return second_value;
				d++;
			}
			else if (d == 3 || d > 3)//for third value
			{
				
				int prime;
				int x = rand();
				prime = (x * x) - x + 11;
				int capacity = HashMap<V>::capacity;
				int first_value = key % capacity;
				int second_value = (prime - (key % prime));
				int candidate_index = (first_value + index * second_value) % capacity;
				return candidate_index;
			}
		}
	}
	void insert(int k, V val)
	{
		HashMap<V>::insert(k, val);
	}
	void Delete(int k)
	{
		HashMap<V>::Delete(k);
	}
	void display()
	{
		HashMap<V>::display();
	}
	~Dhashmap()
	{
		//	cout << "D hash map destructor " << endl;
		d_check = false;
	}
};
void populate_hash(string file, HashMap<string>* obj)
{
	ifstream infile;
	int id;
	string name;
	infile.open(file);
	if (!infile)
	{
		cout << "File not opened " << endl;
	}
	else
	{
		while (!infile.eof())
		{
			if (!infile.eof())
			{
				infile >> id;
				infile >> name;
				
				obj->insert(id, name); 

			}
			else
				break;
		}
	}
}
int main()
{
	HashMap<string>* map = new HashMap<string>();
	populate_hash("students.txt", map);
	cout << map->get(9) << endl;
	map->Delete(9);
	if (map->get(9) == "NULL")
	{
		cout << "Yes It is NULL " << endl;
	}
	else
	{
		cout << "No it is not NULL " << endl;
	}
	delete map;
	//----------------------------------------------------------------------------------------------------------------------
	map = new Qhashmap<string>();
	populate_hash("students.txt", map);
	cout << map->get(98) << endl;
	map->Delete(98);
	if (map->get(98) == "NULL")
	{
		cout << "Yes It is NULL " << endl;
	}
	else
	{
		cout << "No it is not NULL " << endl;
	}
	delete map;
	
	//-----------------------------------------------------------------------------------------------------------------------
	map = new Dhashmap<string>();
	populate_hash("students.txt", map);
	cout << map->get(101) << endl;
	map->Delete(101);
	if (map->get(101) == "NULL")
	{
		cout << "Yes It is NULL " << endl;
	}
	else
	{
		cout << "No it is not NULL " << endl;
	}
	delete map;
	return 0;
}



