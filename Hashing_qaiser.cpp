#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

template<class v>
struct HashItem
{
	int key = -1;
	v value;
	short status = 0;
};

template <class v>
class HashMap
{
protected:
	HashItem<v>* hashArray;
	int capa;
	int currentElements;

	virtual int getNextCandidateIndex(int key, int i)
	{
		while (i)
		{
			i = i % capa;

			if (hashArray[i].status == 0 || hashArray[i].status == 1)
			{
				break;
			}

			i++;
		}

		return i;
	}

	void doubleCapacity()
	{
		HashItem<v>* temp = hashArray;
		hashArray = new HashItem<v>[capa*2];
		currentElements = 0;
		int j = capa;
		capa *= 2;

		cout << "\n Capacity increased from " << j << " to " << capa;

		for (int i = 0; i < j; i++)
		{
			hashArray[i].key = temp[i].key;
			hashArray[i].status = temp[i].status;
			hashArray[i].value = temp[i].value;
		}

		delete[] temp;
	}

public:
	HashMap()
	{
		capa = 10;
		currentElements = 0;
		hashArray = new HashItem<v>[10];
	}

	HashMap(const int capacity)
	{
		//assert(capacity < 1);

		if (capacity >= 1)
		{
			currentElements = 0;
			this->capa = capacity;
			hashArray = new HashItem<v>[capa];
		}

		else
			cout << "\n Error!!\n\n";
	}

	void insert(int const key, v const value)
	{
		if (currentElements >= (int)capa*0.75)
		{
			doubleCapacity();
		}

		int ind = key % capa;
		ind = getNextCandidateIndex(key, ind);
		
		hashArray[ind].status = 2;
		hashArray[ind].value = value;
		hashArray[ind].key = key;
		currentElements++;
		cout << "\n Inserted-> Key: " << key << "\t value: " << value;
	}
	
	bool deleteKey(int const key)
	{
		bool del = 0;

		for (int i = 0; i < capa; i++)
		{
			if (hashArray[i].status == 2 && hashArray[i].key == key)
			{
				hashArray[i].status = 1; //deleted
				currentElements--;
				del = 1;
				cout << "\n deleted-> key: " << key;
				return del;
			}
		}

		return del;
	}

	v* get(int const key)
	{
		v* val = nullptr;
		for (int i = 0; i < capa; i++)
		{
			if (hashArray[i].status == 2 && hashArray[i].key == key )
			{
				val = &hashArray[i].value;
				return val;
			}
		}
		return val;
	}

	~HashMap()
	{
		delete[] hashArray;
	}
};

template<class v>
void populateHash(string file, HashMap<v>* h)
{
	ifstream read;
	read.open(file);

	if (!read.is_open())
	{
		cout << "\n can't open " << file;
	}

	int T_size;
	read >> T_size;
	read.ignore();

	while (T_size > 0)
	{
		string name;
		getline(read, name);

		int i = name.find(' ');
		string k = name.substr(0, i);

		stringstream key(k);
		int K = -1;
		key >> K;	//to get number instread of ascii of numbers

		name = name.substr(i + 1, name.size()); //extract stud name

		if (K != -1)
			h->insert(K, name);

		T_size--;
	}

	read.close();
}

template <class v>
class QHashMap: public HashMap<v>
{
protected: 
	int getNextCandidateIndex(int key, int i)
	{
		if (this->hashArray[i].status == 0 || this->hashArray[i].status == 1)//if no collis...
		{
			return i;
		}

		for(int j = 1; j < this->capa; j++)
		{
			i = (i + (j*j)) % this->capa;

			if (this->hashArray[i].status == 0 || this->hashArray[i].status == 1)
			{
				break;
			}

			i++;
		}

		return i;
	}

public:
	QHashMap() : HashMap<v>()
	{
		cout << "\n\n Quadratic Hash constructed!!\n";
	}

	QHashMap(const int cap) : HashMap<v>(cap)
	{
		cout << "\n\n Quadratic Hash constructed!!\n";
	}
};

template <class v>
class DHashMap : public HashMap<v>
{
protected:
	int getNextCandidateIndex(int key, int i)
	{
		int f = key % this->capa, s = 13 -(key % 13);
		i = (f + 1 * s) % this->capa;

		if (this->hashArray[i].status == 0 || this->hashArray[i].status == 1)//if no collis...
		{
			return i;
		}

		for (int j = 2; j < this->capa; j++)
		{
			i = (f + j * s) % this->capa;

			if (this->hashArray[i].status == 0 || this->hashArray[i].status == 1)
			{
				break;
			}
		}

		return i;
	}

public:
	DHashMap() : HashMap<v>()
	{
		cout << "\n\n Double Hash constructed!!\n";
	}

	DHashMap(const int cap) : HashMap<v>(cap)
	{
		cout << "\n\n Double Hash constructed!!\n";
	}
};


int main()
{
	HashMap<string> *map;
	map = new HashMap<string>;
	populateHash("students.txt", map);
	cout<<"\n Get(9)->" << *map->get(9);
	map->deleteKey(9);

	if (nullptr == map->get(9))
	{
		cout << "\n key 9 do not exist!!\n";
	}
	delete map;

	map = new QHashMap<string>;
	populateHash("students.txt", map);
	cout << "\n Get(98)->" << *map->get(98);
	map->deleteKey(98);

	if (nullptr == map->get(98))
	{
		cout << "\n key 98 do not exist!!\n";
	}
	delete map;

	map = new DHashMap<string>;
	populateHash("students.txt", map);

	cout << "\n Get(111)->" << *map->get(111);
	map->deleteKey(111);

	if (nullptr == map->get(111))
	{
		cout << "\n key 111 do not exist!!\n";
	}
	delete map;

	cout << "\n\n";
	system("pause");
	return 0;
}
