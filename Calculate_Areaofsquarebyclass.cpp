#include<iostream>
using namespace std;
class Square
{
public:
int l,b;
void Area()
{
	cout<<"Enter length: ";
	cin>>l;
	cout<<"Enter breadth: ";
	cin>>b;
	cout<<"Area is : "<<l*b<<endl;
	}	
};
int main()
{
Square s1,s2;
s1.Area();
s2.Area();
 return 0;
}


