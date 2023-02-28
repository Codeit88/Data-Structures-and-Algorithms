#include<iostream>
#include<fstream>
using namespace std;
int main()
{
 ifstream point;
 point.open("Good.txt");
 	int ar[8];
 	for(int i=0;i<8;i++)
 	{
 	   point>>ar[i];
 	   cout<<ar[i]<<endl;;
	 }
 return 0;
}


