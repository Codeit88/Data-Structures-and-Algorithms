#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string line_txt;
	ifstream check;
	check.open("numbers.txt");
	while(!check.eof())
	{
		check>>line_txt;
		cout<<line_txt;
	}
	check.close();
 return 0;
}


